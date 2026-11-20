/* Decompiled from supplied 5.2.2 arm package. VA 0x259518. FUN_00259518 */

undefined4 * FUN_00259518(undefined4 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_av_mallocz(0x40);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = param_1;
    *(undefined8 *)(puVar1 + 8) = param_2;
    *(undefined8 *)(puVar1 + 10) = param_3;
    *(undefined8 *)(puVar1 + 2) = 0x3ff0000000000000;
  }
  return puVar1;
}


