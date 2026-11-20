/* Decompiled from supplied 5.2.2 arm package. VA 0x27bde8. FUN_0027bde8 */

void FUN_0027bde8(float param_1,long *param_2,long *param_3,int param_4,int param_5)

{
  double dVar1;
  float *pfVar2;
  undefined4 *puVar3;
  int iVar4;
  long lVar5;
  float fVar6;
  float fVar7;
  undefined4 uVar8;
  
  dVar1 = DAT_00c51e38;
  pfVar2 = (float *)*param_3;
  puVar3 = (undefined4 *)*param_2;
  for (iVar4 = 0; iVar4 < param_4; iVar4 = iVar4 + 1) {
    for (lVar5 = 0; lVar5 < param_5; lVar5 = lVar5 + 1) {
      fVar6 = *pfVar2;
      fVar7 = (float)_sinf((float)((double)fVar6 * dVar1) * 4.0);
      uVar8 = _sinf(fVar7 * param_1 + (float)((double)fVar6 * dVar1));
      *puVar3 = uVar8;
      pfVar2 = pfVar2 + 1;
      puVar3 = puVar3 + 1;
    }
  }
  return;
}


