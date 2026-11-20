/* Decompiled from supplied 5.2.2 arm package. VA 0x2459fc. FUN_002459fc */

void FUN_002459fc(long param_1,long param_2,long param_3,int *param_4,int param_5,int param_6,
                 undefined4 param_7)

{
  int iVar1;
  int iVar2;
  long lVar3;
  int iVar4;
  long lVar5;
  int iVar6;
  
  lVar3 = param_1 + (long)param_5 * 2;
  param_2 = param_2 + (long)param_5 * -2;
  iVar6 = param_5 * 0x10000 + -0x40000;
  iVar4 = 0x28 - param_5;
  for (lVar5 = (long)param_5; lVar5 <= param_6; lVar5 = lVar5 + 1) {
    iVar2 = iVar6 >> 0x10;
    iVar1 = FUN_0024e098(param_1,param_2,iVar2,param_7);
    *param_4 = iVar1;
    iVar1 = FUN_0024e098(param_1 + (long)iVar2 * 2,param_3,4,param_7);
    *param_4 = *param_4 + iVar1;
    param_3 = param_3 + (long)((int)lVar5 - iVar2) * 2;
    iVar2 = FUN_0024e098(lVar3,param_2,iVar4,param_7);
    lVar3 = lVar3 + 2;
    iVar6 = iVar6 + 0x10000;
    param_2 = param_2 + -2;
    *param_4 = *param_4 + iVar2;
    iVar4 = iVar4 + -1;
    param_4 = param_4 + 1;
  }
  return;
}


