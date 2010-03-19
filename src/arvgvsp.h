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

#ifndef ARV_GVSP_H
#define ARV_GVSP_H

#include <arv.h>

G_BEGIN_DECLS

typedef enum {
	ARV_GVSP_PACKET_TYPE_DATA_LEADER = 	0x0100,
	ARV_GVSP_PACKET_TYPE_DATA_TRAILER = 	0x0200,
	ARV_GVSP_PACKET_TYPE_DATA_BLOCK =	0x0300
} ArvGvspPacketType;

typedef struct {
	guint32 frame_id;
	guint16 packet_type;
	guint16 block_id;
} __attribute__((__packed__)) ArvGvspHeader;

typedef struct {
	guint32 data0;
	guint32 data1;
	guint32 data2;
	guint32 data3;
	guint32 width;
	guint32 height;
} __attribute__((__packed__)) ArvGvspDataLeader;

typedef struct {
	guint32 data0;
	guint32 data1;
} __attribute__((__packed__)) ArvGvspDataTrailer;

typedef struct {
	ArvGvspHeader header;
	guint8 data[];
} ArvGvspPacket;

void 			arv_gvsp_packet_debug 			(const ArvGvspPacket *packet, size_t packet_size);

static inline ArvGvspPacketType
arv_gvsp_packet_get_packet_type	(const ArvGvspPacket *packet)
{
	return g_ntohs (packet->header.packet_type);
}

static inline guint16
arv_gvsp_packet_get_block_id (const ArvGvspPacket *packet)
{
	return g_ntohs (packet->header.block_id);
}

static inline guint32
arv_gvsp_packet_get_frame_id (const ArvGvspPacket *packet)
{
	return g_ntohl (packet->header.frame_id);
}

static inline guint32
arv_gvsp_packet_get_width (const ArvGvspPacket *packet)
{
	ArvGvspDataLeader *leader;

	leader = (ArvGvspDataLeader *) &packet->data;
	return g_ntohl (leader->width);
}

static inline guint32
arv_gvsp_packet_get_height (const ArvGvspPacket *packet)
{
	ArvGvspDataLeader *leader;

	leader = (ArvGvspDataLeader *) &packet->data;
	return g_ntohl (leader->height);
}

static inline size_t
arv_gvsp_packet_get_data_size (size_t packet_size)
{
	return packet_size - sizeof (ArvGvspHeader);
}

G_END_DECLS

#endif