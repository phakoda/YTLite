/* Decompiled from supplied 5.2.2 arm package. VA 0x261880. _av_md5_final */

void _av_md5_final(ulong *param_1,long param_2)

{
  long lVar1;
  undefined4 *puVar2;
  long local_38;
  
  local_38 = *param_1 << 3;
  _av_md5_update(param_1,s__00b9cd75,1);
  while ((*param_1 & 0x3f) != 0x38) {
    _av_md5_update(param_1,"",1);
  }
  _av_md5_update(param_1,&local_38,8);
  puVar2 = (undefined4 *)((long)param_1 + 0x54);
  for (lVar1 = 0; lVar1 != 0x10; lVar1 = lVar1 + 4) {
    *(undefined4 *)(param_2 + lVar1) = *puVar2;
    puVar2 = puVar2 + -1;
  }
  return;
}


