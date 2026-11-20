/* Decompiled from supplied 5.2.2 arm package. VA 0x81bd4. FUN_00081bd4 */

undefined1  [16] FUN_00081bd4(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined1 auVar3 [16];
  
  puVar1 = PTR_s_parentResponder_0114aef0;
  _objc_retain(param_3);
  _objc_msgSend(param_1,puVar1);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR_DownloadMenuHelper_0114ed78,PTR_s_showDownloadSheet_withSender__0114c780,uVar2,
                param_3);
  _objc_release(param_3);
  _objc_release(uVar2);
  CallSupervisor(0xec22);
  auVar3._8_8_ = 0x1f;
  auVar3._0_8_ = 0x1a;
  return auVar3;
}


