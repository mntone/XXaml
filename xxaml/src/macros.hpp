#pragma once

#define NULL_CHECK( __OBJECT__ ) if( ( __OBJECT__ ) == nullptr ) { return xresult::argument_null_pointer; }
#define NULL_CHECK2( __OBJECT1__, __OBJECT2__ ) NULL_CHECK( __OBJECT1__ ) NULL_CHECK( __OBJECT2__ )
#define NULL_CHECK3( __OBJECT1__, __OBJECT2__, __OBJECT3__ ) NULL_CHECK2( __OBJECT1__, __OBJECT2__ ) NULL_CHECK( __OBJECT3__ )

#define NEW_CHECK( __OBJECT__ ) if( ( __OBJECT__ ) == nullptr ) { return xresult::out_of_memory; }
#define NEW_AND_CHECK( __VARIABLE_NAME__, __CLASS_NAME__ ) __CLASS_NAME__* __VARIABLE_NAME__ = new( ::std::nothrow ) __CLASS_NAME__(); NEW_CHECK( __VARIABLE_NAME__ );

#define TEXT( __TEXT__ ) ::xxaml::foundation::xstring { __TEXT__, wcslen( __TEXT__ ) }
#define TYPE( __TYPE_NAME__ ) ::xxaml::foundation::type_name { TEXT( __TYPE_NAME__ ) }

#define GET_CASTED_VALUE( __DP__, __TYPE__, __RESULT__ ) \
	::xxaml::foundation::xresult xresult__ = ::xxaml::foundation::xresult::ok; \
	\
	::xxaml::foundation::xobject_sptr<::xxaml::foundation::xobject> xobject_value__; \
	xresult__ = get_value( __DP__, xobject_value__ ); \
	if( xresult__ != ::xxaml::foundation::xresult::ok ) return xresult__; \
	\
	*__RESULT__ = static_cast<__TYPE__*>( xobject_value__.value() ); \
	return ::xxaml::foundation::xresult::ok;

#define GET_BOXED_VALUE( __DP__, __TYPE__, __RESULT__ ) \
	::xxaml::foundation::xresult xresult__ = ::xxaml::foundation::xresult::ok; \
	\
	::xxaml::foundation::xobject_sptr<::xxaml::foundation::xobject> xobject_value__; \
	xresult__ = get_value( __DP__, xobject_value__ ); \
	if( xresult__ != ::xxaml::foundation::xresult::ok ) return xresult__; \
	if( wcscmp( xobject_value__->type().type.value, ::xxaml::foundation::xxaml__foundation__xbox ) != 0 ) return xresult::failed; \
	\
	::xxaml::foundation::xobject_sptr<::xxaml::foundation::xbox> box_value__ = static_cast<::xxaml::foundation::xbox*>( xobject_value__.value() ); \
	__TYPE__ unboxed_value__; \
	xresult__ = box_value__->get_ ## __TYPE__( &unboxed_value__ ); \
	if( xresult__ != ::xxaml::foundation::xresult::ok ) return xresult__; \
	\
	*__RESULT__ = unboxed_value__; \
	return ::xxaml::foundation::xresult::ok;

#define SET_BOXED_VALUE( __DP__, __VALUE__ ) \
	::xxaml::foundation::xobject_sptr<::xxaml::foundation::xobject> xobject_value__ = new xbox( __VALUE__ ); \
	return set_value( __DP__, xobject_value__ );