/* Aravis - Digital camera library
 *
 * Copyright © 2009-2010 Emmanuel Pacaud
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General
 * Public License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place, Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 * Author: Emmanuel Pacaud <emmanuel@gnome.org>
 */

#ifndef ARV_DEBUG_H
#define ARV_DEBUG_H

#include <glib.h>

G_BEGIN_DECLS

typedef enum {
	ARV_DEBUG_LEVEL_NONE,
	ARV_DEBUG_LEVEL_STANDARD,
	ARV_DEBUG_LEVEL_GVCP,
	ARV_DEBUG_LEVEL_GVSP
} ArvDebugLevel;

void 		arv_debug 			(ArvDebugLevel level, char const *format, ...);
gboolean 	arv_debug_check 		(ArvDebugLevel level);
void 		arv_debug_enable 		(ArvDebugLevel level);

G_END_DECLS

#endif