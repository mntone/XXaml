#pragma once
#include "ui/basic_structures.hpp"

namespace xxaml { namespace graphics {

	class drawing_context final
	{
	public:
		XXAML_IMPORT drawing_context();

		XXAML_IMPORT foundation::xresult draw_line( ui::point const& point1, ui::point const& point2, ui::color const& color );
		XXAML_IMPORT foundation::xresult draw_line( ui::point const& point1, ui::point const& point2, ui::color const& color, float thickness );

		XXAML_IMPORT foundation::xresult draw_rectangle( ui::rect const& rect, ui::color const& color, ui::xaml::thickness const& thickness );
		XXAML_IMPORT foundation::xresult fill_rectangle( ui::rect const& rect, ui::color const& color );
	};

} }