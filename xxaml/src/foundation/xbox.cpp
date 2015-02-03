#include "pch.hpp"
#include "exports.hpp"
#include "macros.hpp"
#include "foundation/xbox.hpp"

using namespace xxaml;
using namespace xxaml::foundation;

xbox::xbox()
	: type_( property_type::empty )
{ }

xbox::xbox( ::std::nullptr_t )
	: type_( property_type::empty )
{ }

xbox::xbox( bool value )
	: type_( property_type::boolean )
	, boolean_( value )
{ }

xbox::xbox( wchar_t value )
	: type_( property_type::boolean )
	, char16_( value )
{ }

xbox::xbox( xstring* value )
	: type_( property_type::string )
	, xstring_( value )
{ }

xbox::xbox( xobject* value )
	: type_( property_type::xobject )
	, xobject_( value )
{ }

xbox::xbox( short value )
	: type_( property_type::int16 )
	, int16_( value )
{ }

xbox::xbox( int value )
	: type_( property_type::int32 )
	, int32_( value )
{ }

xbox::xbox( long long value )
	: type_( property_type::int64 )
	, int64_( value )
{ }

xbox::xbox( unsigned char value )
	: type_( property_type::uint8 )
	, uint8_( value )
{ }

xbox::xbox( float value )
	: type_( property_type::float32 )
	, float32_( value )
{ }

xbox::xbox( double value )
	: type_( property_type::float64 )
	, float64_( value )
{ }

xbox::xbox( ui::color value )
	: type_( property_type::color )
	, color_( value )
{ }

xbox::xbox( ui::point value )
	: type_( property_type::point )
	, point_( value )
{ }

xbox::xbox( ui::size value )
	: type_( property_type::size )
	, size_( value )
{ }

xbox::xbox( ui::rect value )
	: type_( property_type::rect )
	, rect_( value )
{ }

xbox::xbox( ui::xaml::thickness value )
	: type_( property_type::thickness )
	, thickness_( value )
{ }

xbox::xbox( ui::xaml::corner_radius value )
	: type_( property_type::corner_radius )
	, corner_radius_( value )
{ }

xbox::xbox( void* value )
	: type_( property_type::other_type )
	, other_type_( value )
{ }


xbox::xbox( bool* value, int length )
	: type_( property_type::boolean_array )
	, boolean_array_( value )
	, length_( length )
{ }

xbox::xbox( wchar_t* value, int length )
	: type_( property_type::char16_array )
	, char16_array_( value )
	, length_( length )
{ }

xbox::xbox( xstring** value, int length )
	: type_( property_type::string_array )
	, xstring_array_( value )
	, length_( length )
{ }

xbox::xbox( xobject** value, int length )
	: type_( property_type::xobject_array )
	, xobject_array_( value )
	, length_( length )
{ }

xbox::xbox( short* value, int length )
	: type_( property_type::int16_array )
	, int16_array_( value )
	, length_( length )
{ }

xbox::xbox( int* value, int length )
	: type_( property_type::int32_array )
	, int32_array_( value )
	, length_( length )
{ }

xbox::xbox( long long* value, int length )
	: type_( property_type::int64_array )
	, int64_array_( value )
	, length_( length )
{ }

xbox::xbox( unsigned char* value, int length )
	: type_( property_type::uint8_array )
	, uint8_array_( value )
	, length_( length )
{ }

xbox::xbox( float* value, int length )
	: type_( property_type::float32_array )
	, float32_array_( value )
	, length_( length )
{ }

xbox::xbox( double* value, int length )
	: type_( property_type::float64_array )
	, float64_array_( value )
	, length_( length )
{ }

xbox::xbox( ui::color* value, int length )
	: type_( property_type::color_array )
	, color_array_( value )
	, length_( length )
{ }

xbox::xbox( ui::point* value, int length )
	: type_( property_type::point_array )
	, point_array_( value )
	, length_( length )
{ }

xbox::xbox( ui::size* value, int length )
	: type_( property_type::size_array )
	, size_array_( value )
	, length_( length )
{ }

xbox::xbox( ui::rect* value, int length )
	: type_( property_type::rect_array )
	, rect_array_( value )
	, length_( length )
{ }

xbox::xbox( ui::xaml::thickness* value, int length )
	: type_( property_type::thickness_array )
	, thickness_array_( value )
	, length_( length )
{ }

xbox::xbox( ui::xaml::corner_radius* value, int length )
	: type_( property_type::corner_radius_array )
	, corner_radius_array_( value )
	, length_( length )
{ }

xbox::xbox( void** value, int length )
	: type_( property_type::other_type_array )
	, other_type_array_( value )
	, length_( length )
{ }


xresult xbox::get_boolean( bool* result ) const
{
	if( type_ == property_type::boolean )
	{
		*result = boolean_;
		return xresult::ok;
	}
	return xresult::invalid_operation;
}

xresult xbox::get_char16( wchar_t* result ) const
{
	if( type_ == property_type::char16 )
	{
		*result = char16_;
		return xresult::ok;
	}
	return xresult::invalid_operation;
}

xresult xbox::get_xstring( xstring** result ) const
{
	if( type_ == property_type::string )
	{
		*result = xstring_;
		return xresult::ok;
	}
	return xresult::invalid_operation;
}

xresult xbox::get_xobject( xobject** result ) const
{
	if( type_ == property_type::xobject )
	{
		*result = xobject_;
		return xresult::ok;
	}
	return xresult::invalid_operation;
}

xresult xbox::get_int16( short* result ) const
{
	if( type_ == property_type::int16 )
	{
		*result = int16_;
		return xresult::ok;
	}
	return xresult::invalid_operation;
}

xresult xbox::get_int32( int* result ) const
{
	if( type_ == property_type::int32 )
	{
		*result = int32_;
		return xresult::ok;
	}
	return xresult::invalid_operation;
}

xresult xbox::get_int64( long long* result ) const
{
	if( type_ == property_type::int64 )
	{
		*result = int64_;
		return xresult::ok;
	}
	return xresult::invalid_operation;
}

xresult xbox::get_uint8( unsigned char* result ) const
{
	if( type_ == property_type::uint8 )
	{
		*result = uint8_;
		return xresult::ok;
	}
	return xresult::invalid_operation;
}

xresult xbox::get_float32( float* result ) const
{
	if( type_ == property_type::float32 )
	{
		*result = float32_;
		return xresult::ok;
	}
	return xresult::invalid_operation;
}

xresult xbox::get_float64( double* result ) const
{
	if( type_ == property_type::float64 )
	{
		*result = float64_;
		return xresult::ok;
	}
	return xresult::invalid_operation;
}

xresult xbox::get_color( ui::color* result ) const
{
	if( type_ == property_type::color )
	{
		*result = color_;
		return xresult::ok;
	}
	return xresult::invalid_operation;
}

xresult xbox::get_point( ui::point* result ) const
{
	if( type_ == property_type::point )
	{
		*result = point_;
		return xresult::ok;
	}
	return xresult::invalid_operation;
}

xresult xbox::get_size( ui::size* result ) const
{
	if( type_ == property_type::size )
	{
		*result = size_;
		return xresult::ok;
	}
	return xresult::invalid_operation;
}

xresult xbox::get_rect( ui::rect* result ) const
{
	if( type_ == property_type::rect )
	{
		*result = rect_;
		return xresult::ok;
	}
	return xresult::invalid_operation;
}

xresult xbox::get_thickness( ui::xaml::thickness* result ) const
{
	if( type_ == property_type::thickness )
	{
		*result = thickness_;
		return xresult::ok;
	}
	return xresult::invalid_operation;
}

xresult xbox::get_corner_radius( ui::xaml::corner_radius* result ) const
{
	if( type_ == property_type::corner_radius )
	{
		*result = corner_radius_;
		return xresult::ok;
	}
	return xresult::invalid_operation;
}

xresult xbox::get_boolean_array( int* length, bool** result ) const
{
	if( type_ == property_type::boolean_array )
	{
		*result = boolean_array_;
		*length = length_;
		return xresult::ok;
	}
	return xresult::invalid_operation;
}

xresult xbox::get_char16_array( int* length, wchar_t** result ) const
{
	if( type_ == property_type::char16_array )
	{
		*result = char16_array_;
		*length = length_;
		return xresult::ok;
	}
	return xresult::invalid_operation;
}

xresult xbox::get_string_array( int* length, xstring*** result ) const
{
	if( type_ == property_type::string_array )
	{
		*result = xstring_array_;
		*length = length_;
		return xresult::ok;
	}
	return xresult::invalid_operation;
}

xresult xbox::get_xobject_array( int* length, xobject*** result ) const
{
	if( type_ == property_type::xobject_array )
	{
		*result = xobject_array_;
		*length = length_;
		return xresult::ok;
	}
	return xresult::invalid_operation;
}

xresult xbox::get_int16_array( int* length, short** result ) const
{
	if( type_ == property_type::int16_array )
	{
		*result = int16_array_;
		*length = length_;
		return xresult::ok;
	}
	return xresult::invalid_operation;
}

xresult xbox::get_int32_array( int* length, int** result ) const
{
	if( type_ == property_type::int32_array )
	{
		*result = int32_array_;
		*length = length_;
		return xresult::ok;
	}
	return xresult::invalid_operation;
}

xresult xbox::get_int64_array( int* length, long long** result ) const
{
	if( type_ == property_type::int64_array )
	{
		*result = int64_array_;
		*length = length_;
		return xresult::ok;
	}
	return xresult::invalid_operation;
}

xresult xbox::get_uint8_array( int* length, unsigned char** result ) const
{
	if( type_ == property_type::uint8_array )
	{
		*result = uint8_array_;
		*length = length_;
		return xresult::ok;
	}
	return xresult::invalid_operation;
}

xresult xbox::get_float32_array( int* length, float** result ) const
{
	if( type_ == property_type::float32_array )
	{
		*result = float32_array_;
		*length = length_;
		return xresult::ok;
	}
	return xresult::invalid_operation;
}

xresult xbox::get_float64_array( int* length, double** result ) const
{
	if( type_ == property_type::float64_array )
	{
		*result = float64_array_;
		*length = length_;
		return xresult::ok;
	}
	return xresult::invalid_operation;
}

xresult xbox::get_color_array( int* length, ui::color** result ) const
{
	if( type_ == property_type::color_array )
	{
		*result = color_array_;
		*length = length_;
		return xresult::ok;
	}
	return xresult::invalid_operation;
}

xresult xbox::get_point_array( int* length, ui::point** result ) const
{
	if( type_ == property_type::point_array )
	{
		*result = point_array_;
		*length = length_;
		return xresult::ok;
	}
	return xresult::invalid_operation;
}

xresult xbox::get_size_array( int* length, ui::size** result ) const
{
	if( type_ == property_type::size_array )
	{
		*result = size_array_;
		*length = length_;
		return xresult::ok;
	}
	return xresult::invalid_operation;
}

xresult xbox::get_rect_array( int* length, ui::rect** result ) const
{
	if( type_ == property_type::rect_array )
	{
		*result = rect_array_;
		*length = length_;
		return xresult::ok;
	}
	return xresult::invalid_operation;
}

xresult xbox::get_thickness_array( int* length, ui::xaml::thickness** result ) const
{
	if( type_ == property_type::thickness_array )
	{
		*result = thickness_array_;
		*length = length_;
		return xresult::ok;
	}
	return xresult::invalid_operation;
}

xresult xbox::get_corner_radius_array( int* length, ui::xaml::corner_radius** result ) const
{
	if( type_ == property_type::corner_radius_array )
	{
		*result = corner_radius_array_;
		*length = length_;
		return xresult::ok;
	}
	return xresult::invalid_operation;
}


type_name xbox::type() const { return TYPE( xxaml__foundation__xbox ); }

property_type xbox::box_type() const
{
	return type_;
}