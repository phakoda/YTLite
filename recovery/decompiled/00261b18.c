/* Decompiled from supplied 5.2.2 arm package. VA 0x261b18. _av_freep */

void _av_freep(undefined8 *param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)*param_1;
  *param_1 = 0;
  _free(pvVar1);
  return;
}


