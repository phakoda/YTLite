/* Decompiled from supplied 5.2.2 arm package. VA 0x279218. FUN_00279218 */

void FUN_00279218(long param_1,long param_2,long param_3)

{
  uint uVar1;
  long lVar2;
  
  uVar1 = *(uint *)(param_1 + 4);
  for (lVar2 = 0; lVar2 < (int)uVar1; lVar2 = lVar2 + 1) {
    *(undefined8 *)(param_2 + (long)*(int *)(*(long *)(param_1 + 0x28) + lVar2 * 4) * 8) =
         *(undefined8 *)(param_3 + lVar2 * 8);
  }
                    /* WARNING: Could not recover jumptable at 0x00279260. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(&DAT_0106d4b8 + (long)(0x1f - (int)LZCOUNT(uVar1 | 1)) * 8))(param_2);
  return;
}


