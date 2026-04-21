/*
 * This file is auto-generated. Modifications will be lost.
 *
 * See https://android.googlesource.com/platform/bionic/+/master/libc/kernel/
 * for more information.
 */
#ifndef _UAPI_COMPAT_QSEECOM_H_
#define _UAPI_COMPAT_QSEECOM_H_
#include <linux/types.h>
#include <linux/ioctl.h>
#include <linux/qseecom.h>
struct qseecom_register_listener_req_32bit {
  __u32 listener_id;
  __s32 ifd_data_fd;
  __u32 virt_sb_base;
  __u32 sb_size;
};
struct qseecom_send_cmd_req_32bit {
  __u32 cmd_req_buf;
  __u32 cmd_req_len;
  __u32 resp_buf;
  __u32 resp_len;
};
struct qseecom_ion_fd_info_32bit {
  __s32 fd;
  __u32 cmd_buf_offset;
};
struct qseecom_send_modfd_cmd_req_32bit {
  __u32 cmd_req_buf;
  __u32 cmd_req_len;
  __u32 resp_buf;
  __u32 resp_len;
  struct qseecom_ion_fd_info_32bit ifd_data[MAX_ION_FD];
};
struct qseecom_send_resp_req_32bit {
  __u32 resp_buf;
  __u32 resp_len;
};
struct qseecom_load_img_req_32bit {
  __u32 mdt_len;
  __u32 img_len;
  __s32 ifd_data_fd;
  char img_name[MAX_APP_NAME_SIZE];
  __u32 app_arch;
  __u32 app_id;
};
struct qseecom_set_sb_mem_param_req_32bit {
  __s32 ifd_data_fd;
  __u32 virt_sb_base;
  __u32 sb_len;
};
struct qseecom_qseos_version_req_32bit {
  __u32 qseos_version;
};
struct qseecom_qseos_app_load_query_32bit {
  char app_name[MAX_APP_NAME_SIZE];
  __u32 app_id;
  __u32 app_arch;
};
struct qseecom_send_svc_cmd_req_32bit {
  __u32 cmd_id;
  __u32 cmd_req_buf;
  __u32 cmd_req_len;
  __u32 resp_buf;
  __u32 resp_len;
};
struct qseecom_create_key_req_32bit {
  unsigned char hash32[QSEECOM_HASH_SIZE];
  enum qseecom_key_management_usage_type usage;
};
struct qseecom_wipe_key_req_32bit {
  enum qseecom_key_management_usage_type usage;
  __s32 wipe_key_flag;
};
struct qseecom_update_key_userinfo_req_32bit {
  unsigned char current_hash32[QSEECOM_HASH_SIZE];
  unsigned char new_hash32[QSEECOM_HASH_SIZE];
  enum qseecom_key_management_usage_type usage;
};
struct qseecom_save_partition_hash_req_32bit {
  __s32 partition_id;
  char digest[SHA256_DIGEST_LENGTH];
};
struct qseecom_is_es_activated_req_32bit {
  __s32 is_activated;
};
struct qseecom_mdtp_cipher_dip_req_32bit {
  __u32 in_buf;
  __u32 in_buf_size;
  __u32 out_buf;
  __u32 out_buf_size;
  __u32 direction;
};
struct qseecom_send_modfd_listener_resp_32bit {
  __u32 resp_buf_ptr;
  __u32 resp_len;
  struct qseecom_ion_fd_info_32bit ifd_data[MAX_ION_FD];
};
struct qseecom_qteec_req_32bit {
  __u32 req_ptr;
  __u32 req_len;
  __u32 resp_ptr;
  __u32 resp_len;
};
struct qseecom_qteec_modfd_req_32bit {
  __u32 req_ptr;
  __u32 req_len;
  __u32 resp_ptr;
  __u32 resp_len;
  struct qseecom_ion_fd_info_32bit ifd_data[MAX_ION_FD];
};
struct qseecom_ce_pipe_entry_32bit {
  __s32 valid;
  __u32 ce_num;
  __u32 ce_pipe_pair;
};
struct ce_info_req_32bit {
  unsigned char handle[MAX_CE_INFO_HANDLE_SIZE];
  __u32 usage;
  __u32 unit_num;
  __u32 num_ce_pipe_entries;
  struct qseecom_ce_pipe_entry_32bit ce_pipe_entry[MAX_CE_PIPE_PAIR_PER_UNIT];
};
struct file;
#define QSEECOM_IOCTL_REGISTER_LISTENER_REQ_32BIT _IOWR(QSEECOM_IOC_MAGIC, 1, struct qseecom_register_listener_req_32bit)
#define QSEECOM_IOCTL_UNREGISTER_LISTENER_REQ_32BIT _IO(QSEECOM_IOC_MAGIC, 2)
#define QSEECOM_IOCTL_SEND_CMD_REQ_32BIT _IOWR(QSEECOM_IOC_MAGIC, 3, struct qseecom_send_cmd_req_32bit)
#define QSEECOM_IOCTL_SEND_MODFD_CMD_REQ_32BIT _IOWR(QSEECOM_IOC_MAGIC, 4, struct qseecom_send_modfd_cmd_req_32bit)
#define QSEECOM_IOCTL_RECEIVE_REQ_32BIT _IO(QSEECOM_IOC_MAGIC, 5)
#define QSEECOM_IOCTL_SEND_RESP_REQ_32BIT _IO(QSEECOM_IOC_MAGIC, 6)
#define QSEECOM_IOCTL_LOAD_APP_REQ_32BIT _IOWR(QSEECOM_IOC_MAGIC, 7, struct qseecom_load_img_req_32bit)
#define QSEECOM_IOCTL_SET_MEM_PARAM_REQ_32BIT _IOWR(QSEECOM_IOC_MAGIC, 8, struct qseecom_set_sb_mem_param_req_32bit)
#define QSEECOM_IOCTL_UNLOAD_APP_REQ_32BIT _IO(QSEECOM_IOC_MAGIC, 9)
#define QSEECOM_IOCTL_GET_QSEOS_VERSION_REQ_32BIT _IOWR(QSEECOM_IOC_MAGIC, 10, struct qseecom_qseos_version_req_32bit)
#define QSEECOM_IOCTL_LOAD_EXTERNAL_ELF_REQ_32BIT _IOWR(QSEECOM_IOC_MAGIC, 13, struct qseecom_load_img_req_32bit)
#define QSEECOM_IOCTL_UNLOAD_EXTERNAL_ELF_REQ_32BIT _IO(QSEECOM_IOC_MAGIC, 14)
#define QSEECOM_IOCTL_APP_LOADED_QUERY_REQ_32BIT _IOWR(QSEECOM_IOC_MAGIC, 15, struct qseecom_qseos_app_load_query_32bit)
#define QSEECOM_IOCTL_SEND_CMD_SERVICE_REQ_32BIT _IOWR(QSEECOM_IOC_MAGIC, 16, struct qseecom_send_svc_cmd_req_32bit)
#define QSEECOM_IOCTL_CREATE_KEY_REQ_32BIT _IOWR(QSEECOM_IOC_MAGIC, 17, struct qseecom_create_key_req_32bit)
#define QSEECOM_IOCTL_WIPE_KEY_REQ_32BIT _IOWR(QSEECOM_IOC_MAGIC, 18, struct qseecom_wipe_key_req_32bit)
#define QSEECOM_IOCTL_SAVE_PARTITION_HASH_REQ_32BIT _IOWR(QSEECOM_IOC_MAGIC, 19, struct qseecom_save_partition_hash_req_32bit)
#define QSEECOM_IOCTL_IS_ES_ACTIVATED_REQ_32BIT _IOWR(QSEECOM_IOC_MAGIC, 20, struct qseecom_is_es_activated_req_32bit)
#define QSEECOM_IOCTL_SEND_MODFD_RESP_32BIT _IOWR(QSEECOM_IOC_MAGIC, 21, struct qseecom_send_modfd_listener_resp_32bit)
#define QSEECOM_IOCTL_UPDATE_KEY_USER_INFO_REQ_32BIT _IOWR(QSEECOM_IOC_MAGIC, 24, struct qseecom_update_key_userinfo_req_32bit)
#define QSEECOM_QTEEC_IOCTL_OPEN_SESSION_REQ_32BIT _IOWR(QSEECOM_IOC_MAGIC, 30, struct qseecom_qteec_modfd_req_32bit)
#define QSEECOM_QTEEC_IOCTL_CLOSE_SESSION_REQ_32BIT _IOWR(QSEECOM_IOC_MAGIC, 31, struct qseecom_qteec_req_32bit)
#define QSEECOM_QTEEC_IOCTL_INVOKE_MODFD_CMD_REQ_32BIT _IOWR(QSEECOM_IOC_MAGIC, 32, struct qseecom_qteec_modfd_req_32bit)
#define QSEECOM_QTEEC_IOCTL_REQUEST_CANCELLATION_REQ_32BIT _IOWR(QSEECOM_IOC_MAGIC, 33, struct qseecom_qteec_modfd_req_32bit)
#define QSEECOM_IOCTL_MDTP_CIPHER_DIP_REQ_32BIT _IOWR(QSEECOM_IOC_MAGIC, 34, struct qseecom_mdtp_cipher_dip_req_32bit)
#define QSEECOM_IOCTL_SEND_MODFD_CMD_64_REQ_32BIT _IOWR(QSEECOM_IOC_MAGIC, 35, struct qseecom_send_modfd_cmd_req_32bit)
#define QSEECOM_IOCTL_SEND_MODFD_RESP_64_32BIT _IOWR(QSEECOM_IOC_MAGIC, 36, struct qseecom_send_modfd_listener_resp_32bit)
#define QSEECOM_IOCTL_GET_CE_PIPE_INFO_32BIT _IOWR(QSEECOM_IOC_MAGIC, 40, struct qseecom_ce_info_req)
#define QSEECOM_IOCTL_FREE_CE_PIPE_INFO_32BIT _IOWR(QSEECOM_IOC_MAGIC, 41, struct qseecom_ce_info_req)
#define QSEECOM_IOCTL_QUERY_CE_PIPE_INFO_32BIT _IOWR(QSEECOM_IOC_MAGIC, 42, struct qseecom_ce_info_req_32bit)
#endif
