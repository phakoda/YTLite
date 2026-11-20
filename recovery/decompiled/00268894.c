/* Decompiled from supplied 5.2.2 arm package. VA 0x268894. _av_get_pix_fmt_loss */

int _av_get_pix_fmt_loss(undefined8 param_1,undefined8 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_14;
  
  uVar2 = 0xffffffff;
  if (param_3 == 0) {
    uVar2 = 0xfffffff7;
  }
  iVar1 = FUN_002688d0(param_1,param_2,&local_14,uVar2);
  if (-1 < iVar1) {
    iVar1 = local_14;
  }
  return iVar1;
}


