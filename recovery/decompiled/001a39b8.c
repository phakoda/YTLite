/* Decompiled from supplied 5.2.2 arm package. VA 0x1a39b8. presentFilePickerForVC:isMultipleSelection: */

/* Function Stack Size: 0x1c bytes */

void DVNMediaPicker::presentFilePickerForVC_isMultipleSelection_
               (ID param_1,SEL param_2,ID param_3,bool param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined **ppuStack_190;
  undefined **ppuStack_188;
  undefined **ppuStack_180;
  undefined **ppuStack_178;
  undefined **ppuStack_170;
  undefined **ppuStack_168;
  undefined **ppuStack_160;
  undefined **ppuStack_158;
  undefined **ppuStack_150;
  undefined **ppuStack_148;
  undefined **ppuStack_140;
  undefined **ppuStack_138;
  undefined **ppuStack_130;
  undefined **ppuStack_128;
  undefined **ppuStack_120;
  undefined **ppuStack_118;
  undefined **ppuStack_110;
  undefined **ppuStack_108;
  undefined **ppuStack_100;
  undefined **ppuStack_f8;
  undefined **ppuStack_f0;
  undefined **ppuStack_e8;
  undefined **ppuStack_e0;
  undefined **ppuStack_d8;
  undefined **ppuStack_d0;
  undefined **ppuStack_c8;
  undefined **ppuStack_c0;
  undefined **ppuStack_b8;
  undefined **ppuStack_b0;
  undefined **ppuStack_a8;
  undefined **local_80;
  uint local_74;
  undefined **local_70;
  long local_68;
  
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  local_70 = &PTR_LAB_011ae888;
  local_74 = (uint)(DAT_01227964 == 0);
  local_80 = &PTR_LAB_011ae4f0;
  DAT_01227964 = 1;
  _objc_storeStrong(param_1 + 8,param_3);
  _objc_retain(param_3);
  ppuStack_190 = &PTR____CFConstantStringClassReference_011adeb0;
  ppuStack_188 = &PTR____CFConstantStringClassReference_011adc70;
  ppuStack_180 = &PTR____CFConstantStringClassReference_011adcf0;
  ppuStack_178 = &PTR____CFConstantStringClassReference_011addf0;
  ppuStack_170 = &PTR____CFConstantStringClassReference_011addb0;
  ppuStack_168 = &PTR____CFConstantStringClassReference_011adaf0;
  ppuStack_160 = &PTR____CFConstantStringClassReference_011add70;
  ppuStack_158 = &PTR____CFConstantStringClassReference_011adcb0;
  ppuStack_150 = &PTR____CFConstantStringClassReference_011ad8b0;
  ppuStack_148 = &PTR____CFConstantStringClassReference_011adc30;
  ppuStack_140 = &PTR____CFConstantStringClassReference_011adbf0;
  ppuStack_138 = &PTR____CFConstantStringClassReference_011ada70;
  ppuStack_130 = &PTR____CFConstantStringClassReference_011ade70;
  ppuStack_128 = &PTR____CFConstantStringClassReference_011adb70;
  ppuStack_120 = &PTR____CFConstantStringClassReference_011ad930;
  ppuStack_118 = &PTR____CFConstantStringClassReference_011adb30;
  ppuStack_110 = &PTR____CFConstantStringClassReference_011adab0;
  ppuStack_108 = &PTR____CFConstantStringClassReference_011add30;
  ppuStack_100 = &PTR____CFConstantStringClassReference_011ada30;
  ppuStack_f8 = &PTR____CFConstantStringClassReference_011ad8f0;
  ppuStack_f0 = &PTR____CFConstantStringClassReference_011ad9b0;
  ppuStack_e8 = &PTR____CFConstantStringClassReference_011ade30;
  ppuStack_e0 = &PTR____CFConstantStringClassReference_011ad970;
  ppuStack_d8 = &PTR____CFConstantStringClassReference_011ad870;
  ppuStack_d0 = &PTR____CFConstantStringClassReference_011ad830;
  ppuStack_c8 = &PTR____CFConstantStringClassReference_011ad7f0;
  ppuStack_c0 = &PTR____CFConstantStringClassReference_011ad7b0;
  ppuStack_b8 = &PTR____CFConstantStringClassReference_011adbb0;
  ppuStack_b0 = &PTR____CFConstantStringClassReference_011ad770;
  ppuStack_a8 = &PTR____CFConstantStringClassReference_011ad9f0;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,PTR_s_arrayWithObjects_count__0114b600,
                &ppuStack_190,0x1e);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  uVar2 = _objc_alloc(PTR__OBJC_CLASS___UIDocumentPickerViewController_0114ef38);
  uVar2 = _objc_msgSend(uVar2,PTR_s_initWithDocumentTypes_inMode__0114dc40,uVar1,0);
  _objc_msgSend(uVar2,PTR_s_setDelegate__0114b7d8,param_1);
  _objc_msgSend(uVar2,PTR_s_setAllowsMultipleSelection__0114dc48,param_4);
  _objc_msgSend(param_3,PTR_s_presentViewController_animated_c_0114b298,uVar2,1,0);
  _objc_release(param_3);
  _objc_release(uVar2);
  _objc_release(uVar1);
  CallSupervisor(0x4294);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(0x1f,0,0,0);
}


