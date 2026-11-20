/* Decompiled from supplied 5.2.2 arm package. VA 0x262018. _av_memcpy_backptr */

void _av_memcpy_backptr(byte *param_1,int param_2,uint param_3)

{
  undefined8 uVar1;
  undefined4 uVar2;
  byte bVar3;
  undefined2 uVar4;
  uint uVar5;
  uint uVar6;
  long lVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  ulong uVar12;
  uint *puVar13;
  byte *pbVar14;
  byte *pbVar15;
  byte *pbVar16;
  byte *pbVar17;
  
  pbVar15 = param_1 + -param_2;
  switch(param_2) {
  case 0:
    break;
  case 1:
    _memset(param_1,(uint)*pbVar15,(long)(int)param_3);
    break;
  case 2:
    uVar4 = *(undefined2 *)(param_1 + -2);
    uVar5 = param_3;
    if (2 < (int)param_3) {
      uVar5 = 3;
    }
    pbVar15 = param_1;
    for (uVar8 = param_3; 3 < (int)uVar8; uVar8 = uVar8 - 4) {
      *(uint *)pbVar15 = CONCAT22(uVar4,uVar4);
      pbVar15 = pbVar15 + 4;
    }
    uVar8 = 0xfffffffc;
    if (-4 < (int)~param_3) {
      uVar8 = ~param_3;
    }
    pbVar15 = param_1 + (ulong)(param_3 + ~uVar5 + 4 >> 2) * 4;
    for (iVar9 = (param_3 + uVar8 + 4 & 0xfffffffc) - param_3; iVar9 != 0; iVar9 = iVar9 + 1) {
      *pbVar15 = pbVar15[-2];
      pbVar15 = pbVar15 + 1;
    }
    break;
  case 3:
    lVar7 = 0;
    bVar3 = param_1[-1];
    uVar5 = (uint)bVar3 << 0x10 | (uint)param_1[-2] << 8;
    uVar11 = uVar5 | param_1[-3];
    uVar5 = uVar5 >> 8 | uVar11 << 0x10;
    uVar8 = uVar11 | (uint)param_1[-3] << 0x18;
    uVar6 = param_3;
    while( true ) {
      uVar12 = (ulong)uVar6;
      if ((int)uVar6 < 0xc) break;
      puVar13 = (uint *)(param_1 + lVar7);
      *puVar13 = uVar8;
      puVar13[1] = uVar5;
      puVar13[2] = (uint)bVar3 | uVar11 << 8;
      lVar7 = lVar7 + 0xc;
      uVar6 = uVar6 - 0xc;
    }
    puVar13 = (uint *)(param_1 + lVar7);
    if (3 < (int)uVar6) {
      *puVar13 = uVar8;
      uVar12 = (ulong)(param_3 - 4) - lVar7;
      puVar13 = puVar13 + 1;
      if (3 < (int)uVar12) {
        *(uint *)(param_1 + lVar7 + 4) = uVar5;
        uVar12 = (ulong)((param_3 - 8) - (int)lVar7);
        puVar13 = (uint *)(param_1 + lVar7 + 8);
      }
    }
    for (; (int)uVar12 != 0; uVar12 = (ulong)((int)uVar12 - 1)) {
      *(undefined1 *)puVar13 = *(undefined1 *)((long)puVar13 + -3);
      puVar13 = (uint *)((long)puVar13 + 1);
    }
    break;
  case 4:
    uVar2 = *(undefined4 *)(param_1 + -4);
    uVar5 = param_3;
    if (0x1e < (int)param_3) {
      uVar5 = 0x1f;
    }
    uVar1 = CONCAT44(uVar2,uVar2);
    uVar5 = param_3 + ~uVar5 + 0x20 >> 5;
    pbVar15 = param_1;
    for (uVar8 = param_3; 0x1f < (int)uVar8; uVar8 = uVar8 - 0x20) {
      *(undefined8 *)pbVar15 = uVar1;
      *(undefined8 *)(pbVar15 + 8) = uVar1;
      *(undefined8 *)(pbVar15 + 0x10) = uVar1;
      *(undefined8 *)(pbVar15 + 0x18) = uVar1;
      pbVar15 = pbVar15 + 0x20;
    }
    uVar11 = param_3 + uVar5 * -0x20;
    uVar8 = uVar11;
    if (2 < (int)uVar11) {
      uVar8 = 3;
    }
    iVar9 = uVar11 + ~uVar8;
    pbVar15 = param_1 + (uVar5 << 5);
    for (; 3 < (int)uVar11; uVar11 = uVar11 - 4) {
      *(undefined4 *)pbVar15 = uVar2;
      pbVar15 = pbVar15 + 4;
    }
    uVar8 = 0xffffffe0;
    if (-0x20 < (int)~param_3) {
      uVar8 = ~param_3;
    }
    uVar8 = param_3 + uVar8 + 0x20 & 0xffffffe0;
    iVar10 = (uVar8 - 1) - param_3;
    if (iVar10 < -3) {
      iVar10 = -4;
    }
    pbVar15 = param_1 + (uVar5 << 5) + (iVar9 + 4U & 0xfffffffc);
    for (iVar10 = -((param_3 - ((param_3 + iVar10 + 4) - uVar8 & 0xfffffffc)) - uVar8); iVar10 != 0;
        iVar10 = iVar10 + 1) {
      *pbVar15 = pbVar15[-4];
      pbVar15 = pbVar15 + 1;
    }
    break;
  default:
    if ((int)param_3 < 0x10) {
      if (7 < (int)param_3) {
        *(undefined4 *)param_1 = *(undefined4 *)pbVar15;
        pbVar14 = pbVar15 + 4;
        pbVar15 = pbVar15 + 8;
        *(undefined4 *)(param_1 + 4) = *(undefined4 *)pbVar14;
        param_1 = param_1 + 8;
        param_3 = param_3 - 8;
      }
      pbVar14 = param_1;
      pbVar16 = pbVar15;
      if (3 < (int)param_3) {
        pbVar16 = pbVar15 + 4;
        pbVar14 = param_1 + 4;
        *(undefined4 *)param_1 = *(undefined4 *)pbVar15;
        param_3 = param_3 - 4;
      }
      pbVar15 = pbVar14;
      pbVar17 = pbVar16;
      if (1 < (int)param_3) {
        pbVar17 = pbVar16 + 2;
        pbVar15 = pbVar14 + 2;
        *(undefined2 *)pbVar14 = *(undefined2 *)pbVar16;
        param_3 = param_3 - 2;
      }
      if (param_3 != 0) {
        *pbVar15 = *pbVar17;
      }
    }
    else {
      for (; uVar5 = param_3 - param_2, uVar5 != 0 && param_2 <= (int)param_3;
          param_2 = param_2 << 1) {
        _memcpy(param_1,pbVar15,(long)param_2);
        param_1 = param_1 + param_2;
        param_3 = uVar5;
      }
      _memcpy(param_1,pbVar15,(long)(int)param_3);
    }
  }
  return;
}


