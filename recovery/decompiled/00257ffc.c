/* Decompiled from supplied 5.2.2 arm package. VA 0x257ffc. _av_encryption_init_info_add_side_data */

uint * _av_encryption_init_info_add_side_data(undefined8 *param_1,ulong *param_2)

{
  ulong uVar1;
  undefined8 *puVar2;
  ulong uVar3;
  uint *puVar4;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  
  iVar5 = 0;
  uVar1 = 4;
  for (puVar2 = param_1; puVar2 != (undefined8 *)0x0; puVar2 = (undefined8 *)puVar2[6]) {
    iVar5 = iVar5 + -1;
    if (iVar5 == 0) {
      return (uint *)0x0;
    }
    uVar1 = uVar1 + *(uint *)(puVar2 + 1) + (ulong)*(uint *)(puVar2 + 5) + 0x10;
    if (uVar1 >> 0x20 != 0) {
      return (uint *)0x0;
    }
    uVar3 = puVar2[3];
    if (((int)uVar3 != 0) &&
       (uVar1 = uVar1 + (uVar3 >> 0x20) * (uVar3 & 0xffffffff), uVar1 >> 0x20 != 0))
    goto LAB_0025813c;
  }
  *param_2 = uVar1;
  puVar4 = (uint *)_av_malloc();
  if (puVar4 == (uint *)0x0) {
LAB_0025813c:
    puVar4 = (uint *)0x0;
  }
  else {
    uVar7 = (-iVar5 & 0xff00ff00U) >> 8 | (-iVar5 & 0xff00ffU) << 8;
    puVar6 = puVar4 + 1;
    *puVar4 = uVar7 >> 0x10 | uVar7 << 0x10;
    for (; param_1 != (undefined8 *)0x0; param_1 = (undefined8 *)param_1[6]) {
      uVar7 = (*(uint *)(param_1 + 1) & 0xff00ff00) >> 8 | (*(uint *)(param_1 + 1) & 0xff00ff) << 8;
      *puVar6 = uVar7 >> 0x10 | uVar7 << 0x10;
      uVar7 = (*(uint *)(param_1 + 3) & 0xff00ff00) >> 8 | (*(uint *)(param_1 + 3) & 0xff00ff) << 8;
      puVar6[1] = uVar7 >> 0x10 | uVar7 << 0x10;
      uVar7 = (*(uint *)((long)param_1 + 0x1c) & 0xff00ff00) >> 8 |
              (*(uint *)((long)param_1 + 0x1c) & 0xff00ff) << 8;
      puVar6[2] = uVar7 >> 0x10 | uVar7 << 0x10;
      uVar7 = (*(uint *)(param_1 + 5) & 0xff00ff00) >> 8 | (*(uint *)(param_1 + 5) & 0xff00ff) << 8;
      puVar6[3] = uVar7 >> 0x10 | uVar7 << 0x10;
      _memcpy(puVar6 + 4,(void *)*param_1,(ulong)*(uint *)(param_1 + 1));
      puVar6 = (uint *)((long)(puVar6 + 4) + (ulong)*(uint *)(param_1 + 1));
      for (uVar7 = 0; uVar7 < (uint)param_1[3]; uVar7 = uVar7 + 1) {
        _memcpy(puVar6,*(void **)(param_1[2] + (ulong)uVar7 * 8),(ulong)param_1[3] >> 0x20);
        puVar6 = (uint *)((long)puVar6 + (ulong)*(uint *)((long)param_1 + 0x1c));
      }
      if (*(uint *)(param_1 + 5) != 0) {
        _memcpy(puVar6,(void *)param_1[4],(ulong)*(uint *)(param_1 + 5));
        puVar6 = (uint *)((long)puVar6 + (ulong)*(uint *)(param_1 + 5));
      }
    }
  }
  return puVar4;
}


