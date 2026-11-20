/* Decompiled from supplied 5.2.2 arm package. VA 0x27bf38. FUN_0027bf38 */

void FUN_0027bf38(float param_1,long param_2,long param_3,int param_4,int param_5)

{
  double dVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  float fVar6;
  undefined4 uVar7;
  float fVar8;
  
  dVar1 = DAT_00c51e38;
  for (lVar2 = 0; lVar2 < param_5; lVar2 = lVar2 + 1) {
    lVar3 = *(long *)(param_3 + lVar2 * 8);
    lVar4 = *(long *)(param_2 + lVar2 * 8);
    for (lVar5 = 0; lVar5 < param_4; lVar5 = lVar5 + 1) {
      fVar8 = (float)((double)*(float *)(lVar3 + lVar5 * 4) * dVar1);
      fVar6 = (float)_sinf(fVar8 * 4.0);
      uVar7 = _sinf(fVar6 * param_1 + fVar8);
      *(undefined4 *)(lVar4 + lVar5 * 4) = uVar7;
    }
  }
  return;
}


