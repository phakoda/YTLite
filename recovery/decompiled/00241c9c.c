/* Decompiled from supplied 5.2.2 arm package. VA 0x241c9c. _shine_putbits */

void _shine_putbits(undefined8 *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  void *pvVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  
  uVar3 = *(uint *)((long)param_1 + 0x14);
  uVar1 = uVar3 - param_3;
  if (uVar3 < param_3 || uVar1 == 0) {
    pvVar2 = (void *)*param_1;
    lVar6 = param_1[1];
    iVar4 = (int)lVar6;
    if ((ulong)(long)iVar4 <= (long)*(int *)((long)param_1 + 0xc) + 4U) {
      iVar5 = iVar4;
      if (iVar4 < 0) {
        iVar5 = iVar4 + 1;
      }
      pvVar2 = _realloc(pvVar2,(long)(iVar4 + (iVar5 >> 1)));
      lVar6 = param_1[1];
      *param_1 = pvVar2;
      iVar5 = (int)lVar6;
      uVar3 = *(uint *)((long)param_1 + 0x14);
      iVar4 = iVar5;
      if (iVar5 < 0) {
        iVar4 = iVar5 + 1;
      }
      *(int *)(param_1 + 1) = iVar5 + (iVar4 >> 1);
    }
    uVar1 = param_2 >> (ulong)(param_3 - uVar3 & 0x1f) | *(uint *)(param_1 + 2);
    *(uint *)(param_1 + 2) = uVar1;
    uVar1 = (uVar1 & 0xff00ff00) >> 8 | (uVar1 & 0xff00ff) << 8;
    *(uint *)((long)pvVar2 + (lVar6 >> 0x20)) = uVar1 >> 0x10 | uVar1 << 0x10;
    uVar1 = 0x20 - (param_3 - uVar3);
    *(uint *)((long)param_1 + 0x14) = uVar1;
    *(int *)((long)param_1 + 0xc) = *(int *)((long)param_1 + 0xc) + 4;
    if (uVar3 == param_3) {
      *(undefined4 *)(param_1 + 2) = 0;
    }
    else {
      *(uint *)(param_1 + 2) = param_2 << (ulong)(uVar1 & 0x1f);
    }
  }
  else {
    *(uint *)((long)param_1 + 0x14) = uVar1;
    *(uint *)(param_1 + 2) = *(uint *)(param_1 + 2) | param_2 << (ulong)(uVar1 & 0x1f);
  }
  return;
}


