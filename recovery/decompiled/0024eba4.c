/* Decompiled from supplied 5.2.2 arm package. VA 0x24eba4. FUN_0024eba4 */

uint * FUN_0024eba4(uint param_1)

{
  uint *puVar1;
  
  if ((param_1 < 0xb) && (puVar1 = _malloc(4), puVar1 != (uint *)0x0)) {
    *puVar1 = param_1;
  }
  else {
    puVar1 = (uint *)0x0;
  }
  return puVar1;
}


