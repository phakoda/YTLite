/* Decompiled from supplied 5.2.2 arm package. VA 0x245c90. FUN_00245c90 */

void FUN_00245c90(undefined4 param_1,long param_2,long param_3,int param_4,int param_5,
                 undefined2 *param_6,undefined2 *param_7,undefined4 param_8,short param_9)

{
  int iVar1;
  uint uVar2;
  long lVar3;
  
  param_2 = param_2 + (long)param_4 * 2;
  lVar3 = param_2 + (long)param_5 * -2;
  iVar1 = FUN_0024e098(lVar3,lVar3,param_5,param_8);
  uVar2 = FUN_00245da0();
  *param_7 = (short)uVar2;
  *param_6 = (short)((uint)(iVar1 << (ulong)(uVar2 & 0x1f)) >> 0x10);
  FUN_00245f78(iVar1,param_1,lVar3 + -2,param_2 + -2,param_6,param_7,param_8,0);
  param_3 = param_3 + (long)param_4 * 2;
  lVar3 = param_3 + (long)param_5 * -2;
  iVar1 = FUN_0024e098(lVar3,lVar3,param_5,param_8);
  uVar2 = FUN_00245da0();
  param_7[(int)param_9] = (short)uVar2;
  param_3 = param_3 + -2;
  param_6[(int)param_9] = (short)((uint)(iVar1 << (ulong)(uVar2 & 0x1f)) >> 0x10);
  FUN_00245f78(iVar1,param_1,param_3 + (long)param_5 * -2,param_3,param_6,param_7,param_8,
               (int)param_9);
  return;
}


