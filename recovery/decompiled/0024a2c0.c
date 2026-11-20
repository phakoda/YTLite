/* Decompiled from supplied 5.2.2 arm package. VA 0x24a2c0. _WebRtcIlbcfix_InitEncode */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _WebRtcIlbcfix_InitEncode(undefined2 *param_1,int param_2)

{
  undefined8 uVar1;
  undefined4 uVar2;
  undefined2 uVar3;
  short sVar4;
  undefined8 uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  
  FUN_0024edd4();
  *param_1 = (short)param_2;
  if (param_2 == 0x14) {
    uVar3 = 1;
    uVar5 = 0x260002000400a0;
    uVar6 = 0x13;
    uVar7 = 0x39;
  }
  else {
    if (param_2 != 0x1e) {
      sVar4 = -1;
      goto LAB_0024a3a4;
    }
    uVar3 = 2;
    uVar5 = 0x320004000600f0;
    uVar6 = 0x19;
    uVar7 = 0x3a;
  }
  param_1[6] = uVar3;
  *(undefined8 *)(param_1 + 1) = uVar5;
  param_1[5] = uVar6;
  param_1[7] = uVar7;
  thunk_FUN_0024de70(param_1 + 8,0,10);
  uVar2 = DAT_00c4f0f0;
  uVar1 = _UNK_00c4f0e8;
  uVar5 = _DAT_00c4f0e0;
  *(undefined4 *)(param_1 + 0x1a) = DAT_00c4f0f0;
  *(undefined8 *)(param_1 + 0x16) = uVar1;
  *(undefined8 *)(param_1 + 0x12) = uVar5;
  *(undefined4 *)(param_1 + 0x24) = uVar2;
  *(undefined8 *)(param_1 + 0x20) = uVar1;
  *(undefined8 *)(param_1 + 0x1c) = uVar5;
  thunk_FUN_0024de70(param_1 + 0x26,0,300);
  thunk_FUN_0024de70(param_1 + 0x152,0,2);
  thunk_FUN_0024de70(param_1 + 0x154,0,4);
  sVar4 = param_1[4];
LAB_0024a3a4:
  return (int)sVar4;
}


