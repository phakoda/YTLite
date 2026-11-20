/* Decompiled from supplied 5.2.2 arm package. VA 0x25fc34. _av_lfg_init_from_data */

undefined8 _av_lfg_init_from_data(long param_1,long param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  uint uVar5;
  long lVar6;
  
  if (param_3 >> 0x19 == 0) {
    *(undefined4 *)(param_1 + 0x100) = 0;
    uVar4 = _av_crc_get_table(3);
    uVar3 = 1;
    uVar5 = 0;
    uVar1 = param_3;
    for (lVar6 = 0; lVar6 != 0x100; lVar6 = lVar6 + 4) {
      uVar2 = uVar1 >> 6;
      uVar3 = _av_crc(uVar4,uVar3,param_2 + (ulong)uVar5,uVar2 - uVar5);
      *(undefined4 *)(param_1 + lVar6) = uVar3;
      uVar1 = uVar1 + param_3;
      uVar5 = uVar2;
    }
    uVar4 = 0;
  }
  else {
    uVar4 = 0xffffffea;
  }
  return uVar4;
}


