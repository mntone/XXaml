#pragma once
#include "ui/core/core_window.hpp"
#include "core_dispatcher.hpp"
#include "ui/xaml/controls/frame.hpp"

namespace xxaml { namespace ui { namespace core {

	class core_window_win32 final:
		public core_window
	{
	public:
		XXAML_IMPORT core_window_win32();
		XXAML_IMPORT ~core_window_win32();

		XXAML_IMPORT virtual foundation::xresult activate() override;
		XXAML_IMPORT virtual foundation::xresult close() override;

	private:
		foundation::xresult initialize();
		foundation::xresult adjust_rect( RECT& rect ) const;
		foundation::xresult get_rect( RECT& rect ) const;

	public:
		XXAML_IMPORT virtual foundation::xresult dispatcher( core_dispatcher** result ) const override;

		XXAML_IMPORT virtual foundation::xresult content( xaml::controls::frame** result ) const override;
		XXAML_IMPORT virtual foundation::xresult set_content( xaml::controls::frame* value ) override;

		XXAML_IMPORT virtual foundation::xresult title( foundation::xstring** result ) const override;
		XXAML_IMPORT virtual foundation::xresult window_state( core::window_state* result ) const override;
		XXAML_IMPORT virtual foundation::xresult left( int* result ) const override;
		XXAML_IMPORT virtual foundation::xresult top( int* result ) const override;
		XXAML_IMPORT virtual foundation::xresult width( int* result ) const override;
		XXAML_IMPORT virtual foundation::xresult height( int* result ) const override;
		XXAML_IMPORT virtual foundation::xresult position( ui::point* result ) const override;
		XXAML_IMPORT virtual foundation::xresult size( ui::size* result ) const override;
		XXAML_IMPORT virtual foundation::xresult position_and_size( ui::rect* result ) const override;
		XXAML_IMPORT virtual foundation::xresult min_width( int* result ) const override;
		XXAML_IMPORT virtual foundation::xresult max_width( int* result ) const override;
		XXAML_IMPORT virtual foundation::xresult min_height( int* result ) const override;
		XXAML_IMPORT virtual foundation::xresult max_height( int* result ) const override;
		XXAML_IMPORT virtual foundation::xresult min( ui::size* result ) const override;
		XXAML_IMPORT virtual foundation::xresult max( ui::size* result ) const override;

		XXAML_IMPORT virtual foundation::xresult set_title( foundation::xstring* value ) override;
		XXAML_IMPORT virtual foundation::xresult set_window_state( core::window_state value ) override;
		XXAML_IMPORT virtual foundation::xresult set_left( int value ) override;
		XXAML_IMPORT virtual foundation::xresult set_top( int value ) override;
		XXAML_IMPORT virtual foundation::xresult set_width( int value ) override;
		XXAML_IMPORT virtual foundation::xresult set_height( int value ) override;
		XXAML_IMPORT virtual foundation::xresult set_position( ui::point value ) override;
		XXAML_IMPORT virtual foundation::xresult set_size( ui::size value ) override;
		XXAML_IMPORT virtual foundation::xresult set_position_and_size( ui::rect value ) override;
		XXAML_IMPORT virtual foundation::xresult set_min_width( int value ) override;
		XXAML_IMPORT virtual foundation::xresult set_max_width( int value ) override;
		XXAML_IMPORT virtual foundation::xresult set_min_height( int value ) override;
		XXAML_IMPORT virtual foundation::xresult set_max_height( int value ) override;
		XXAML_IMPORT virtual foundation::xresult set_min( ui::size value ) override;
		XXAML_IMPORT virtual foundation::xresult set_max( ui::size value ) override;

	private:
		bool initialized_;
		foundation::xobject_sptr<core_dispatcher_win32> dispatcher_;
		ATOM window_class_atom_;
		HINSTANCE hinstance_;
		HWND hwnd_;

		// TODO: for drawing system
		HDC hdc_;
		HGLRC hglrc_;

		foundation::xobject_sptr<xaml::controls::frame> content_;
	};

} } }