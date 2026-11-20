/* Decompiled from supplied 5.2.2 arm package. VA 0x259644. FUN_00259644 */

int FUN_00259644(long *param_1,long param_2)

{
  undefined8 uVar1;
  int iVar2;
  long lVar3;
  undefined8 local_48;
  long local_40;
  uint local_38;
  uint local_34;
  
  iVar2 = FUN_00259754(&local_40,param_2,&local_34);
  if (-1 < iVar2) {
    while (lVar3 = local_40, **(char **)(param_2 + 0x10) == '^') {
      *(char **)(param_2 + 0x10) = *(char **)(param_2 + 0x10) + 1;
      iVar2 = FUN_00259754(&local_48,param_2,&local_38);
      uVar1 = local_48;
      if (iVar2 < 0) {
        _av_expr_free(lVar3);
        return iVar2;
      }
      local_40 = FUN_00259518(0x12,lVar3,local_48);
      if (local_40 == 0) {
        _av_expr_free(lVar3);
        _av_expr_free(uVar1);
        return -0xc;
      }
      lVar3 = *(long *)(local_40 + 0x28);
      if (lVar3 != 0) {
        *(double *)(lVar3 + 8) = *(double *)(lVar3 + 8) * (double)(int)(local_38 | 1);
      }
    }
    if (local_40 != 0) {
      *(double *)(local_40 + 8) = *(double *)(local_40 + 8) * (double)(int)(local_34 | 1);
    }
    iVar2 = 0;
    *param_1 = local_40;
  }
  return iVar2;
}


