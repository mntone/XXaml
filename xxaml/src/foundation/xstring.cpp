#include "pch.hpp"
#include "basics.hpp"
#include "foundation/xstring.hpp"

using namespace std;
using namespace xxaml::foundation;

xstring::xstring()
	: value_( nullptr )
	, length_( 0 )
{ }

xstring::xstring( wchar_t const* value )
{
	assign( value, wcslen( value ) );
}

xstring::xstring( wchar_t const* value, int length )
{
	assign( value, length );
}

void xstring::assign( wchar_t const* value, int length )
{
	wchar_t* out = new wchar_t[length + 1];

	auto ip = value;
	auto ipe = value + length;
	auto op = out;
	while( ip != ipe )
	{
		*op = *ip;
		++op;
		++ip;
	}
	*op = L'\0';

	value_ = out;
	length_ = length;
}

void xstring::reset()
{
	if( value_ != nullptr )
	{
		delete value_;
		value_ = nullptr;
	}
}

xstring::~xstring()
{
	if( value_ != nullptr )
	{
		delete value_;
		value_ = nullptr;
	}
}


type_name xstring::type() const { return TYPE( xxaml__foundation__xstring ); }

wchar_t const* xstring::value() const
{
	return value_;
}

int xstring::length() const
{
	return length_;
}