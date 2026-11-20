/* Decompiled from supplied 5.2.2 arm package. VA 0x93d70. FUN_00093d70 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16]
FUN_00093d70(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
            undefined8 param_5,undefined8 param_6,long param_7)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  undefined1 auVar6 [16];
  
  DAT_01226d90 = 1;
  _objc_retain(param_7);
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,PTR_s_standardUserDefaults_0114afa0);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_objectForKey__0114b238,&PTR____CFConstantStringClassReference_0116a100);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar2);
  puVar1 = PTR__OBJC_CLASS___NSKeyedUnarchiver_0114ec50;
  uVar2 = _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_class_0114ae88);
  _objc_msgSend(puVar1,PTR_s_unarchivedObjectOfClass_fromData_0114b758,uVar2,uVar3,0);
  lVar4 = _objc_retainAutoreleasedReturnValue();
  lVar5 = _ytpInt(&PTR____CFConstantStringClassReference_0116a0c0);
  if (lVar5 != 0 && lVar4 != 0) {
    _objc_retain((&PTR_LAB_0117eb18)[lVar5 != 0 && lVar4 != 0] +
                 (int)-(uRam000000000117eb28 ^ 0x3fb000ec),lVar4);
    _objc_release(param_7);
    param_7 = lVar4;
  }
  (*_DAT_01226560)(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  _objc_release(lVar4);
  _objc_release(uVar3);
  _objc_release(param_7);
  CallSupervisor(0x1ea4);
  auVar6._8_8_ = 0x1f;
  auVar6._0_8_ = 0x1a;
  return auVar6;
}


