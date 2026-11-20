/* Decompiled from supplied 5.2.2 arm package. VA 0x24a8d0. FUN_0024a8d0 */

void FUN_0024a8d0(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
                 undefined4 param_5)

{
  uint uVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  ulong uVar5;
  
  uVar5 = (*DAT_0191b7d0)(param_2,param_3);
  uVar1 = (uint)(uVar5 >> 0xb) & 0x10;
  uVar4 = (uint)uVar5;
  if ((0xff00 << (ulong)uVar1 & uVar4) != 0) {
    uVar1 = uVar1 | 8;
  }
  if ((0xf0 << (ulong)uVar1 & uVar4) != 0) {
    uVar1 = uVar1 | 4;
  }
  uVar3 = (ushort)uVar1;
  if ((0xc << (ulong)uVar1 & uVar4) != 0) {
    uVar3 = (ushort)uVar1 | 2;
  }
  if ((2 << (ulong)(uint)(int)(short)uVar3 & uVar4) != 0) {
    uVar3 = uVar3 + 1;
  }
  if ((1 << (ulong)((int)(short)uVar3 & 0x1f) & uVar4) != 0) {
    uVar3 = uVar3 + 1;
  }
  uVar3 = uVar3 * 2 - 0x1a;
  uVar2 = 0;
  if ((uVar3 & 0x8000) == 0) {
    uVar2 = uVar3;
  }
                    /* WARNING: Could not recover jumptable at 0x0024a9cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_0191b800)(param_1,param_4,param_2,param_5,
                  (int)(short)(((short)param_3 + 1) - (short)param_5),(int)(short)uVar2,1);
  return;
}


