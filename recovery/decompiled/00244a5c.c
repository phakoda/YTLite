/* Decompiled from supplied 5.2.2 arm package. VA 0x244a5c. _shine_window_filter_subband */

/* WARNING: Removing unreachable block (ram,0x00244d24) */

void _shine_window_filter_subband(long *param_1,long param_2,int param_3,long param_4,ulong param_5)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  uint *puVar5;
  bool bVar6;
  int *piVar7;
  int *piVar8;
  ushort uVar9;
  uint uVar10;
  long lVar11;
  long lVar12;
  long lVar13;
  long lVar14;
  long lVar15;
  long lVar16;
  int *piVar17;
  long lVar18;
  long lVar19;
  int *piVar20;
  ushort *puVar21;
  int iVar22;
  long lVar23;
  int *piVar24;
  ushort *puVar25;
  ulong uVar26;
  int aiStack_158 [66];
  
  puVar21 = (ushort *)*param_1;
  puVar5 = (uint *)(param_4 + (long)param_3 * 4 + 0x14690);
  iVar22 = 0x1f;
  puVar25 = puVar21;
  do {
    uVar9 = *puVar25;
    puVar25 = (ushort *)
              ((long)puVar25 +
              (-(param_5 >> 0x1f & 1) & 0xfffffffe00000000 | (param_5 & 0xffffffff) << 1));
    iVar4 = iVar22 + *puVar5;
    iVar22 = iVar22 + -1;
    *(uint *)(&LAB_00016698 + param_4 + (long)param_3 * 0x800 + (long)iVar4 * 4) =
         (uint)uVar9 << 0x10;
  } while (iVar22 != -1);
  *param_1 = (long)(puVar21 +
                   (-(param_5 >> 0x1f & 1) & 0xffffffe000000000 | (param_5 & 0xffffffff) << 5));
  uVar10 = *puVar5;
  piVar20 = &DAT_00c4e10c;
  lVar18 = 0;
  do {
    iVar22 = uVar10 + (int)lVar18;
    lVar23 = param_4 + (long)param_3 * 0x800;
    piVar17 = piVar20 + -0x80;
    piVar3 = piVar20 + -0x40;
    iVar4 = *piVar20;
    piVar24 = piVar20 + 0x40;
    piVar1 = piVar20 + 0x80;
    piVar2 = piVar20 + 0xc0;
    piVar20 = piVar20 + -1;
    lVar19 = lVar18 + -1;
    aiStack_158[lVar18 + 0x3f] =
         (int)((ulong)((long)(int)(&DAT_00c4de0c)[lVar18] *
                      (long)*(int *)(&LAB_00016698 + ((ulong)(iVar22 + 0x7f) & 0x1ff) * 4 + lVar23))
              >> 0x20) +
         (int)((ulong)((long)(int)(&DAT_00c4dd0c)[lVar18] *
                      (long)*(int *)(&LAB_00016698 + ((ulong)(iVar22 + 0x3f) & 0x1ff) * 4 + lVar23))
              >> 0x20) +
         (int)((ulong)((long)*piVar17 *
                      (long)*(int *)(&LAB_00016698 + ((ulong)(iVar22 + 0xbf) & 0x1ff) * 4 + lVar23))
              >> 0x20) +
         (int)((ulong)((long)*piVar3 *
                      (long)*(int *)(&LAB_00016698 + ((ulong)(iVar22 + 0xff) & 0x1ff) * 4 + lVar23))
              >> 0x20) +
         (int)((ulong)((long)iVar4 *
                      (long)*(int *)(&LAB_00016698 + ((ulong)(iVar22 + 0x13f) & 0x1ff) * 4 + lVar23)
                      ) >> 0x20) +
         (int)((ulong)((long)*piVar24 *
                      (long)*(int *)(&LAB_00016698 + ((ulong)(iVar22 + 0x17f) & 0x1ff) * 4 + lVar23)
                      ) >> 0x20) +
         (int)((ulong)((long)*piVar1 *
                      (long)*(int *)(&LAB_00016698 + ((ulong)(iVar22 + 0x1bf) & 0x1ff) * 4 + lVar23)
                      ) >> 0x20) +
         (int)((ulong)((long)*piVar2 *
                      (long)*(int *)(&LAB_00016698 + ((ulong)(iVar22 + 0x1ff) & 0x1ff) * 4 + lVar23)
                      ) >> 0x20);
    lVar18 = lVar19;
  } while (lVar19 != -0x40);
  *puVar5 = uVar10 + 0x1e0 & 0x1ff;
  piVar20 = (int *)(&LAB_00016684 + param_4);
  lVar18 = 0x1f;
  do {
    lVar23 = 0;
    uVar26 = (ulong)((long)aiStack_158[0x3f] *
                    (long)*(int *)(_objc_msgSend + param_4 + lVar18 * 0x100 + 4)) >> 0x20;
    piVar24 = piVar20;
    do {
      piVar2 = piVar24 + 2;
      piVar17 = piVar24 + 3;
      lVar19 = lVar23 + 0xf8;
      iVar22 = *piVar24;
      piVar7 = piVar24 + 1;
      piVar3 = piVar24 + -2;
      piVar8 = piVar24 + -1;
      piVar1 = piVar24 + -3;
      lVar11 = lVar23 + 0xf0;
      lVar12 = lVar23 + 0xf4;
      lVar13 = lVar23 + 0xe8;
      lVar14 = lVar23 + 0xec;
      lVar15 = lVar23 + 0xe0;
      lVar16 = lVar23 + 0xe4;
      lVar23 = lVar23 + -0x1c;
      piVar24 = piVar24 + -7;
      uVar10 = (int)((ulong)((long)*(int *)((long)aiStack_158 + lVar19) * (long)*piVar17) >> 0x20) +
               (int)uVar26 +
               (int)((ulong)((long)*(int *)((long)aiStack_158 + lVar12) * (long)*piVar2) >> 0x20) +
               (int)((ulong)((long)*(int *)((long)aiStack_158 + lVar11) * (long)*piVar7) >> 0x20) +
               (int)((ulong)((long)*(int *)((long)aiStack_158 + lVar14) * (long)iVar22) >> 0x20) +
               (int)((ulong)((long)*(int *)((long)aiStack_158 + lVar13) * (long)*piVar8) >> 0x20) +
               (int)((ulong)((long)*(int *)((long)aiStack_158 + lVar16) * (long)*piVar3) >> 0x20) +
               (int)((ulong)((long)*(int *)((long)aiStack_158 + lVar15) * (long)*piVar1) >> 0x20);
      uVar26 = (ulong)uVar10;
    } while (lVar23 != -0xfc);
    *(uint *)(param_2 + lVar18 * 4) = uVar10;
    piVar20 = piVar20 + -0x40;
    bVar6 = lVar18 != 0;
    lVar18 = lVar18 + -1;
  } while (bVar6);
  return;
}


