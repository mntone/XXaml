#pragma once
#include "foundation/type_name.hpp"

namespace xxaml { namespace foundation {

	const wchar_t xxaml__foundation__xobject[] = L"XXaml.Foundation.XObject";
	class xobject
	{
	public:
		XXAML_IMPORT virtual ~xobject();

		XXAML_IMPORT int add();
		XXAML_IMPORT int release();

	protected:
		xobject();

	public:
		XXAML_IMPORT virtual foundation::type_name type() const;

	private:
		::std::atomic_int reference_count_;
	};

} }