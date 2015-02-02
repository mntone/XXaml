#include "pch.hpp"
#include "basics.hpp"
#include "ui/core/win32/core_dispatcher.hpp"
#include "ui/core/win32/core_window.hpp"

using namespace xxaml::foundation;
using namespace xxaml::ui::core;
using namespace xxaml::ui::xaml::controls;

/*
	[Windows 版 CoreDispatcher 設計]
	1. バックグラウンドから Queue にデータを追加するときは mutex で lock
	2. フォアグラウンドへの通知は Win32 の TryPostMessage で通知。
	ただし、PeekMessage でメッセージの重複を取り除く。
	以上
	*/

core_dispatcher_win32::core_dispatcher_win32( core_window_win32* parent )
	: parent_( parent )
	, thread_id_( GetCurrentThreadId() )
{ }

void core_dispatcher_win32::process_events()
{
	MSG msg;
	while( GetMessageW( &msg, nullptr, 0, 0 ) )
	{
		TranslateMessage( &msg );
		DispatchMessageW( &msg );
	}
}

#include "graphics/drawing_context.hpp"
#include "ui/xaml/controls/border.hpp"
void paint_dev( frame* c )
{
	//xxaml::graphics::drawing_context d;
	//xobject_sptr<page> p = c->page_;
	//xobject_sptr<xxaml::ui::xaml::uielement> bb;
	//p->content( bb );
	//xobject_sptr<border> b = static_cast<border*>( bb.value() );

}

LRESULT core_dispatcher_win32::window_procedure( HWND hwnd, window_message message, WPARAM wparam, LPARAM lparam )
{
	switch( message )
	{
	case window_message::wmpaint:
		if( parent_ != nullptr )
		{
			//xobject_sptr<frame> content;
			//parent_->content( content );
			//paint_dev( content );
		}
		break;

	case window_message::destroy:
		PostQuitMessage( 0 );
	}
	return DefWindowProcW( hwnd, static_cast<UINT>( message ), wparam, lparam );
}

LRESULT CALLBACK core_dispatcher_win32::window_procedure_lancher( HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam )
{
	if( message == WM_CREATE )
	{
		LPCREATESTRUCT create_struct = reinterpret_cast<LPCREATESTRUCT>( lparam );
		xobject_sptr<core_dispatcher_win32> dispatcher = static_cast<core_dispatcher_win32*>( create_struct->lpCreateParams );
		if( dispatcher.value() == nullptr )
		{
			PostQuitMessage( 0 );
			return DefWindowProcW( hwnd, message, wparam, lparam );
		}

		SetWindowLongPtrW( hwnd, GWLP_USERDATA, reinterpret_cast<::std::size_t>( dispatcher.value() ) );
		return dispatcher->window_procedure( hwnd, static_cast<window_message>( message ), wparam, lparam );
	}

	core_dispatcher_win32* dispatcher = reinterpret_cast<core_dispatcher_win32*>( GetWindowLongPtrW( hwnd, GWLP_USERDATA ) );
	if( dispatcher == nullptr )
	{
		return DefWindowProcW( hwnd, message, wparam, lparam );
	}

	xobject_sptr<core_dispatcher_win32> sd = dispatcher;
	return sd->window_procedure( hwnd, static_cast<window_message>( message ), wparam, lparam );
}


type_name core_dispatcher_win32::type() const { return TYPE( xxaml__ui__core__core_dispatcher ); }

bool core_dispatcher_win32::has_thread_access() const
{
	return thread_id_ == GetCurrentThreadId();
}