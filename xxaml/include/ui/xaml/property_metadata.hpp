#pragma once
#include "foundation/xobject.hpp"

namespace xxaml { namespace ui { namespace xaml {

	class dependency_object;

	using property_changed_callback_type = void( * )( dependency_object const* );
	using create_default_value_callback_type = void*( * )();

	const wchar_t xxaml__ui__xaml__property_metadata[] = L"XXaml.UI.Xaml.PropertyMetadata";
	class property_metadata final
		: public foundation::xobject
	{
	public:
		XXAML_IMPORT foundation::xobject* default_value() const;
		XXAML_IMPORT create_default_value_callback_type create_default_value_callback() const;

	private:
		property_metadata();

	public:
		XXAML_IMPORT static foundation::xresult create( foundation::xobject* default_value, property_metadata** result );
		XXAML_IMPORT static foundation::xresult create( foundation::xobject* default_value, property_changed_callback_type property_changed_callback, property_metadata** result );
		XXAML_IMPORT static foundation::xresult create( create_default_value_callback_type create_default_value_callback, property_metadata** result );
		XXAML_IMPORT static foundation::xresult create( create_default_value_callback_type create_default_value_callback, property_changed_callback_type property_changed_callback, property_metadata** result );

	public:
		XXAML_IMPORT virtual foundation::type_name type() override;

	private:
		foundation::xobject_sptr<foundation::xobject> default_value_;
		create_default_value_callback_type create_default_value_callback_;
		property_changed_callback_type property_changed_callback_;
	};

} } }