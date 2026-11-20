/* Decompiled from supplied 5.2.2 arm package. VA 0x248260. _WebRtcIlbcfix_EncodeImpl */

void _WebRtcIlbcfix_EncodeImpl(undefined8 param_1,undefined8 param_2,short *param_3)

{
  short *psVar1;
  uint uVar2;
  uint uVar3;
  short sVar4;
  bool bVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined1 *puVar9;
  short *psVar10;
  undefined1 *puVar11;
  int iVar12;
  long lVar13;
  long lVar14;
  long lVar15;
  short sVar16;
  undefined8 uVar17;
  undefined1 auStack_4da [12];
  undefined1 auStack_4ce [30];
  undefined1 auStack_4b0 [30];
  short local_492;
  ushort local_490;
  undefined1 auStack_48e [118];
  short local_418;
  undefined1 auStack_40e [80];
  undefined1 auStack_3be [44];
  undefined1 auStack_392 [10];
  undefined1 auStack_388 [80];
  undefined1 auStack_338 [78];
  undefined1 auStack_2ea [2];
  undefined1 auStack_2e8 [8];
  undefined8 local_2e0 [2];
  undefined4 local_2d0;
  undefined1 auStack_2cc [480];
  undefined1 auStack_ec [132];
  long local_68;
  
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  lVar13 = (long)param_3[1];
  psVar1 = param_3 + (0x152 - lVar13);
  ___memcpy_chk(auStack_2cc,param_2,lVar13 << 1,0x1e0);
  FUN_00249ea4(auStack_2cc,&DAT_00c4e410,param_3 + 0x154,param_3 + 0x152,(long)param_3[1]);
  FUN_0024a470(auStack_40e,auStack_ec,auStack_4da,auStack_2cc,param_3);
  local_2d0 = *(undefined4 *)(param_3 + 0x10);
  local_2e0[1] = *(undefined8 *)(param_3 + 0xc);
  local_2e0[0] = *(undefined8 *)(param_3 + 8);
  lVar14 = -1;
  puVar9 = auStack_2cc;
  psVar10 = param_3 + 0x152 + -lVar13;
  puVar11 = auStack_40e;
  while (lVar14 = lVar14 + 1, lVar14 < param_3[2]) {
    FUN_0024e304(puVar9,psVar10,puVar11,0xb,0x28);
    puVar9 = puVar9 + 0x50;
    psVar10 = psVar10 + 0x28;
    puVar11 = puVar11 + 0x16;
  }
  lVar14 = (long)param_3[1] * 2;
  *(undefined4 *)(param_3 + 0x10) = *(undefined4 *)(auStack_2cc + lVar14 + -4);
  uVar17 = *(undefined8 *)((long)local_2e0 + lVar14);
  *(undefined8 *)(param_3 + 0xc) = *(undefined8 *)((long)local_2e0 + lVar14 + 8);
  *(undefined8 *)(param_3 + 8) = uVar17;
  iVar6 = FUN_00249710(param_3,psVar1);
  local_418 = (short)iVar6;
  iVar6 = iVar6 * 0x28 + -0x28;
  psVar10 = psVar1 + iVar6;
  iVar7 = (*DAT_0191b7d0)(psVar10,0x50);
  uVar3 = iVar7 * iVar7;
  bVar5 = uVar3 >> 0x10 != 0;
  lVar14 = (ulong)bVar5 << 4;
  uVar2 = (uint)lVar14;
  if ((0xff00 << lVar14 & uVar3) != 0) {
    uVar2 = (uint)bVar5 << 4 | 8;
  }
  if ((0xf0 << (ulong)uVar2 & uVar3) != 0) {
    uVar2 = uVar2 | 4;
  }
  if ((0xc << (ulong)uVar2 & uVar3) != 0) {
    uVar2 = uVar2 | 2;
  }
  if ((2 << (ulong)(uint)(int)(short)uVar2 & uVar3) != 0) {
    uVar2 = (int)(short)uVar2 + 1;
  }
  sVar4 = 0x50 - param_3[7];
  if ((1 << (ulong)((int)(short)uVar2 & 0x1f) & uVar3) != 0) {
    uVar2 = (int)(short)uVar2 + 1;
  }
  iVar7 = 0;
  if ((uVar2 + 0xffe7 & 0x8000) == 0) {
    iVar7 = (int)(short)(uVar2 + 0xffe7);
  }
  iVar8 = FUN_0024e098(psVar10,psVar10,(long)param_3[7],iVar7);
  iVar12 = (int)sVar4;
  iVar6 = FUN_0024e098(psVar1 + (iVar6 + sVar4),psVar1 + (iVar6 + sVar4),(long)param_3[7],iVar7);
  if (iVar8 <= iVar6) {
    uVar2 = iVar12 + local_418 * 0x28 + 0xffd8;
  }
  else {
    uVar2 = local_418 * 0x28 - 0x28;
  }
  local_490 = (ushort)(iVar8 > iVar6);
  lVar13 = (long)psVar1 + ((long)((ulong)uVar2 << 0x30) >> 0x2f);
  lVar14 = (long)local_418 * 0xb00000000 + -0xb00000000 >> 0x1f;
  FUN_0024c634(param_3,auStack_4da,lVar13,auStack_40e + lVar14,auStack_ec + lVar14);
  FUN_0024c41c((long)local_492,auStack_48e,
               auStack_40e + ((long)local_418 * 0xb00000000 + -0xb00000000 >> 0x1f),lVar13,
               (long)param_3[7]);
  sVar4 = (short)uVar2;
  if (local_490 == 0) {
    FUN_0024de90(auStack_2cc + (long)(iVar12 + -1) * 2,
                 (long)psVar1 + ((long)local_418 * 0x2800000000 + -0x2800000000 >> 0x1f),iVar12);
    FUN_0024de90(auStack_2ea,lVar13,(long)param_3[7]);
    thunk_FUN_0024de70(auStack_40e,0,(int)(short)(0x93 - param_3[7]));
    FUN_00246050(param_3,auStack_4ce,auStack_4b0,auStack_2cc,auStack_392,0x55,iVar12,
                 auStack_ec + ((long)local_418 * 0xb00000000 + -0xb00000000 >> 0x1f),0);
    FUN_00245b34(auStack_2cc,auStack_4ce,auStack_4b0,auStack_392,0x55,iVar12);
    FUN_0024de90(psVar1 + (sVar4 + -1),auStack_2cc,iVar12);
  }
  else {
    thunk_FUN_0024de70(auStack_40e,0,(int)(short)(0x93 - param_3[7]));
    _memcpy(auStack_2e8 + (long)param_3[7] * -2,psVar1 + (int)sVar4,(long)param_3[7] << 1);
    FUN_00246050(param_3,auStack_4ce,auStack_4b0,psVar1 + ((int)param_3[7] + (int)sVar4),auStack_392
                 ,0x55,iVar12,auStack_ec + ((long)local_418 * 0xb00000000 >> 0x1f),0);
    FUN_00245b34(psVar1 + ((int)param_3[7] + (int)sVar4),auStack_4ce,auStack_4b0,auStack_392,0x55,
                 iVar12);
  }
  sVar4 = param_3[2];
  iVar6 = (int)local_418;
  lVar14 = 1;
  sVar16 = local_418;
  if (1 < sVar4 - iVar6) {
    thunk_FUN_0024de70(auStack_40e,0,0x43);
    sVar16 = local_418;
    _memcpy(auStack_388,
            (void *)((long)psVar1 + ((long)local_418 * 0x2800000000 + -0x2800000000 >> 0x1f)),0xa0);
    puVar9 = auStack_4da;
    lVar13 = 0;
    while( true ) {
      lVar14 = lVar13 + 1;
      iVar7 = (int)lVar13;
      if ((sVar4 - iVar6) * 0x10000 + -0x10000 >> 0x10 <= iVar7) break;
      iVar12 = iVar7 + sVar16 + 1;
      FUN_00246050(param_3,puVar9 + 0x12,puVar9 + 0x30,psVar1 + iVar12 * 0x28,auStack_40e,0x93,0x28,
                   auStack_ec + (long)iVar12 * 0x16,(short)lVar14);
      FUN_00245b34(psVar1 + ((iVar7 + local_418) * 0x28 + 0x28),puVar9 + 0x12,puVar9 + 0x30,
                   auStack_40e,0x93,0x28);
      _memmove(auStack_40e,auStack_3be,0xd6);
      sVar16 = local_418;
      _memcpy(auStack_338,psVar1 + ((iVar7 + local_418) * 0x28 + 0x28),0x50);
      puVar9 = puVar9 + 6;
      lVar13 = lVar14;
    }
  }
  iVar6 = sVar16 + -1;
  if (iVar6 != 0 && 0 < sVar16) {
    iVar12 = iVar6 * 0x28;
    FUN_0024de90(auStack_2cc + ((long)iVar12 + -1) * 2,psVar1,iVar12);
    iVar8 = ((param_3[2] + 1) - (int)local_418) * 0x28;
    iVar7 = 0x93;
    if (iVar8 < 0x94) {
      iVar7 = iVar8;
    }
    FUN_0024de90(auStack_2ea,psVar1 + iVar12,iVar7);
    thunk_FUN_0024de70(auStack_40e,0,(int)(short)(0x93 - (short)iVar7));
    lVar15 = -2;
    puVar11 = auStack_4da + lVar14 * 6;
    puVar9 = auStack_2cc;
    for (lVar13 = 0; lVar13 < (int)(short)iVar6; lVar13 = lVar13 + 1) {
      FUN_00246050(param_3,puVar11 + 0xc,puVar11 + 0x2a,puVar9,auStack_40e,0x93,0x28,
                   auStack_ec + ((lVar15 + local_418) * 0xb00000000 >> 0x1f),
                   (short)lVar14 + (short)lVar13);
      FUN_00245b34(puVar9,puVar11 + 0xc,puVar11 + 0x2a,auStack_40e,0x93,0x28);
      _memmove(auStack_40e,auStack_3be,0xd6);
      _memcpy(auStack_338,puVar9,0x50);
      puVar11 = puVar11 + 6;
      lVar15 = lVar15 + -1;
      puVar9 = puVar9 + 0x50;
    }
    FUN_0024de90(psVar1 + (long)iVar12 + -1,auStack_2cc,iVar12);
  }
  FUN_0024a0d0(auStack_4ce);
  FUN_0024aa58(param_1,auStack_4da,(long)*param_3);
  thunk_FUN_0024c904(param_1,(long)param_3[5],param_1);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_68) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  return;
}


