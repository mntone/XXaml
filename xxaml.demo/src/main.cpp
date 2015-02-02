#include "pch.hpp"
#include <xxaml.hpp>
#include <graphics/drawing_context.hpp>
#include <ui/core/core_window.hpp>
#include <ui/xaml/controls/frame.hpp>
#include <ui/xaml/controls/page.hpp>
#include <ui/xaml/controls/border.hpp>

using namespace xxaml::foundation;
using namespace xxaml::ui::core;
using namespace xxaml::ui::xaml;
using namespace xxaml::ui::xaml::controls;

int APIENTRY wWinMain( _In_ HINSTANCE hinstance, _In_opt_  HINSTANCE /*hPrevInstance*/, _In_ LPWSTR /*cmd_line*/, _In_ int cmd_show )
{
	xresult xr = xresult::ok;

	core_window* wnd;
	xr = core_window::create( &wnd );

	xobject_sptr<core_window> w = wnd;
	xr = w->activate();

	xobject_sptr<border> b = new border();
	xr = b->set_border_thickness( thickness{ 2, 4, 6, 8 } );

	xobject_sptr<page> p = new page();
	xr = p->set_content( b );

	xobject_sptr<frame> f = new frame();
	xr = f->navigate_with_tree( p );
	xr = w->set_content( f );

	core_dispatcher* d = nullptr;
	xr = w->dispatcher( &d );

	xobject_sptr<core_dispatcher> sd = d;
	sd->process_events();

	return 0;
}