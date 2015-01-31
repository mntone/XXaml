#pragma once
#include "control.hpp"

namespace xxaml { namespace ui { namespace xaml { namespace controls {

	const wchar_t xxaml__ui__xaml__controls__content_control[] = L"XXaml.UI.Xaml.Controls.ContentControl";
	class content_control
		: public control
	{
	protected:
		XXAML_IMPORT content_control();

	public:
		XXAML_IMPORT virtual foundation::type_name type() override;
	};

} } } }