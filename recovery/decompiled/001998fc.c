/* Decompiled from supplied 5.2.2 arm package. VA 0x1998fc. FUN_001998fc */

undefined1  [16] FUN_001998fc(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar2 = _objc_alloc_init(*(undefined8 *)(param_1 + 0x20));
  uVar1 = DAT_01227888;
  DAT_01227888 = uVar2;
  _objc_release(uVar1);
  CallSupervisor(0x8efb);
  return ZEXT816(0x1f);
}


