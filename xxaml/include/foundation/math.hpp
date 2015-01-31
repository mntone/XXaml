#pragma once
#include <cmath>

namespace xxaml { namespace foundation {

	class math
	{
	public:
		template<typename T>
		static bool is_nan( T value )
		{
			return ::std::isnan<T>( value );
		}
	};

} }