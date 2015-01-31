#include "pch.hpp"
#include "basics.hpp"
#include "graphics/drawing_context.hpp"

#include <gl/GL.h>
#include <gl/GLU.h>

using namespace std;
using namespace xxaml::foundation;
using namespace xxaml::graphics;
using namespace xxaml::ui;
using namespace xxaml::ui::xaml;

struct gl_drawing_context
{
	gl_drawing_context( GLenum mode )
	{
		glBegin( mode );
	}

	~gl_drawing_context()
	{
		glEnd();
	}
};

#define ASSIGN_COLOR( __COLOR__ ) glColor4f( ( __COLOR__ ).red, ( __COLOR__ ).green, ( __COLOR__ ).blue, ( __COLOR__ ).alpha );

#define DRAW_RECT( __P1X__, __P1Y__, __P2X__, __P2Y__ ) \
	{ \
		gl_drawing_context dc( GL_QUADS ); \
		glVertex2f( ( __P1X__ ), ( __P1Y__ ) ); \
		glVertex2f( ( __P1X__ ), ( __P2Y__ ) ); \
		glVertex2f( ( __P2X__ ), ( __P2Y__ ) ); \
		glVertex2f( ( __P2X__ ), ( __P1Y__ ) ); \
	}

drawing_context::drawing_context()
{

}

xresult drawing_context::draw_line( point const& point1, point const& point2, color const& color )
{
	return draw_line( point1, point2, color, 1.f );
}

xresult drawing_context::draw_line( point const& point1, point const& point2, color const& color, float thickness )
{
	const float rad = atan2( point2.x - point1.x, point2.y - point1.y );

	ASSIGN_COLOR( color );
	gl_drawing_context dc( GL_QUADS );
	glVertex2f( point1.x, point1.y );
	glVertex2f( point1.x, point1.y );
	glVertex2f( point2.x, point2.y );
	glVertex2f( point2.x, point2.y );
	return xresult::ok;
}

xresult drawing_context::draw_rectangle( rect const& rect, color const& color, thickness const& thickness )
{
	ASSIGN_COLOR( color );
	DRAW_RECT( rect.x, rect.y, rect.x + thickness.left, rect.y + rect.height );
	DRAW_RECT( rect.x + thickness.left, rect.y + rect.height - thickness.bottom, rect.x + rect.width - thickness.right, rect.y + rect.height );
	DRAW_RECT( rect.x + rect.width - thickness.right, rect.y, rect.x + rect.width, rect.y + rect.height );
	DRAW_RECT( rect.x + thickness.left, rect.y, rect.x + rect.width - thickness.right, rect.y + thickness.top );
	return xresult::ok;
}

xresult drawing_context::fill_rectangle( rect const& rect, color const& color )
{
	ASSIGN_COLOR( color );
	DRAW_RECT( rect.x, rect.y, rect.x + rect.width, rect.y + rect.height );
	return xresult::ok;
}