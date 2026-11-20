/* Decompiled from supplied 5.2.2 arm package. VA 0x24b530. FUN_0024b530 */

void FUN_0024b530(short *param_1,void *param_2,int param_3,int param_4,int param_5,
                 undefined8 param_6,undefined4 param_7)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  ushort uVar5;
  int iVar6;
  bool bVar7;
  short sVar8;
  uint uVar9;
  undefined1 *puVar10;
  size_t sVar11;
  short sVar12;
  long lVar13;
  undefined2 *puVar14;
  undefined2 *puVar15;
  long lVar16;
  int aiStack_200dc [16338];
  undefined2 auStack_10192 [32773];
  undefined1 auStack_188 [12];
  undefined1 auStack_17c [160];
  int aiStack_dc [5];
  undefined1 auStack_c8 [82];
  undefined1 auStack_76 [12];
  undefined2 auStack_6a [5];
  
  lVar16 = *(long *)PTR____stack_chk_guard_01060708;
  iVar2 = param_5 * 0x4000 + -0x8000 >> 0x10;
  iVar3 = iVar2 + 2;
  if (param_3 <= iVar2 + 0x52) {
    iVar3 = param_3 + -0x51;
  }
  iVar6 = 0;
  if ((iVar2 + 0xfffeU & 0x8000) == 0) {
    iVar6 = (int)(short)(iVar2 + 0xfffeU);
  }
  uVar1 = (iVar3 - iVar6) + 1;
  iVar2 = (int)(short)uVar1;
  FUN_0024a8d0(aiStack_dc,(void *)((long)param_2 + (long)iVar6 * 2),
               (int)(short)((short)uVar1 + 0x4f),(void *)((long)param_2 + (long)param_4 * 2),0x50);
  uVar9 = (*DAT_0191b7d8)(aiStack_dc,iVar2);
  sVar8 = 0;
  bVar7 = (uVar9 & 0xffff0000) != 0;
  lVar13 = (ulong)bVar7 << 4;
  uVar4 = (uint)lVar13;
  if ((0xff00 << lVar13 & uVar9) != 0) {
    uVar4 = (uint)bVar7 << 4 | 8;
  }
  if ((0xf0 << (ulong)uVar4 & uVar9) != 0) {
    uVar4 = uVar4 | 4;
  }
  uVar5 = (ushort)uVar4;
  if ((0xc << (ulong)uVar4 & uVar9) != 0) {
    uVar5 = (ushort)uVar4 | 2;
  }
  if ((2 << (ulong)(uint)(int)(short)uVar5 & uVar9) != 0) {
    uVar5 = uVar5 + 1;
  }
  if ((1 << (ulong)((int)(short)uVar5 & 0x1f) & uVar9) != 0) {
    uVar5 = uVar5 + 1;
  }
  if ((uint)(int)(short)uVar5 < 0x10) {
    for (; sVar8 < iVar2; sVar8 = sVar8 + 1) {
      auStack_10192[(long)sVar8 + 0x8000] = (short)aiStack_dc[sVar8];
    }
  }
  else {
    for (; sVar8 < iVar2; sVar8 = sVar8 + 1) {
      auStack_10192[(long)sVar8 + 0x8000] =
           (short)(aiStack_dc[sVar8] >> ((int)(short)uVar5 - 0xfU & 0x1f));
    }
  }
  for (lVar13 = (long)(short)(((short)iVar3 + 1) - (short)iVar6); lVar13 < 5; lVar13 = lVar13 + 1) {
    auStack_10192[lVar13 + 0x8000] = 0;
  }
  FUN_00248a78(auStack_c8,auStack_10192 + 0x8000);
  sVar8 = FUN_0024eacc(auStack_c8,-(uVar1 >> 0xd & 1) & 0xffff0000 | (uVar1 & 0x3fff) << 2);
  iVar2 = sVar8 + 3 >> 2;
  *param_1 = (short)iVar6 * 4 + sVar8 + 4;
  uVar1 = iVar6 + iVar2 + 0xfffd;
  if ((int)(uVar1 * 0x10000) < 0) {
    iVar3 = -(int)(short)uVar1;
    thunk_FUN_0024de70(auStack_188,0,(int)(short)iVar3);
    puVar10 = auStack_188 + (long)iVar3 * 2;
    uVar1 = (int)(short)uVar1 + 0x56;
    sVar11 = -(ulong)(uVar1 >> 0x1f) & 0xfffffffe00000000 | (ulong)uVar1 << 1;
  }
  else {
    iVar3 = (int)(uVar1 * 0x10000 + 0x560000) >> 0x10;
    param_2 = (void *)((long)param_2 + ((long)((ulong)uVar1 << 0x30) >> 0x2f));
    iVar6 = iVar3 - param_3;
    if (iVar6 != 0 && param_3 <= iVar3) {
      uVar1 = 0x56 - iVar6;
      ___memcpy_chk(auStack_188,param_2,
                    -(ulong)(uVar1 >> 0x1f) & 0xfffffffe00000000 | (ulong)uVar1 << 1,0xac);
      thunk_FUN_0024de70(auStack_188 + (long)(int)uVar1 * 2,0,(int)(short)iVar6);
      goto LAB_0024b7bc;
    }
    puVar10 = auStack_188;
    sVar11 = 0xac;
  }
  _memcpy(puVar10,param_2,sVar11);
LAB_0024b7bc:
  puVar14 = auStack_6a;
  puVar15 = (undefined2 *)(&DAT_00c4f61e + (long)(short)((short)iVar2 * 4 - sVar8) * 0xe);
  for (sVar12 = 0; sVar12 < 7; sVar12 = sVar12 + 1) {
    *puVar14 = *puVar15;
    puVar14 = puVar14 + -1;
    puVar15 = puVar15 + 1;
  }
  FUN_0024e304(auStack_17c,auStack_188,auStack_76,7,0x50);
  FUN_0024e3f4(param_6,auStack_188,param_7,0x8000,0x10,0x50);
  if (*(long *)PTR____stack_chk_guard_01060708 == lVar16) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


