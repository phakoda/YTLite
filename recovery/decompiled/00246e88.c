/* Decompiled from supplied 5.2.2 arm package. VA 0x246e88. FUN_00246e88 */

void FUN_00246e88(undefined4 *param_1,int *param_2,long param_3,int param_4,int param_5,int param_6,
                 undefined4 param_7)

{
  long lVar1;
  undefined4 uVar2;
  int iVar3;
  
  lVar1 = param_3 + (long)((param_5 - param_6) - param_4) * 2;
  uVar2 = FUN_0024e098(param_3 + (long)(param_5 - param_6) * 2,lVar1,param_6,param_7);
  *param_1 = uVar2;
  iVar3 = FUN_0024e098(lVar1,lVar1,param_6,param_7);
  *param_2 = iVar3;
  if (iVar3 == 0) {
    *param_1 = 0;
    *param_2 = 1;
  }
  return;
}


