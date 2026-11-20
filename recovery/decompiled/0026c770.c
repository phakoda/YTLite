/* Decompiled from supplied 5.2.2 arm package. VA 0x26c770. _av_spherical_tile_bounds */

void _av_spherical_tile_bounds
               (long param_1,long param_2,long param_3,ulong *param_4,ulong *param_5,long *param_6,
               long *param_7)

{
  uint uVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  
  uVar1 = *(uint *)(param_1 + 0x14);
  uVar3 = (ulong)(~*(uint *)(param_1 + 0x18) - *(uint *)(param_1 + 0x10));
  uVar2 = 0;
  if (uVar3 != 0) {
    uVar2 = (ulong)((param_2 << 0x20) - param_2) / uVar3;
  }
  uVar4 = (ulong)(~*(uint *)(param_1 + 0x1c) - uVar1);
  uVar3 = 0;
  if (uVar4 != 0) {
    uVar3 = (ulong)((param_3 << 0x20) - param_3) / uVar4;
  }
  *param_4 = (uVar2 * *(uint *)(param_1 + 0x10) + 0xfffffffe) / 0xffffffff;
  *param_5 = (uVar1 * uVar3 + 0xfffffffe) / 0xffffffff;
  *param_6 = (uVar2 - param_2) - *param_4;
  *param_7 = (uVar3 - param_3) - *param_5;
  return;
}


