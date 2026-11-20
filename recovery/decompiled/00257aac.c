/* Decompiled from supplied 5.2.2 arm package. VA 0x257aac. _av_encryption_info_get_side_data */

uint * _av_encryption_info_get_side_data(uint *param_1,ulong param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  long lVar5;
  long lVar6;
  uint *puVar7;
  ulong uVar8;
  ulong uVar9;
  
  puVar7 = (uint *)0x0;
  if ((param_1 != (uint *)0x0) && (0x17 < param_2)) {
    uVar3 = (param_1[3] & 0xff00ff00) >> 8 | (param_1[3] & 0xff00ff) << 8;
    uVar4 = (param_1[4] & 0xff00ff00) >> 8 | (param_1[4] & 0xff00ff) << 8;
    uVar4 = uVar4 >> 0x10 | uVar4 << 0x10;
    uVar9 = (ulong)(uVar3 >> 0x10 | uVar3 << 0x10);
    uVar8 = (ulong)uVar4;
    uVar3 = (param_1[5] & 0xff00ff00) >> 8 | (param_1[5] & 0xff00ff) << 8;
    uVar3 = uVar3 >> 0x10 | uVar3 << 0x10;
    if ((param_2 < uVar9 + uVar4 + (ulong)uVar3 * 8 + 0x18) ||
       (puVar7 = (uint *)_av_encryption_info_alloc(uVar3,uVar9,uVar8), puVar7 == (uint *)0x0)) {
      puVar7 = (uint *)0x0;
    }
    else {
      uVar4 = (*param_1 & 0xff00ff00) >> 8 | (*param_1 & 0xff00ff) << 8;
      *puVar7 = uVar4 >> 0x10 | uVar4 << 0x10;
      uVar4 = (param_1[1] & 0xff00ff00) >> 8 | (param_1[1] & 0xff00ff) << 8;
      puVar7[1] = uVar4 >> 0x10 | uVar4 << 0x10;
      uVar4 = (param_1[2] & 0xff00ff00) >> 8 | (param_1[2] & 0xff00ff) << 8;
      puVar7[2] = uVar4 >> 0x10 | uVar4 << 0x10;
      _memcpy(*(void **)(puVar7 + 4),param_1 + 6,uVar9);
      _memcpy(*(void **)(puVar7 + 8),(void *)((long)param_1 + uVar9 + 0x18),uVar8);
      lVar5 = 0;
      lVar6 = (ulong)uVar3 + 1;
      while (lVar6 = lVar6 + -1, lVar6 != 0) {
        puVar1 = (uint *)((long)param_1 + lVar5 + uVar9 + uVar8 + 0x18);
        uVar3 = *puVar1;
        uVar3 = (uVar3 & 0xff00ff00) >> 8 | (uVar3 & 0xff00ff) << 8;
        puVar2 = (uint *)(*(long *)(puVar7 + 0xc) + lVar5);
        *puVar2 = uVar3 >> 0x10 | uVar3 << 0x10;
        uVar3 = puVar1[1];
        lVar5 = lVar5 + 8;
        uVar3 = (uVar3 & 0xff00ff00) >> 8 | (uVar3 & 0xff00ff) << 8;
        puVar2[1] = uVar3 >> 0x10 | uVar3 << 0x10;
      }
    }
  }
  return puVar7;
}


