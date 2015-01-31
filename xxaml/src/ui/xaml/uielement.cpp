#include "pch.hpp"
#include "basics.hpp"
#include "ui/xaml/uielement.hpp"
#include "foundation/math.hpp"

using namespace xxaml::foundation;
using namespace xxaml::ui;
using namespace xxaml::ui::xaml;

bool uielement::initialized_ = false;
xobject_sptr<dependency_property> uielement::visibility_property_;

xresult uielement::initialize_property()
{
	xresult xr = xresult::ok;
	auto visibility_visible_box = new xbox( static_cast<unsigned char>( visibility::visible ) );

	xobject_sptr<property_metadata> metadata;
	xr = property_metadata::create( visibility_visible_box, metadata );
	if( xr != xresult::ok )
	{
		return xr;
	}

	xr = dependency_property::register_property(
		TEXT( L"Visibility" ),
		TYPE( xxaml__ui__xaml__visibility ),
		TYPE( xxaml__ui__xaml__uielement ),
		metadata,
		visibility_property_ );
	return xr;
}


uielement::uielement()
	: dependency_object()
	, desired_size_()
{
	if( !initialized_ )
	{
		initialize_property();
		initialized_ = true;
	}
}

void uielement::invalidate_measure()
{

}

void uielement::invalidate_arrange()
{

}

xresult uielement::measure( size available_size )
{
	if( math::is_nan( available_size.width ) || math::is_nan( available_size.height ) )
	{
		return xresult::invalid_operation;
	}


	return xresult::ok;
}

xresult uielement::arrange( size final_size )
{
	return xresult::ok;
}

xresult uielement::desired_size( size* result ) const
{
	*result = desired_size_;
	return xresult::ok;
}

xresult uielement::set_desired_size( size desired_size )
{
	desired_size_ = desired_size;
	return xresult::ok;
}


type_name uielement::type() { return TYPE( xxaml__ui__xaml__uielement ); }

xresult uielement::visibility( ::visibility* result ) const
{
	xobject_sptr<xobject> obj;
	xresult xr = get_value( visibility_property_, obj );
	if( xr != xresult::ok )
	{
		return xr;
	}

	xobject_sptr<xbox> box = static_cast<xbox*>( obj.value() );
	::visibility v;
	xr = box->get_uint8( reinterpret_cast<unsigned char*>( &v ) );
	if( xr != xresult::ok )
	{
		return xr;
	}

	*result = v;
	return xresult::ok;
}
xresult uielement::set_visibility( ::visibility value )
{
	xobject* obj = new xbox( static_cast<unsigned char>( value ) );
	return set_value( visibility_property_, obj );
}
dependency_property* uielement::visibility_property()
{
	return visibility_property_;
}