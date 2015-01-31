#pragma once

namespace xxaml { namespace foundation {

	enum class xresult: unsigned int
	{
		ok = 0,
		failed = 1,
		out_of_memory,
		not_implemented,

		argument = 0x00001000,
		argument_null_pointer,

		invalid_operation = 0x00002000,
	};

} }