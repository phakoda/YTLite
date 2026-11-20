/* Decompiled from supplied 5.2.2 arm package. VA 0x268140. _av_get_bits_per_pixel */

int _av_get_bits_per_pixel(long param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  
  iVar6 = 0;
  iVar5 = 0;
  uVar1 = (uint)*(byte *)(param_1 + 10) + (uint)*(byte *)(param_1 + 9);
  piVar7 = (int *)(param_1 + 0x28);
  for (uVar4 = (uint)*(byte *)(param_1 + 8); uVar4 != 0; uVar4 = uVar4 - 1) {
    uVar3 = iVar6 - 1;
    iVar6 = iVar6 + 1;
    uVar2 = 0;
    if (1 < uVar3) {
      uVar2 = uVar1;
    }
    iVar5 = (*piVar7 << (ulong)(uVar2 & 0x1f)) + iVar5;
    piVar7 = piVar7 + 8;
  }
  return iVar5 >> (uVar1 & 0x1f);
}


