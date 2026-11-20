/* Decompiled from supplied 5.2.2 arm package. VA 0x2648f0. _av_opt_flag_is_set */

uint _av_opt_flag_is_set(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  uint uVar2;
  long lVar3;
  long lVar4;
  undefined8 uVar5;
  uint local_38 [2];
  
  lVar3 = _av_opt_find2(param_1,param_2,0,0,0,0);
  uVar5 = 0;
  if (lVar3 != 0) {
    uVar5 = *(undefined8 *)(lVar3 + 0x38);
  }
  lVar4 = _av_opt_find2(param_1,param_3,uVar5,0,0,0);
  uVar2 = 0;
  if ((lVar3 != 0) && (lVar4 != 0)) {
    if (*(int *)(lVar4 + 0x14) == 10) {
      iVar1 = _av_opt_get_int(param_1,param_2,0,local_38);
      uVar2 = 0;
      if (-1 < iVar1) {
        uVar2 = *(uint *)(lVar4 + 0x18) & local_38[0];
      }
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}


