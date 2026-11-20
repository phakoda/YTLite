/* Decompiled from supplied 5.2.2 arm package. VA 0x260030. FUN_00260030 */

undefined1  [16] FUN_00260030(long param_1,long param_2,int param_3)

{
  long lVar1;
  double dVar2;
  undefined1 auVar3 [16];
  
  dVar2 = 0.0;
  for (lVar1 = 0; lVar1 <= param_3; lVar1 = lVar1 + 1) {
    dVar2 = dVar2 + *(double *)(param_2 + lVar1 * 8) *
                    *(double *)(&DAT_00002880 + lVar1 * 8 + param_1 + (long)param_3 * 0x100);
  }
  auVar3._8_8_ = 0;
  auVar3._0_8_ = dVar2;
  return auVar3;
}


