/* Decompiled from supplied 5.2.2 arm package. VA 0x257a20. _av_encryption_info_clone */

undefined4 * _av_encryption_info_clone(undefined8 *param_1)

{
  undefined4 *puVar1;
  undefined8 uVar2;
  
  puVar1 = (undefined4 *)
           _av_encryption_info_alloc
                     (*(undefined4 *)(param_1 + 7),*(undefined4 *)(param_1 + 3),
                      *(undefined4 *)(param_1 + 5));
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    uVar2 = *param_1;
    *puVar1 = (int)uVar2;
    puVar1[1] = (int)((ulong)uVar2 >> 0x20);
    puVar1[2] = *(undefined4 *)(param_1 + 1);
    _memcpy(*(void **)(puVar1 + 8),(void *)param_1[4],(ulong)*(uint *)(param_1 + 5));
    _memcpy(*(void **)(puVar1 + 4),(void *)param_1[2],(ulong)*(uint *)(param_1 + 3));
    _memcpy(*(void **)(puVar1 + 0xc),(void *)param_1[6],(ulong)*(uint *)(param_1 + 7) << 3);
  }
  return puVar1;
}


