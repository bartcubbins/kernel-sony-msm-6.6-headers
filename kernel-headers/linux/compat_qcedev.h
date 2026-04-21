/*
 * This file is auto-generated. Modifications will be lost.
 *
 * See https://android.googlesource.com/platform/bionic/+/master/libc/kernel/
 * for more information.
 */
#ifndef _UAPI_COMPAT_QCEDEV__H
#define _UAPI_COMPAT_QCEDEV__H
#include <linux/types.h>
#include <linux/ioctl.h>
#include <linux/qcedev.h>
struct compat_buf_info {
  union {
    __u32 offset;
    __u32 vaddr;
  };
  __u32 len;
};
struct compat_qcedev_vbuf_info {
  struct compat_buf_info src[QCEDEV_MAX_BUFFERS];
  struct compat_buf_info dst[QCEDEV_MAX_BUFFERS];
};
struct compat_qcedev_pmem_info {
  __s32 fd_src;
  struct compat_buf_info src[QCEDEV_MAX_BUFFERS];
  __s32 fd_dst;
  struct compat_buf_info dst[QCEDEV_MAX_BUFFERS];
};
struct compat_qcedev_cipher_op_req {
  __u8 use_pmem;
  union {
    struct compat_qcedev_pmem_info pmem;
    struct compat_qcedev_vbuf_info vbuf;
  };
  __u32 entries;
  __u32 data_len;
  __u8 in_place_op;
  __u8 enckey[QCEDEV_MAX_KEY_SIZE];
  __u32 encklen;
  __u8 iv[QCEDEV_MAX_IV_SIZE];
  __u32 ivlen;
  __u32 byteoffset;
  enum qcedev_cipher_alg_enum alg;
  enum qcedev_cipher_mode_enum mode;
  enum qcedev_oper_enum op;
};
struct compat_qcedev_sha_op_req {
  struct compat_buf_info data[QCEDEV_MAX_BUFFERS];
  __u32 entries;
  __u32 data_len;
  __u8 digest[QCEDEV_MAX_SHA_DIGEST];
  __u32 diglen;
  __u32 authkey;
  __u32 authklen;
  enum qcedev_sha_alg_enum alg;
};
struct compat_qcedev_map_buf_req {
  __s32 fd[QCEDEV_MAX_BUFFERS];
  __u32 num_fds;
  __u32 fd_size[QCEDEV_MAX_BUFFERS];
  __u32 fd_offset[QCEDEV_MAX_BUFFERS];
  __u64 buf_vaddr[QCEDEV_MAX_BUFFERS];
};
struct compat_qcedev_unmap_buf_req {
  __s32 fd[QCEDEV_MAX_BUFFERS];
  __u32 num_fds;
};
struct file;
#define COMPAT_QCEDEV_IOCTL_ENC_REQ _IOWR(QCEDEV_IOC_MAGIC, 1, struct compat_qcedev_cipher_op_req)
#define COMPAT_QCEDEV_IOCTL_DEC_REQ _IOWR(QCEDEV_IOC_MAGIC, 2, struct compat_qcedev_cipher_op_req)
#define COMPAT_QCEDEV_IOCTL_SHA_INIT_REQ _IOWR(QCEDEV_IOC_MAGIC, 3, struct compat_qcedev_sha_op_req)
#define COMPAT_QCEDEV_IOCTL_SHA_UPDATE_REQ _IOWR(QCEDEV_IOC_MAGIC, 4, struct compat_qcedev_sha_op_req)
#define COMPAT_QCEDEV_IOCTL_SHA_FINAL_REQ _IOWR(QCEDEV_IOC_MAGIC, 5, struct compat_qcedev_sha_op_req)
#define COMPAT_QCEDEV_IOCTL_GET_SHA_REQ _IOWR(QCEDEV_IOC_MAGIC, 6, struct compat_qcedev_sha_op_req)
#define COMPAT_QCEDEV_IOCTL_LOCK_CE _IO(QCEDEV_IOC_MAGIC, 7)
#define COMPAT_QCEDEV_IOCTL_UNLOCK_CE _IO(QCEDEV_IOC_MAGIC, 8)
#define COMPAT_QCEDEV_IOCTL_GET_CMAC_REQ _IOWR(QCEDEV_IOC_MAGIC, 9, struct compat_qcedev_sha_op_req)
#define COMPAT_QCEDEV_IOCTL_MAP_BUF_REQ _IOWR(QCEDEV_IOC_MAGIC, 10, struct compat_qcedev_map_buf_req)
#define COMPAT_QCEDEV_IOCTL_UNMAP_BUF_REQ _IOWR(QCEDEV_IOC_MAGIC, 11, struct compat_qcedev_unmap_buf_req)
#endif
