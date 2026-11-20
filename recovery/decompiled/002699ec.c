/* Decompiled from supplied 5.2.2 arm package. VA 0x2699ec. _av_rc4_init */

undefined4 _av_rc4_init(long param_1,long param_2,uint param_3)

{
  int iVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  long lVar4;
  byte bVar5;
  int iVar6;
  
  if ((param_3 & 7) == 0) {
    for (lVar4 = 0; lVar4 != 0x100; lVar4 = lVar4 + 1) {
      *(char *)(param_1 + lVar4) = (char)lVar4;
    }
    bVar5 = 0;
    iVar6 = 0;
    for (lVar4 = 0; lVar4 != 0x100; lVar4 = lVar4 + 1) {
      iVar1 = 0;
      if (iVar6 != (int)param_3 >> 3) {
        iVar1 = iVar6;
      }
      bVar5 = *(char *)(param_1 + lVar4) + bVar5 + *(char *)(param_2 + iVar1);
      uVar2 = *(undefined1 *)(param_1 + (ulong)bVar5);
      *(char *)(param_1 + (ulong)bVar5) = *(char *)(param_1 + lVar4);
      *(undefined1 *)(param_1 + lVar4) = uVar2;
      iVar6 = iVar1 + 1;
    }
    uVar3 = 0;
    *(undefined4 *)(param_1 + 0x100) = 1;
    *(uint *)(param_1 + 0x104) = (uint)*(byte *)(param_1 + 1);
  }
  else {
    uVar3 = 0xffffffea;
  }
  return uVar3;
}


