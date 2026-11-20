/* Decompiled from supplied 5.2.2 arm package. VA 0x25b1e0. _av_frame_set_qp_table */

undefined8 _av_frame_set_qp_table(long param_1,long param_2,undefined4 param_3,undefined4 param_4)

{
  long lVar1;
  undefined8 uVar2;
  undefined4 *puVar3;
  undefined8 local_38;
  
  _av_buffer_unref(param_1 + 0x1d8);
  *(long *)(param_1 + 0x1d8) = param_2;
  uVar2 = *(undefined8 *)(param_2 + 8);
  *(undefined4 *)(param_1 + 0x1d0) = param_3;
  *(undefined8 *)(param_1 + 0x1c8) = uVar2;
  *(undefined4 *)(param_1 + 0x1d4) = param_4;
  _av_frame_remove_side_data(param_1,0x10);
  _av_frame_remove_side_data(param_1,0x11);
  local_38 = _av_buffer_ref(param_2);
  lVar1 = _av_frame_new_side_data_from_buf(param_1,0x11,local_38);
  if (lVar1 == 0) {
    _av_buffer_unref(&local_38);
  }
  else {
    lVar1 = _av_frame_new_side_data(param_1,0x10,8);
    if (lVar1 != 0) {
      puVar3 = *(undefined4 **)(lVar1 + 8);
      *puVar3 = param_3;
      puVar3[1] = param_4;
      return 0;
    }
  }
  return 0xfffffff4;
}


