/* Decompiled from supplied 5.2.2 arm package. VA 0x25e3d4. FUN_0025e3d4 */

undefined8 FUN_0025e3d4(long param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined4 *puVar1;
  undefined8 uVar2;
  
  puVar1 = (undefined4 *)_av_malloc_array(2,4);
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 0xfffffff4;
  }
  else {
    uVar2 = 0;
    *puVar1 = *(undefined4 *)(param_1 + 0x48);
    puVar1[1] = 0xffffffff;
    *param_3 = puVar1;
  }
  return uVar2;
}


