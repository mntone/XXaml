#pragma once
#include "property_type.hpp"
#include "ui/basic_structures.hpp"
#include "xresult.hpp"
#include "xobject.hpp"

namespace xxaml { namespace foundation {

	const wchar_t xxaml__foundation__xbox[] = L"XXaml.Foundation.XBox";
	class xbox final
		: public xobject
	{
	public:
		XXAML_IMPORT xbox();
		XXAML_IMPORT xbox( ::std::nullptr_t );
		XXAML_IMPORT xbox( bool value );
		XXAML_IMPORT xbox( wchar_t value );
		XXAML_IMPORT xbox( xstring value );
		XXAML_IMPORT xbox( xobject const* value );

		XXAML_IMPORT xbox( short value );
		XXAML_IMPORT xbox( int value );
		XXAML_IMPORT xbox( long long value );

		XXAML_IMPORT xbox( unsigned char value );

		XXAML_IMPORT xbox( float value );
		XXAML_IMPORT xbox( double value );

		XXAML_IMPORT xbox( ui::color value );
		XXAML_IMPORT xbox( ui::point value );
		XXAML_IMPORT xbox( ui::size value );
		XXAML_IMPORT xbox( ui::rect value );

		XXAML_IMPORT xbox( ui::xaml::thickness value );
		XXAML_IMPORT xbox( ui::xaml::corner_radius value );

		XXAML_IMPORT xbox( void* value );


		XXAML_IMPORT xbox( bool* value, int length );
		XXAML_IMPORT xbox( wchar_t* value, int length );
		XXAML_IMPORT xbox( xstring* value, int length );
		XXAML_IMPORT xbox( xobject const** value, int length );

		XXAML_IMPORT xbox( short* value, int length );
		XXAML_IMPORT xbox( int* value, int length );
		XXAML_IMPORT xbox( long long* value, int length );

		XXAML_IMPORT xbox( unsigned char* value, int length );

		XXAML_IMPORT xbox( float* value, int length );
		XXAML_IMPORT xbox( double* value, int length );

		XXAML_IMPORT xbox( ui::color* value, int length );
		XXAML_IMPORT xbox( ui::point* value, int length );
		XXAML_IMPORT xbox( ui::size* value, int length );
		XXAML_IMPORT xbox( ui::rect* value, int length );

		XXAML_IMPORT xbox( ui::xaml::thickness* value, int length );
		XXAML_IMPORT xbox( ui::xaml::corner_radius* value, int length );

		XXAML_IMPORT xbox( void** value, int length );


		XXAML_IMPORT xresult get_boolean( bool* result ) const;
		XXAML_IMPORT xresult get_char16( wchar_t* result ) const;
		XXAML_IMPORT xresult get_string( xstring* result ) const;
		XXAML_IMPORT xresult get_xobject( xobject const** result ) const;

		XXAML_IMPORT xresult get_int16( short* result ) const;
		XXAML_IMPORT xresult get_int32( int* result ) const;
		XXAML_IMPORT xresult get_int64( long long* result ) const;

		XXAML_IMPORT xresult get_uint8( unsigned char* result ) const;

		XXAML_IMPORT xresult get_float32( float* result ) const;
		XXAML_IMPORT xresult get_float64( double* result ) const;

		XXAML_IMPORT xresult get_color( ui::color* result ) const;
		XXAML_IMPORT xresult get_point( ui::point* result ) const;
		XXAML_IMPORT xresult get_size( ui::size* result ) const;
		XXAML_IMPORT xresult get_rect( ui::rect* result ) const;

		XXAML_IMPORT xresult get_thickness( ui::xaml::thickness* result ) const;
		XXAML_IMPORT xresult get_corner_radius( ui::xaml::corner_radius* result ) const;


		XXAML_IMPORT xresult get_boolean_array( int* length, bool** result ) const;
		XXAML_IMPORT xresult get_char16_array( int* length, wchar_t** result ) const;
		XXAML_IMPORT xresult get_string_array( int* length, xstring** result ) const;
		XXAML_IMPORT xresult get_xobject_array( int* length, xobject const*** result ) const;

		XXAML_IMPORT xresult get_int16_array( int* length, short** result ) const;
		XXAML_IMPORT xresult get_int32_array( int* length, int** result ) const;
		XXAML_IMPORT xresult get_int64_array( int* length, long long** result ) const;

		XXAML_IMPORT xresult get_uint8_array( int* length, unsigned char** result ) const;

		XXAML_IMPORT xresult get_float32_array( int* length, float** result ) const;
		XXAML_IMPORT xresult get_float64_array( int* length, double** result ) const;

		XXAML_IMPORT xresult get_color_array( int* length, ui::color** result ) const;
		XXAML_IMPORT xresult get_point_array( int* length, ui::point** result ) const;
		XXAML_IMPORT xresult get_size_array( int* length, ui::size** result ) const;
		XXAML_IMPORT xresult get_rect_array( int* length, ui::rect** result ) const;

		XXAML_IMPORT xresult get_thickness_array( int* length, ui::xaml::thickness** result ) const;
		XXAML_IMPORT xresult get_corner_radius_array( int* length, ui::xaml::corner_radius** result ) const;

	public:
		XXAML_IMPORT virtual foundation::type_name type() const;
		XXAML_IMPORT property_type box_type() const;

	private:
		property_type type_;
		union
		{
			bool boolean_;
			wchar_t char16_;
			xstring string_;
			xobject const* xobject_;

			short int16_;
			int int32_;
			long long int64_;

			unsigned char uint8_;

			float float32_;
			double float64_;

			ui::color color_;
			ui::point point_;
			ui::size size_;
			ui::rect rect_;

			ui::xaml::thickness thickness_;
			ui::xaml::corner_radius corner_radius_;

			void* other_type_;

			struct
			{
				union
				{
					bool* boolean_array_;
					wchar_t* char16_array_;
					xstring* string_array_;
					xobject const** xobject_array_;

					short* int16_array_;
					int* int32_array_;
					long long* int64_array_;

					unsigned char* uint8_array_;

					float* float32_array_;
					double* float64_array_;

					ui::color* color_array_;
					ui::point* point_array_;
					ui::size* size_array_;
					ui::rect* rect_array_;

					ui::xaml::thickness* thickness_array_;
					ui::xaml::corner_radius* corner_radius_array_;

					void** other_type_array_;
				};
				int length_;
			};
		};
	};

} }