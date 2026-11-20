/* Decompiled from supplied 5.2.2 arm package. VA 0x234998. FUN_00234998 */

void FUN_00234998(void)

{
  long lVar1;
  undefined *puVar2;
  uint uVar3;
  undefined8 uVar4;
  long lVar5;
  long lVar6;
  undefined8 uVar7;
  undefined1 auStack_4b0 [1032];
  undefined **local_a8;
  undefined **ppuStack_a0;
  uint uStack_94;
  undefined **local_90;
  undefined **ppuStack_88;
  uint uStack_7c;
  undefined **local_78;
  undefined **ppuStack_70;
  uint local_64;
  undefined **local_60;
  long local_58;
  
  puVar2 = PTR_s_mainBundle_0114adf8;
  local_58 = *(long *)PTR____stack_chk_guard_01060708;
  local_60 = &PTR_LAB_011d1d58;
  local_64 = (uint)(DAT_01228454 == 0);
  local_78 = &PTR_LAB_011d1d78;
  ppuStack_70 = &PTR_LAB_011d1cd0;
  local_90 = &PTR_LAB_011d1d98;
  ppuStack_88 = &PTR_LAB_011d1cd0;
  local_a8 = &PTR_LAB_011d1cd0;
  ppuStack_a0 = &PTR_LAB_011d1cd0;
  DAT_01228454 = 1;
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_mainBundle_0114adf8);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,PTR_s_pathForResource_ofType__0114df88,
                &PTR____CFConstantStringClassReference_011d1c50,
                &PTR____CFConstantStringClassReference_011d1bd0);
  lVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar4);
  uVar4 = _objc_msgSend(&PTR____CFConstantStringClassReference_011d1c10,
                        PTR_s_fileSystemRepresentation_0114e7d8);
  lVar6 = thunk_FUN_00008118(uVar4,auStack_4b0);
  uStack_7c = (uint)(lVar6 == 0);
  if (lVar6 == 0) {
    lVar6 = 0;
  }
  else {
    _objc_msgSend(PTR__OBJC_CLASS___NSString_0114eb38,PTR_s_stringWithUTF8String__0114b220,lVar6);
    lVar6 = _objc_retainAutoreleasedReturnValue();
  }
  lVar1 = lVar6;
  if (lVar5 != 0) {
    lVar1 = lVar5;
  }
  _objc_retain(lVar1);
  _objc_msgSend(PTR__OBJC_CLASS___NSFileManager_0114eb48,PTR_s_defaultManager_0114b240);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  uVar3 = FUN_002358f4(uVar4,PTR_s_fileExistsAtPath__0114c408,lVar1);
  _objc_release(uVar4);
  uStack_94 = uVar3;
  if (uVar3 == 0) {
    _objc_msgSend(local_90[uVar3] + (int)-(uRam00000000011d1da8 ^ 0x3342f15a),
                  PTR__OBJC_CLASS___NSBundle_0114eae8,puVar2);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    uVar4 = uRam0000000001228440;
    uRam0000000001228440 = uVar7;
    _objc_release(uVar4);
    uVar4 = _NSClassFromString(&PTR____CFConstantStringClassReference_011d1b50);
    _objc_msgSend(uVar4,PTR_s_infoDialog_0114b270);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,PTR_s_setTitle__0114afc0,&PTR____CFConstantStringClassReference_011d1b10);
    _objc_msgSend(uVar4,PTR_s_setSubtitle__0114b280,&PTR____CFConstantStringClassReference_011d1b90)
    ;
    _objc_msgSend(uVar4,PTR_s_show_0114b288);
  }
  else {
    _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_bundleWithPath__0114e7c8,lVar1);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    uVar4 = uRam0000000001228440;
    uRam0000000001228440 = uVar7;
  }
  _objc_release(uVar4);
  _objc_release(lVar1);
  _objc_release(lVar6);
  _objc_release(lVar5);
  CallSupervisor(0x6e02);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_58) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(0x1a,0x1f,0,0);
}


