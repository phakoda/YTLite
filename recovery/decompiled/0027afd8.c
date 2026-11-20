/* Decompiled from supplied 5.2.2 arm package. VA 0x27afd8. _av_video_enc_params_create_side_data */

long _av_video_enc_params_create_side_data(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  long lVar1;
  undefined4 local_38 [2];
  long local_30;
  long local_28;
  
  local_30 = _av_video_enc_params_alloc(param_2,param_3,local_38);
  if (local_30 != 0) {
    local_28 = _av_buffer_create(local_30,local_38[0],0,0,0);
    if (local_28 == 0) {
      _av_freep(&local_30);
    }
    else {
      lVar1 = _av_frame_new_side_data_from_buf(param_1,0x15,local_28);
      if (lVar1 != 0) {
        return local_30;
      }
      _av_buffer_unref(&local_28);
    }
  }
  return 0;
}


