#pragma once

namespace xxaml { namespace foundation {

	struct XXAML_IMPORT xstring
	{
		wchar_t const* value;
		int length;
	};

} }

#ifdef CPP_METHODS
namespace std {
	template<>
	struct hash<::xxaml::foundation::xstring>
		: public unary_function<::xxaml::foundation::xstring, size_t>
	{
		size_t operator()( ::xxaml::foundation::xstring const& value ) const
		{
			return _Hash_seq( reinterpret_cast<const unsigned char*>( value.value ), value.length * sizeof( wchar_t ) );
		}
	};
}
#endif