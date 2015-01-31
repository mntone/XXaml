#pragma once
#include "control.hpp"

namespace xxaml { namespace ui { namespace xaml { namespace controls {

	const wchar_t xxaml__ui__xaml__controls__user_control[] = L"XXaml.UI.Xaml.Controls.UserControl";
	class user_control
		: public control
	{
	protected:
		XXAML_IMPORT user_control();

	private:
		static foundation::xresult initialize_property();

	public:
		XXAML_IMPORT virtual foundation::type_name type() override;

		XXAML_IMPORT foundation::xresult content( uielement** result ) const;
		XXAML_IMPORT foundation::xresult set_content( uielement* value );
		XXAML_IMPORT dependency_property* content_property() const;

	private:
		static bool initialized_;
		static foundation::xobject_sptr<dependency_property> content_property_;
	};

} } } }