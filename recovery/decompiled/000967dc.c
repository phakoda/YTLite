/* Decompiled from supplied 5.2.2 arm package. VA 0x967dc. FUN_000967dc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000967dc(undefined8 param_1,undefined8 param_2,long param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  long lVar7;
  long lVar8;
  
  DAT_01226dac = 1;
  _objc_retain(param_3);
  puVar1 = PTR_s_standardUserDefaults_0114afa0;
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,PTR_s_standardUserDefaults_0114afa0);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  puVar2 = PTR_s_objectForKey__0114b238;
  _objc_msgSend(uVar4,PTR_s_objectForKey__0114b238,&PTR____CFConstantStringClassReference_0116ab50);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar4);
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,puVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,puVar2,&PTR____CFConstantStringClassReference_0116ab10);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar4);
  puVar3 = PTR__OBJC_CLASS___NSKeyedUnarchiver_0114ec50;
  puVar1 = PTR_s_class_0114ae88;
  uVar4 = _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_class_0114ae88);
  puVar2 = PTR_s_unarchivedObjectOfClass_fromData_0114b758;
  _objc_msgSend(puVar3,PTR_s_unarchivedObjectOfClass_fromData_0114b758,uVar4,uVar5,0);
  lVar7 = _objc_retainAutoreleasedReturnValue();
  puVar3 = PTR__OBJC_CLASS___NSKeyedUnarchiver_0114ec50;
  uVar4 = _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,puVar1);
  _objc_msgSend(puVar3,puVar2,uVar4,uVar6,0);
  _objc_retainAutoreleasedReturnValue();
  lVar8 = _ytpInt(&PTR____CFConstantStringClassReference_0116aad0);
  if (lVar8 != 0 && lVar7 != 0) {
    _objc_retain((&PTR_LAB_0117edb0)[lVar8 != 0 && lVar7 != 0] +
                 (int)-(uRam000000000117edc0 ^ 0x21398f13),lVar7);
    _objc_release(param_3);
    param_3 = lVar7;
  }
  (*_DAT_01226598)(param_1,param_2,param_3);
  uVar4 = _objc_msgSend(param_1,puVar1);
  lVar7 = _class_getInstanceVariable(uVar4,s__progressBarGradient_0116a990);
                    /* WARNING: Could not recover jumptable at 0x00097070. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR__objc_msgSend_0117edd0)[lVar7 == 0] + (int)-(uRam000000000117ede0 ^ 0xe8f444cb)))
            ();
  return;
}


