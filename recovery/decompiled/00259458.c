/* Decompiled from supplied 5.2.2 arm package. VA 0x259458. FUN_00259458 */

int FUN_00259458(long *param_1,long param_2)

{
  undefined8 uVar1;
  long lVar2;
  int iVar3;
  undefined8 local_40;
  long local_38;
  
  iVar3 = FUN_00259568(&local_38);
  if (-1 < iVar3) {
    do {
      lVar2 = local_38;
      if ((**(char **)(param_2 + 0x10) != '-') && (**(char **)(param_2 + 0x10) != '+')) {
        *param_1 = local_38;
        return 0;
      }
      iVar3 = FUN_00259568(&local_40,param_2);
      uVar1 = local_40;
      if (iVar3 < 0) {
        _av_expr_free(lVar2);
        return iVar3;
      }
      local_38 = FUN_00259518(0x15,lVar2,local_40);
    } while (local_38 != 0);
    _av_expr_free(lVar2);
    _av_expr_free(uVar1);
    iVar3 = -0xc;
  }
  return iVar3;
}


