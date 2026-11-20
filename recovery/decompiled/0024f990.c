/* Decompiled from supplied 5.2.2 arm package. VA 0x24f990. _oggpackB_look */

ulong _oggpackB_look(long *param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte *pbVar5;
  
  uVar3 = -param_2 + 0x20;
  if ((int)(uVar3 | param_2) < 0) {
    return 0xffffffffffffffff;
  }
  uVar2 = *(uint *)(param_1 + 1);
  iVar1 = uVar2 + param_2;
  if (param_1[4] + -4 <= *param_1) {
    if (param_1[4] - (long)(iVar1 + 7 >> 3) < *param_1) {
      return 0xffffffffffffffff;
    }
    if (iVar1 == 0) {
      return 0;
    }
  }
  pbVar5 = (byte *)param_1[3];
  uVar4 = (uint)*pbVar5 << (ulong)(uVar2 + 0x18 & 0x1f);
  if ((((8 < iVar1) &&
       (uVar4 = (uint)pbVar5[1] << (ulong)(uVar2 + 0x10 & 0x1f) | uVar4, 0x10 < iVar1)) &&
      (uVar4 = (uint)pbVar5[2] << (ulong)(uVar2 + 8 & 0x1f) | uVar4, 0x18 < iVar1)) &&
     ((uVar4 = (uint)pbVar5[3] << (ulong)(uVar2 & 0x1f) | uVar4, 0x20 < iVar1 && (uVar2 != 0)))) {
    uVar4 = pbVar5[4] >> (ulong)(8 - uVar2 & 0x1f) | uVar4;
  }
  return (ulong)((uVar4 >> ((ulong)(uint)((int)uVar3 >> 1) & 0x3f)) >>
                ((ulong)(uint)((int)(-param_2 + 0x21) >> 1) & 0x3f));
}


