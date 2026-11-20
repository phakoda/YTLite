/* Decompiled from supplied 5.2.2 arm package. VA 0x26bae4. _av_sha_final */

void _av_sha_final(byte *param_1,long param_2)

{
  uint uVar1;
  ulong uVar2;
  long lVar3;
  long lVar4;
  ulong local_38;
  
  uVar2 = (*(long *)(param_1 + 8) << 3 & 0xff00ff00ff00ff00U) >> 8 |
          (*(long *)(param_1 + 8) << 3 & 0xff00ff00ff00ffU) << 8;
  uVar2 = (uVar2 & 0xffff0000ffff0000) >> 0x10 | (uVar2 & 0xffff0000ffff) << 0x10;
  local_38 = uVar2 >> 0x20 | uVar2 << 0x20;
  _av_sha_update(param_1,s__00b9cd75,1);
  while ((*(ulong *)(param_1 + 8) & 0x3f) != 0x38) {
    _av_sha_update(param_1,"",1);
  }
  _av_sha_update(param_1,&local_38,8);
  lVar3 = 0;
  for (lVar4 = 0; lVar4 < (long)(ulong)*param_1; lVar4 = lVar4 + 1) {
    uVar1 = (*(uint *)(param_1 + lVar3 + 0x50) & 0xff00ff00) >> 8 |
            (*(uint *)(param_1 + lVar3 + 0x50) & 0xff00ff) << 8;
    *(uint *)(param_2 + (int)lVar3) = uVar1 >> 0x10 | uVar1 << 0x10;
    lVar3 = lVar3 + 4;
  }
  return;
}


