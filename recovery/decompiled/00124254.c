/* Decompiled from supplied 5.2.2 arm package. VA 0x124254. FUN_00124254 */

void FUN_00124254(long param_1)

{
  undefined *puVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  long lVar5;
  
  puVar1 = PTR_s_validationHandler_0114d620;
  _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_validationHandler_0114d620);
  lVar2 = _objc_retainAutoreleasedReturnValue();
  if (lVar2 == 0) {
    _objc_msgSend(*(undefined8 *)(param_1 + 0x28),PTR_s_text_0114b370);
    lVar5 = _objc_retainAutoreleasedReturnValue();
  }
  else {
    _objc_msgSend((&PTR_LAB_0118dff8)[lVar2 == 0] + (int)-(DAT_0118e008 ^ 0xefb330d7),
                  *(undefined8 *)(param_1 + 0x20),puVar1);
    lVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(*(undefined8 *)(param_1 + 0x28),PTR_s_text_0114b370);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    (**(code **)(lVar3 + 0x10))(lVar3,uVar4);
    lVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar4);
    _objc_release(lVar3);
  }
  _objc_release(lVar2);
                    /* WARNING: Could not recover jumptable at 0x001243b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0118e020)[lVar5 == 0] + (int)-(DAT_0118e030 ^ 0xd2fc9572)))();
  return;
}


