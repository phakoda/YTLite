/* Decompiled from supplied 5.2.2 arm package. VA 0x27be94. FUN_0027be94 */

void FUN_0027be94(float param_1,long *param_2,long *param_3,int param_4,int param_5)

{
  double dVar1;
  int iVar2;
  double *pdVar3;
  undefined8 *puVar4;
  long lVar5;
  double dVar6;
  double dVar7;
  undefined8 uVar8;
  
  dVar1 = DAT_00c51e38;
  pdVar3 = (double *)*param_3;
  puVar4 = (undefined8 *)*param_2;
  for (iVar2 = 0; iVar2 < param_4; iVar2 = iVar2 + 1) {
    for (lVar5 = 0; lVar5 < param_5; lVar5 = lVar5 + 1) {
      dVar6 = *pdVar3;
      dVar7 = (double)_sin(dVar6 * dVar1 * 4.0);
      uVar8 = _sin(dVar6 * dVar1 + (double)param_1 * dVar7);
      *puVar4 = uVar8;
      pdVar3 = pdVar3 + 1;
      puVar4 = puVar4 + 1;
    }
  }
  return;
}


