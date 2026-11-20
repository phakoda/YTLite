/* Decompiled from supplied 5.2.2 arm package. VA 0x27bff4. FUN_0027bff4 */

void FUN_0027bff4(float param_1,long param_2,long param_3,int param_4,int param_5)

{
  double dVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  double dVar6;
  undefined8 uVar7;
  double dVar8;
  
  dVar1 = DAT_00c51e38;
  for (lVar2 = 0; lVar2 < param_5; lVar2 = lVar2 + 1) {
    lVar3 = *(long *)(param_3 + lVar2 * 8);
    lVar4 = *(long *)(param_2 + lVar2 * 8);
    for (lVar5 = 0; lVar5 < param_4; lVar5 = lVar5 + 1) {
      dVar8 = *(double *)(lVar3 + lVar5 * 8) * dVar1;
      dVar6 = (double)_sin(dVar8 * 4.0);
      uVar7 = _sin(dVar8 + (double)param_1 * dVar6);
      *(undefined8 *)(lVar4 + lVar5 * 8) = uVar7;
    }
  }
  return;
}


