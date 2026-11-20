/* Decompiled from supplied 5.2.2 arm package. VA 0x25b53c. FUN_0025b53c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0025b53c(void *param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  if (*(void **)((long)param_1 + 0x60) != param_1) {
    _av_freep();
  }
  _bzero(param_1,0x218);
  *(undefined8 *)((long)param_1 + 0x90) = 0x8000000000000000;
  *(undefined8 *)((long)param_1 + 0x98) = 0x8000000000000000;
  *(undefined8 *)((long)param_1 + 0x88) = 0x8000000000000000;
  *(undefined8 *)((long)param_1 + 0x198) = 0x8000000000000000;
  *(undefined8 *)((long)param_1 + 0x1a0) = 0xffffffffffffffff;
  *(undefined8 *)((long)param_1 + 0x1a8) = 0;
  uVar2 = _UNK_00c50e28;
  uVar1 = _DAT_00c50e20;
  *(undefined4 *)((long)param_1 + 0x80) = 0;
  *(undefined4 *)((long)param_1 + 0x84) = 1;
  *(void **)((long)param_1 + 0x60) = param_1;
  *(undefined4 *)((long)param_1 + 400) = 0;
  *(undefined4 *)((long)param_1 + 0x1c0) = 0xffffffff;
  *(undefined4 *)((long)param_1 + 0x74) = 0xffffffff;
  *(undefined4 *)((long)param_1 + 0x78) = 1;
  *(undefined8 *)((long)param_1 + 0x188) = uVar2;
  *(undefined8 *)((long)param_1 + 0x180) = uVar1;
  *(undefined4 *)((long)param_1 + 0x17c) = 0;
  return;
}


