/* Decompiled from supplied 5.2.2 arm package. VA 0x134f50. setSegment: */

/* Function Stack Size: 0x18 bytes */

void TabbarVC::setSegment_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  DAT_0122740c = 1;
  _objc_retain(param_3);
  puVar1 = PTR_s_standardUserDefaults_0114afa0;
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,PTR_s_standardUserDefaults_0114afa0);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_objectForKey__0114b238,&PTR____CFConstantStringClassReference_0118f860);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  uVar5 = _objc_msgSend(uVar4,PTR_s_mutableCopy_0114b010);
  _objc_release(uVar4);
  _objc_release(uVar3);
  iVar2 = FUN_00138598(uVar5,PTR_s_containsObject__0114c848,
                       &PTR____CFConstantStringClassReference_0118f820);
  if (iVar2 != 0) {
    _objc_msgSend(uVar5,PTR_s_removeObject__0114cad0,&PTR____CFConstantStringClassReference_0118f820
                 );
  }
  uVar3 = _objc_msgSend(param_3,PTR_s_selectedSegmentIndex_0114d550);
  _objc_msgSend(uVar5,PTR_s_objectAtIndexedSubscript__0114aeb0,uVar3);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,puVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,PTR_s_setObject_forKey__0114c2b8,uVar3,
                &PTR____CFConstantStringClassReference_0118f7e0);
  _objc_release(uVar4);
  _objc_release(uVar3);
  _objc_release(uVar5);
  _objc_release(param_3);
  CallSupervisor(0x3043);
  return;
}


