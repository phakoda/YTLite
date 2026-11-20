/* Decompiled from supplied 5.2.2 arm package. VA 0x257e6c. _av_encryption_init_info_get_side_data */

undefined8 * _av_encryption_init_info_get_side_data(uint *param_1,ulong param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  ulong uVar7;
  ulong uVar8;
  long lVar9;
  uint *puVar10;
  undefined8 *unaff_x19;
  void *pvVar11;
  undefined8 *puVar12;
  ulong uVar13;
  ulong uVar14;
  ulong uVar15;
  ulong uVar16;
  
  puVar12 = (undefined8 *)0x0;
  if ((param_1 != (uint *)0x0) && (uVar8 = param_2 - 4, 3 < param_2)) {
    puVar10 = param_1 + 1;
    puVar12 = (undefined8 *)0x0;
    uVar1 = (*param_1 & 0xff00ff00) >> 8 | (*param_1 & 0xff00ff) << 8;
    for (uVar15 = 0; uVar15 < (uVar1 >> 0x10 | uVar1 << 0x10); uVar15 = uVar15 + 1) {
      if (uVar8 < 0x10) {
LAB_00257fcc:
        _av_encryption_init_info_free(puVar12);
        return (undefined8 *)0x0;
      }
      uVar2 = (*puVar10 & 0xff00ff00) >> 8 | (*puVar10 & 0xff00ff) << 8;
      uVar13 = (ulong)(uVar2 >> 0x10 | uVar2 << 0x10);
      uVar2 = (puVar10[1] & 0xff00ff00) >> 8 | (puVar10[1] & 0xff00ff) << 8;
      uVar2 = uVar2 >> 0x10 | uVar2 << 0x10;
      uVar3 = (puVar10[2] & 0xff00ff00) >> 8 | (puVar10[2] & 0xff00ff) << 8;
      uVar3 = uVar3 >> 0x10 | uVar3 << 0x10;
      uVar4 = (puVar10[3] & 0xff00ff00) >> 8 | (puVar10[3] & 0xff00ff) << 8;
      uVar4 = uVar4 >> 0x10 | uVar4 << 0x10;
      lVar9 = uVar13 + (ulong)uVar3 * (ulong)uVar2;
      uVar14 = (ulong)uVar3;
      uVar7 = (ulong)uVar4;
      if ((uVar8 - 0x10 < lVar9 + (ulong)uVar4) ||
         (puVar6 = (undefined8 *)_av_encryption_init_info_alloc(uVar13,uVar2,uVar14),
         puVar6 == (undefined8 *)0x0)) goto LAB_00257fcc;
      puVar10 = puVar10 + 4;
      puVar5 = puVar6;
      if (uVar15 != 0) {
        unaff_x19[6] = puVar6;
        puVar5 = puVar12;
      }
      puVar12 = puVar5;
      _memcpy((void *)*puVar6,puVar10,uVar13);
      pvVar11 = (void *)((long)puVar10 + uVar13);
      for (uVar16 = 0; uVar2 != uVar16; uVar16 = uVar16 + 1) {
        _memcpy(*(void **)(puVar6[2] + uVar16 * 8),pvVar11,uVar14);
        pvVar11 = (void *)((long)pvVar11 + uVar14);
      }
      pvVar11 = (void *)((long)puVar10 + lVar9);
      _memcpy((void *)puVar6[4],pvVar11,uVar7);
      puVar10 = (uint *)((long)pvVar11 + uVar7);
      uVar8 = (((uVar8 - 0x10) - (ulong)uVar3 * (ulong)uVar2) - uVar13) - uVar7;
      unaff_x19 = puVar6;
    }
  }
  return puVar12;
}


