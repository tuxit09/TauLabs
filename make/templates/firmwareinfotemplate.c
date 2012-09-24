/**
 ******************************************************************************
 *
 * @file       ${OUTFILENAME}
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2011.
 * @brief      Firmware version info file autogenerated using template
 *             ${TEMPLATE}
 *
 * @see        The GNU Public License (GPL) Version 3
 *
 *****************************************************************************/
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include <stdint.h>

/**
 * We have 100 bytes for the whole description.
 *
 *
 * Structure is:
 *   4 bytes: header: "OpFw".
 *   4 bytes: GIT commit tag (short version of SHA1).
 *   4 bytes: Unix timestamp of compile time.
 *   2 bytes: target platform. Should follow same rule as BOARD_TYPE and BOARD_REVISION in board define files.
 *  26 bytes: commit tag if it is there, otherwise branch name. '-dirty' may be added if needed. Zero-padded.
 *  20 bytes: SHA1 sum of the firmware.
 *  20 bytes: SHA1 sum of the uavo definitions.
 *  20 bytes: free for now.
 *
 */

struct __attribute__((packed)) fw_version_info {
	uint8_t magic[4];
	uint32_t commit_hash_prefix;
	uint32_t timestamp;
	uint8_t board_type;
	uint8_t board_revision;
	uint8_t commit_tag_name[26];
	uint8_t sha1sum[20];
	uint8_t uavosha1[20];
	uint8_t pad[20];
};

const struct fw_version_info fw_version_blob __attribute__((used)) __attribute__((__section__(".fw_version_blob"))) = {
	.magic = { 'O','p','F','w' },
	.commit_hash_prefix = 0x${HASH8},
	.timestamp = ${UNIXTIME},
	.board_type = ${BOARD_TYPE},
	.board_revision = ${BOARD_REVISION},
	.commit_tag_name = "${FWTAG}",
	.sha1sum = { ${SHA1} },
	.uavosha1 = { ${UAVOSHA1} },
}; 

/**
 * @}
 */
