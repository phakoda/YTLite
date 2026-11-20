/* Decompiled from supplied 5.2.2 arm package. VA 0x270a38. FUN_00270a38 */

void FUN_00270a38(long param_1,long param_2,undefined8 *param_3)

{
  uint uVar1;
  undefined8 *puVar2;
  long lVar3;
  undefined8 uVar4;
  
  uVar1 = *(uint *)(param_1 + 4);
  for (lVar3 = 0; lVar3 < (int)uVar1; lVar3 = lVar3 + 1) {
    uVar4 = *param_3;
    puVar2 = (undefined8 *)(param_2 + (long)*(int *)(*(long *)(param_1 + 0x28) + lVar3 * 4) * 0x10);
    puVar2[1] = param_3[1];
    *puVar2 = uVar4;
    param_3 = param_3 + 2;
  }
                    /* WARNING: Could not recover jumptable at 0x00270a80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(&DAT_0106d398 + (long)(0x1f - (int)LZCOUNT(uVar1 | 1)) * 8))(param_2);
  return;
}


