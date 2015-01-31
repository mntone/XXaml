#pragma once
#include "exports.hpp"
#include "foundation/xobject.hpp"

namespace xxaml { namespace foundation {

	template<typename T, bool = ::std::is_base_of<xobject, T>::value>
	class xobject_sptr;

	template<typename T>
	class xobject_sptr<T, false>
	{
		static_assert( ::std::is_base_of<xobject, T>::value, "xobject_sptr<T> requires T to be valid XXaml types." );
	};

	template<typename T, bool>
	class xobject_sptr
	{
	public:
		xobject_sptr()
			: value_( nullptr )
		{ }

		xobject_sptr( T* value )
			: value_( value )
		{
			static_cast<xobject&>( *value_ ).add();
		}

		explicit xobject_sptr( xobject_sptr const& value )
			: value_( value )
		{
			static_cast<xobject&>( *value_ ).add();
		}

		explicit xobject_sptr( xobject_sptr&& value )
			: value_( value )
		{ }

		explicit xobject_sptr( ::std::nullptr_t )
			: value_( nullptr )
		{ }

		~xobject_sptr()
		{
			if( value_ != nullptr )
			{
				static_cast<xobject&>( *value_ ).release();
			}
		}

		xobject_sptr& operator=( T* other_value )
		{
			reset( other_value );
			return *this;
		}

		xobject_sptr& operator=( xobject_sptr const& other )
		{
			xobject_sptr( other ).swap( *this );
			return *this;
		}

		xobject_sptr& operator=( xobject_sptr&& other )
		{
			::std::swap( value_, other );
			if( other.value_ != nullptr )
			{
				static_cast<xobject&>( *value_ ).release();
			}
			return *this;
		}

		void swap( xobject_sptr& other )
		{
			::std::swap( value_, other.value_ );
		}

		friend void swap( xobject_sptr& left, xobject_sptr& right )
		{
			left.swap( right );
		}

		void reset( T* value )
		{
			if( value != nullptr )
			{
				static_cast<xobject&>( *value ).add();
			}
			::std::swap( value_, value );
			if( value != nullptr )
			{
				static_cast<xobject&>( *value_ ).release();
			}
		}

		T* value() const
		{
			return value_;
		}

		operator T*() const
		{
			return value_;
		}

		operator T**()
		{
			return &value_;
		}

		T* operator->() const
		{
			return value_;
		}

	private:
		T* value_;
	};

} }