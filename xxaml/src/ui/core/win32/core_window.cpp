#include "pch.hpp"
#include "basics.hpp"
#include "ui/core/win32/core_window.hpp"

// TODO: drawing system
#include <gl/GL.h>
#include <gl/GLU.h>

using namespace xxaml::foundation;
using namespace xxaml::ui;
using namespace xxaml::ui::core;

xresult core_window::create( core_window** result )
{
	NEW_AND_CHECK( ret, core_window_win32 );

	*result = ret;
	return xresult::ok;
}

enum class ProcessDpiAwareness
{
	Unaware = 0,
	DpiAware = 1,
	PerMonitorDpiAware = 2
};

typedef HRESULT __stdcall SetProcessDpiAwareness( _In_ ProcessDpiAwareness value );

class dll_loader
{
public:
	dll_loader( wchar_t* const dll_filename )
	{
		hinstance_ = LoadLibraryW( dll_filename );
	}

	~dll_loader()
	{
		FreeLibrary( hinstance_ );
	}

	operator HINSTANCE() const
	{
		return hinstance_;
	}

private:
	HINSTANCE hinstance_;
};

core_window_win32::core_window_win32()
	: initialized_( false )
	, hinstance_( nullptr )
	, hwnd_( nullptr )
{ }

core_window_win32::~core_window_win32()
{
	if( initialized_ )
	{
		{
			wglMakeCurrent( nullptr, nullptr );
			wglDeleteContext( hglrc_ );
			ReleaseDC( hwnd_, hdc_ );
		}

		UnregisterClassW( MAKEINTATOM( window_class_atom_ ), hinstance_ );
		initialized_ = false;
	}
}

xresult core_window_win32::activate()
{
	if( !initialized_ )
	{
		initialize();
	}

	ShowWindow( hwnd_, SW_SHOW );

	return xresult::ok;
}

xresult core_window_win32::initialize()
{
	hinstance_ = GetModuleHandleW( nullptr );
	if( hinstance_ == nullptr )
	{
		return xresult::failed;
	}

	long long timestamp = 0;
	GetSystemTimeAsFileTime( reinterpret_cast<LPFILETIME>( &timestamp ) );
	int process_id = GetCurrentProcessId();
	int thread_id = GetCurrentThreadId();

	wchar_t class_name[64] = { 0 };
	swprintf_s( class_name, L"XXaml.UI.Core.CoreWindow[%llx;p%d-t%d]", timestamp, process_id, thread_id );

	WNDCLASSEXW wcex = { sizeof( WNDCLASSEXW ) };
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = core_dispatcher_win32::window_procedure_lancher;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = sizeof( core_dispatcher_win32* );
	wcex.hInstance = hinstance_;
	wcex.hIcon = LoadIconW( hinstance_, IDI_APPLICATION );
	wcex.hCursor = LoadCursorW( nullptr, IDC_ARROW );
	wcex.hbrBackground = reinterpret_cast<HBRUSH>( COLOR_WINDOW );
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName = class_name;
	wcex.hIconSm = LoadIconW( wcex.hInstance, IDI_APPLICATION );
	window_class_atom_ = RegisterClassExW( &wcex );
	if( window_class_atom_ == 0 )
	{
		return xresult::failed;
	}

	{
		dll_loader loader( L"shcore.dll" );
		if( loader != nullptr )
		{
			auto fnSetProcessDpiAwareness = reinterpret_cast<SetProcessDpiAwareness*>( GetProcAddress( loader, "SetProcessDpiAwareness" ) );
			fnSetProcessDpiAwareness( ProcessDpiAwareness::PerMonitorDpiAware );
		}
	}

	dispatcher_ = new core_dispatcher_win32( this );

	hwnd_ = CreateWindowExW(
		0,
		class_name,
		L"",
		WS_OVERLAPPEDWINDOW,
		0, 0, 640, 480,
		nullptr,
		nullptr,
		hinstance_,
		dispatcher_.value() );
	if( hwnd_ == nullptr )
	{
		return xresult::failed;
	}

	// TODO: drawing system
	{
		hdc_ = GetDC( hwnd_ );

		PIXELFORMATDESCRIPTOR pixelFormatDesc =
		{
			sizeof( PIXELFORMATDESCRIPTOR ),
			1,
			PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
			PFD_TYPE_RGBA,
			32,
			0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0,
			24, 8,
			0,
			PFD_MAIN_PLANE,
			0,
			0, 0, 0,
		};

		int format = ChoosePixelFormat( hdc_, &pixelFormatDesc );
		if( format == 0 )
		{
			return xresult::failed;
		}

		if( !SetPixelFormat( hdc_, format, &pixelFormatDesc ) )
		{
			return xresult::failed;
		}

		hglrc_ = wglCreateContext( hdc_ );
		if( !wglMakeCurrent( hdc_, hglrc_ ) )
		{
			return xresult::failed;
		}

		glEnable( GL_BLEND );
		glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

		glDisable( GL_DEPTH_TEST );

		glEnable( GL_CULL_FACE );
		glCullFace( GL_BACK );

		glMatrixMode( GL_PROJECTION );
		glLoadIdentity();
		glTranslatef( -1.f, 1.f, 0.f );

		::size s;
		size( &s );
		glScalef( 2.f / s.width, -2.f / s.height, 1.f );
	}

	initialized_ = true;
	return xresult::ok;
}

xresult core_window_win32::close()
{
	return xresult::ok;
}

xresult core_window_win32::adjust_rect( RECT& rect ) const
{
	::std::size_t style = GetWindowLongPtrW( hwnd_, GWL_STYLE );
	if( style == FALSE )
	{
		return xresult::failed;
	}

	::std::size_t exstyle = GetWindowLongPtrW( hwnd_, GWL_EXSTYLE );
	if( style == FALSE )
	{
		return xresult::failed;
	}

	return AdjustWindowRectEx( &rect, style, FALSE, exstyle ) != FALSE ? xresult::ok : xresult::failed;
}

xresult core_window_win32::get_rect( RECT& rect ) const
{
	return GetWindowRect( hwnd_, &rect ) != FALSE ? xresult::ok : xresult::failed;
}


xresult core_window_win32::dispatcher( core_dispatcher** result ) const
{
	*result = dispatcher_;
	return xresult::ok;
}


xresult core_window_win32::content( xaml::controls::frame** result ) const
{
	*result = content_.value() != nullptr ? content_.value() : nullptr;
	return xresult::ok;
}
xresult core_window_win32::set_content( xaml::controls::frame* value )
{
	content_ = value;
	return xresult::ok;
}


xresult core_window_win32::title( xstring* result ) const
{
	return xresult::ok;
}

xresult core_window_win32::window_state( ::window_state* result ) const
{
	return xresult::ok;
}

xresult core_window_win32::left( int* result ) const
{
	if( !initialized_ )
	{
		return xresult::invalid_operation;
	}

	RECT rect = { 0 };
	if( get_rect( rect ) != xresult::ok )
	{
		return xresult::failed;
	}
	*result = rect.left;
	return xresult::ok;
}

xresult core_window_win32::top( int* result ) const
{
	if( !initialized_ )
	{
		return xresult::invalid_operation;
	}

	RECT rect = { 0 };
	if( get_rect( rect ) != xresult::ok )
	{
		return xresult::failed;
	}
	*result = rect.top;
	return xresult::ok;
}

xresult core_window_win32::width( int* result ) const
{
	if( !initialized_ )
	{
		return xresult::invalid_operation;
	}

	RECT rect = { 0 };
	if( get_rect( rect ) != xresult::ok )
	{
		return xresult::failed;
	}
	*result = rect.right - rect.left;
	return xresult::ok;
}

xresult core_window_win32::height( int* result ) const
{
	if( !initialized_ )
	{
		return xresult::invalid_operation;
	}

	RECT rect = { 0 };
	if( get_rect( rect ) != xresult::ok )
	{
		return xresult::failed;
	}
	*result = rect.bottom - rect.top;
	return xresult::ok;
}

xresult core_window_win32::position( point* result ) const
{
	if( !initialized_ )
	{
		return xresult::invalid_operation;
	}

	RECT rect = { 0 };
	if( get_rect( rect ) != xresult::ok )
	{
		return xresult::failed;
	}
	*result = point{ rect.left, rect.top };
	return xresult::ok;
}

xresult core_window_win32::size( ::size* result ) const
{
	if( !initialized_ )
	{
		return xresult::invalid_operation;
	}

	RECT rect = { 0 };
	if( get_rect( rect ) != xresult::ok )
	{
		return xresult::failed;
	}
	*result = ::size{ rect.right - rect.left, rect.bottom - rect.top };
	return xresult::ok;
}

xresult core_window_win32::position_and_size( rect* result ) const
{
	if( !initialized_ )
	{
		return xresult::invalid_operation;
	}

	RECT rect = { 0 };
	if( get_rect( rect ) != xresult::ok )
	{
		return xresult::failed;
	}
	*result = ::rect{ rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top };
	return xresult::ok;
}

xresult core_window_win32::min_width( int* result ) const
{
	return xresult::not_implemented;
}

xresult core_window_win32::max_width( int* result ) const
{
	return xresult::not_implemented;
}

xresult core_window_win32::min_height( int* result ) const
{
	return xresult::not_implemented;
}

xresult core_window_win32::max_height( int* result ) const
{
	return xresult::not_implemented;
}

xresult core_window_win32::min( ::size* result ) const
{
	return xresult::not_implemented;
}

xresult core_window_win32::max( ::size* result ) const
{
	return xresult::not_implemented;
}


xresult core_window_win32::set_title( xstring value )
{
	if( !initialized_ )
	{
		return xresult::invalid_operation;
	}

	return xresult::ok;
}

xresult core_window_win32::set_window_state( ::window_state value )
{
	if( !initialized_ )
	{
		return xresult::invalid_operation;
	}

	return xresult::ok;
}

xresult core_window_win32::set_left( int value )
{
	if( !initialized_ )
	{
		return xresult::invalid_operation;
	}

	int top_value = 0;
	if( top( &top_value ) != xresult::ok )
	{
		return xresult::failed;
	}
	return set_position( point{ value, top_value } );
}

xresult core_window_win32::set_top( int value )
{
	if( !initialized_ )
	{
		return xresult::invalid_operation;
	}

	int left_value = 0;
	if( left( &left_value ) != xresult::ok )
	{
		return xresult::failed;
	}
	return set_position( point{ value, left_value } );
}

xresult core_window_win32::set_width( int value )
{
	if( !initialized_ )
	{
		return xresult::invalid_operation;
	}

	int height_value = 0;
	if( height( &height_value ) != xresult::ok )
	{
		return xresult::failed;
	}
	return set_size( ::size{ value, height_value } );
}

xresult core_window_win32::set_height( int value )
{
	if( !initialized_ )
	{
		return xresult::invalid_operation;
	}

	int width_value = 0;
	if( width( &width_value ) != xresult::ok )
	{
		return xresult::failed;
	}
	return set_size( ::size{ width_value, value } );
}

xresult core_window_win32::set_position( point value )
{
	if( !initialized_ )
	{
		return xresult::invalid_operation;
	}

	RECT rect = { value.x, value.y, 0, 0 };
	if( adjust_rect( rect ) != xresult::ok )
	{
		return xresult::failed;
	}
	return SetWindowPos(
		hwnd_,
		nullptr,
		rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top,
		SWP_NOZORDER | SWP_NOSIZE ) != FALSE ? xresult::ok : xresult::failed;
}

xresult core_window_win32::set_size( ::size value )
{
	if( !initialized_ )
	{
		return xresult::invalid_operation;
	}

	RECT rect = { 0, 0, value.width, value.height };
	if( adjust_rect( rect ) != xresult::ok )
	{
		return xresult::failed;
	}
	return SetWindowPos(
		hwnd_,
		nullptr,
		rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top,
		SWP_NOZORDER | SWP_NOMOVE ) != FALSE ? xresult::ok : xresult::failed;
}

xresult core_window_win32::set_position_and_size( rect value )
{
	if( !initialized_ )
	{
		return xresult::invalid_operation;
	}

	RECT rect = { value.x, value.y, value.width, value.height };
	if( adjust_rect( rect ) != xresult::ok )
	{
		return xresult::failed;
	}
	return SetWindowPos(
		hwnd_,
		nullptr,
		rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top,
		SWP_NOZORDER ) != FALSE ? xresult::ok : xresult::failed;
}

xresult core_window_win32::set_min_width( int value )
{
	return xresult::not_implemented;
}

xresult core_window_win32::set_max_width( int value )
{
	return xresult::not_implemented;
}

xresult core_window_win32::set_min_height( int value )
{
	return xresult::not_implemented;
}

xresult core_window_win32::set_max_height( int value )
{
	return xresult::not_implemented;
}

xresult core_window_win32::set_min( ::size value )
{
	return xresult::not_implemented;
}

xresult core_window_win32::set_max( ::size value )
{
	return xresult::not_implemented;
}