/* Decompiled from supplied 5.2.2 arm package. VA 0x24a124. _WebRtcIlbcfix_InitDecode */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _WebRtcIlbcfix_InitDecode(undefined2 *param_1,int param_2,undefined4 param_3)

{
  undefined8 uVar1;
  undefined2 uVar2;
  short sVar3;
  long lVar4;
  undefined8 uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  
  FUN_0024edd4();
  *param_1 = (short)param_2;
  if (param_2 == 0x14) {
    uVar2 = 1;
    uVar5 = 0x260002000400a0;
    uVar6 = 0x13;
    uVar7 = 0x39;
  }
  else {
    if (param_2 != 0x1e) {
      sVar3 = -1;
      goto LAB_0024a2ac;
    }
    uVar2 = 2;
    uVar5 = 0x320004000600f0;
    uVar6 = 0x19;
    uVar7 = 0x3a;
  }
  param_1[6] = uVar2;
  *(undefined8 *)(param_1 + 1) = uVar5;
  param_1[5] = uVar6;
  param_1[7] = uVar7;
  uVar1 = _UNK_00c4f0e8;
  uVar5 = _DAT_00c4f0e0;
  *(undefined4 *)(param_1 + 0x1a) = DAT_00c4f0f0;
  *(undefined8 *)(param_1 + 0x16) = uVar1;
  *(undefined8 *)(param_1 + 0x12) = uVar5;
  thunk_FUN_0024de70(param_1 + 8,0,10);
  thunk_FUN_0024de70(param_1 + 0x122,0,0x42);
  lVar4 = 0;
  while (lVar4 + 0x16 != 0x9a) {
    *(undefined2 *)((long)(param_1 + 0x122) + lVar4) = 0x1000;
    lVar4 = lVar4 + 0x16;
  }
  *(undefined4 *)(param_1 + 0x1c) = 0x14;
  *(undefined4 *)(param_1 + 0x1e) = 0;
  param_1[0x24] = 0;
  param_1[0x22] = 0;
  param_1[0x25] = 0x78;
  param_1[0x26] = 0x1000;
  thunk_FUN_0024de70(param_1 + 0x27,0,10);
  thunk_FUN_0024de70(param_1 + 0x31,0,0xf0);
  param_1[0x121] = 0x309;
  thunk_FUN_0024de70(param_1 + 0x164,0,2);
  thunk_FUN_0024de70(param_1 + 0x166,0,4);
  *(undefined4 *)(param_1 + 0x16a) = param_3;
  thunk_FUN_0024de70(param_1 + 0x16c,0,0x283);
  for (lVar4 = 0; lVar4 != 0x10; lVar4 = lVar4 + 2) {
    *(undefined2 *)((long)param_1 + lVar4 + 0x7de) = 0xa0;
  }
  sVar3 = param_1[1];
  *(undefined4 *)(param_1 + 0x20) = 0;
LAB_0024a2ac:
  return (int)sVar3;
}


