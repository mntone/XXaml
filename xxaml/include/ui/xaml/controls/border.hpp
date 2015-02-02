#pragma once
#include "ui/xaml/framework_element.hpp"

namespace xxaml { namespace ui { namespace xaml { namespace controls {

	const wchar_t xxaml__ui__xaml__controls__border[] = L"XXaml.UI.Xaml.Controls.Border";
	class border final
		: public framework_element
	{
	public:
		XXAML_IMPORT border();

	private:
		static foundation::xresult initialize_property();

	public:
		XXAML_IMPORT virtual foundation::type_name type() const override;

		XXAML_IMPORT foundation::xresult border_thickness( thickness* result ) const;
		XXAML_IMPORT foundation::xresult set_border_thickness( thickness value );
		XXAML_IMPORT static dependency_property* border_thickness_property();

	private:
		static bool initialized_;
		static foundation::xobject_sptr<dependency_property> border_thickness_property_;
	};

} } } }