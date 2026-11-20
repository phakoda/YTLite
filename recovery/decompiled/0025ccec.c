/* Decompiled from supplied 5.2.2 arm package. VA 0x25ccec. _av_hash_final_b64 */

/* WARNING: Removing unreachable block (ram,0x0025cdb8) */

void _av_hash_final_b64(long param_1,void *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined1 auStack_e1 [89];
  undefined1 auStack_88 [72];
  
  iVar3 = *(int *)(&DAT_01064500 + (ulong)*(uint *)(param_1 + 8) * 0x10);
  _av_hash_final(param_1,auStack_88);
  _av_base64_encode(auStack_e1,0x59,auStack_88,iVar3);
  uVar1 = (iVar3 + 2U) / 3 << 2 | 1;
  uVar2 = param_3;
  if (uVar1 <= param_3) {
    uVar2 = uVar1;
  }
  _memcpy(param_2,auStack_e1,(ulong)uVar2);
  if (param_3 < uVar1) {
    *(undefined1 *)((long)param_2 + (long)(int)param_3 + -1) = 0;
  }
  return;
}


