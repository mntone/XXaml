#include "pch.hpp"
#include "basics.hpp"
#include "ui/xaml/property_metadata.hpp"

using namespace xxaml::foundation;
using namespace xxaml::ui::xaml;

property_metadata::property_metadata()
{ }

xobject* property_metadata::default_value() const { return default_value_; }
create_default_value_callback_type property_metadata::create_default_value_callback() const { return create_default_value_callback_; }

xresult property_metadata::create( xobject* default_value, property_metadata** result )
{
	NULL_CHECK( result );
	NEW_AND_CHECK( ret, property_metadata );
	ret->default_value_ = default_value;
	*result = ret;
	return xresult::ok;
}

xresult property_metadata::create( xobject* default_value, property_changed_callback_type property_changed_callback, property_metadata** result )
{
	NULL_CHECK2( property_changed_callback, result );
	NEW_AND_CHECK( ret, property_metadata );
	ret->default_value_ = default_value;
	ret->property_changed_callback_ = property_changed_callback;
	*result = ret;
	return xresult::ok;
}

xresult property_metadata::create( create_default_value_callback_type create_default_value_callback, property_metadata** result )
{
	NULL_CHECK2( create_default_value_callback, result );
	NEW_AND_CHECK( ret, property_metadata );
	ret->create_default_value_callback_ = create_default_value_callback;
	*result = ret;
	return xresult::ok;
}

xresult property_metadata::create( create_default_value_callback_type create_default_value_callback, property_changed_callback_type property_changed_callback, property_metadata** result )
{
	NULL_CHECK3( create_default_value_callback, property_changed_callback, result );
	NEW_AND_CHECK( ret, property_metadata );
	ret->create_default_value_callback_ = create_default_value_callback;
	ret->property_changed_callback_ = property_changed_callback;
	*result = ret;
	return xresult::ok;
}


type_name property_metadata::type() const { return TYPE( xxaml__ui__xaml__property_metadata ); }