/* Decompiled from supplied 5.2.2 arm package. VA 0x25ac08. FUN_0025ac08 */

void FUN_0025ac08(long param_1,long param_2,long param_3,long param_4,int param_5,uint param_6)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  uint uVar6;
  long lVar7;
  uint uVar8;
  long lVar9;
  long lVar10;
  
  if (param_6 == 0) {
    lVar3 = 0;
  }
  else {
    lVar3 = (long)(1 << (ulong)(param_6 - 1 & 0x1f));
  }
  param_1 = param_1 + (long)param_5 * 2;
  param_4 = param_4 + (long)param_5 * 4;
  lVar5 = (long)(param_5 + -1);
  for (lVar4 = (long)-param_5; lVar4 < 0; lVar4 = lVar4 + 1) {
    lVar7 = (long)*(int *)(param_3 + lVar5 * 4);
    lVar9 = (long)*(int *)(param_4 + lVar4 * 4);
    lVar10 = (long)*(int *)(param_4 + lVar5 * 4);
    lVar2 = (long)*(int *)(param_2 + (long)param_5 * 4 + lVar4 * 4);
    uVar8 = (uint)(lVar3 + ((0x40000000 - lVar9 * lVar7) + lVar10 * lVar2 >> 0x1f) >>
                  ((ulong)param_6 & 0x3f));
    uVar6 = (uint)(lVar3 + (lVar10 * lVar7 + lVar9 * lVar2 + 0x40000000 >> 0x1f) >>
                  ((ulong)param_6 & 0x3f));
    uVar1 = (int)uVar8 >> 0x1f ^ 0x7fff;
    if (uVar8 + 0x8000 >> 0x10 == 0) {
      uVar1 = uVar8;
    }
    *(short *)(param_1 + lVar4 * 2) = (short)uVar1;
    uVar1 = (int)uVar6 >> 0x1f ^ 0x7fff;
    if (uVar6 + 0x8000 >> 0x10 == 0) {
      uVar1 = uVar6;
    }
    *(short *)(param_1 + lVar5 * 2) = (short)uVar1;
    lVar5 = lVar5 + -1;
  }
  return;
}


