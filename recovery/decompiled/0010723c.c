/* Decompiled from supplied 5.2.2 arm package. VA 0x10723c. FUN_0010723c */

undefined1  [16] FUN_0010723c(long param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  long lVar9;
  undefined1 auVar10 [16];
  char acStack_e0 [24];
  undefined8 uStack_c8;
  undefined **local_c0;
  undefined **local_b8;
  undefined **ppuStack_b0;
  undefined **local_a0;
  uint uStack_94;
  undefined **local_90;
  uint uStack_84;
  undefined **local_80;
  undefined **local_78;
  uint local_6c;
  undefined **local_68;
  
  local_68 = &PTR_LAB_0118aa20;
  local_6c = (uint)(DAT_012271e0 == 0);
  local_80 = &PTR_LAB_0118aa40;
  local_90 = &PTR_LAB_0118aa58;
  local_a0 = &PTR_LAB_0118aa70;
  local_78 = &PTR_LAB_011882f0;
  local_b8 = &PTR_LAB_011882f0;
  ppuStack_b0 = &PTR_LAB_011882f0;
  local_c0 = &PTR_LAB_011882f0;
  DAT_012271e0 = 1;
  _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_videoID_0114c960);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_playerData_0114c7d0);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,PTR_s_videoDetails_0114c7d8);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,PTR_s_thumbnail_0114cf88);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar7,PTR_s_thumbnailsArray_0114cf90);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar7);
  _objc_release(uVar6);
  _objc_release(uVar5);
  _objc_msgSend(uVar8,PTR_s_lastObject_0114b250);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  puVar2 = PTR__OBJC_CLASS___NSData_0114eb98;
  puVar1 = PTR__OBJC_CLASS___NSURL_0114eb78;
  _objc_msgSend(uVar5,PTR_s_URL_0114c578);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar1,PTR_s_URLWithString__0114b3d0,uVar6);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar2,PTR_s_dataWithContentsOfURL__0114c598,uVar7);
  lVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar7);
  _objc_release(uVar6);
  uStack_84 = (uint)(lVar9 == 0);
  if (lVar9 != 0) {
    uStack_c8 = uVar4;
    _NSTemporaryDirectory();
    uVar4 = _objc_retainAutoreleasedReturnValue();
    acStack_e0[0] = '\0';
    _objc_msgSend(PTR__OBJC_CLASS___NSFileManager_0114eb48,PTR_s_defaultManager_0114b240);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    uVar3 = FUN_00113750(uVar5,PTR_s_fileExistsAtPath_isDirectory__0114d048,uVar4,acStack_e0);
    _objc_release(uVar5);
    uStack_94 = 0;
    if (acStack_e0[0] != '\0') {
      uStack_94 = uVar3;
    }
                    /* WARNING: Could not recover jumptable at 0x00107858. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    auVar10 = (*(code *)(local_90[uStack_94] + (int)-(DAT_0118aa68 ^ 0xec0accb5)))();
    return auVar10;
  }
  _objc_release(local_80[uStack_84] + (int)-(DAT_0118aa50 ^ 0x64f0daed),0);
  _objc_release(uVar5);
  _objc_release(uVar8);
  _objc_release(uVar4);
  CallSupervisor(0x4ed0);
  auVar10._8_8_ = 0x1f;
  auVar10._0_8_ = 0x1a;
  return auVar10;
}


