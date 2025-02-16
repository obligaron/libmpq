/*
 *  common.h -- header functions used by mpq-tools.
 *
 *  Copyright (c) 2003-2011 Maik Broemme <mbroemme@libmpq.org>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef _COMMON_H
#define _COMMON_H

#include <stddef.h>
#include <stdint.h>

/* function to detect decryption key. */
int32_t libmpq__decrypt_key(
	uint8_t		*in_buf,
	uint32_t	in_size,
	uint32_t	block_size,
	uint32_t	*key
);

/* function to obtain the decryption key given a filename. */
int32_t libmpq__encryption_key_from_filename(
	const char	*filename,
	uint32_t	*key
);

int32_t libmpq__encryption_key_from_filename_s(
	const char	*filename,
	size_t	filename_length,
	uint32_t	*key
);

/* function to obtain the decryption key given a filename for files with LIBMPQ_FLAG_ENCRYPTION_KEY_V2. */
int32_t libmpq__encryption_key_from_filename_v2(
	const char	*filename,
	uint32_t	offset,
	uint32_t	unpacked_size,
	uint32_t	*key
);

int32_t libmpq__encryption_key_from_filename_v2_s(
	const char	*filename,
	size_t	filename_length,
	uint32_t	offset,
	uint32_t	unpacked_size,
	uint32_t	*key
);

/* function to decompress or explode block from archive. */
int32_t libmpq__decompress_block(
	uint8_t		*in_buf,
	uint32_t	in_size,
	uint8_t		*work_buf,
	uint8_t		*out_buf,
	uint32_t	out_size,
	uint32_t	compression_type
);

#endif						/* _COMMON_H */
