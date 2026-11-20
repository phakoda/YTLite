/* Decompiled from supplied 5.2.2 arm package. VA 0x123038. stepperLabelForCell: */

/* Function Stack Size: 0x18 bytes */

ID DVNTableViewController::stepperLabelForCell_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  ID IVar7;
  float fVar8;
  undefined8 auStack_c0 [2];
  undefined8 auStack_b0 [3];
  undefined8 *puStack_98;
  undefined **local_90;
  uint local_84;
  undefined **local_80;
  long local_78;
  
  puVar1 = PTR__OBJC_CLASS___NSMutableAttributedString_0114ec28;
  local_78 = *(long *)PTR____stack_chk_guard_01060708;
  local_80 = &PTR_LAB_0118df70;
  local_84 = (uint)(DAT_01227374 == 0);
  local_90 = &PTR__objc_msgSend_0118c130;
  DAT_01227374 = 1;
  puStack_98 = auStack_b0;
  _objc_retain(param_3);
  uVar2 = _objc_alloc(puVar1);
  _objc_msgSend(param_3,PTR_s_title_0114c7f0);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  uVar2 = _objc_msgSend(uVar2,PTR_s_initWithString__0114b658,uVar3);
  _objc_release(uVar3);
  puVar1 = PTR__OBJC_CLASS___NSString_0114eb38;
  _objc_msgSend(param_1,PTR_s_defaults_0114d278);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_3,PTR_s_key_0114c8f8);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  fVar8 = (float)_objc_msgSend(uVar3,PTR_s_floatForKey__0114c308,uVar4);
  uVar5 = _objc_msgSend(param_3,PTR_s_sliderFormat_0114d418);
  _objc_release(param_3);
  _objc_msgSend((double)fVar8,param_1,PTR_s_formatSliderValue_format__0114d420,uVar5);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  thunk_FUN_0012d504(puVar1,PTR_s_stringWithFormat__0114b378,
                     &PTR____CFConstantStringClassReference_0118bf00,uVar5);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_release(uVar3);
  uVar3 = _objc_alloc(PTR__OBJC_CLASS___NSAttributedString_0114ee30);
  auStack_c0[0] = *(undefined8 *)PTR__NSForegroundColorAttributeName_01060370;
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_secondaryLabelColor_0114d0e8);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  auStack_b0[0] = uVar4;
  _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,
                PTR_s_dictionaryWithObjects_forKeys_co_0114b420,puStack_98,auStack_c0,1);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  uVar3 = _objc_msgSend(uVar3,PTR_s_initWithString_attributes__0114d5d0,uVar6,uVar5);
  _objc_msgSend(uVar2,PTR_s_appendAttributedString__0114d358,uVar3);
  _objc_release(uVar3);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_release(uVar6);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_78) {
    IVar7 = _objc_autoreleaseReturnValue(uVar2);
    return IVar7;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


