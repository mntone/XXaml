#pragma once
#include "ui/xaml/framework_element.hpp"

namespace xxaml { namespace ui { namespace xaml { namespace controls {

	const wchar_t xxaml__ui__xaml__controls__control[] = L"XXaml.UI.Xaml.Controls.Control";
	class control
		: public framework_element
	{
	protected:
		XXAML_IMPORT control();

	public:
		XXAML_IMPORT virtual foundation::type_name type() override;
	};

} } } }