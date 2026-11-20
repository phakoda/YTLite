/* Decompiled from supplied 5.2.2 arm package. VA 0x94198. FUN_00094198 */

void FUN_00094198(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5,undefined8 param_6,undefined8 param_7)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  undefined8 uStack_110;
  undefined8 uStack_108;
  undefined8 uStack_100;
  undefined8 uStack_f8;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined **local_d8;
  undefined **ppuStack_d0;
  uint uStack_c4;
  undefined **local_c0;
  undefined **local_b8;
  uint uStack_ac;
  undefined **local_a8;
  undefined **local_a0;
  uint local_94;
  undefined **local_90;
  long local_88;
  
  local_88 = *(long *)PTR____stack_chk_guard_01060708;
  local_90 = &PTR_LAB_0117eb38;
  local_94 = (uint)(DAT_01226d94 == 0);
  local_a8 = &PTR_LAB_0117eb58;
  local_c0 = &PTR_LAB_0117eb78;
  local_a0 = &PTR_LAB_01175340;
  local_b8 = &PTR_LAB_01175340;
  local_d8 = &PTR_LAB_01175340;
  ppuStack_d0 = &PTR_LAB_01175340;
  DAT_01226d94 = 1;
  local_e8 = param_5;
  uStack_e0 = param_6;
  _objc_retain(param_7);
  puVar1 = PTR_s_standardUserDefaults_0114afa0;
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,PTR_s_standardUserDefaults_0114afa0);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  puVar2 = PTR_s_objectForKey__0114b238;
  _objc_msgSend(uVar4,PTR_s_objectForKey__0114b238,&PTR____CFConstantStringClassReference_0116a280);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar4);
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,puVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,puVar2,&PTR____CFConstantStringClassReference_0116a240);
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
  lVar8 = _objc_retainAutoreleasedReturnValue();
  lVar9 = _ytpInt(&PTR____CFConstantStringClassReference_0116a200);
  uStack_ac = (uint)(lVar9 == 1 && lVar7 != 0);
  if (lVar9 == 1 && lVar7 != 0) {
    uVar4 = _objc_retainAutorelease(local_a8[uStack_ac] + (int)-(DAT_0117eb68 ^ 0xa1bc272f),lVar7);
    puVar1 = PTR_s_CGColor_0114c8c0;
    uStack_100 = _objc_msgSend(uVar4,PTR_s_CGColor_0114c8c0);
    uVar4 = _objc_retainAutorelease(lVar7);
    uStack_f8 = _objc_msgSend(uVar4,puVar1);
    _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,PTR_s_arrayWithObjects_count__0114b600,
                  &uStack_100,2);
    uVar4 = _objc_retainAutoreleasedReturnValue();
  }
  else {
    lVar9 = _ytpInt(&PTR____CFConstantStringClassReference_0116a200);
    uStack_c4 = (uint)((lVar7 != 0 && lVar8 != 0) && lVar9 == 2);
    if ((lVar7 == 0 || lVar8 == 0) || lVar9 != 2) goto LAB_00094838;
    uVar4 = _objc_retainAutorelease
                      (local_c0[uStack_c4] + (int)-(uRam000000000117eb88 ^ 0xfc40e05b),lVar7);
    puVar1 = PTR_s_CGColor_0114c8c0;
    uStack_110 = _objc_msgSend(uVar4,PTR_s_CGColor_0114c8c0);
    uVar4 = _objc_retainAutorelease(lVar8);
    uStack_108 = _objc_msgSend(uVar4,puVar1);
    _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,PTR_s_arrayWithObjects_count__0114b600,
                  &uStack_110,2);
    uVar4 = _objc_retainAutoreleasedReturnValue();
  }
  _objc_msgSend(param_7,PTR_s_setColors__0114ca48,uVar4);
  _objc_release(uVar4);
LAB_00094838:
  (*DAT_01226568)(param_1,param_2,param_3,param_4,local_e8,uStack_e0,param_7);
  _objc_release(lVar8);
  _objc_release(lVar7);
  _objc_release(uVar6);
  _objc_release(uVar5);
  _objc_release(param_7);
  CallSupervisor(0xc54d);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_88) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(0x1f,0,0,0);
}


