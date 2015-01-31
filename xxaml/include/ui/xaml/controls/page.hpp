#pragma once
#include "user_control.hpp"

namespace xxaml { namespace ui { namespace xaml { namespace controls {

	const wchar_t xxaml__ui__xaml__controls__page[] = L"XXaml.UI.Xaml.Controls.Page";
	class page
		: public user_control
	{
	public:
		XXAML_IMPORT page();

	public:
		XXAML_IMPORT virtual foundation::type_name type() override;
	};

} } } }