/* Decompiled from supplied 5.2.2 arm package. VA 0x241c54. _shine_open_bit_stream */

void _shine_open_bit_stream(undefined8 *param_1,int param_2)

{
  void *pvVar1;
  
  pvVar1 = _malloc((long)param_2);
  *param_1 = pvVar1;
  *(int *)(param_1 + 1) = param_2;
  *(undefined4 *)((long)param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 2) = 0;
  *(undefined4 *)((long)param_1 + 0x14) = 0x20;
  return;
}


