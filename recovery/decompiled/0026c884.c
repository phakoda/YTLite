/* Decompiled from supplied 5.2.2 arm package. VA 0x26c884. _av_stereo3d_create_side_data */

undefined8 _av_stereo3d_create_side_data(undefined8 param_1)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  
  lVar1 = _av_frame_new_side_data(param_1,2,0xc);
  if (lVar1 == 0) {
    uVar2 = 0;
  }
  else {
    puVar3 = *(undefined8 **)(lVar1 + 8);
    *(undefined4 *)(puVar3 + 1) = 0;
    *puVar3 = 0;
    uVar2 = *(undefined8 *)(lVar1 + 8);
  }
  return uVar2;
}


