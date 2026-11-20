/* Decompiled from supplied 5.2.2 arm package. VA 0x2587f8. FUN_002587f8 */

undefined8 FUN_002587f8(int *param_1,long param_2,int param_3,int param_4)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  
  uVar2 = 0xffffffea;
  if (((param_1 != (int *)0x0) && (param_2 != 0)) && (param_3 != 0)) {
    lVar3 = 0;
    while ((lVar3 < 3 && *param_1 != param_4 && (*(long *)(param_1 + lVar3 * 2 + 8) != 0))) {
      FUN_002587f8(*(long *)(param_1 + lVar3 * 2 + 8),param_2,param_3,param_4);
      lVar3 = lVar3 + 1;
    }
    if ((*param_1 == param_4) && (iVar1 = param_1[4], iVar1 < param_3)) {
      uVar2 = 0;
      *(int *)(param_2 + (long)iVar1 * 4) = *(int *)(param_2 + (long)iVar1 * 4) + 1;
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}


