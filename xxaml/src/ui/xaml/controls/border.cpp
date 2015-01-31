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

	xobject_sptr<property_metadata> metadata;
	xr = property_metadata::create( thickness_zero_box, metadata );
	if( xr != xresult::ok )
	{
		return xr;
	}

	xr = dependency_property::register_property(
		TEXT( L"BorderThickness" ),
		TYPE( xxaml__ui__xaml__thickness ),
		TYPE( xxaml__ui__xaml__framework_element ),
		metadata,
		border_thickness_property_ );
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