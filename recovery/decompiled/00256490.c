/* Decompiled from supplied 5.2.2 arm package. VA 0x256490. _av_crc_init */

undefined4 _av_crc_init(long param_1,int param_2,uint param_3,uint param_4,int param_5)

{
  undefined4 uVar1;
  ulong uVar2;
  int iVar3;
  uint uVar4;
  ulong uVar5;
  
  if (((param_3 - 8 < 0x19) && ((long)(ulong)param_4 < 1L << ((ulong)param_3 & 0x3f))) &&
     ((param_5 == 0x1000 || (param_5 == 0x404)))) {
    for (uVar2 = 0; uVar2 != 0x100; uVar2 = uVar2 + 1) {
      if (param_2 == 0) {
        uVar4 = (int)uVar2 << 0x18;
        iVar3 = 9;
        while (iVar3 = iVar3 + -1, iVar3 != 0) {
          uVar4 = param_4 << (ulong)(0x20 - param_3 & 0x1f) & (int)uVar4 >> 0x1f ^ uVar4 << 1;
        }
        uVar4 = (uVar4 & 0xff00ff00) >> 8 | (uVar4 & 0xff00ff) << 8;
        *(uint *)(param_1 + uVar2 * 4) = uVar4 >> 0x10 | uVar4 << 0x10;
      }
      else {
        iVar3 = 9;
        uVar5 = uVar2 & 0xffffffff;
        while( true ) {
          iVar3 = iVar3 + -1;
          uVar4 = (uint)uVar5;
          if (iVar3 == 0) break;
          uVar5 = (ulong)(-(uVar4 & 1) & param_4 ^ uVar4 >> 1);
        }
        *(uint *)(param_1 + uVar2 * 4) = uVar4;
      }
    }
    uVar1 = 0;
    *(undefined4 *)(param_1 + 0x400) = 1;
  }
  else {
    uVar1 = 0xffffffea;
  }
  return uVar1;
}


