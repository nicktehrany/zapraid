/*-
 *   BSD LICENSE
 *
 *   Copyright (c) Intel Corporation. All rights reserved.
 *   Copyright (c) 2019 Mellanox Technologies LTD. All rights reserved.
 *
 *   Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following conditions
 *   are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in
 *       the documentation and/or other materials provided with the
 *       distribution.
 *     * Neither the name of Intel Corporation nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef SPDK_BDEV_ZNS_RAID_H
#define SPDK_BDEV_ZNS_RAID_H

#include "spdk/stdinc.h"

typedef void (*spdk_delete_zns_raid_complete)(void *cb_arg, int bdeverrno);

struct spdk_bdev;
struct spdk_uuid;

struct spdk_zns_raid_bdev_opts {
	const char *name;
	const struct spdk_uuid *uuid;
	uint64_t num_blocks;
	uint32_t block_size;
        uint32_t system_mode;
        uint32_t num_data_blocks;
        uint32_t num_parity_blocks;
        uint32_t raid_level;
        uint32_t enable_gc;
        uint32_t sync_group_size;
        uint32_t num_open_segments;
        uint32_t inject_degraded_read;
        uint32_t enable_event_framework;
};

int bdev_zns_raid_create(struct spdk_bdev **bdev, const struct spdk_zns_raid_bdev_opts *opts);

/**
 * Delete zns_raid bdev.
 *
 * \param bdev Pointer to zns_raid bdev.
 * \param cb_fn Function to call after deletion.
 * \param cb_arg Argument to pass to cb_fn.
 */
void bdev_zns_raid_delete(struct spdk_bdev *bdev, spdk_delete_zns_raid_complete cb_fn,
		      void *cb_arg);
/**
 * Resize zns_raid bdev.
 *
 * \param bdev Pointer to zns_raid bdev.
 * \param new_size_in_mb The new size in MiB for this bdev
 */
int bdev_zns_raid_resize(struct spdk_bdev *bdev, const uint64_t new_size_in_mb);

#endif /* SPDK_BDEV_ZNS_RAID_H */
