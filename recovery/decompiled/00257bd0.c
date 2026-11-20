/* Decompiled from supplied 5.2.2 arm package. VA 0x257bd0. _av_encryption_info_add_side_data */

uint * _av_encryption_info_add_side_data(uint *param_1,ulong *param_2)

{
  void *pvVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  
  uVar4 = param_1[6];
  if (uVar4 < 0xffffffe8) {
    uVar2 = param_1[10];
    if ((uVar2 <= -uVar4 - 0x19) && (param_1[0xe] <= (-uVar4 - 0x19) - uVar2 >> 3)) {
      *param_2 = (ulong)(uVar4 + uVar2 + param_1[0xe] * 8 + 0x18);
      puVar3 = (uint *)_av_malloc();
      if (puVar3 != (uint *)0x0) {
        uVar4 = (*param_1 & 0xff00ff00) >> 8 | (*param_1 & 0xff00ff) << 8;
        uVar2 = (param_1[1] & 0xff00ff00) >> 8 | (param_1[1] & 0xff00ff) << 8;
        *puVar3 = uVar4 >> 0x10 | uVar4 << 0x10;
        puVar3[1] = uVar2 >> 0x10 | uVar2 << 0x10;
        uVar4 = (param_1[2] & 0xff00ff00) >> 8 | (param_1[2] & 0xff00ff) << 8;
        puVar3[2] = uVar4 >> 0x10 | uVar4 << 0x10;
        uVar4 = param_1[6];
        uVar2 = (uVar4 & 0xff00ff00) >> 8 | (uVar4 & 0xff00ff) << 8;
        puVar3[3] = uVar2 >> 0x10 | uVar2 << 0x10;
        uVar2 = (param_1[10] & 0xff00ff00) >> 8 | (param_1[10] & 0xff00ff) << 8;
        puVar3[4] = uVar2 >> 0x10 | uVar2 << 0x10;
        uVar2 = (param_1[0xe] & 0xff00ff00) >> 8 | (param_1[0xe] & 0xff00ff) << 8;
        puVar3[5] = uVar2 >> 0x10 | uVar2 << 0x10;
        _memcpy(puVar3 + 6,*(void **)(param_1 + 4),(ulong)uVar4);
        pvVar1 = (void *)((long)(puVar3 + 6) + (ulong)param_1[6]);
        _memcpy(pvVar1,*(void **)(param_1 + 8),(ulong)param_1[10]);
        puVar5 = (uint *)((long)pvVar1 + (ulong)param_1[10]);
        for (uVar4 = 0; uVar4 < param_1[0xe]; uVar4 = uVar4 + 1) {
          uVar2 = *(uint *)(*(long *)(param_1 + 0xc) + (ulong)uVar4 * 8);
          uVar2 = (uVar2 & 0xff00ff00) >> 8 | (uVar2 & 0xff00ff) << 8;
          *puVar5 = uVar2 >> 0x10 | uVar2 << 0x10;
          uVar2 = *(uint *)(*(long *)(param_1 + 0xc) + (ulong)uVar4 * 8 + 4);
          uVar2 = (uVar2 & 0xff00ff00) >> 8 | (uVar2 & 0xff00ff) << 8;
          puVar5[1] = uVar2 >> 0x10 | uVar2 << 0x10;
          puVar5 = puVar5 + 2;
        }
        return puVar3;
      }
    }
  }
  return (uint *)0x0;
}


