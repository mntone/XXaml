#include "pch.hpp"
#include "basics.hpp"
#include "ui/xaml/framework_element.hpp"

using namespace xxaml::foundation;
using namespace xxaml::ui;
using namespace xxaml::ui::xaml;

bool framework_element::initialized_ = false;
xobject_sptr<dependency_property> framework_element::margin_property_;

xresult framework_element::initialize_property()
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
		TEXT( L"Margin" ),
		TYPE( xxaml__ui__xaml__thickness ),
		TYPE( xxaml__ui__xaml__framework_element ),
		metadata,
		margin_property_ );
	return xr;
}


framework_element::framework_element()
	: uielement()
	, parent_( nullptr )
{
	if( !initialized_ )
	{
		initialize_property();
		initialized_ = true;
	}
}

size framework_element::measure_override( size available_size ) const
{
	return size{ 0.f, 0.f };
}

size framework_element::arrange_override( size final_size ) const
{
	return size{ 0.f, 0.f };
}


type_name framework_element::type() { return TYPE( xxaml__ui__xaml__framework_element ); }

xresult framework_element::parent( xobject** result ) const
{
	*result = parent_ != nullptr ? parent_ : nullptr;
	return xresult::ok;
}

xresult framework_element::margin( thickness* result ) const
{
	GET_BOXED_VALUE( margin_property_, thickness, result );
}
xresult framework_element::set_margin( thickness value )
{
	SET_BOXED_VALUE( margin_property_, value );
}
dependency_property* framework_element::margin_property()
{
	return margin_property_;
}