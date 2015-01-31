#pragma once
#include "uielement.hpp"

namespace xxaml { namespace ui { namespace xaml {

	const wchar_t xxaml__ui__xaml__framework_element[] = L"XXaml.UI.Xaml.FrameworkElement";
	class framework_element
		: public uielement
	{
	protected:
		XXAML_IMPORT framework_element();

	public:
		XXAML_IMPORT virtual ::xxaml::ui::size measure_override( ::xxaml::ui::size available_size ) const;
		XXAML_IMPORT virtual ::xxaml::ui::size arrange_override( ::xxaml::ui::size final_size ) const;

	private:
		static foundation::xresult initialize_property();

	public:
		XXAML_IMPORT virtual foundation::type_name type() override;

		XXAML_IMPORT foundation::xresult parent( foundation::xobject** result ) const;

		XXAML_IMPORT foundation::xresult margin( thickness* result ) const;
		XXAML_IMPORT foundation::xresult set_margin( thickness value );
		XXAML_IMPORT static dependency_property* margin_property();

	private:
		foundation::xobject_sptr<dependency_object> parent_;

		static bool initialized_;
		static foundation::xobject_sptr<dependency_property> margin_property_;
	};

} } }