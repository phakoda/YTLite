/* Decompiled from supplied 5.2.2 arm package. VA 0x15014. FUN_00015014 */

void FUN_00015014(long param_1)

{
  undefined *puVar1;
  long lVar2;
  
  puVar1 = PTR_s_completion_0114b0b8;
  _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_completion_0114b0b8);
  lVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_release();
  if (lVar2 != 0) {
    _objc_msgSend((&PTR_LAB_01155040)[lVar2 == 0] + (int)-(DAT_01155050 ^ 0xb395ed2b),
                  *(undefined8 *)(param_1 + 0x20),puVar1);
    lVar2 = _objc_retainAutoreleasedReturnValue();
    (**(code **)(lVar2 + 0x10))();
    (*(code *)PTR__objc_release_01061028)(lVar2);
    return;
  }
  return;
}


