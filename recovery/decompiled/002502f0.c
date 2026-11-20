/* Decompiled from supplied 5.2.2 arm package. VA 0x2502f0. _av_aes_init */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _av_aes_init(undefined8 *param_1,void *param_2,int param_3,int param_4)

{
  int iVar1;
  code *pcVar2;
  uint uVar3;
  undefined8 uVar4;
  long lVar5;
  byte *pbVar6;
  uint uVar7;
  byte *pbVar8;
  ulong uVar9;
  undefined8 *puVar10;
  long lVar11;
  byte *pbVar12;
  long lVar13;
  size_t sVar14;
  size_t sVar15;
  undefined8 *local_3e8;
  undefined8 local_3e0;
  undefined8 uStack_3d8;
  undefined8 local_3d0;
  undefined8 uStack_3c8;
  undefined8 local_3c0;
  undefined8 uStack_3b8;
  undefined1 auStack_3b0 [16];
  undefined8 local_3a0;
  undefined8 uStack_398;
  byte local_388 [512];
  byte local_188 [256];
  byte local_88 [4];
  byte local_84 [28];
  long local_68;
  
  lVar13 = *(long *)PTR____stack_chk_guard_01060708;
  pcVar2 = FUN_00250710;
  if (param_4 == 0) {
    pcVar2 = FUN_002507fc;
  }
  local_68 = lVar13;
  param_1[0x23] = pcVar2;
  if (DAT_01228bac == 0) {
    uVar7 = 1;
    for (lVar5 = 0; lVar5 != 0xff; lVar5 = lVar5 + 1) {
      local_188[(int)uVar7] = (byte)lVar5;
      uVar3 = uVar7 ^ uVar7 << 1;
      local_388[lVar5 + 0xff] = (byte)uVar7;
      local_388[lVar5] = (byte)uVar7;
      uVar7 = uVar3 ^ 0x11b;
      if ((int)uVar3 < 0x100) {
        uVar7 = uVar3;
      }
    }
    lVar5 = 0;
    do {
      if (lVar5 == 0) {
        uVar7 = 0;
      }
      else {
        if (lVar5 == 0x100) goto LAB_00250408;
        uVar7 = (uint)local_388[(ulong)local_188[lVar5] ^ 0xff];
      }
      uVar3 = uVar7 << 1 ^ uVar7 << 2 ^ uVar7 << 3 ^ uVar7 << 4;
      uVar7 = (uVar3 ^ uVar7 ^ uVar3 >> 8) & 0xff ^ 99;
      (&DAT_012285b0)[uVar7] = (char)lVar5;
      (&DAT_012286b0)[lVar5] = (char)uVar7;
      lVar5 = lVar5 + 1;
    } while( true );
  }
LAB_00250450:
  if (((param_3 == 0x80) || (param_3 == 0x100)) || (param_3 == 0xc0)) {
    iVar1 = param_3 >> 5;
    *(int *)(param_1 + 0x22) = iVar1 + 6;
    sVar14 = (size_t)(iVar1 << 2);
    ___memcpy_chk(local_88,param_2,sVar14,0x20);
    _memcpy(param_1,param_2,sVar14);
    lVar13 = 0;
    lVar5 = (ulong)(uint)(param_3 >> 6) * 4 + -0x88;
    for (sVar15 = sVar14; (long)sVar15 < (long)((iVar1 + 7) * 0x10); sVar15 = sVar15 + sVar14) {
      uVar9 = 0;
      while (uVar9 != 4) {
        local_88[uVar9] =
             local_88[uVar9] ^ (&DAT_012286b0)[local_88[(uVar9 + 1 & 3) + ((long)iVar1 + -1) * 4]];
        uVar9 = uVar9 + 1;
      }
      pbVar6 = local_88;
      local_88[0] = local_88[0] ^ (&DAT_00c502a4)[lVar13];
      pbVar8 = local_84;
      for (uVar9 = 1; (long)uVar9 < (long)iVar1; uVar9 = uVar9 + 1) {
        lVar11 = 4;
        pbVar12 = pbVar8;
        if (iVar1 == 8 && uVar9 == (uint)(param_3 >> 6)) {
          pbVar12 = pbVar6;
          for (lVar11 = 0; lVar11 != 4; lVar11 = lVar11 + 1) {
            local_88[lVar11 + lVar5 + 0x88] =
                 local_88[lVar11 + lVar5 + 0x88] ^ (&DAT_012286b0)[*pbVar12];
            pbVar12 = pbVar12 + 1;
          }
        }
        else {
          for (; lVar11 != 0; lVar11 = lVar11 + -1) {
            *pbVar12 = *pbVar12 ^ pbVar12[-4];
            pbVar12 = pbVar12 + 1;
          }
        }
        pbVar8 = pbVar8 + 4;
        pbVar6 = pbVar6 + 4;
      }
      lVar13 = lVar13 + 1;
      _memcpy((void *)((long)param_1 + sVar15),local_88,sVar14);
    }
    if (param_4 == 0) {
      lVar5 = -1;
      lVar13 = *(long *)PTR____stack_chk_guard_01060708;
      puVar10 = param_1 + (long)iVar1 * 2 + 0xc;
      local_3e8 = param_1;
      while (lVar5 = lVar5 + 1, lVar5 < iVar1 + 7 >> 1) {
        uStack_3b8 = puVar10[1];
        local_3c0 = *puVar10;
        uVar4 = *local_3e8;
        puVar10[1] = local_3e8[1];
        *puVar10 = uVar4;
        local_3e8[1] = uStack_3b8;
        *local_3e8 = local_3c0;
        puVar10 = puVar10 + -2;
        local_3e8 = local_3e8 + 2;
      }
      uVar4 = 0;
    }
    else {
      lVar13 = 0;
      while( true ) {
        puVar10 = param_1 + 2;
        lVar13 = lVar13 + 1;
        if (iVar1 + 6 <= lVar13) break;
        uStack_398 = param_1[3];
        local_3a0 = *puVar10;
        FUN_00250994(auStack_3b0,0,&DAT_012286b0);
        FUN_00250a68(&local_3c0,&DAT_01228bb0,1,3);
        param_1[3] = uStack_3b8;
        *puVar10 = local_3c0;
        param_1 = puVar10;
      }
      uVar4 = 0;
      lVar13 = *(long *)PTR____stack_chk_guard_01060708;
    }
  }
  else {
    uVar4 = 0xffffffea;
  }
  if (lVar13 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(uVar4);
LAB_00250408:
  uStack_3c8 = _UNK_00c50288;
  local_3d0 = _DAT_00c50280;
  FUN_00250924(&DAT_01228bb0,&local_3d0,local_188,local_388,&DAT_012285b0);
  uStack_3d8 = _UNK_00c50298;
  local_3e0 = _DAT_00c50290;
  FUN_00250924(&DAT_012287b0,&local_3e0,local_188,local_388,&DAT_012286b0);
  goto LAB_00250450;
}


