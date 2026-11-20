/* Decompiled from supplied 5.2.2 arm package. VA 0x25e8e8. _av_image_fill_linesizes */

void _av_image_fill_linesizes(undefined8 *param_1,undefined4 param_2,undefined4 param_3)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  undefined4 local_78 [4];
  undefined4 local_68 [4];
  long local_58;
  
  lVar3 = *(long *)PTR____stack_chk_guard_01060708;
  local_58 = lVar3;
  lVar1 = _av_pix_fmt_desc_get(param_2);
  *param_1 = 0;
  param_1[1] = 0;
  if ((lVar1 == 0) || ((*(byte *)(lVar1 + 0x10) >> 3 & 1) != 0)) {
    uVar2 = 0xffffffea;
  }
  else {
    _av_image_fill_max_pixsteps(local_68,local_78,lVar1);
    for (lVar4 = 0; lVar4 < 4; lVar4 = lVar4 + 1) {
      uVar2 = FUN_0025e874(param_3,local_68[lVar4],local_78[lVar4],lVar1);
      if ((int)uVar2 < 0) goto LAB_0025e990;
      *(int *)((long)param_1 + lVar4 * 4) = (int)uVar2;
    }
    uVar2 = 0;
  }
LAB_0025e990:
  if (lVar3 != local_58) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail(uVar2);
  }
  return;
}


