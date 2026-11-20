/* Decompiled from supplied 5.2.2 arm package. VA 0x269b08. _av_ripemd_init */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _av_ripemd_init(undefined1 *param_1,uint param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  code *pcVar7;
  
  *param_1 = (char)(param_2 >> 5);
  uVar6 = _UNK_00c51418;
  uVar5 = _DAT_00c51410;
  uVar4 = _UNK_00c51408;
  uVar3 = _DAT_00c51400;
  uVar2 = _UNK_00c513f8;
  uVar1 = _DAT_00c513f0;
  if ((int)param_2 < 0x100) {
    if (param_2 != 0x80) {
      if (param_2 != 0xa0) {
        return 0xffffffea;
      }
      *(undefined4 *)(param_1 + 0x60) = 0xc3d2e1f0;
      *(undefined8 *)(param_1 + 0x58) = uVar2;
      *(undefined8 *)(param_1 + 0x50) = uVar1;
      *(code **)(param_1 + 0x78) = FUN_00269fd0;
      goto LAB_00269bd4;
    }
    pcVar7 = FUN_00269be4;
    *(undefined8 *)(param_1 + 0x58) = _UNK_00c513f8;
    *(undefined8 *)(param_1 + 0x50) = uVar1;
  }
  else {
    if (param_2 != 0x100) {
      if (param_2 != 0x140) {
        return 0xffffffea;
      }
      *(undefined4 *)(param_1 + 0x70) = 0x1234567;
      *(undefined4 *)(param_1 + 0x74) = 0x3c2d1e0f;
      *(undefined8 *)(param_1 + 0x58) = uVar2;
      *(undefined8 *)(param_1 + 0x50) = uVar1;
      *(undefined8 *)(param_1 + 0x68) = uVar4;
      *(undefined8 *)(param_1 + 0x60) = uVar3;
      *(code **)(param_1 + 0x78) = FUN_0026a8ac;
      goto LAB_00269bd4;
    }
    pcVar7 = FUN_0026a4a8;
    *(undefined8 *)(param_1 + 0x58) = _UNK_00c513f8;
    *(undefined8 *)(param_1 + 0x50) = uVar1;
    *(undefined8 *)(param_1 + 0x68) = uVar6;
    *(undefined8 *)(param_1 + 0x60) = uVar5;
  }
  *(code **)(param_1 + 0x78) = pcVar7;
LAB_00269bd4:
  *(undefined8 *)(param_1 + 8) = 0;
  return 0;
}


