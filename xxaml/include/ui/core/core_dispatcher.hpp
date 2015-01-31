#pragma once

namespace xxaml { namespace ui { namespace core {

	class core_dispatcher:
		public foundation::xobject
	{
	public:
		XXAML_IMPORT virtual void process_events() = 0;

	public:
		XXAML_IMPORT virtual bool has_thread_access() const = 0;
	};

} } }