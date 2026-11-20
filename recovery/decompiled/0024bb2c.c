/* Decompiled from supplied 5.2.2 arm package. VA 0x24bb2c. FUN_0024bb2c */

void FUN_0024bb2c(long param_1,void *param_2,long param_3)

{
  void *pvVar1;
  uint uVar2;
  short sVar3;
  void *pvVar4;
  undefined *puVar5;
  long lVar6;
  long lVar7;
  undefined1 auStack_2a4 [4];
  undefined1 auStack_2a0 [20];
  undefined1 auStack_28c [480];
  undefined1 auStack_ac [46];
  undefined2 local_7e;
  undefined1 auStack_7c [28];
  
  lVar6 = *(long *)PTR____stack_chk_guard_01060708;
  pvVar1 = (void *)(param_3 + 0x4c);
  _memcpy((void *)((long)pvVar1 + (long)(int)(short)(300 - *(short *)(param_3 + 2)) * 2),param_2,
          (long)*(short *)(param_3 + 2) << 1);
  for (lVar7 = 0; lVar7 < *(short *)(param_3 + 0xc); lVar7 = lVar7 + 1) {
    pvVar4 = (void *)(param_3 + 0xc4);
    puVar5 = &DAT_00c4e61c;
    if (lVar7 < (long)*(short *)(param_3 + 0xc) + -1) {
      pvVar4 = pvVar1;
      puVar5 = &DAT_00c4e43c;
    }
    FUN_0024e3a4(auStack_28c,pvVar4,puVar5,0xf0,0xf);
    FUN_0024d684(auStack_28c,0xf0,10,auStack_ac,auStack_2a4);
    FUN_0024d244(auStack_ac,auStack_ac,&DAT_00c4e7fc,0xb);
    sVar3 = FUN_0024e44c(auStack_ac,&local_7e,auStack_2a0,10);
    if (sVar3 != 1) {
      local_7e = 0x1000;
      thunk_FUN_0024de70(auStack_7c,0,10);
    }
    FUN_00245af8(&local_7e,&local_7e,&DAT_00c4e828,0xb);
    FUN_0024b1cc(param_1,&local_7e);
    param_1 = param_1 + 0x14;
  }
  uVar2 = 300 - *(ushort *)(param_3 + 2);
  _memcpy(pvVar1,(void *)(param_3 + (long)(int)(short)uVar2 * -2 + 0x2a4),
          -((ulong)(uVar2 >> 0xf) & 1) & 0xfffffffffffe0000 | ((ulong)uVar2 & 0xffff) << 1);
  if (*(long *)PTR____stack_chk_guard_01060708 != lVar6) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  return;
}


