/* Decompiled from supplied 5.2.2 arm package. VA 0x26c074. _av_sha512_final */

/* WARNING: Type propagation algorithm not settling */

void _av_sha512_final(byte *param_1,ulong *param_2)

{
  uint uVar1;
  ulong uVar2;
  ulong uVar3;
  ulong local_40 [2];
  
  local_40[1] = 0;
  uVar3 = (*(long *)(param_1 + 8) << 3 & 0xff00ff00ff00ff00U) >> 8 |
          (*(long *)(param_1 + 8) << 3 & 0xff00ff00ff00ffU) << 8;
  uVar3 = (uVar3 & 0xffff0000ffff0000) >> 0x10 | (uVar3 & 0xffff0000ffff) << 0x10;
  local_40[0] = uVar3 >> 0x20 | uVar3 << 0x20;
  _av_sha512_update(param_1,s__00b9cd75,1);
  while ((*(ulong *)(param_1 + 8) & 0x7f) != 0x70) {
    _av_sha512_update(param_1,"",1);
  }
  _av_sha512_update(param_1,local_40 + 1,8);
  _av_sha512_update(param_1,local_40,8);
  for (uVar3 = 0; uVar3 < *param_1; uVar3 = uVar3 + 1) {
    uVar2 = (*(ulong *)(param_1 + uVar3 * 8 + 0x90) & 0xff00ff00ff00ff00) >> 8 |
            (*(ulong *)(param_1 + uVar3 * 8 + 0x90) & 0xff00ff00ff00ff) << 8;
    uVar2 = (uVar2 & 0xffff0000ffff0000) >> 0x10 | (uVar2 & 0xffff0000ffff) << 0x10;
    *param_2 = uVar2 >> 0x20 | uVar2 << 0x20;
    param_2 = param_2 + 1;
  }
  if ((*param_1 & 1) != 0) {
    uVar1 = (*(uint *)(param_1 + uVar3 * 8 + 0x94) & 0xff00ff00) >> 8 |
            (*(uint *)(param_1 + uVar3 * 8 + 0x94) & 0xff00ff) << 8;
    *(uint *)param_2 = uVar1 >> 0x10 | uVar1 << 0x10;
  }
  return;
}


