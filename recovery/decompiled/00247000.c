/* Decompiled from supplied 5.2.2 arm package. VA 0x247000. _WebRtcIlbcfix_DecodeImpl */

void _WebRtcIlbcfix_DecodeImpl(void *param_1,undefined8 param_2,uint *param_3,short param_4)

{
  int iVar1;
  short sVar2;
  uint uVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  long lVar9;
  long lVar10;
  uint *puVar11;
  uint uVar12;
  long lVar13;
  undefined1 auStack_5b8 [132];
  undefined1 auStack_534 [40];
  undefined1 auStack_50c [50];
  undefined8 local_4da;
  undefined6 uStack_4d2;
  undefined2 uStack_4cc;
  undefined6 uStack_4ca;
  undefined8 local_4c4;
  undefined6 uStack_4bc;
  undefined2 uStack_4b6;
  undefined6 uStack_4b4;
  undefined8 local_440;
  undefined8 uStack_438;
  undefined1 auStack_434 [4];
  uint local_430;
  undefined1 auStack_42c [80];
  undefined1 auStack_3dc [80];
  undefined1 auStack_38c [14];
  short local_37e;
  undefined1 auStack_310 [40];
  undefined1 auStack_2e8 [40];
  undefined1 auStack_2c0 [120];
  undefined1 auStack_248 [488];
  
  lVar13 = *(long *)PTR____stack_chk_guard_01060708;
  if (param_4 != 0) {
    thunk_FUN_0024c904(param_2,(int)*(short *)((long)param_3 + 10),auStack_50c);
    sVar2 = FUN_0024c910(auStack_50c,&local_440,(long)(short)*param_3);
    if ((((sVar2 != 1) && (local_37e < 6 || (short)*param_3 != 0x1e)) && (0 < local_37e)) &&
       (local_37e < 4 || (short)*param_3 != 0x14)) {
      FUN_0024a084(auStack_434);
      FUN_0024bce8(auStack_534,&local_440,(long)(short)param_3[3]);
      FUN_0024a528(auStack_534,10,(long)(short)param_3[3]);
      FUN_00247890(&local_4c4,auStack_5b8,auStack_534,10,param_3);
      FUN_002474ec(param_3,&local_440,auStack_248,&local_4c4);
      FUN_00247a9c(&local_440,&local_4da,0,auStack_248,
                   (long)&local_4c4 + ((long)(short)param_3[1] * 0xb00000000 + -0xb00000000 >> 0x1f)
                   ,(long)(short)param_3[0xe],param_3);
      ___memcpy_chk(auStack_248,&local_440,(long)*(short *)((long)param_3 + 2) << 1,0x1e0);
      uVar12 = 0;
      goto LAB_002471dc;
    }
  }
  FUN_00247a9c(&local_440,&local_4da,1,auStack_248,&local_4c4,(long)(short)param_3[0xe],param_3);
  ___memcpy_chk(auStack_248,&local_440,(long)*(short *)((long)param_3 + 2) << 1,0x1e0);
  lVar9 = -1;
  puVar7 = &local_4c4;
  while (lVar9 = lVar9 + 1, lVar9 < (short)param_3[1]) {
    *(ulong *)((long)puVar7 + 0xe) = CONCAT62(uStack_4ca,uStack_4cc);
    puVar7[1] = CONCAT26(uStack_4cc,uStack_4d2);
    *puVar7 = local_4da;
    puVar7 = (undefined8 *)((long)puVar7 + 0x16);
  }
  uVar12 = 1;
LAB_002471dc:
  if (param_3[0xb5] == 1) {
    if (param_3[0x10] == 2) {
      lVar9 = -1;
      puVar11 = param_3 + 0x91;
      while (lVar9 = lVar9 + 1, lVar9 < (short)param_3[1]) {
        *(ulong *)((long)puVar11 + 0xe) = CONCAT62(uStack_4b4,uStack_4b6);
        *(ulong *)(puVar11 + 2) = CONCAT26(uStack_4b6,uStack_4bc);
        *(undefined8 *)puVar11 = local_4c4;
        puVar11 = (uint *)((long)puVar11 + 0x16);
      }
    }
    uVar3 = FUN_00248c30(auStack_42c,auStack_248,param_3);
    param_3[0xe] = uVar3;
    local_430 = param_3[8];
    uStack_438 = *(undefined8 *)(param_3 + 6);
    local_440 = *(undefined8 *)(param_3 + 4);
    if ((short)*param_3 == 0x14) {
      FUN_0024e20c(auStack_42c,auStack_42c,
                   (long)param_3 +
                   ((long)(short)param_3[1] * 0xb00000000 + -0xb00000000 >> 0x1f) + 0x244,0xb,0x28);
      lVar9 = 0;
      puVar4 = auStack_3dc;
      lVar10 = 0;
      while (lVar9 = lVar9 + 1, lVar9 < (short)param_3[1]) {
        FUN_0024e20c(puVar4,puVar4,(long)&local_4c4 + (lVar10 >> 0x1f),0xb,0x28);
        puVar4 = puVar4 + 0x50;
        lVar10 = lVar10 + 0xb00000000;
      }
    }
    else if ((short)*param_3 == 0x1e) {
      puVar4 = auStack_42c;
      lVar9 = 0;
      while (lVar9 + 0x16 != 0x42) {
        FUN_0024e20c(puVar4,puVar4,(long)param_3 + lVar9 + 0x29c,0xb,0x28);
        puVar4 = puVar4 + 0x50;
        lVar9 = lVar9 + 0x16;
      }
      lVar9 = 1;
      puVar4 = auStack_38c;
      lVar10 = 0;
      while (lVar9 = lVar9 + 1, lVar9 < (short)param_3[1]) {
        FUN_0024e20c(puVar4,puVar4,(long)&local_4c4 + (lVar10 >> 0x1f),0xb,0x28);
        puVar4 = puVar4 + 0x50;
        lVar10 = lVar10 + 0xb00000000;
      }
    }
    lVar9 = (long)*(short *)((long)param_3 + 2) * 2;
    param_3[8] = *(uint *)(auStack_42c + lVar9 + -4);
    uVar6 = *(undefined8 *)((long)&local_440 + lVar9);
    *(undefined8 *)(param_3 + 6) = *(undefined8 *)((long)&stack0xfffffffffffffbc8 + lVar9);
    *(undefined8 *)(param_3 + 4) = uVar6;
    lVar9 = *(long *)PTR____stack_chk_guard_01060708;
  }
  else {
    iVar1 = (int)*param_3 >> 0x10;
    if ((*param_3 & 0xffff) == 0x14) {
      lVar9 = (long)iVar1 * 2;
      puVar4 = auStack_2c0 + lVar9;
      puVar5 = auStack_2e8 + lVar9;
      uVar6 = 0x3c;
      uVar8 = 0x50;
    }
    else {
      lVar9 = (long)iVar1 * 2;
      puVar4 = auStack_2e8 + lVar9;
      puVar5 = auStack_310 + lVar9;
      uVar6 = 0x50;
      uVar8 = 100;
    }
    sVar2 = FUN_0024d374(puVar4,puVar5,uVar6,uVar8,0x14,0xffffffff);
    param_3[0xe] = (int)sVar2;
    ___memcpy_chk(auStack_42c,auStack_248,(long)*(short *)((long)param_3 + 2) << 1,0x1e0);
    local_430 = param_3[8];
    uStack_438 = *(undefined8 *)(param_3 + 6);
    local_440 = *(undefined8 *)(param_3 + 4);
    lVar9 = -1;
    puVar4 = auStack_42c;
    puVar7 = &local_4c4;
    while (lVar9 = lVar9 + 1, lVar9 < (short)param_3[1]) {
      FUN_0024e20c(puVar4,puVar4,puVar7,0xb,0x28);
      puVar4 = puVar4 + 0x50;
      puVar7 = (undefined8 *)((long)puVar7 + 0x16);
    }
    lVar9 = (long)*(short *)((long)param_3 + 2) * 2;
    param_3[8] = *(uint *)(auStack_42c + lVar9 + -4);
    uVar6 = *(undefined8 *)((long)&local_440 + lVar9);
    *(undefined8 *)(param_3 + 6) = *(undefined8 *)((long)&stack0xfffffffffffffbc8 + lVar9);
    *(undefined8 *)(param_3 + 4) = uVar6;
    lVar9 = lVar13;
  }
  _memcpy(param_1,auStack_42c,(long)*(short *)((long)param_3 + 2) << 1);
  FUN_00249f8c(param_1,&DAT_00c4e41a,param_3 + 0xb3,param_3 + 0xb2,
               (long)*(short *)((long)param_3 + 2));
  _memcpy(param_3 + 0x91,&local_4c4,(long)(short)param_3[1] * 0xb00000000 >> 0x1f);
  param_3[0x10] = uVar12;
  if (lVar9 != lVar13) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  return;
}


