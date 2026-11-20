/* Decompiled from supplied 5.2.2 arm package. VA 0x279644. FUN_00279644 */

void FUN_00279644(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1[1];
  iVar2 = *param_1;
  *param_1 = param_1[2] + iVar2;
  param_1[1] = param_1[3] + iVar1;
  param_1[2] = iVar2 - param_1[2];
  param_1[3] = iVar1 - param_1[3];
  return;
}


