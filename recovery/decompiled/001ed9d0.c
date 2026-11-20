/* Decompiled from supplied 5.2.2 arm package. VA 0x1ed9d0. documentPicker:didPickDocumentAtURL: */

/* Function Stack Size: 0x20 bytes */

void YTLUserDefaults::documentPicker_didPickDocumentAtURL_
               (ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  long lVar2;
  
  _objc_retain(param_4);
  puVar1 = PTR_s_prefsPickerCompletion_0114e170;
  _objc_msgSend(param_1,PTR_s_prefsPickerCompletion_0114e170);
  lVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_release();
  if (lVar2 != 0) {
    _objc_msgSend((&PTR_LAB_011bd1f0)[lVar2 == 0] + (int)-(DAT_011bd200 ^ 0xb4b81dd1),param_1,puVar1
                 );
    lVar2 = _objc_retainAutoreleasedReturnValue();
    (**(code **)(lVar2 + 0x10))(lVar2,param_4);
    _objc_release(lVar2);
  }
  _objc_release(param_4);
  CallSupervisor(0x9fe3);
  return;
}


