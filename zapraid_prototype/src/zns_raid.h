#ifndef __ZNS_RAID_H__
#define __ZNS_RAID_H__

typedef void (*zns_raid_request_complete)(void *cb_arg);

void *zns_raid_create(void);
void zns_raid_destroy(void *ctrl);

void zns_raid_write(void *ctrl, uint64_t offset, uint32_t size, void *data,
    zns_raid_request_complete cb_fn, void *args);
void zns_raid_read(void *ctrl, uint64_t offset, uint32_t size, void *data,
    zns_raid_request_complete cb_fn, void *args);
void zns_raid_flush(void *ctrl);

void zns_raid_set_system_mode(int mode);
void zns_raid_set_raid_parameters(int n_data_blocks, int n_parity_blocks, int raid_level);
void zns_raid_set_gc(bool enable);
void zns_raid_set_sync_group_size(uint32_t group_size);
void zns_raid_set_degraded_read(bool enable);

void zns_raid_set_num_open_segments(uint32_t num_open_segments);
void zns_raid_set_header_footer(uint32_t enable_header_footer);

void zns_raid_set_storage_space_in_bytes(uint64_t storage_space_in_bytes);
void zns_raid_set_enable_event_framework(bool enable);

#endif
