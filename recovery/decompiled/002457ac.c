/* Decompiled from supplied 5.2.2 arm package. VA 0x2457ac. FUN_002457ac */

/* WARNING: Removing unreachable block (ram,0x002458bc) */

void FUN_002457ac(long param_1,long param_2,long param_3,long param_4)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short local_17c;
  short local_17a;
  undefined1 auStack_178 [20];
  undefined1 auStack_164 [116];
  undefined1 auStack_f0 [20];
  undefined1 auStack_dc [124];
  
  thunk_FUN_0024de70(auStack_f0,0,0x44);
  thunk_FUN_0024de70(auStack_178,0,10);
  sVar1 = *(short *)(param_1 + 0xe) + -0x28;
  sVar2 = 0x28;
  sVar3 = sVar1;
  if (*(short *)(param_2 + 0x4a) != 0) {
    sVar3 = 0x28;
    sVar2 = sVar1;
  }
  local_17c = sVar3;
  local_17a = sVar2;
  FUN_0024e20c(param_3,auStack_164,param_4,0xb,(int)sVar3);
  FUN_0024e20c(param_3 + (long)sVar3 * 2,auStack_164 + (long)sVar3 * 2,param_4 + 0x16,0xb,(int)sVar2
              );
  FUN_002458c0(auStack_dc,auStack_164,param_4,&local_17c,param_2 + 0x4c);
  return;
}


