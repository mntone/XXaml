#pragma once
#include "window_state.hpp"
#include "core_dispatcher.hpp"

namespace xxaml { namespace ui {

	namespace xaml { namespace controls { class frame; } }

namespace core {

	class core_window:
		public foundation::xobject
	{
	public:
		XXAML_IMPORT virtual foundation::xresult activate() = 0;
		XXAML_IMPORT virtual foundation::xresult close() = 0;

		XXAML_IMPORT static foundation::xresult create( core_window** result );

	public:
		XXAML_IMPORT virtual foundation::xresult dispatcher( core_dispatcher** result ) const = 0;

		XXAML_IMPORT virtual foundation::xresult content( xaml::controls::frame** result ) const = 0;
		XXAML_IMPORT virtual foundation::xresult set_content( xaml::controls::frame* value ) = 0;

		XXAML_IMPORT virtual foundation::xresult title( foundation::xstring* result ) const = 0;
		XXAML_IMPORT virtual foundation::xresult window_state( core::window_state* result ) const = 0;
		XXAML_IMPORT virtual foundation::xresult left( int* result ) const = 0;
		XXAML_IMPORT virtual foundation::xresult top( int* result ) const = 0;
		XXAML_IMPORT virtual foundation::xresult width( int* result ) const = 0;
		XXAML_IMPORT virtual foundation::xresult height( int* result ) const = 0;
		XXAML_IMPORT virtual foundation::xresult position( ui::point* result ) const = 0;
		XXAML_IMPORT virtual foundation::xresult size( ui::size* result ) const = 0;
		XXAML_IMPORT virtual foundation::xresult position_and_size( ui::rect* result ) const = 0;
		XXAML_IMPORT virtual foundation::xresult min_width( int* result ) const = 0;
		XXAML_IMPORT virtual foundation::xresult max_width( int* result ) const = 0;
		XXAML_IMPORT virtual foundation::xresult min_height( int* result ) const = 0;
		XXAML_IMPORT virtual foundation::xresult max_height( int* result ) const = 0;
		XXAML_IMPORT virtual foundation::xresult min( ui::size* result ) const = 0;
		XXAML_IMPORT virtual foundation::xresult max( ui::size* result ) const = 0;

		XXAML_IMPORT virtual foundation::xresult set_title( foundation::xstring value ) = 0;
		XXAML_IMPORT virtual foundation::xresult set_window_state( core::window_state value ) = 0;
		XXAML_IMPORT virtual foundation::xresult set_left( int value ) = 0;
		XXAML_IMPORT virtual foundation::xresult set_top( int value ) = 0;
		XXAML_IMPORT virtual foundation::xresult set_width( int value ) = 0;
		XXAML_IMPORT virtual foundation::xresult set_height( int value ) = 0;
		XXAML_IMPORT virtual foundation::xresult set_position( ui::point value ) = 0;
		XXAML_IMPORT virtual foundation::xresult set_size( ui::size value ) = 0;
		XXAML_IMPORT virtual foundation::xresult set_position_and_size( ui::rect value ) = 0;
		XXAML_IMPORT virtual foundation::xresult set_min_width( int value ) = 0;
		XXAML_IMPORT virtual foundation::xresult set_max_width( int value ) = 0;
		XXAML_IMPORT virtual foundation::xresult set_min_height( int value ) = 0;
		XXAML_IMPORT virtual foundation::xresult set_max_height( int value ) = 0;
		XXAML_IMPORT virtual foundation::xresult set_min( ui::size value ) = 0;
		XXAML_IMPORT virtual foundation::xresult set_max( ui::size value ) = 0;
	};

} } }