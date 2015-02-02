#pragma once
#include "foundation/xobject.hpp"
#include "dependency_property.hpp"
#include "ui/core/core_dispatcher.hpp"

namespace xxaml { namespace ui { namespace xaml {

	const wchar_t xxaml__ui__xaml__dependency_object[] = L"XXaml.UI.Xaml.DependencyObject";
	class dependency_object
		: public foundation::xobject
	{
	public:
		XXAML_IMPORT foundation::xresult clear_value( dependency_property const* dp );
		XXAML_IMPORT foundation::xresult get_value( dependency_property const* dp, foundation::xobject** result ) const;
		XXAML_IMPORT foundation::xresult set_value( dependency_property const* dp, foundation::xobject* value );

	protected:
		XXAML_IMPORT dependency_object();

	public:
		XXAML_IMPORT virtual foundation::type_name type() const override;
		XXAML_IMPORT core::core_dispatcher const* dispatcher() const;

	private:
		core::core_dispatcher const* dispatcher_;
		::std::unordered_map<from_name, foundation::xobject_sptr<foundation::xobject>> property_map_;
	};

} } }