/* Decompiled from supplied 5.2.2 arm package. VA 0x24c22c. FUN_0024c22c */

ushort FUN_0024c22c(uint param_1)

{
  uint uVar1;
  ushort uVar2;
  bool bVar3;
  long lVar4;
  
  bVar3 = (param_1 & 0xffff0000) != 0;
  lVar4 = (ulong)bVar3 << 4;
  uVar1 = (uint)lVar4;
  if ((0xff00 << lVar4 & param_1) != 0) {
    uVar1 = (uint)bVar3 << 4 | 8;
  }
  if ((0xf0 << (ulong)uVar1 & param_1) != 0) {
    uVar1 = uVar1 | 4;
  }
  uVar2 = (ushort)uVar1;
  if ((0xc << (ulong)uVar1 & param_1) != 0) {
    uVar2 = (ushort)uVar1 | 2;
  }
  if ((2 << (ulong)(uint)(int)(short)uVar2 & param_1) != 0) {
    uVar2 = uVar2 + 1;
  }
  if ((1 << (ulong)((int)(short)uVar2 & 0x1f) & param_1) != 0) {
    uVar2 = uVar2 + 1;
  }
  return uVar2;
}


