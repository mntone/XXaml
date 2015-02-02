#pragma once
#include "property_metadata.hpp"

#ifdef INTERNAL
#include "foundation/xstring.hpp"
#include "foundation/type_name.hpp"
#endif

namespace xxaml { namespace ui { namespace xaml {

	class dependency_property;

	struct from_name final
	{
		foundation::xstring name;
		foundation::type_name type;
		::std::size_t hash;

		from_name( dependency_property const* dp );
		from_name( foundation::xstring name, foundation::type_name type );

		bool operator==( from_name const& other ) const
		{
			return hash == other.hash;
		}
	};
	
} } }

namespace std {
	template<>
	struct hash<::xxaml::ui::xaml::from_name>
		: public unary_function<::xxaml::ui::xaml::from_name, size_t>
	{
		size_t operator()( ::xxaml::ui::xaml::from_name const& value ) const
		{
			return value.hash;
		}
	};
}
	
namespace xxaml { namespace ui { namespace xaml {

	const wchar_t xxaml__ui__xaml__dependency_property[] = L"XXaml.UI.Xaml.DependencyProperty";
	class dependency_property final
		: public foundation::xobject
	{
	public:
		XXAML_IMPORT property_metadata const* get_metadata() const;

	public:
		XXAML_IMPORT static foundation::xresult register_property(
			foundation::xstring name,
			foundation::type_name property_type,
			foundation::type_name owner_type,
			property_metadata* default_metadata,
			dependency_property** result );

		XXAML_IMPORT static foundation::xresult register_attached_property(
			foundation::xstring name,
			foundation::type_name property_type,
			foundation::type_name owner_type,
			property_metadata* default_metadata,
			dependency_property** result );

	public:
		XXAML_IMPORT virtual foundation::type_name type() const override final;
		XXAML_IMPORT foundation::xstring name() const;
		XXAML_IMPORT foundation::type_name property_type() const;
		XXAML_IMPORT foundation::type_name owner_type() const;

	private:
		dependency_property();

	private:
		static foundation::xresult register_common(
			foundation::xstring name,
			foundation::type_name property_type,
			foundation::type_name owner_type,
			property_metadata* default_metadata,
			dependency_property** result );

	private:
		foundation::xstring name_;
		foundation::type_name property_type_;
		foundation::type_name owner_type_;
		foundation::xobject_sptr<property_metadata> default_metadata_;

		static ::std::mutex mutex_;
	};

} } }