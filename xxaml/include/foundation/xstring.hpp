#pragma once
#include "xobject.hpp"

namespace xxaml { namespace foundation {

	const wchar_t xxaml__foundation__xstring[] = L"XXaml.Foundation.XString";
	class xstring final
		: public xobject
	{
	public:
		XXAML_IMPORT xstring();
		XXAML_IMPORT xstring( wchar_t const* value );
		XXAML_IMPORT xstring( wchar_t const* value, int length );
		XXAML_IMPORT virtual ~xstring();

	private:
		void assign( wchar_t const* value, int length );
		void reset();

	public:
		XXAML_IMPORT virtual type_name type() const override;
		XXAML_IMPORT wchar_t const* value() const;
		XXAML_IMPORT int length() const;

	private:
		wchar_t const* value_;
		int length_;
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
			return _Hash_seq( reinterpret_cast<const unsigned char*>( value.value() ), value.length() * sizeof( wchar_t ) );
		}
	};
}
#endif