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
	return reference_count_.fetch_add( 1 ) + 1;
}

int xobject::release()
{
	size_t const val = reference_count_.fetch_sub( 1 ) - 1;
	if( val == 0 )
	{
		delete this;
		return 0;
	}
	return val;
}

type_name xobject::type() { return TYPE( xxaml__foundation__xobject ); }