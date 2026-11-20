/* Decompiled from supplied 5.2.2 arm package. VA 0x266650. FUN_00266650 */

uint FUN_00266650(ulong param_1,undefined8 param_2)

{
  long lVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = (uint)((ulong)param_2 >> 0x20);
  iVar3 = (int)param_2;
  iVar2 = (int)param_1;
  lVar1 = (long)iVar2 * (long)(int)uVar4 - (long)iVar3 * ((long)param_1 >> 0x20);
  if (lVar1 == 0) {
    if ((((param_1 >> 0x20 == 0) || (uVar5 = 0, uVar4 == 0)) && (uVar5 = 0x80000000, iVar2 != 0)) &&
       (iVar3 != 0)) {
      uVar5 = (iVar2 >> 0x1f) - (iVar3 >> 0x1f);
    }
  }
  else {
    uVar5 = (int)((int)(uVar4 ^ (uint)(param_1 >> 0x20)) >> 0x1f ^ (uint)((ulong)lVar1 >> 0x20)) >>
            0x1f | 1;
  }
  return uVar5;
}


