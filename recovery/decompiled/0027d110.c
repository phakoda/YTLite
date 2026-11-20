/* Decompiled from supplied 5.2.2 arm package. VA 0x27d110. FUN_0027d110 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0027d110(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  long lVar3;
  undefined4 uVar4;
  long lVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  
  lVar5 = *(long *)(*(long *)(param_1 + 0x10) + 0x48);
  *(double *)(lVar5 + 0x38) = 1.0 / *(double *)(lVar5 + 0x30);
  dVar6 = (double)_exp2(*(undefined8 *)(lVar5 + 0x18));
  *(double *)(lVar5 + 0x78) = dVar6 + -1.0;
  dVar9 = *(double *)(lVar5 + 0x48);
  *(undefined8 *)(lVar5 + 0xa0) = *(undefined8 *)(lVar5 + 0x60);
  dVar7 = DAT_00c537b0;
  *(int *)(lVar5 + 0x80) = (int)dVar9;
  *(double *)(lVar5 + 0x68) = SQRT((dVar6 + -1.0) * 0.5);
  dVar6 = *(double *)(lVar5 + 0x58) * 0.5;
  dVar8 = dVar9 - dVar6;
  dVar9 = dVar9 + dVar6;
  *(double *)(lVar5 + 0x70) = (1.0 - *(double *)(lVar5 + 0x40)) * 0.5;
  uVar2 = _UNK_00c537c8;
  uVar1 = _DAT_00c537c0;
  dVar6 = dVar8;
  if (dVar8 <= 1.0) {
    dVar6 = 1.0;
  }
  dVar10 = dVar9;
  if (dVar7 < dVar9) {
    dVar10 = dVar7;
  }
  dVar7 = dVar6 - (dVar9 - dVar10);
  *(double *)(lVar5 + 0x90) = dVar7;
  *(double *)(lVar5 + 0x98) = (dVar10 - (dVar8 - dVar6)) - dVar7;
  uVar4 = *(undefined4 *)(param_1 + 0x40);
  *(undefined8 *)(lVar5 + 0xc0) = uVar2;
  *(undefined8 *)(lVar5 + 0xb8) = uVar1;
  *(undefined4 *)(lVar5 + 0xb0) = uVar4;
  lVar3 = _av_calloc((long)*(int *)(param_1 + 0xc4),0x20);
  uVar4 = 0xfffffff4;
  if (lVar3 != 0) {
    uVar4 = 0;
  }
  *(long *)(lVar5 + 0xd0) = lVar3;
  return uVar4;
}


