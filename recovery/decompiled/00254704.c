/* Decompiled from supplied 5.2.2 arm package. VA 0x254704. FUN_00254704 */

undefined8 FUN_00254704(long *param_1,uint param_2)

{
  uint uVar1;
  long lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined8 uVar6;
  void *pvVar7;
  
  uVar3 = *(uint *)((long)param_1 + 0xc);
  uVar5 = *(uint *)(param_1 + 2);
  if (uVar3 == uVar5) {
    uVar6 = 0xfffffffb;
  }
  else {
    uVar4 = *(uint *)(param_1 + 1);
    if (uVar4 < *(uint *)((long)param_1 + 0xc)) {
      if (-uVar4 - 2 <= param_2) {
        param_2 = -uVar4 - 2;
      }
      uVar1 = uVar5;
      if (uVar3 <= uVar5 >> 1) {
        uVar1 = uVar3 << 1;
      }
      uVar3 = uVar4 + param_2 + 1;
      if (uVar3 < uVar5) {
        uVar5 = uVar4 + param_2 + 1;
      }
      if (uVar3 <= uVar1) {
        uVar5 = uVar1;
      }
      lVar2 = 0;
      if (*param_1 != (long)param_1 + 0x14) {
        lVar2 = *param_1;
      }
      pvVar7 = (void *)_av_realloc(lVar2,uVar5);
      if (pvVar7 == (void *)0x0) {
        uVar6 = 0xfffffff4;
      }
      else {
        if (lVar2 == 0) {
          _memcpy(pvVar7,(void *)*param_1,(ulong)((int)param_1[1] + 1));
        }
        uVar6 = 0;
        *param_1 = (long)pvVar7;
        *(uint *)((long)param_1 + 0xc) = uVar5;
      }
    }
    else {
      uVar6 = 0xbebbb1b7;
    }
  }
  return uVar6;
}


