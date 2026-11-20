/* Decompiled from supplied 5.2.2 arm package. VA 0x268c18. _av_find_best_pix_fmt_of_2 */

uint _av_find_best_pix_fmt_of_2
               (uint param_1,uint param_2,undefined4 param_3,int param_4,uint *param_5)

{
  undefined **ppuVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined1 auStack_68 [4];
  undefined1 auStack_64 [4];
  
  ppuVar1 = (undefined **)0x0;
  if (param_2 < 0xc6) {
    ppuVar1 = &PTR_s_yuv420p_01065540 + (long)(int)param_2 * 0x14;
  }
  uVar5 = param_2;
  if (param_1 < 0xc6) {
    if ((&PTR_s_yuv420p_01065540 + (long)(int)param_1 * 0x14 != (undefined **)0x0) &&
       (uVar5 = param_1, ppuVar1 != (undefined **)0x0)) {
      if (param_5 == (uint *)0x0) {
        uVar5 = 0xffffffff;
      }
      else {
        uVar5 = ~*param_5;
      }
      uVar4 = uVar5 & 0xfffffff7;
      if (param_4 != 0) {
        uVar4 = uVar5;
      }
      iVar2 = FUN_002688d0(param_1,param_3,auStack_64,uVar4);
      iVar3 = FUN_002688d0(param_2,param_3,auStack_68,uVar4);
      if (iVar2 == iVar3) {
        iVar2 = _av_get_padded_bits_per_pixel(ppuVar1);
        iVar3 = _av_get_padded_bits_per_pixel(&PTR_s_yuv420p_01065540 + (long)(int)param_1 * 0x14);
        if (iVar2 == iVar3) {
          uVar5 = param_2;
          if ((byte)(&DAT_01065548)[(long)(int)param_1 * 0xa0] <= *(byte *)(ppuVar1 + 1)) {
            uVar5 = param_1;
          }
        }
        else {
          uVar5 = param_2;
          if (iVar3 <= iVar2) {
            uVar5 = param_1;
          }
        }
      }
      else {
        uVar5 = param_2;
        if (iVar3 <= iVar2) {
          uVar5 = param_1;
        }
      }
    }
  }
  if (param_5 != (uint *)0x0) {
    uVar4 = _av_get_pix_fmt_loss(uVar5,param_3,param_4);
    *param_5 = uVar4;
  }
  return uVar5;
}


