/* Decompiled from supplied 5.2.2 arm package. VA 0x24c378. FUN_0024c378 */

void FUN_0024c378(long param_1,long param_2,long param_3,long param_4,short *param_5,short *param_6)

{
  FUN_0024d0e8(param_1,param_2,param_4,param_3,(int)*param_6);
  param_4 = param_4 + ((long)((ulong)(uint)((int)*param_5 * (int)*param_6) << 0x20) >> 0x1f);
  FUN_0024d0e8(param_1 + 6,param_2 + 2,param_4,param_3 + 6,(long)param_6[1]);
  FUN_0024d19c(param_1 + 0xc,param_2 + 4,
               param_4 + ((long)((ulong)(uint)((int)param_5[1] * (int)param_6[1]) << 0x20) >> 0x1f),
               param_3 + 0xc,(long)param_6[2]);
  return;
}


