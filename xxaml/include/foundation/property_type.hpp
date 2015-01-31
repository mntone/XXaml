#pragma once

namespace xxaml { namespace foundation {

#define _ARRAY_OFFSET 128

	enum class property_type: unsigned char
	{
		empty = 0,
		boolean = 1,
		char16 = 3,
		string = 5,
		xobject = 6,

		int16 = 11,
		int32 = 12,
		int64 = 13,

		uint8 = 21,

		float32 = 31,
		float64 = 32,

		color = 40,
		point = 41,
		size = 42,
		rect = 43,

		thickness = 100,
		corner_radius,

		other_type = 127,


		boolean_array = _ARRAY_OFFSET + boolean,
		char16_array = _ARRAY_OFFSET + char16,
		string_array = _ARRAY_OFFSET + string,
		xobject_array = _ARRAY_OFFSET + xobject,

		int16_array = _ARRAY_OFFSET + int16,
		int32_array = _ARRAY_OFFSET + int32,
		int64_array = _ARRAY_OFFSET + int64,

		uint8_array = _ARRAY_OFFSET + uint8,

		float32_array = _ARRAY_OFFSET + float32,
		float64_array = _ARRAY_OFFSET + float64,

		color_array = _ARRAY_OFFSET + color,
		point_array = _ARRAY_OFFSET + point,
		size_array = _ARRAY_OFFSET + size,
		rect_array = _ARRAY_OFFSET + rect,

		thickness_array = _ARRAY_OFFSET + thickness,
		corner_radius_array = _ARRAY_OFFSET + corner_radius,

		other_type_array = _ARRAY_OFFSET + other_type,
	};

#undef _ARRAY_OFFSET

} }