/* Decompiled from supplied 5.2.2 arm package. VA 0x254f9c. _av_buffer_create */

undefined8 *
_av_buffer_create(undefined8 param_1,undefined4 param_2,code *param_3,undefined8 param_4,
                 undefined4 param_5)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 *local_48;
  
  puVar1 = (undefined8 *)_av_mallocz(0x28);
  if (puVar1 != (undefined8 *)0x0) {
    *puVar1 = param_1;
    *(undefined4 *)(puVar1 + 1) = param_2;
    if (param_3 == (code *)0x0) {
      param_3 = _av_buffer_default_free;
    }
    puVar1[2] = param_3;
    puVar1[3] = param_4;
    *(undefined4 *)((long)puVar1 + 0xc) = 1;
    *(undefined4 *)(puVar1 + 4) = param_5;
    local_48 = puVar1;
    puVar2 = (undefined8 *)_av_mallocz(0x18);
    if (puVar2 != (undefined8 *)0x0) {
      *puVar2 = puVar1;
      puVar2[1] = param_1;
      *(undefined4 *)(puVar2 + 2) = param_2;
      return puVar2;
    }
    _av_freep(&local_48);
  }
  return (undefined8 *)0x0;
}


