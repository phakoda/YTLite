/* Decompiled from supplied 5.2.2 arm package. VA 0x25e7d4. _av_image_get_linesize */

void _av_image_get_linesize(undefined8 param_1,undefined4 param_2,int param_3)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  undefined4 auStack_68 [4];
  undefined4 auStack_58 [4];
  long local_48;
  
  lVar3 = *(long *)PTR____stack_chk_guard_01060708;
  local_48 = lVar3;
  lVar1 = _av_pix_fmt_desc_get();
  if ((lVar1 == 0) || ((*(byte *)(lVar1 + 0x10) >> 3 & 1) != 0)) {
    uVar2 = 0xffffffea;
  }
  else {
    _av_image_fill_max_pixsteps(auStack_58,auStack_68,lVar1);
    uVar2 = FUN_0025e874(param_2,auStack_58[param_3],auStack_68[param_3],lVar1);
  }
  if (lVar3 == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(uVar2);
}


