/*
 * This file is auto-generated. Modifications will be lost.
 *
 * See https://android.googlesource.com/platform/bionic/+/master/libc/kernel/
 * for more information.
 */
#ifndef __QCOM_FASTRPC_H__
#define __QCOM_FASTRPC_H__
#include <linux/types.h>
#define FASTRPC_IOCTL_ALLOC_DMA_BUFF _IOWR('R', 1, struct fastrpc_alloc_dma_buf)
#define FASTRPC_IOCTL_FREE_DMA_BUFF _IOWR('R', 2, __u32)
#define FASTRPC_IOCTL_INVOKE _IOWR('R', 3, struct fastrpc_invoke)
#define FASTRPC_IOCTL_INIT_ATTACH _IO('R', 4)
#define FASTRPC_IOCTL_INIT_CREATE _IOWR('R', 5, struct fastrpc_init_create)
#define FASTRPC_IOCTL_MMAP _IOWR('R', 6, struct fastrpc_req_mmap)
#define FASTRPC_IOCTL_MUNMAP _IOWR('R', 7, struct fastrpc_req_munmap)
#define FASTRPC_IOCTL_INIT_ATTACH_SNS _IO('R', 8)
#define FASTRPC_IOCTL_INIT_CREATE_STATIC _IOWR('R', 9, struct fastrpc_init_create_static)
#define FASTRPC_IOCTL_MEM_MAP _IOWR('R', 10, struct fastrpc_mem_map)
#define FASTRPC_IOCTL_MEM_UNMAP _IOWR('R', 11, struct fastrpc_mem_unmap)
#define FASTRPC_IOCTL_MULTIMODE_INVOKE _IOWR('R', 12, struct fastrpc_ioctl_multimode_invoke)
#define FASTRPC_IOCTL_GET_DSP_INFO _IOWR('R', 13, struct fastrpc_ioctl_capability)
enum fastrpc_map_flags {
  FASTRPC_MAP_STATIC = 0,
  FASTRPC_MAP_RESERVED,
  FASTRPC_MAP_FD = 2,
  FASTRPC_MAP_FD_DELAYED,
  FASTRPC_MAP_FD_NOMAP = 16,
  FASTRPC_MAP_MAX,
};
enum fastrpc_proc_attr {
  FASTRPC_MODE_DEBUG = (1 << 0),
  FASTRPC_MODE_PTRACE = (1 << 1),
  FASTRPC_MODE_CRC = (1 << 2),
  FASTRPC_MODE_UNSIGNED_MODULE = (1 << 3),
  FASTRPC_MODE_ADAPTIVE_QOS = (1 << 4),
  FASTRPC_MODE_SYSTEM_PROCESS = (1 << 5),
  FASTRPC_MODE_PRIVILEGED = (1 << 6),
  FASTRPC_MODE_SYSTEM_UNSIGNED_PD = 1 << 17,
};
#define FASTRPC_ATTR_SECUREMAP (1)
#define FASTRPC_ATTR_NOVA (256)
struct fastrpc_invoke_args {
  __u64 ptr;
  __u64 length;
  __s32 fd;
  __u32 attr;
};
struct fastrpc_invoke {
  __u32 handle;
  __u32 sc;
  __u64 args;
};
struct fastrpc_enhanced_invoke {
  struct fastrpc_invoke inv;
  __u64 crc;
  __u64 perf_kernel;
  __u64 perf_dsp;
  __u32 reserved[20];
};
struct fastrpc_ioctl_multimode_invoke {
  __u32 req;
  __u64 invparam;
  __u64 size;
  __u32 reserved[8];
};
enum fastrpc_multimode_invoke_type {
  FASTRPC_INVOKE = 1,
  FASTRPC_INVOKE_ENHANCED = 2,
  FASTRPC_INVOKE_CONTROL = 3,
  FASTRPC_INVOKE_DSPSIGNAL = 4,
  FASTRPC_INVOKE_NOTIF = 5,
  FASTRPC_INVOKE_MULTISESSION = 6,
  FASTRPC_INVOKE_CONFIG = 7,
  FASTRPC_INVOKE_SESSIONINFO = 8,
};
struct fastrpc_init_create {
  __u32 filelen;
  __s32 filefd;
  __u32 attrs;
  __u32 siglen;
  __u64 file;
};
struct fastrpc_init_create_static {
  __u32 namelen;
  __u32 memlen;
  __u64 name;
};
struct fastrpc_alloc_dma_buf {
  __s32 fd;
  __u32 flags;
  __u64 size;
};
struct fastrpc_req_mmap {
  __s32 fd;
  __u32 flags;
  __u64 vaddrin;
  __u64 size;
  __u64 vaddrout;
};
struct fastrpc_mem_map {
  __s32 version;
  __s32 fd;
  __s32 offset;
  __u32 flags;
  __u64 vaddrin;
  __u64 length;
  __u64 vaddrout;
  __s32 attrs;
  __s32 reserved[4];
};
struct fastrpc_req_munmap {
  __u64 vaddrout;
  __u64 size;
};
struct fastrpc_mem_unmap {
  __s32 vesion;
  __s32 fd;
  __u64 vaddr;
  __u64 length;
  __s32 reserved[5];
};
enum fastrpc_control_type {
  FASTRPC_CONTROL_LATENCY = 1,
  FASTRPC_CONTROL_SMMU = 2,
  FASTRPC_CONTROL_KALLOC = 3,
  FASTRPC_CONTROL_WAKELOCK = 4,
  FASTRPC_CONTROL_PM = 5,
  FASTRPC_CONTROL_DSPPROCESS_CLEAN = 6,
  FASTRPC_CONTROL_RPC_POLL = 7,
  FASTRPC_CONTROL_ASYNC_WAKE = 8,
  FASTRPC_CONTROL_NOTIF_WAKE = 9,
};
enum fastrpc_dspsignal_type {
  FASTRPC_DSPSIGNAL_SIGNAL = 1,
  FASTRPC_DSPSIGNAL_WAIT = 2,
  FASTRPC_DSPSIGNAL_CREATE = 3,
  FASTRPC_DSPSIGNAL_DESTROY = 4,
  FASTRPC_DSPSIGNAL_CANCEL_WAIT = 5,
};
enum fastrpc_status_flags {
  FASTRPC_USERPD_UP = 0,
  FASTRPC_USERPD_EXIT = 1,
  FASTRPC_USERPD_FORCE_KILL = 2,
  FASTRPC_USERPD_EXCEPTION = 3,
  FASTRPC_DSP_SSR = 4,
};
struct fastrpc_ioctl_capability {
  __u32 domain;
  __u32 attribute_id;
  __u32 capability;
  __u32 reserved[4];
};
enum fastrpc_perfkeys {
  PERF_COUNT = 0,
  PERF_RESERVED1 = 1,
  PERF_MAP = 2,
  PERF_COPY = 3,
  PERF_LINK = 4,
  PERF_GETARGS = 5,
  PERF_PUTARGS = 6,
  PERF_RESERVED2 = 7,
  PERF_INVOKE = 8,
  PERF_RESERVED3 = 9,
  PERF_KEY_MAX = 10,
};
#endif
