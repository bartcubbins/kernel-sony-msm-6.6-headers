/*
 * This file is auto-generated. Modifications will be lost.
 *
 * See https://android.googlesource.com/platform/bionic/+/master/libc/kernel/
 * for more information.
 */
#ifndef _UAPI_LINUX_MSM_AUDIO_H
#define _UAPI_LINUX_MSM_AUDIO_H
#include <linux/types.h>
#include <linux/ioctl.h>
#define AUDIO_IOCTL_MAGIC 'a'
#define IOCTL_MAP_PHYS_ADDR _IOW(AUDIO_IOCTL_MAGIC, 97, int)
#define IOCTL_UNMAP_PHYS_ADDR _IOW(AUDIO_IOCTL_MAGIC, 98, int)
#define IOCTL_MAP_HYP_ASSIGN _IOW(AUDIO_IOCTL_MAGIC, 109, int)
#define IOCTL_UNMAP_HYP_ASSIGN _IOW(AUDIO_IOCTL_MAGIC, 110, int)
#define IOCTL_MAP_HYP_ASSIGN_V2 _IOW(AUDIO_IOCTL_MAGIC, 111, struct msm_mdf_data)
#define IOCTL_UNMAP_HYP_ASSIGN_V2 _IOW(AUDIO_IOCTL_MAGIC, 112, struct msm_mdf_data)
#define AUDIO_MAX_COMMON_IOCTL_NUM 113
struct msm_mdf_data {
  __u64 ss_masks;
  __u32 mem_fd;
  __u32 reserved;
};
#endif
