#pragma once
#include "ui/core/core_dispatcher.hpp"
#include "window_message.hpp"

namespace xxaml { namespace ui { namespace core {

	class core_dispatcher_win32 final
		: public core_dispatcher
	{
		friend class core_window_win32;

	public:
		core_dispatcher_win32( core_window_win32* parent );

		XXAML_IMPORT virtual void process_events();

	private:
		LRESULT window_procedure( HWND hwnd, window_message message, WPARAM wparam, LPARAM lparam );
		static LRESULT CALLBACK window_procedure_lancher( HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam );

	public:
		XXAML_IMPORT virtual foundation::type_name type() const override final;
		XXAML_IMPORT virtual bool has_thread_access() const;

	private:
		core_window_win32* parent_; // TODO: weak smart pointer
		DWORD thread_id_;
	};

} } }