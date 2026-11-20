/* Decompiled from supplied 5.2.2 arm package. VA 0x2578f8. _av_downmix_info_update_side_data */

undefined8 _av_downmix_info_update_side_data(undefined8 param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = _av_frame_get_side_data(param_1,4);
  if ((lVar1 == 0) && (lVar1 = _av_frame_new_side_data(param_1,4,0x30), lVar1 == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined8 *)(lVar1 + 8);
  }
  return uVar2;
}


