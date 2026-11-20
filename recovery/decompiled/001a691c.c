/* Decompiled from supplied 5.2.2 arm package. VA 0x1a691c. documentPicker:didPickDocumentsAtURLs: */

/* Function Stack Size: 0x20 bytes */

void DVNMediaPicker::documentPicker_didPickDocumentsAtURLs_
               (ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  long lVar2;
  ID IVar3;
  undefined **ppuVar4;
  
  puVar1 = PTR_s_count_0114b840;
  _objc_retain(param_4);
  lVar2 = _objc_msgSend(param_4,puVar1);
  if (lVar2 == 1) {
    _objc_msgSend(param_4,PTR_s_firstObject_0114b748);
    IVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_release(param_4);
    ppuVar4 = &PTR_s_prepareMediaForUse__0114dc30;
  }
  else {
    ppuVar4 = &PTR_s_prepareURLsForImport__0114dc50;
    IVar3 = param_4;
  }
  _objc_msgSend(param_1,*ppuVar4,IVar3);
  _objc_release(IVar3);
  CallSupervisor(0xd2e0);
  return;
}


