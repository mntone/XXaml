#pragma once
#include "ui/basic_structures.hpp"
#include "visibility.hpp"
#include "dependency_object.hpp"

namespace xxaml { namespace ui { namespace xaml {

	const wchar_t xxaml__ui__xaml__uielement[] = L"XXaml.UI.Xaml.UIElement";
	class uielement
		: public dependency_object
	{
	protected:
		XXAML_IMPORT uielement();

	public:
		XXAML_IMPORT void invalidate_measure();
		XXAML_IMPORT void invalidate_arrange();

		XXAML_IMPORT foundation::xresult measure( ::xxaml::ui::size available_size );
		XXAML_IMPORT foundation::xresult arrange( ::xxaml::ui::size final_size );

	private:
		static foundation::xresult initialize_property();

	public:
		XXAML_IMPORT foundation::xresult desired_size( ::xxaml::ui::size* result ) const;

		XXAML_IMPORT foundation::xresult visibility( xaml::visibility* result ) const;
		XXAML_IMPORT foundation::xresult set_visibility( xaml::visibility value );
		XXAML_IMPORT static dependency_property* visibility_property();

		XXAML_IMPORT virtual foundation::type_name type() const override;

	protected:
		XXAML_IMPORT foundation::xresult set_desired_size( ::xxaml::ui::size desired_size );

	protected:
		::xxaml::ui::size desired_size_;

	private:
		static bool initialized_;
		static foundation::xobject_sptr<dependency_property> visibility_property_;
	};

} } }