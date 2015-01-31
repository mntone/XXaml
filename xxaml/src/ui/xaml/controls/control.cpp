#include "pch.hpp"
#include "basics.hpp"
#include "ui/xaml/controls/control.hpp"

using namespace xxaml::foundation;
using namespace xxaml::ui;
using namespace xxaml::ui::xaml::controls;

control::control()
	: framework_element()
{ }

type_name control::type() { return TYPE( xxaml__ui__xaml__controls__control ); }