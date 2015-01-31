#pragma once

namespace xxaml { namespace ui { namespace core {

	enum class window_state
		: unsigned char
	{
		normal = 0,
		minimized,
		maximized,
		full_screen,
	};

} } }