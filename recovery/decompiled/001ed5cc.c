/* Decompiled from supplied 5.2.2 arm package. VA 0x1ed5cc. presentDocumentPicker: */

/* Function Stack Size: 0x18 bytes */

void YTLUserDefaults::presentDocumentPicker_(ID param_1,SEL param_2,ID param_3,undefined4 param_4)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined **appuStack_70 [2];
  undefined **local_60;
  uint local_54;
  undefined **local_50;
  long local_48;
  
  puVar1 = PTR__OBJC_CLASS___UIDocumentPickerViewController_0114ef38;
  local_48 = *(long *)PTR____stack_chk_guard_01060708;
  local_50 = &PTR_LAB_011bd1d0;
  local_54 = (uint)(DAT_01227ec8 == 0);
  local_60 = &PTR_LAB_011bce10;
  DAT_01227ec8 = 1;
  _objc_retain(param_3,param_2,param_3,param_4);
  uVar2 = _objc_alloc(puVar1);
  appuStack_70[0] = &PTR____CFConstantStringClassReference_011bccf0;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,PTR_s_arrayWithObjects_count__0114b600,
                appuStack_70,1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  uVar2 = _objc_msgSend(uVar2,PTR_s_initWithDocumentTypes_inMode__0114dc40,uVar3,0);
  _objc_release(uVar3);
  _objc_msgSend(uVar2,PTR_s_setDelegate__0114b7d8,param_1);
  _objc_msgSend(uVar2,PTR_s_setAllowsMultipleSelection__0114dc48,0);
  uVar3 = _NSClassFromString(&PTR____CFConstantStringClassReference_011bccb0);
  _objc_msgSend(uVar3,PTR_s_topViewControllerForPresenting_0114ce48);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_presentViewController_animated_c_0114b298,uVar2,1,0);
  _objc_release(uVar3);
  _objc_msgSend(param_1,PTR_s_setPrefsPickerCompletion__0114e168,param_3);
  _objc_release(param_3);
  _objc_release(uVar2);
  CallSupervisor(0x9c9f);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(0x1f,0,0,0);
}


