/* Decompiled from supplied 5.2.2 arm package. VA 0x25eef4. _av_image_check_sar */

undefined4 _av_image_check_sar(undefined4 param_1,undefined4 param_2,long param_3)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined4 uVar4;
  int iVar5;
  
  uVar4 = 0xffffffea;
  iVar2 = (int)param_3;
  if ((((-1 < iVar2) && (iVar5 = (int)((ulong)param_3 >> 0x20), 0 < iVar5)) &&
      (uVar4 = 0, iVar2 != 0)) && (iVar2 != iVar5)) {
    if (iVar2 < iVar5) {
      lVar1 = (long)iVar2;
      lVar3 = param_3 >> 0x20;
      param_2 = param_1;
    }
    else {
      lVar3 = (long)iVar2;
      lVar1 = param_3 >> 0x20;
    }
    lVar1 = _av_rescale_rnd(param_2,lVar1,lVar3,0);
    uVar4 = 0;
    if (lVar1 < 1) {
      uVar4 = 0xffffffea;
    }
  }
  return uVar4;
}


