/* Decompiled from supplied 5.2.2 arm package. VA 0x193a60. segmentWithDictionary: */

/* Function Stack Size: 0x18 bytes */

ID SBSegment::segmentWithDictionary_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  long lVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  ID IVar10;
  
  DAT_012277d0 = 1;
  _objc_retain(param_3);
  puVar1 = PTR_s_objectForKeyedSubscript__0114ae80;
  if (param_3 == 0) {
    uVar6 = 0;
  }
  else {
    _objc_msgSend(param_3,PTR_s_objectForKeyedSubscript__0114ae80,
                  &PTR____CFConstantStringClassReference_011a9b60);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    uVar6 = _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,PTR_s_class_0114ae88);
    iVar4 = FUN_00194900(uVar5,PTR_s_isKindOfClass__0114ad70,uVar6);
    uVar6 = 0;
    if (iVar4 != 0) {
      lVar7 = _objc_msgSend(uVar5,PTR_s_count_0114b840);
      uVar6 = 0;
      if (lVar7 == 2) {
        uVar6 = _objc_alloc_init(PTR_SBSegment_0114eed8);
        _objc_msgSend(param_3,puVar1,&PTR____CFConstantStringClassReference_011a9a60);
        uVar8 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar6,PTR_s_setUuid__0114da50,uVar8);
        _objc_release(uVar8);
        _objc_msgSend(param_3,puVar1,&PTR____CFConstantStringClassReference_011a9a20);
        uVar8 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar6,PTR_s_setCategory__0114da58,uVar8);
        _objc_release(uVar8);
        _objc_msgSend(param_3,puVar1,&PTR____CFConstantStringClassReference_011a99e0);
        uVar8 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar6,PTR_s_setActionType__0114da60,uVar8);
        _objc_release(uVar8);
        _objc_msgSend(param_3,puVar1,&PTR____CFConstantStringClassReference_011a9aa0);
        uVar8 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar6,PTR_s_setSegmentDescription__0114da68,uVar8);
        _objc_release(uVar8);
        _objc_msgSend(param_3,puVar1,&PTR____CFConstantStringClassReference_011a9b60);
        uVar8 = _objc_retainAutoreleasedReturnValue();
        puVar2 = PTR_s_objectAtIndexedSubscript__0114aeb0;
        _objc_msgSend(uVar8,PTR_s_objectAtIndexedSubscript__0114aeb0,0);
        uVar9 = _objc_retainAutoreleasedReturnValue();
        puVar3 = PTR_s_doubleValue_0114b3f0;
        _objc_msgSend(uVar9,PTR_s_doubleValue_0114b3f0);
        _objc_msgSend(uVar6,PTR_s_setStart__0114da70);
        _objc_release(uVar9);
        _objc_release(uVar8);
        _objc_msgSend(param_3,puVar1,&PTR____CFConstantStringClassReference_011a9b60);
        uVar8 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar8,puVar2,1);
        uVar9 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar9,puVar3);
        _objc_msgSend(uVar6,PTR_s_setEnd__0114da78);
        _objc_release(uVar9);
        _objc_release(uVar8);
        _objc_msgSend(param_3,puVar1,&PTR____CFConstantStringClassReference_011a9b20);
        uVar8 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar8,puVar3);
        _objc_msgSend(uVar6,PTR_s_setVideoDuration__0114da80);
        _objc_release(uVar8);
        _objc_msgSend(param_3,puVar1,&PTR____CFConstantStringClassReference_011a9ae0);
        uVar8 = _objc_retainAutoreleasedReturnValue();
        uVar9 = FUN_00194818(uVar8,PTR_s_boolValue_0114b3d8);
        _objc_msgSend(uVar6,PTR_s_setLocked__0114da88,uVar9);
        _objc_release(uVar8);
        _objc_msgSend(param_3,puVar1,&PTR____CFConstantStringClassReference_011a99a0);
        uVar8 = _objc_retainAutoreleasedReturnValue();
        uVar9 = _objc_msgSend(uVar8,PTR_s_integerValue_0114b4c8);
        _objc_msgSend(uVar6,PTR_s_setVotes__0114da90,uVar9);
        _objc_release(uVar8);
      }
    }
    _objc_release(uVar5);
  }
  _objc_release(param_3);
  IVar10 = _objc_autoreleaseReturnValue(uVar6);
  return IVar10;
}


