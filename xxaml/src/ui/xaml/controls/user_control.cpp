#include "pch.hpp"
#include "basics.hpp"
#include "ui/xaml/controls/user_control.hpp"

using namespace xxaml::foundation;
using namespace xxaml::ui;
using namespace xxaml::ui::xaml;
using namespace xxaml::ui::xaml::controls;

bool user_control::initialized_ = false;
xobject_sptr<dependency_property> user_control::content_property_;

xresult user_control::initialize_property()
{
	xresult xr = xresult::ok;

	xobject_sptr<property_metadata> metadata;
	xr = property_metadata::create( reinterpret_cast<xobject*>( nullptr ), metadata );
	if( xr != xresult::ok )
	{
		return xr;
	}

	xobject_sptr<dependency_property> content_property;
	xr = dependency_property::register_property(
		TEXT( L"Content" ),
		TYPE( xxaml__ui__xaml__uielement ),
		TYPE( xxaml__ui__xaml__controls__user_control ),
		metadata,
		content_property );

	content_property_ = content_property;
	return xr;
}


user_control::user_control()
	: control()
{
	if( !initialized_ )
	{
		initialize_property();
		initialized_ = true;
	}
}

type_name user_control::type() { return TYPE( xxaml__ui__xaml__controls__user_control ); }


xresult user_control::content( uielement** result ) const
{
	GET_CASTED_VALUE( content_property_, uielement, result );
}
xresult user_control::set_content( uielement* value )
{
	return set_value( content_property_, value );
}
dependency_property* user_control::content_property() const
{
	return content_property_;
}