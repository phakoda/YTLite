/* Decompiled from supplied 5.2.2 arm package. VA 0x26100c. _av_mastering_display_metadata_create_side_data */

undefined8 _av_mastering_display_metadata_create_side_data(undefined8 param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = _av_frame_new_side_data(param_1,0xb,0x58);
  if (lVar1 == 0) {
    uVar2 = 0;
  }
  else {
    _memset(*(void **)(lVar1 + 8),0,0x58);
    uVar2 = *(undefined8 *)(lVar1 + 8);
  }
  return uVar2;
}


