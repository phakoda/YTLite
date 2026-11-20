/* Decompiled from supplied 5.2.2 arm package. VA 0x25b3b4. _av_frame_new_side_data */

long _av_frame_new_side_data(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  long lVar1;
  undefined8 local_28;
  
  local_28 = _av_buffer_alloc(param_3);
  lVar1 = _av_frame_new_side_data_from_buf(param_1,param_2,local_28);
  if (lVar1 == 0) {
    _av_buffer_unref(&local_28);
  }
  return lVar1;
}


