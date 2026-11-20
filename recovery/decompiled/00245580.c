/* Decompiled from supplied 5.2.2 arm package. VA 0x245580. _shine_flush */

undefined8 _shine_flush(long param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0x6c);
  *(undefined4 *)(param_1 + 0x6c) = 0;
  return *(undefined8 *)(param_1 + 0x60);
}


