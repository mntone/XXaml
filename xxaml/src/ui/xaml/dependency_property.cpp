#include "pch.hpp"
#include "basics.hpp"
#include "ui/xaml/dependency_property.hpp"

using namespace std;
using namespace xxaml::foundation;
using namespace xxaml::ui::xaml;

from_name::from_name( dependency_property const* dp )
	: from_name( dp->name(), dp->owner_type() )
{ }

from_name::from_name( xstring* name, type_name type )
	: name( name )
	, type( type )
{
	auto hasher = ::std::hash<xstring>();
	hash = hasher( name->value() ) ^ hasher( type.name );
}

::std::mutex dependency_property::mutex_;
::std::unordered_map<from_name, xobject_sptr<dependency_property>> property_from_name_;

dependency_property::dependency_property()
{ }

property_metadata const* dependency_property::get_metadata() const { return default_metadata_; }

xresult dependency_property::register_property(
	xstring* name,
	type_name property_type,
	type_name owner_type,
	property_metadata* default_metadata,
	dependency_property** result )
{
	return register_common( name, property_type, owner_type, default_metadata, result );
}

xresult dependency_property::register_attached_property(
	xstring* name,
	type_name property_type,
	type_name owner_type,
	property_metadata* default_metadata,
	dependency_property** result )
{
	return register_common( name, property_type, owner_type, default_metadata, result );
}

xresult dependency_property::register_common(
	xstring* name,
	type_name property_type,
	type_name owner_type,
	property_metadata* default_metadata,
	dependency_property** result )
{
	NULL_CHECK( result );

	auto key = from_name( name, owner_type );
	{
		lock_guard<decltype( mutex_ )> locker( mutex_ );
		if( property_from_name_.find( key ) != property_from_name_.cend() )
		{
			return xresult::argument;
		}
	}

	xobject_sptr<property_metadata> metadata;
	if( default_metadata == nullptr )
	{
		// TODO: Activator が必要。Activator から default_value を生成し、property_metadata を生成。現在は not_implemented で例外
		return xresult::not_implemented;
	}
	else
	{
		metadata = default_metadata;
	}

	NEW_AND_CHECK( ret, dependency_property );
	ret->name_ = name;
	ret->property_type_ = property_type;
	ret->owner_type_ = owner_type;
	ret->default_metadata_ = metadata;
	{
		lock_guard<decltype( mutex_ )> locker( mutex_ );
		property_from_name_.emplace( key, ret );
	}

	*result = ret;
	return xresult::ok;
}


type_name dependency_property::type() const { return TYPE( xxaml__ui__xaml__dependency_property ); }
xstring* dependency_property::name() const { return name_; }
type_name dependency_property::property_type() const { return property_type_; }
type_name dependency_property::owner_type() const { return owner_type_; }