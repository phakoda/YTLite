/* Decompiled from supplied 5.2.2 arm package. VA 0x243a4c. _shine_loop_initialise */

void _shine_loop_initialise(long param_1)

{
  long lVar1;
  double dVar2;
  int *piVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  double dVar7;
  
  dVar2 = DAT_00c4d5f8;
  lVar5 = 0;
  lVar6 = 0;
  do {
    dVar7 = (double)_exp2((double)(int)lVar6 * 0.25);
    *(double *)(&LAB_00009e28 + lVar5 * 8 + param_1) = dVar7;
    lVar1 = lVar5 * 4;
    lVar6 = lVar6 + 1;
    lVar5 = lVar5 + -1;
    iVar4 = 0x7fffffff;
    if (dVar7 + dVar7 <= dVar2) {
      iVar4 = (int)(dVar7 + dVar7 + 0.5);
    }
    *(int *)(&LAB_00009e28 + lVar1 + param_1 + 0x204) = iVar4;
    dVar7 = DAT_00c4d600;
  } while (lVar6 != 0x80);
  lVar6 = -10000;
  iVar4 = 9999;
  piVar3 = (int *)(param_1 + 0x13c6c);
  do {
    lVar6 = lVar6 + 1;
    *piVar3 = (int)(SQRT((double)iVar4 * SQRT((double)iVar4)) + dVar7 + 0.5);
    iVar4 = iVar4 + -1;
    piVar3 = piVar3 + -1;
  } while (lVar6 != 0);
  return;
}


