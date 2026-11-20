/* Decompiled from supplied 5.2.2 arm package. VA 0x24c634. FUN_0024c634 */

/* WARNING: Removing unreachable block (ram,0x0024c8ec) */

void FUN_0024c634(long param_1,long param_2,undefined8 param_3,long param_4,undefined8 param_5)

{
  uint uVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  ulong uVar6;
  undefined2 *puVar7;
  int iVar8;
  long lVar9;
  short sVar10;
  int iVar11;
  undefined1 auStack_262 [20];
  undefined1 auStack_24e [212];
  undefined1 auStack_17a [20];
  short local_166 [116];
  undefined2 auStack_7e [15];
  
  uVar6 = (*DAT_0191b7d0)(param_3,(int)*(short *)(param_1 + 0xe));
  uVar1 = (uint)(uVar6 >> 0xb) & 0x10;
  uVar4 = (uint)uVar6;
  if ((0xff00 << (ulong)uVar1 & uVar4) != 0) {
    uVar1 = uVar1 | 8;
  }
  if ((0xf0 << (ulong)uVar1 & uVar4) != 0) {
    uVar1 = uVar1 | 4;
  }
  if ((0xc << (ulong)uVar1 & uVar4) != 0) {
    uVar1 = uVar1 | 2;
  }
  if ((2 << (ulong)(uint)(int)(short)uVar1 & uVar4) != 0) {
    uVar1 = (int)(short)uVar1 + 1;
  }
  if ((1 << (ulong)((int)(short)uVar1 & 0x1f) & uVar4) != 0) {
    uVar1 = (int)(short)uVar1 + 1;
  }
  uVar1 = (int)(uVar1 * 0x10000 + -0xc0000) >> 0x10;
  uVar4 = 0;
  if (-1 < (int)uVar1) {
    uVar4 = uVar1;
  }
  puVar7 = auStack_7e;
  for (lVar9 = 0x14; lVar9 != -2; lVar9 = lVar9 + -2) {
    *puVar7 = (short)((int)*(short *)(param_4 + lVar9) >> (uVar4 & 0x1f));
    puVar7 = puVar7 + 1;
  }
  ___memcpy_chk(local_166,param_3,(long)*(short *)(param_1 + 0xe) << 1,0xe8);
  thunk_FUN_0024de70(local_166 + *(short *)(param_1 + 0xe),0);
  thunk_FUN_0024de70(auStack_17a,0,10);
  FUN_0024e304(local_166,auStack_262,auStack_7e,0xb,(int)(short)(*(short *)(param_1 + 0xe) + 10));
  thunk_FUN_0024de70(auStack_24e + (long)*(short *)(param_1 + 0xe) * 2,0,
                     *(short *)(param_1 + 0xe) + -10);
  FUN_0024e20c(auStack_262,local_166,param_4,0xb,
               -(*(ushort *)(param_1 + 0xe) >> 0xe & 1) & 0xffff0000 |
               (*(ushort *)(param_1 + 0xe) & 0x7fff) << 1);
  sVar10 = *(short *)(param_1 + 0xe);
  for (lVar9 = 0; lVar9 < sVar10; lVar9 = lVar9 + 1) {
    local_166[lVar9] = local_166[lVar9] + local_166[sVar10 + lVar9];
  }
  iVar5 = (*DAT_0191b7d0)(local_166);
  if (iVar5 << (ulong)(uVar4 & 0x1f) < 0x5a82) {
    iVar5 = iVar5 * iVar5 << (ulong)(uVar4 * 2 + 2 & 0x1f);
  }
  else {
    iVar5 = 0x7fffffff;
  }
  iVar8 = 0;
  iVar3 = iVar8;
  while (iVar11 = iVar3, iVar11 < 0x3f) {
    iVar3 = 0x40;
    if (*(int *)(&DAT_00c4f328 + (long)iVar11 * 4) <= iVar5) {
      iVar8 = iVar11 + 1;
      iVar3 = iVar8;
    }
  }
  sVar2 = (short)iVar8;
  *(short *)(param_2 + 0x48) = sVar2;
  sVar10 = 4;
  if (0x1a < sVar2) {
    sVar10 = 9;
  }
  FUN_0024f198(local_166,local_166,(long)*(short *)((long)&DAT_00c4f428 + (long)sVar2 * 2),
               (long)*(short *)(param_1 + 0xe),(int)(short)(sVar10 - (short)uVar4));
  FUN_002457ac(param_1,param_2,local_166,param_5);
  return;
}


