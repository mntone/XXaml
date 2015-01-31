#include "pch.hpp"
#include "basics.hpp"
#include "ui/xaml/controls/page.hpp"

using namespace xxaml::foundation;
using namespace xxaml::ui;
using namespace xxaml::ui::xaml::controls;

page::page()
	: user_control()
{ }

type_name page::type() { return TYPE( xxaml__ui__xaml__controls__page ); }