/* Decompiled from supplied 5.2.2 arm package. VA 0x245598. _shine_close */

void _shine_close(void *param_1)

{
  _shine_close_bit_stream((long)param_1 + 0x60);
  _free(param_1);
  return;
}


