/* style.c : Glue to access fields in GtkStyle.
 *
 * Author: Rachel Hestilow  <hestilow@ximian.com>
 *         Radek Doulik <rodo@matfyz.cz>
 *
 * <c> 2002, 2003 Rachel Hestilow, Mike Kestner, Radek Doulik
 */

#include <gtk/gtkstyle.h>

/* Forward declarations */
GdkGC *gtksharp_gtk_style_get_white_gc (GtkStyle *style);

GdkGC *gtksharp_gtk_style_get_black_gc (GtkStyle *style);

GdkGC *gtksharp_gtk_style_get_fg_gc (GtkStyle *style, int i);

GdkGC *gtksharp_gtk_style_get_bg_gc (GtkStyle *style, int i);

GdkGC *gtksharp_gtk_style_get_base_gc (GtkStyle *style, int i);

GdkGC *gtksharp_gtk_style_get_text_gc (GtkStyle *style, int i);

void gtksharp_gtk_style_set_fg_gc (GtkStyle *style, int i, GdkGC *gc);

void gtksharp_gtk_style_set_bg_gc (GtkStyle *style, int i, GdkGC *gc);

void gtksharp_gtk_style_set_base_gc (GtkStyle *style, int i, GdkGC *gc);

void gtksharp_gtk_style_set_text_gc (GtkStyle *style, int i, GdkGC *gc);

GdkColor *gtksharp_gtk_style_get_white (GtkStyle *style);

GdkColor *gtksharp_gtk_style_get_black (GtkStyle *style);

GdkColor *gtksharp_gtk_style_get_fg (GtkStyle *style, int i);

GdkColor *gtksharp_gtk_style_get_bg (GtkStyle *style, int i);

PangoFontDescription *gtksharp_gtk_style_get_font_description (GtkStyle *style);

int gtksharp_gtk_style_get_thickness (GtkStyle *style, int x);

void gtksharp_gtk_style_set_thickness (GtkStyle *style, int thickness);
/* */

/* FIXME: include all fields */

GdkGC*
gtksharp_gtk_style_get_white_gc (GtkStyle *style)
{
	g_object_ref (G_OBJECT (style->white_gc));
	return style->white_gc;
}

GdkGC*
gtksharp_gtk_style_get_black_gc (GtkStyle *style)
{
	g_object_ref (G_OBJECT (style->black_gc));
	return style->black_gc;
}

GdkGC*
gtksharp_gtk_style_get_fg_gc (GtkStyle *style, int i)
{
	g_object_ref (G_OBJECT (style->fg_gc[i]));
        return style->fg_gc[i];
}

GdkGC*
gtksharp_gtk_style_get_bg_gc (GtkStyle *style, int i)
{
	g_object_ref (G_OBJECT (style->bg_gc[i]));
	return style->bg_gc[i];
}

GdkGC*
gtksharp_gtk_style_get_base_gc (GtkStyle *style, int i)
{
	g_object_ref (G_OBJECT (style->base_gc[i]));
	return style->base_gc[i];
}

GdkGC*
gtksharp_gtk_style_get_text_gc (GtkStyle *style, int i)
{
	g_object_ref (G_OBJECT (style->text_gc[i]));
	return style->text_gc[i];
}

void
gtksharp_gtk_style_set_fg_gc (GtkStyle *style, int i, GdkGC *gc)
{
	g_object_ref (G_OBJECT (gc));
	style->fg_gc[i] = gc;
}

void
gtksharp_gtk_style_set_bg_gc (GtkStyle *style, int i, GdkGC *gc)
{
	g_object_ref (G_OBJECT (gc));
	style->bg_gc[i] = gc;
}

void
gtksharp_gtk_style_set_base_gc (GtkStyle *style, int i, GdkGC *gc)
{
	g_object_ref (G_OBJECT (gc));
	style->base_gc[i] = gc;
}

void
gtksharp_gtk_style_set_text_gc (GtkStyle *style, int i, GdkGC *gc)
{
	g_object_ref (G_OBJECT (gc));
	style->text_gc[i] = gc;
}

GdkColor*
gtksharp_gtk_style_get_white (GtkStyle *style)
{
	return &style->white;
}

GdkColor*
gtksharp_gtk_style_get_black (GtkStyle *style)
{
	return &style->black;
}

GdkColor*
gtksharp_gtk_style_get_fg (GtkStyle *style, int i)
{
	return &style->fg[i];
}

GdkColor*
gtksharp_gtk_style_get_bg (GtkStyle *style, int i)
{
	return &style->bg[i];
}

PangoFontDescription *
gtksharp_gtk_style_get_font_description (GtkStyle *style)
{
	return style->font_desc;
}

int
gtksharp_gtk_style_get_thickness (GtkStyle *style, int x)
{
	if (x)
		return style->xthickness;
	else
		return style->ythickness;
}

void
gtksharp_gtk_style_set_thickness (GtkStyle *style, int thickness)
{
	if (thickness > 0)
		style->xthickness = thickness;
	else
		style->ythickness = -thickness;
}
