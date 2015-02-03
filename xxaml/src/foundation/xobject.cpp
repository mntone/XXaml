#include "pch.hpp"
#include "basics.hpp"
#include "foundation/xobject.hpp"

using namespace std;
using namespace xxaml::foundation;

xobject::xobject()
{
	reference_count_.store( 0 );
}

xobject::~xobject()
{ }

int xobject::add()
{
#ifdef _DEBUG
	wchar_t buf[64];
	swprintf_s( buf, L"[ADD] type: %s (%d++)\n", type().name, reference_count_.load() );
	OutputDebugStringW( buf );
#endif

	return reference_count_.fetch_add( 1 ) + 1;
}

int xobject::release()
{
#ifdef _DEBUG
	auto v = reference_count_.load();
	if( v == 0 )
	{
		assert( v );
	}

	wchar_t buf[64];
	swprintf_s( buf, L"[REL] type: %s (%d--)\n", type().name, v );
	OutputDebugStringW( buf );
#endif

	size_t const val = reference_count_.fetch_sub( 1 ) - 1;
	if( val == 0 )
	{
		delete this;
		return 0;
	}
	return val;
}


type_name xobject::type() const { return TYPE( xxaml__foundation__xobject ); }