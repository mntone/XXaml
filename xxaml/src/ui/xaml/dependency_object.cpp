#include "pch.hpp"
#include "basics.hpp"
#include "ui/xaml/dependency_object.hpp"

using namespace xxaml::foundation;
using namespace xxaml::ui::core;
using namespace xxaml::ui::xaml;

dependency_object::dependency_object()
{ }

xresult dependency_object::clear_value( dependency_property const* dp )
{
	auto key = from_name( dp );
	auto itr = property_map_.find( key );
	if( itr != property_map_.cend() )
	{
		property_map_.erase( itr );
	}
	return xresult::ok;
}

xresult dependency_object::get_value( dependency_property const* dp, xobject** result ) const
{
	auto key = from_name( dp );
	auto itr = property_map_.find( key );
	if( itr != property_map_.cend() && itr->second.value() != nullptr )
	{
		*result = itr->second;
		return xresult::ok;
	}

	*result = dp->get_metadata()->default_value();
	return xresult::ok;
}

xresult dependency_object::set_value( dependency_property const* dp, xobject* value )
{
	auto key = from_name( dp );
	auto itr = property_map_.find( key );
	if( itr != property_map_.cend() && itr->second.value() != nullptr )
	{
		itr->second = value;
		return xresult::ok;
	}
	property_map_.emplace( key, value );
	return xresult::ok;
}

type_name dependency_object::type() { return TYPE( xxaml__ui__xaml__dependency_object ); }
core_dispatcher const* dependency_object::dispatcher() const { return dispatcher_; }