#pragma once
#include "content_control.hpp"
#include "page.hpp"

namespace xxaml { namespace ui { namespace xaml { namespace controls {

	const wchar_t xxaml__ui__xaml__controls__frame[] = L"XXaml.UI.Xaml.Controls.Frame";
	class frame
		: public content_control
	{
	public:
		XXAML_IMPORT frame();
		
		// for debug
		XXAML_IMPORT foundation::xresult navigate_with_tree( page* root_object );

	public:
		XXAML_IMPORT virtual foundation::type_name type() const override;

	public:
		foundation::xobject_sptr<page> page_;
	};

} } } }