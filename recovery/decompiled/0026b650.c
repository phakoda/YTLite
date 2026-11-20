/* Decompiled from supplied 5.2.2 arm package. VA 0x26b650. _av_sha_init */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _av_sha_init(undefined1 *param_1,uint param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  *param_1 = (char)(param_2 >> 5);
  uVar2 = _UNK_00c513f8;
  uVar1 = _DAT_00c513f0;
  uVar3 = _DAT_00c51a20;
  uVar4 = _UNK_00c51a28;
  uVar5 = _DAT_00c51a30;
  uVar6 = _UNK_00c51a38;
  if ((param_2 == 0x100) ||
     (uVar3 = _DAT_00c51a40, uVar4 = _UNK_00c51a48, uVar5 = _DAT_00c51a50, uVar6 = _UNK_00c51a58,
     param_2 == 0xe0)) {
    *(undefined8 *)(param_1 + 0x58) = uVar4;
    *(undefined8 *)(param_1 + 0x50) = uVar3;
    *(undefined8 *)(param_1 + 0x68) = uVar6;
    *(undefined8 *)(param_1 + 0x60) = uVar5;
    *(code **)(param_1 + 0x70) = FUN_0026b898;
  }
  else {
    if (param_2 != 0xa0) {
      return 0xffffffea;
    }
    *(undefined4 *)(param_1 + 0x60) = 0xc3d2e1f0;
    *(undefined8 *)(param_1 + 0x58) = uVar2;
    *(undefined8 *)(param_1 + 0x50) = uVar1;
    *(code **)(param_1 + 0x70) = FUN_0026b6e8;
  }
  *(undefined8 *)(param_1 + 8) = 0;
  return 0;
}


