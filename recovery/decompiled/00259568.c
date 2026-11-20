/* Decompiled from supplied 5.2.2 arm package. VA 0x259568. FUN_00259568 */

int FUN_00259568(long *param_1,long param_2)

{
  char cVar1;
  undefined8 uVar2;
  long lVar3;
  int iVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined8 local_50;
  long local_48;
  
  iVar4 = FUN_00259644(&local_48);
  if (-1 < iVar4) {
    do {
      lVar3 = local_48;
      pcVar5 = *(char **)(param_2 + 0x10);
      if ((*pcVar5 != '/') && (*pcVar5 != '*')) {
        *param_1 = local_48;
        return 0;
      }
      *(char **)(param_2 + 0x10) = pcVar5 + 1;
      cVar1 = *pcVar5;
      iVar4 = FUN_00259644(&local_50,param_2);
      uVar2 = local_50;
      if (iVar4 < 0) {
        _av_expr_free(lVar3);
        return iVar4;
      }
      uVar6 = 0x13;
      if (cVar1 != '*') {
        uVar6 = 0x14;
      }
      local_48 = FUN_00259518(uVar6,lVar3,local_50);
    } while (local_48 != 0);
    _av_expr_free(lVar3);
    _av_expr_free(uVar2);
    iVar4 = -0xc;
  }
  return iVar4;
}


