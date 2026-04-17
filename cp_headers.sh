CLEAN_HEADER=bionic/libc/kernel/tools/clean_header.py

KERNEL_PATH=kernel/sony/msm-6.6
HEADER_SRC=$KERNEL_PATH/kernel/include
HEADER_ORI=$KERNEL_PATH/common-headers/original-kernel-headers
HEADER_SAN=$KERNEL_PATH/common-headers/kernel-headers

LINUX_HEADERS="\
    linux/hdmi.h"

UAPI_HEADERS="\
    asm-generic/ioctls.h\
    drm/drm.h\
    drm/drm_fourcc.h\
    drm/drm_mode.h\
    drm/msm_drm.h\
    sound/asound.h\
    linux/esoc_ctrl.h\
    linux/fb.h\
    linux/fuse.h\
    linux/ion.h\
    linux/msm_ion.h\
    linux/msm_ion_ids.h\
    linux/msm_rmnet.h\
    linux/netlink.h\
    linux/qseecom.h\
    linux/socket.h\
    linux/v4l2-common.h\
    linux/v4l2-controls.h\
    linux/v4l2-mediabus.h\
    linux/videodev2.h\
    linux/mmc/ioctl.h\
    misc/adsp_sleepmon.h\
    sound/compress_offload.h\
    sound/compress_params.h"

TECHPACK_AUDIO_UAPI_HEADERS="\
    linux/msm_audio.h\
    linux/msm_audio_calibration.h\
    sound/audio_effects.h\
    sound/audio_slimslave.h\
    sound/devdep_params.h\
    sound/lsm_params.h\
    sound/msmcal-hwdep.h\
    sound/voice_params.h\
    sound/wcd-dsp-glink.h"

TECHPACK_CAMERA_UAPI_HEADERS="\
    media/cam_cpas.h\
    media/cam_cre.h\
    media/cam_custom.h\
    media/cam_defs.h\
    media/cam_fd.h\
    media/cam_icp.h\
    media/cam_isp.h\
    media/cam_isp_ife.h\
    media/cam_isp_sfe.h\
    media/cam_isp_tfe.h\
    media/cam_isp_vfe.h\
    media/cam_jpeg.h\
    media/cam_lrme.h\
    media/cam_ope.h\
    media/cam_req_mgr.h\
    media/cam_sensor.h\
    media/cam_sync.h\
    media/cam_tfe.h"

TECHPACK_DATAIPA_UAPI_HEADERS="\
    linux/ipa_qmi_service_v01.h\
    linux/msm_ipa.h\
    linux/rmnet_ipa_fd_ioctl.h"

TECHPACK_DISPLAY_UAPI_HEADERS="\
    display/drm/msm_drm_aiqe.h\
    display/drm/msm_drm_pp.h\
    display/drm/sde_drm.h\
    display/hdcp/msm_hdmi_hdcp_mgr.h\
    display/media/mmm_color_fmt.h\
    display/media/msm_sde_rotator.h"

TECHPACK_DSP_UAPI_HEADERS="\
    misc/fastrpc.h"

TECHPACK_GRAPHICS_UAPI_HEADERS="\
    linux/msm_kgsl.h"

TECHPACK_SECUREMSM_UAPI_HEADERS="\
    linux/compat_qcedev.h\
    linux/qcedev.h\
    linux/qcota.h\
    linux/qrng.h\
    linux/qseecom.h\
    linux/qseecom_32bit_impl.h\
    linux/qseecom_api.h\
    linux/smcinvoke.h"

TECHPACK_SMMU_PROXY_UAPI_HEADERS="\
    linux/qti-smmu-proxy.h"

TECHPACK_SPU_UAPI_HEADERS="\
    linux/spcom.h\
    linux/spss_utils.h"

TECHPACK_SYNC_FENCE_UAPI_HEADERS="\
    sync_fence/qcom_sync_file.h"

TECHPACK_SYNX_UAPI_HEADERS="\
    synx/media/synx_header.h"

TECHPACK_UBWCP_UAPI_HEADERS="\
    ubwcp_ioctl.h"

TECHPACK_VIDEO_HEADERS="\
    msm_media_info.h"

TECHPACK_VIDEO_UAPI_HEADERS="\
    vidc/media/v4l2_vidc_extensions.h"

HEADER_OVERRIDES="\
    display/media/mmm_color_fmt.h\
    linux/socket.h\
    media/msm_media_info.h"

cd ../../../..

> out/cp_headers_6.6.log

source build/envsetup.sh
lunch aosp_xqfe54-trunk_staging-userdebug

process_headers() {
    local headers=$1
    local src=$2
    local dest=$3

    for x in $headers; do
        mkdir -p $(dirname "$HEADER_ORI/$dest$x")
        cp "$HEADER_SRC/$src$x" "$HEADER_ORI/$dest$x"
        $CLEAN_HEADER -u -v -k "$HEADER_ORI" -d "$HEADER_SAN" "$dest$x" &>> out/cp_headers_6.6.log
    done
}

process_headers "$LINUX_HEADERS" "" ""

process_headers "$UAPI_HEADERS" "uapi/" ""

process_headers "$TECHPACK_AUDIO_UAPI_HEADERS" "../techpack/audio/include/uapi/audio/" ""

process_headers "$TECHPACK_CAMERA_UAPI_HEADERS" "../techpack/camera/include/uapi/camera/" ""

process_headers "$TECHPACK_DATAIPA_UAPI_HEADERS" "../techpack/dataipa/drivers/platform/msm/include/uapi/" ""

process_headers "$TECHPACK_DISPLAY_UAPI_HEADERS" "../techpack/display/include/uapi/" ""

process_headers "$TECHPACK_DSP_UAPI_HEADERS" "../techpack/dsp/include/uapi/" ""

process_headers "$TECHPACK_GRAPHICS_UAPI_HEADERS" "../techpack/graphics/include/uapi/" ""

process_headers "$TECHPACK_SECUREMSM_UAPI_HEADERS" "../techpack/securemsm/include/uapi/" ""

process_headers "$TECHPACK_SMMU_PROXY_UAPI_HEADERS" "../techpack/securemsm/smmu-proxy/include/uapi/" ""

process_headers "$TECHPACK_SPU_UAPI_HEADERS" "../techpack/spu/include/uapi/" ""

process_headers "$TECHPACK_SYNC_FENCE_UAPI_HEADERS" "../techpack/mm/sync_fence/include/uapi/" ""

process_headers "$TECHPACK_SYNX_UAPI_HEADERS" "../techpack/synx/include/uapi/" ""

process_headers "$TECHPACK_UBWCP_UAPI_HEADERS" "../techpack/mm-sys/ubwcp/include/uapi/" ""

# Some components require these internal headers
process_headers "$TECHPACK_VIDEO_HEADERS" "../techpack/video/driver/vidc/inc/" "media/"
process_headers "$TECHPACK_VIDEO_UAPI_HEADERS" "../techpack/video/include/uapi/" ""

for x in $HEADER_OVERRIDES; do \
    cp $HEADER_ORI/$x $HEADER_SAN/$x
done

echo "Copy complete!"
