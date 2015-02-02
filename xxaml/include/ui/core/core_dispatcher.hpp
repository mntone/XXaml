#pragma once

namespace xxaml { namespace ui { namespace core {

	const wchar_t xxaml__ui__core__core_dispatcher[] = L"XXaml.UI.Core.CoreDispatcher";
	class core_dispatcher:
		public foundation::xobject
	{
	public:
		XXAML_IMPORT virtual void process_events() = 0;

	public:
		XXAML_IMPORT virtual bool has_thread_access() const = 0;
	};

} } }