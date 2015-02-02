#include "pch.hpp"
#include "basics.hpp"
#include "ui/xaml/controls/frame.hpp"

using namespace xxaml::foundation;
using namespace xxaml::ui;
using namespace xxaml::ui::xaml::controls;

frame::frame()
	: content_control()
{ }

xresult frame::navigate_with_tree( page* root_object )
{
	page_ = root_object;
	return xresult::ok;
}


type_name frame::type() const { return TYPE( xxaml__ui__xaml__controls__frame ); }