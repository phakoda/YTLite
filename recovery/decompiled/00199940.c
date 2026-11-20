/* Decompiled from supplied 5.2.2 arm package. VA 0x199940. init */

/* Function Stack Size: 0x10 bytes */

ID SBManager::init(ID param_1,SEL param_2)

{
  ID IVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined **ppuStack_e0;
  undefined **ppuStack_d8;
  undefined **ppuStack_d0;
  undefined **ppuStack_c8;
  undefined **ppuStack_c0;
  undefined **ppuStack_b8;
  undefined **ppuStack_b0;
  undefined **ppuStack_a8;
  undefined **ppuStack_a0;
  ID IStack_90;
  undefined *puStack_88;
  undefined **local_78;
  uint uStack_6c;
  undefined **local_68;
  undefined **ppuStack_60;
  uint local_54;
  undefined **local_50;
  long local_48;
  
  local_48 = *(long *)PTR____stack_chk_guard_01060708;
  local_50 = &PTR_LAB_011ab600;
  local_54 = (uint)(DAT_012278a0 == 0);
  local_68 = &PTR_LAB_011ab620;
  ppuStack_60 = &PTR_LAB_011ab4e0;
  local_78 = &PTR_LAB_011ab4e0;
  DAT_012278a0 = 1;
  puStack_88 = PTR_SBManager_0114f0e0;
  IStack_90 = param_1;
  IVar1 = _objc_msgSendSuper2(&IStack_90,PTR_s_init_0114d960);
  uStack_6c = (uint)(IVar1 == 0);
  if (IVar1 != 0) {
    ppuStack_e0 = &PTR____CFConstantStringClassReference_011ab2a0;
    ppuStack_d8 = &PTR____CFConstantStringClassReference_011ab220;
    ppuStack_d0 = &PTR____CFConstantStringClassReference_011ab1a0;
    ppuStack_c8 = &PTR____CFConstantStringClassReference_011ab160;
    ppuStack_c0 = &PTR____CFConstantStringClassReference_011ab1e0;
    ppuStack_b8 = &PTR____CFConstantStringClassReference_011ab120;
    ppuStack_b0 = &PTR____CFConstantStringClassReference_011ab0e0;
    ppuStack_a8 = &PTR____CFConstantStringClassReference_011ab260;
    ppuStack_a0 = &PTR____CFConstantStringClassReference_011ab0a0;
    _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,PTR_s_arrayWithObjects_count__0114b600,
                  &ppuStack_e0,9);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(PTR__OBJC_CLASS___NSJSONSerialization_0114ebb0,
                  PTR_s_dataWithJSONObject_options_error_0114b4f0,uVar2,0,0);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    uVar4 = _objc_alloc(PTR__OBJC_CLASS___NSString_0114eb38);
    uVar4 = _objc_msgSend(uVar4,PTR_s_initWithData_encoding__0114b428,uVar3,4);
    _objc_msgSend(PTR__OBJC_CLASS___NSCharacterSet_0114eb70,
                  PTR_s_URLQueryAllowedCharacterSet_0114b3c0);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,PTR_s_stringByAddingPercentEncodingWit_0114b3c8,uVar5);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    uVar7 = *(undefined8 *)(IVar1 + 8);
    *(undefined8 *)(IVar1 + 8) = uVar6;
    _objc_release(uVar7);
    _objc_release(uVar5);
    _objc_msgSend(PTR__OBJC_CLASS___NSMutableDictionary_0114ed80,PTR_s_dictionary_0114c7f8);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(IVar1,PTR_s_setSegments__0114db30,uVar5);
    _objc_release(uVar5);
    _objc_release(uVar4);
    _objc_release(uVar3);
    _objc_release(uVar2);
  }
  if (*(long *)PTR____stack_chk_guard_01060708 != local_48) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  return IVar1;
}


