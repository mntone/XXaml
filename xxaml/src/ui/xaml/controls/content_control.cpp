#include "pch.hpp"
#include "basics.hpp"
#include "ui/xaml/controls/content_control.hpp"

using namespace xxaml::foundation;
using namespace xxaml::ui;
using namespace xxaml::ui::xaml::controls;

content_control::content_control()
	: control()
{ }

type_name content_control::type() { return TYPE( xxaml__ui__xaml__controls__content_control ); }