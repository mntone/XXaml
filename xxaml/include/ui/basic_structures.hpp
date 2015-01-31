#pragma once

namespace xxaml { namespace ui {

	const wchar_t xxaml__ui__color[] = L"XXaml.UI.Color";
	struct XXAML_IMPORT color
	{
		float red, green, blue, alpha;
	};

	const wchar_t xxaml__ui__point[] = L"XXaml.UI.Point";
	struct XXAML_IMPORT point
	{
		float x, y;
	};

	const wchar_t xxaml__ui__size[] = L"XXaml.UI.Size";
	struct XXAML_IMPORT size
	{
		float width, height;
	};

	const wchar_t xxaml__ui__rect[] = L"XXaml.UI.Rect";
	struct XXAML_IMPORT rect
	{
		float x, y, width, height;
	};

	namespace xaml {

		const wchar_t xxaml__ui__xaml__thickness[] = L"XXaml.UI.Xaml.Thickness";
		struct XXAML_IMPORT thickness
		{
			float left, top, right, bottom;
		};

		const wchar_t xxaml__ui__xaml__corner_radius[] = L"XXaml.UI.Xaml.CornerRadius";
		struct XXAML_IMPORT corner_radius
		{
			float top_left, top_right, bottom_right, bottom_left;
		};

	}

} }