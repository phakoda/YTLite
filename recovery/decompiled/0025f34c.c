/* Decompiled from supplied 5.2.2 arm package. VA 0x25f34c. _av_image_get_buffer_size */

void _av_image_get_buffer_size(undefined4 param_1,int param_2,int param_3,int param_4)

{
  long lVar1;
  ulong uVar2;
  long lVar3;
  undefined1 auStack_78 [16];
  undefined1 auStack_68 [32];
  long local_48;
  
  lVar3 = *(long *)PTR____stack_chk_guard_01060708;
  local_48 = lVar3;
  lVar1 = _av_pix_fmt_desc_get();
  if (lVar1 == 0) {
    uVar2 = 0xffffffea;
  }
  else {
    uVar2 = _av_image_check_size(param_2,param_3,0,0);
    if (-1 < (int)uVar2) {
      if ((*(byte *)(lVar1 + 0x10) >> 6 & 1) == 0) {
        uVar2 = _av_image_fill_arrays(auStack_68,auStack_78,0,param_1,param_2,param_3,param_4);
      }
      else {
        uVar2 = (ulong)(((param_2 + param_4) - 1U & -param_4) * param_3);
      }
    }
  }
  if (lVar3 == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(uVar2);
}


