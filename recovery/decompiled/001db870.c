/* Decompiled from supplied 5.2.2 arm package. VA 0x1db870. FUN_001db870 */

undefined1  [16] FUN_001db870(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  undefined8 uVar1;
  undefined *puVar2;
  undefined8 uVar3;
  undefined1 auVar4 [16];
  
  puVar2 = PTR_s_objectForKeyedSubscript__0114ae80;
  DAT_01227ddc = 1;
  uVar1 = *(undefined8 *)(param_1 + 0x20);
  uVar3 = *(undefined8 *)(param_1 + 0x28);
  _objc_retain(param_4);
  _objc_msgSend(uVar3,puVar2,&PTR____CFConstantStringClassReference_011b8b50);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_removeChannelWithLink__0114e0a0,uVar3);
  _objc_release(uVar3);
  (**(code **)(param_4 + 0x10))(param_4,1);
  _objc_release(param_4);
  CallSupervisor(0xb9a8);
  auVar4._8_8_ = 0x1f;
  auVar4._0_8_ = 0x1a;
  return auVar4;
}


