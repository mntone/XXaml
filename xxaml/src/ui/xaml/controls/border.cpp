#include "pch.hpp"
#include "basics.hpp"
#include "ui/xaml/controls/border.hpp"

using namespace xxaml::foundation;
using namespace xxaml::ui::xaml;
using namespace xxaml::ui::xaml::controls;

bool border::initialized_ = false;
xobject_sptr<dependency_property> border::border_thickness_property_;

xresult border::initialize_property()
{
	xresult xr = xresult::ok;
	auto thickness_zero_box = new xbox( thickness{ 0, 0, 0, 0 } );

	property_metadata* metadata = nullptr;
	xr = property_metadata::create( thickness_zero_box, &metadata );
	if( xr != xresult::ok )
	{
		return xr;
	}

	dependency_property* border_thickness_property = nullptr;
	xr = dependency_property::register_property(
		TEXT( L"BorderThickness" ),
		TYPE( xxaml__ui__xaml__thickness ),
		TYPE( xxaml__ui__xaml__framework_element ),
		metadata,
		&border_thickness_property );

	border_thickness_property_ = border_thickness_property;
	return xr;
}


border::border()
	: framework_element()
{
	if( !initialized_ )
	{
		initialize_property();
		initialized_ = true;
	}
}


type_name border::type() const { return TYPE( xxaml__ui__xaml__controls__border ); }

xresult border::border_thickness( thickness* result ) const
{
	GET_BOXED_VALUE( border_thickness_property_, thickness, result );
}
xresult border::set_border_thickness( thickness value )
{
	SET_BOXED_VALUE( border_thickness_property_, value );
}
dependency_property* border::border_thickness_property()
{
	return border_thickness_property_;
}