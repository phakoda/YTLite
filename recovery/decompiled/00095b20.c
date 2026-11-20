/* Decompiled from supplied 5.2.2 arm package. VA 0x95b20. FUN_00095b20 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00095b20(void)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  
  DAT_01226da4 = 1;
  (*_DAT_01226588)();
  _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,PTR_s_standardUserDefaults_0114afa0);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_objectForKey__0114b238,&PTR____CFConstantStringClassReference_0116a790);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar2);
  puVar1 = PTR__OBJC_CLASS___NSKeyedUnarchiver_0114ec50;
  uVar2 = _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_class_0114ae88);
  _objc_msgSend(puVar1,PTR_s_unarchivedObjectOfClass_fromData_0114b758,uVar2,uVar3,0);
  lVar4 = _objc_retainAutoreleasedReturnValue();
  lVar5 = _ytpInt(&PTR____CFConstantStringClassReference_0116a750);
                    /* WARNING: Could not recover jumptable at 0x00095ea4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117ece8)[lVar5 != 0 && lVar4 != 0] +
            (int)-(uRam000000000117ecf8 ^ 0xd64b92e9)))();
  return;
}


