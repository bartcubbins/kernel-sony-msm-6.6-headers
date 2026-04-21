/*
 * This file is auto-generated. Modifications will be lost.
 *
 * See https://android.googlesource.com/platform/bionic/+/master/libc/kernel/
 * for more information.
 */
#ifndef __UBWCP_IOCTL_H_
#define __UBWCP_IOCTL_H_
#include <linux/ioctl.h>
#include <linux/types.h>
#define UBWCP_IOCTL_SET_BUF_ATTR _IOW('U', 1, struct ubwcp_ioctl_buffer_attrs)
#define UBWCP_IOCTL_GET_HW_VER _IOR('U', 2, struct ubwcp_ioctl_hw_version)
#define UBWCP_IOCTL_GET_STRIDE_ALIGN _IOWR('U', 3, struct ubwcp_ioctl_stride_align)
#define UBWCP_IOCTL_VALIDATE_STRIDE _IOWR('U', 4, struct ubwcp_ioctl_validate_stride)
enum ubwcp_image_format {
  UBWCP_LINEAR = 0,
  UBWCP_RGBA8888,
  UBWCP_NV12,
  UBWCP_NV12_Y,
  UBWCP_NV12_UV,
  UBWCP_NV124R,
  UBWCP_NV124R_Y,
  UBWCP_NV124R_UV,
  UBWCP_TP10,
  UBWCP_TP10_Y,
  UBWCP_TP10_UV,
  UBWCP_P010,
  UBWCP_P010_Y,
  UBWCP_P010_UV,
  UBWCP_P016,
  UBWCP_P016_Y,
  UBWCP_P016_UV,
};
enum ubwcp_compression_type {
  UBWCP_COMPRESSION_LOSSLESS = 0,
};
enum ubwcp_subsample {
  UBWCP_SUBSAMPLE_4_2_0 = 0,
};
#define UBWCP_SUBSYSTEM_TARGET_CPU (1 << 0)
struct ubwcp_buffer_attrs {
  __u16 image_format;
  __u16 major_ubwc_ver;
  __u16 minor_ubwc_ver;
  __u16 compression_type;
  __u64 lossy_params;
  __u32 width;
  __u32 height;
  __u32 stride;
  __u32 scanlines;
  __u32 planar_padding;
  __u32 subsample;
  __u32 sub_system_target;
  __u32 y_offset;
  __u32 batch_size;
  __u32 unused1;
  __u32 unused2;
  __u32 unused3;
  __u32 unused4;
  __u32 unused5;
  __u32 unused6;
  __u32 unused7;
  __u32 unused8;
  __u32 unused9;
};
struct ubwcp_ioctl_buffer_attrs {
  __u32 fd;
  __u32 pad;
  struct ubwcp_buffer_attrs attr;
};
struct ubwcp_ioctl_hw_version {
  __u32 major;
  __u32 minor;
};
struct ubwcp_ioctl_stride_align {
  __u16 image_format;
  __u16 stride_align;
  __u32 unused;
};
struct ubwcp_ioctl_validate_stride {
  __u16 image_format;
  __u32 width;
  __u32 stride;
  __u16 valid;
  __u16 unused1;
  __u16 unused2;
};
#endif
