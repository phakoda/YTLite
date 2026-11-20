/* Decompiled from supplied 5.2.2 arm package. VA 0x1dec80. FUN_001dec80 */

undefined1  [16] FUN_001dec80(long param_1,long param_2)

{
  undefined1 auVar1 [16];
  
  *(undefined8 *)(param_1 + 0x28) = *(undefined8 *)(param_2 + 0x28);
  *(undefined8 *)(param_2 + 0x28) = 0;
  CallSupervisor(0xf27b);
  auVar1._8_8_ = 0x1f;
  auVar1._0_8_ = 0x1a;
  return auVar1;
}


