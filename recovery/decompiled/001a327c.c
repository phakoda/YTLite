/* Decompiled from supplied 5.2.2 arm package. VA 0x1a327c. presentImagePickerForVC: */

/* Function Stack Size: 0x18 bytes */

void DVNMediaPicker::presentImagePickerForVC_(ID param_1,SEL param_2,ID param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  _objc_storeStrong(param_1 + 8,param_3);
  _objc_retain(param_3);
  uVar1 = _objc_alloc_init(PTR__OBJC_CLASS___PHPickerConfiguration_0114ef18);
  _objc_msgSend(uVar1,PTR_s_setSelectionLimit__0114dbe8,1);
  _objc_msgSend(PTR__OBJC_CLASS___PHPickerFilter_0114ef20,PTR_s_videosFilter_0114dbf0);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_setFilter__0114dbf8,uVar2);
  _objc_release(uVar2);
  uVar2 = _objc_alloc(PTR__OBJC_CLASS___PHPickerViewController_0114ef28);
  uVar2 = _objc_msgSend(uVar2,PTR_s_initWithConfiguration__0114dc00,uVar1);
  _objc_msgSend(uVar2,PTR_s_setDelegate__0114b7d8,param_1);
  _objc_msgSend(param_3,PTR_s_presentViewController_animated_c_0114b298,uVar2,1,0);
  _objc_release(param_3);
  _objc_release(uVar2);
  _objc_release(uVar1);
  CallSupervisor(0x46d6);
  return;
}


