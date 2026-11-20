/* Decompiled from supplied 5.2.2 arm package. VA 0x25b410. _av_frame_get_qp_table */

undefined8 _av_frame_get_qp_table(long param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined8 uVar1;
  long lVar2;
  undefined4 *puVar3;
  
  *param_2 = 0;
  *param_3 = 0;
  lVar2 = *(long *)(param_1 + 0x1d8);
  if (lVar2 == 0) {
    lVar2 = _av_frame_get_side_data(param_1,0x10);
    if (lVar2 != 0) {
      puVar3 = *(undefined4 **)(lVar2 + 8);
      lVar2 = _av_frame_get_side_data(param_1,0x11);
      if (lVar2 != 0) {
        *param_2 = *puVar3;
        *param_3 = puVar3[1];
        lVar2 = *(long *)(lVar2 + 0x20);
        if (lVar2 != 0) goto LAB_0025b44c;
      }
    }
    uVar1 = 0;
  }
  else {
    *param_2 = *(undefined4 *)(param_1 + 0x1d0);
    *param_3 = *(undefined4 *)(param_1 + 0x1d4);
LAB_0025b44c:
    uVar1 = *(undefined8 *)(lVar2 + 8);
  }
  return uVar1;
}


