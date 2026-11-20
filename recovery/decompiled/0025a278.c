/* Decompiled from supplied 5.2.2 arm package. VA 0x25a278. FUN_0025a278 */

undefined8 * FUN_0025a278(void *param_1,long param_2)

{
  undefined8 *puVar1;
  
  if (param_1 != (void *)0x0) {
    puVar1 = (undefined8 *)_av_mallocz(0x28);
    if (puVar1 != (undefined8 *)0x0) {
      *puVar1 = param_1;
      puVar1[1] = param_1;
      puVar1[2] = param_1;
      puVar1[3] = (long)param_1 + param_2;
      puVar1[4] = 0;
      return puVar1;
    }
    _av_free(param_1);
  }
  return (undefined8 *)0x0;
}


