// Decompiled implementation evidence for DVNMediaPicker. Not compilable source.

// -[DVNMediaPicker presentImagePickerForVC:], 0x1a327c
/* Decompiled from supplied 5.2.2 arm package. VA 0x1a327c. presentImagePickerForVC: */

/* Function Stack Size: 0x18 bytes */

void DVNMediaPicker::presentImagePickerForVC_(ID param_1,SEL param_2,ID param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  _objc_storeStrong(param_1 + 8,param_3);
  _objc_retain(param_3);
  uVar1 = _objc_alloc_init(PTR__OBJC_CLASS___PHPickerConfiguration_0114ef18);
  _objc_msgSend(uVar1,@selector(setSelectionLimit:),1);
  _objc_msgSend(PTR__OBJC_CLASS___PHPickerFilter_0114ef20,@selector(videosFilter));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,@selector(setFilter:),uVar2);
  _objc_release(uVar2);
  uVar2 = _objc_alloc(PTR__OBJC_CLASS___PHPickerViewController_0114ef28);
  uVar2 = _objc_msgSend(uVar2,@selector(initWithConfiguration:),uVar1);
  _objc_msgSend(uVar2,@selector(setDelegate:),param_1);
  _objc_msgSend(param_3,@selector(presentViewController:animated:completion:),uVar2,1,0);
  _objc_release(param_3);
  _objc_release(uVar2);
  _objc_release(uVar1);
  CallSupervisor(0x46d6);
  return;
}



// -[DVNMediaPicker picker:didFinishPicking:], 0x1a3390
/* Decompiled from supplied 5.2.2 arm package. VA 0x1a3390. picker:didFinishPicking: */

/* Function Stack Size: 0x20 bytes */

void DVNMediaPicker::picker_didFinishPicking_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  uint uVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined *puStack_88;
  undefined8 uStack_80;
  code *pcStack_78;
  undefined *puStack_70;
  ID IStack_68;
  uint local_5c;
  undefined **local_58;
  
  local_58 = &PTR_LAB_011ae7b8;
  _objc_retain(param_4);
  _objc_msgSend(param_3,@selector(dismissViewControllerAnimated:completion:),1,0);
  lVar3 = _objc_msgSend(param_4,@selector(count));
  local_5c = (uint)(lVar3 == 0);
  if (lVar3 != 0) {
    _objc_msgSend(param_4,@selector(firstObject));
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,@selector(itemProvider));
    uVar5 = _objc_retainAutoreleasedReturnValue();
    puVar1 = @selector(identifier);
    uVar7 = *(undefined8 *)PTR__UTTypeMovie_010605e8;
    _objc_msgSend(uVar7,@selector(identifier));
    uVar6 = _objc_retainAutoreleasedReturnValue();
    uVar2 = FUN_001a9728(uVar5,@selector(hasItemConformingToTypeIdentifier:),uVar6);
    _objc_release(uVar6);
    if (uVar2 != 0) {
      _objc_msgSend((&PTR_LAB_011ae7d0)[uVar2] + (int)-(uRam00000000011ae7e0 ^ 0x545188b1),uVar7,
                    puVar1);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      puStack_88 = PTR___NSConcreteStackBlock_01060660;
      uStack_80 = DAT_00c4c228;
      pcStack_78 = FUN_001a35a8;
      puStack_70 = &UNK_010628e0;
      IStack_68 = param_1;
      _objc_msgSend(uVar5,@selector(loadFileRepresentationForTypeIdentifier:completionHandler:),uVar6,&puStack_88);
      _objc_unsafeClaimAutoreleasedReturnValue();
      _objc_release(uVar6);
    }
    _objc_release(uVar5);
    _objc_release(uVar4);
  }
  _objc_release(param_4);
  CallSupervisor(0xeaae);
  return;
}



// -[DVNMediaPicker presentFilePickerForVC:isMultipleSelection:], 0x1a39b8
/* Decompiled from supplied 5.2.2 arm package. VA 0x1a39b8. presentFilePickerForVC:isMultipleSelection: */

/* Function Stack Size: 0x1c bytes */

void DVNMediaPicker::presentFilePickerForVC_isMultipleSelection_
               (ID param_1,SEL param_2,ID param_3,bool param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined **ppuStack_190;
  undefined **ppuStack_188;
  undefined **ppuStack_180;
  undefined **ppuStack_178;
  undefined **ppuStack_170;
  undefined **ppuStack_168;
  undefined **ppuStack_160;
  undefined **ppuStack_158;
  undefined **ppuStack_150;
  undefined **ppuStack_148;
  undefined **ppuStack_140;
  undefined **ppuStack_138;
  undefined **ppuStack_130;
  undefined **ppuStack_128;
  undefined **ppuStack_120;
  undefined **ppuStack_118;
  undefined **ppuStack_110;
  undefined **ppuStack_108;
  undefined **ppuStack_100;
  undefined **ppuStack_f8;
  undefined **ppuStack_f0;
  undefined **ppuStack_e8;
  undefined **ppuStack_e0;
  undefined **ppuStack_d8;
  undefined **ppuStack_d0;
  undefined **ppuStack_c8;
  undefined **ppuStack_c0;
  undefined **ppuStack_b8;
  undefined **ppuStack_b0;
  undefined **ppuStack_a8;
  undefined **local_80;
  uint local_74;
  undefined **local_70;
  long local_68;
  
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  local_70 = &PTR_LAB_011ae888;
  local_74 = (uint)(DAT_01227964 == 0);
  local_80 = &PTR_LAB_011ae4f0;
  DAT_01227964 = 1;
  _objc_storeStrong(param_1 + 8,param_3);
  _objc_retain(param_3);
  ppuStack_190 = @"public.avi";
  ppuStack_188 = @"public.mpeg";
  ppuStack_180 = @"public.mpeg-4";
  ppuStack_178 = @"public.3gpp";
  ppuStack_170 = @"public.3gpp2";
  ppuStack_168 = @"public.movie";
  ppuStack_160 = @"com.microsoft.advanced-systems-format";
  ppuStack_158 = @"com.microsoft.windows-media-wmv";
  ppuStack_150 = @"com.firecore.fileformat.dvr-ms";
  ppuStack_148 = @"com.firecore.fileformat.flv";
  ppuStack_140 = @"com.firecore.fileformat.mpg";
  ppuStack_138 = @"com.firecore.fileformat.wmv";
  ppuStack_130 = @"com.firecore.fileformat.mkv";
  ppuStack_128 = @"com.firecore.fileformat.ts";
  ppuStack_120 = @"com.firecore.fileformat.m2ts";
  ppuStack_118 = @"com.firecore.fileformat.mts";
  ppuStack_110 = @"com.firecore.fileformat.avi";
  ppuStack_108 = @"com.firecore.fileformat.m4v";
  ppuStack_100 = @"com.firecore.fileformat.mov";
  ppuStack_f8 = @"com.firecore.fileformat.mp4";
  ppuStack_f0 = @"com.firecore.fileformat.mpeg";
  ppuStack_e8 = @"com.firecore.fileformat.mod";
  ppuStack_e0 = @"com.firecore.fileformat.wtv";
  ppuStack_d8 = @"com.firecore.fileformat.ogm";
  ppuStack_d0 = @"com.firecore.fileformat.ogv";
  ppuStack_c8 = @"com.firecore.fileformat.webm";
  ppuStack_c0 = @"com.firecore.fileformat.asf";
  ppuStack_b8 = @"com.firecore.fileformat.rmvb";
  ppuStack_b0 = @"com.firecore.fileformat.vob";
  ppuStack_a8 = @"com.firecore.fileformat.mxf";
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,@selector(arrayWithObjects:count:),
                &ppuStack_190,0x1e);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  uVar2 = _objc_alloc(PTR__OBJC_CLASS___UIDocumentPickerViewController_0114ef38);
  uVar2 = _objc_msgSend(uVar2,@selector(initWithDocumentTypes:inMode:),uVar1,0);
  _objc_msgSend(uVar2,@selector(setDelegate:),param_1);
  _objc_msgSend(uVar2,@selector(setAllowsMultipleSelection:),param_4);
  _objc_msgSend(param_3,@selector(presentViewController:animated:completion:),uVar2,1,0);
  _objc_release(param_3);
  _objc_release(uVar2);
  _objc_release(uVar1);
  CallSupervisor(0x4294);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(0x1f,0,0,0);
}



// -[DVNMediaPicker documentPicker:didPickDocumentsAtURLs:], 0x1a691c
/* Decompiled from supplied 5.2.2 arm package. VA 0x1a691c. documentPicker:didPickDocumentsAtURLs: */

/* Function Stack Size: 0x20 bytes */

void DVNMediaPicker::documentPicker_didPickDocumentsAtURLs_
               (ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  long lVar2;
  ID IVar3;
  undefined **ppuVar4;
  
  puVar1 = @selector(count);
  _objc_retain(param_4);
  lVar2 = _objc_msgSend(param_4,puVar1);
  if (lVar2 == 1) {
    _objc_msgSend(param_4,@selector(firstObject));
    IVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_release(param_4);
    ppuVar4 = &@selector(prepareMediaForUse:);
  }
  else {
    ppuVar4 = &@selector(prepareURLsForImport:);
    IVar3 = param_4;
  }
  _objc_msgSend(param_1,*ppuVar4,IVar3);
  _objc_release(IVar3);
  CallSupervisor(0xd2e0);
  return;
}



// -[DVNMediaPicker tempCopyOfURL:], 0x1a6a20
/* Decompiled from supplied 5.2.2 arm package. VA 0x1a6a20. tempCopyOfURL: */

/* Function Stack Size: 0x18 bytes */

ID DVNMediaPicker::tempCopyOfURL_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  long lVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  ID IVar8;
  long lStack_68;
  uint local_5c;
  undefined **local_58;
  
  local_58 = &PTR_LAB_011ae8c8;
  _objc_retain(param_3);
  puVar1 = PTR__OBJC_CLASS___NSURL_0114eb78;
  _NSTemporaryDirectory();
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar1,@selector(fileURLWithPath:isDirectory:),uVar4,1);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar4);
  _objc_msgSend(param_3,@selector(lastPathComponent));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,@selector(URLByAppendingPathComponent:),uVar4);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar4);
  puVar1 = @selector(defaultManager);
  _objc_msgSend(PTR__OBJC_CLASS___NSFileManager_0114eb48,@selector(defaultManager));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,@selector(path));
  uVar7 = _objc_retainAutoreleasedReturnValue();
  uVar3 = FUN_001a9a90(uVar4,@selector(fileExistsAtPath:),uVar7);
  _objc_release(uVar7);
  _objc_release(uVar4);
  local_5c = uVar3;
  if (uVar3 != 0) {
    _objc_msgSend(local_58[uVar3] + (int)-(DAT_011ae8d8 ^ 0x9660a38d),
                  PTR__OBJC_CLASS___NSFileManager_0114eb48,puVar1);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    FUN_001a9b20(uVar4,@selector(removeItemAtURL:error:),uVar6,0);
    _objc_release(uVar4);
  }
  _objc_msgSend(PTR__OBJC_CLASS___NSFileManager_0114eb48,puVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  lStack_68 = 0;
  FUN_001a9ad8(uVar4,@selector(copyItemAtURL:toURL:error:),param_3,uVar6,&lStack_68);
  lVar2 = lStack_68;
  _objc_release(uVar4);
  if (lVar2 == 0) {
    _objc_retain((&PTR_LAB_011ae8e8)[lVar2 == 0] + (int)-(uRam00000000011ae8f8 ^ 0xc022f4a8),uVar6);
    uVar4 = uVar6;
  }
  else {
    uVar4 = 0;
  }
  _objc_release(uVar6);
  _objc_release(uVar5);
  _objc_release(param_3);
  IVar8 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return IVar8;
}



// -[DVNMediaPicker prepareMediaForUse:], 0x1a6c7c
/* Decompiled from supplied 5.2.2 arm package. VA 0x1a6c7c. prepareMediaForUse: */

/* Function Stack Size: 0x18 bytes */

void DVNMediaPicker::prepareMediaForUse_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  long lVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 auStack_250 [2];
  undefined **ppuStack_240;
  undefined **ppuStack_238;
  undefined1 auStack_230 [128];
  undefined8 uStack_1b0;
  undefined8 *puStack_1a8;
  long *plStack_1a0;
  undefined8 uStack_198;
  undefined8 uStack_190;
  undefined8 uStack_188;
  undefined8 uStack_180;
  undefined8 uStack_178;
  undefined8 *puStack_170;
  ID IStack_168;
  undefined8 uStack_160;
  undefined8 uStack_158;
  undefined1 *puStack_150;
  undefined *puStack_148;
  undefined8 uStack_140;
  undefined *puStack_138;
  undefined8 uStack_130;
  undefined **local_128;
  undefined **local_120;
  undefined **local_118;
  int iStack_10c;
  undefined **local_108;
  undefined **local_f8;
  uint uStack_ec;
  undefined **local_e8;
  undefined **ppuStack_e0;
  uint uStack_d4;
  undefined **local_d0;
  undefined **ppuStack_c8;
  undefined **local_c0;
  undefined **ppuStack_b8;
  uint uStack_ac;
  undefined **local_a8;
  undefined **ppuStack_a0;
  uint uStack_94;
  undefined **local_90;
  undefined **local_88;
  uint local_7c;
  undefined **local_78;
  long local_70;
  
  local_70 = *(long *)PTR____stack_chk_guard_01060708;
  local_78 = &PTR_LAB_011ae908;
  local_7c = (uint)(DAT_01227970 == 0);
  local_90 = &PTR_LAB_011ae928;
  local_88 = &PTR_LAB_011ae4f0;
  local_a8 = &PTR_LAB_011ae948;
  ppuStack_a0 = &PTR_LAB_011ae4f0;
  local_c0 = &PTR_LAB_011ae4f0;
  ppuStack_b8 = &PTR_LAB_011ae4f0;
  local_d0 = &PTR_LAB_011ae978;
  ppuStack_c8 = &PTR_LAB_011ae4f0;
  local_e8 = &PTR_LAB_011ae998;
  ppuStack_e0 = &PTR_LAB_011ae4f0;
  local_f8 = &PTR_LAB_011ae9b0;
  local_108 = &PTR_LAB_011ae9c8;
  local_118 = &PTR_LAB_011ae4f0;
  local_120 = &PTR_LAB_011ae4f0;
  local_128 = &PTR_LAB_011ae4f0;
  DAT_01227970 = 1;
  _objc_retain(param_3);
  puVar1 = PTR_ToastManager_0114ecd0;
  uStack_94 = (uint)(param_3 == 0);
  if (param_3 == 0) {
    _objc_msgSend(@"MediaNotFound",@selector(ytl_localized));
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(puVar1,@selector(showMessageWithText:isSuccess:),uVar4,0);
  }
  else {
    thunk_FUN_001a9e38(local_90[uStack_94] + (int)-(DAT_011ae938 ^ 0x1ad97c43),9,1,1);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,@selector(firstObject));
    uStack_130 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar4);
    _objc_msgSend(param_3,@selector(pathExtension));
    uVar4 = _objc_retainAutoreleasedReturnValue();
    puStack_138 = @selector(stringWithFormat:);
    thunk_FUN_001a9e9c(PTR__OBJC_CLASS___NSString_0114eb38,@selector(stringWithFormat:),
                       @"startup_animation.%@",uVar4);
    uStack_158 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(PTR__OBJC_CLASS___NSFileManager_0114eb48,@selector(defaultManager));
    uVar5 = _objc_retainAutoreleasedReturnValue();
    puStack_1a8 = (undefined8 *)0x0;
    uStack_1b0 = 0;
    uStack_198 = 0;
    plStack_1a0 = (long *)0x0;
    uStack_188 = 0;
    uStack_190 = 0;
    uStack_178 = 0;
    uStack_180 = 0;
    ppuStack_240 = @"mp4";
    ppuStack_238 = @"mov";
    _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,@selector(arrayWithObjects:count:),
                  &ppuStack_240,2);
    uStack_140 = _objc_retainAutoreleasedReturnValue();
    puStack_148 = @selector(countByEnumeratingWithState:objects:count:);
    lVar6 = _objc_msgSend(uStack_140,@selector(countByEnumeratingWithState:objects:count:),&uStack_1b0,
                          auStack_230,0x10);
    puVar2 = @selector(removeItemAtPath:error:);
    puVar1 = @selector(stringByAppendingPathComponent:);
    uStack_ac = (uint)(lVar6 == 0);
    uStack_160 = uVar4;
    if (lVar6 != 0) {
      uStack_d4 = (uint)(*plStack_1a0 == *plStack_1a0);
      puStack_170 = auStack_250;
      IStack_168 = param_3;
      puStack_150 = auStack_230;
      if (*plStack_1a0 != *plStack_1a0) {
        _objc_enumerationMutation(uStack_140);
      }
      thunk_FUN_001a9b34(PTR__OBJC_CLASS___NSString_0114eb38,puStack_138,
                         @"startup_animation.%@",*puStack_1a8);
      uVar4 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uStack_130,puVar1,uVar4);
      uVar7 = _objc_retainAutoreleasedReturnValue();
      _objc_release(uVar4);
      FUN_001a9b94(uVar5,puVar2,uVar7,0);
      _objc_release(uVar7);
      uStack_ec = (uint)(lVar6 == 1);
                    /* WARNING: Could not recover jumptable at 0x001a7618. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(local_e8[uStack_ec] + (int)-(uRam00000000011ae9a8 ^ 0x18f49540)))();
      return;
    }
    _objc_release(uStack_140);
    puVar2 = PTR__OBJC_CLASS___NSURL_0114eb78;
    _objc_msgSend(uStack_130,puVar1,uStack_158);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(puVar2,@selector(fileURLWithPath:),uVar4);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar4);
    auStack_250[0] = 0;
    iVar3 = FUN_001a9c5c(uVar5,@selector(copyItemAtURL:toURL:error:),param_3,uVar7,auStack_250);
    uVar4 = auStack_250[0];
    _objc_retain(auStack_250[0]);
    puVar2 = PTR_ToastManager_0114ecd0;
    iStack_10c = iVar3;
    if (iVar3 == 0) {
      _objc_msgSend(uVar4,@selector(localizedDescription));
      uVar8 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(puVar2,@selector(showMessageWithText:isSuccess:),uVar8,0);
      _objc_release(uVar8);
      thunk_FUN_001a9cb0(@"DVN --- error: %@, full path: %@",uVar4,param_3);
    }
    else {
      _objc_msgSend(@"Done",@selector(ytl_localized));
      uVar8 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(puVar2,@selector(showMessageWithText:isSuccess:),uVar8,1);
      _objc_release(uVar8);
      FUN_001a9d30(uVar5,@selector(removeItemAtURL:error:),param_3,0);
    }
    _NSTemporaryDirectory();
    uVar8 = _objc_retainAutoreleasedReturnValue();
    puVar2 = PTR__OBJC_CLASS___NSString_0114eb38;
    _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(mainBundle));
    uVar9 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar9,@selector(bundleIdentifier));
    uVar10 = _objc_retainAutoreleasedReturnValue();
    thunk_FUN_001a9da4(puVar2,puStack_138,@"%@-Inbox",uVar10);
    uVar11 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar8,puVar1,uVar11);
    uVar12 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar11);
    _objc_release(uVar10);
    _objc_release(uVar9);
    _objc_release(uVar8);
    FUN_001a9e04(uVar5,@selector(removeItemAtPath:error:),uVar12,0);
    _objc_release(uVar12);
    _objc_release(uVar4);
    _objc_release(uVar7);
    _objc_release(uVar5);
    _objc_release(uStack_158);
    _objc_release(uStack_160);
    uVar4 = uStack_130;
  }
  _objc_release(uVar4);
  _objc_release(param_3);
  CallSupervisor(0x33a2);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_70) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail(0x1f,0,0,0);
  }
  return;
}



// -[DVNMediaPicker prepareURLsForImport:], 0x1a79a0
/* Decompiled from supplied 5.2.2 arm package. VA 0x1a79a0. prepareURLsForImport: */

/* Function Stack Size: 0x18 bytes */

void DVNMediaPicker::prepareURLsForImport_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined *puStack_b0;
  undefined8 uStack_a8;
  code *pcStack_a0;
  undefined *puStack_98;
  undefined8 uStack_90;
  ID IStack_88;
  undefined **local_78;
  uint local_6c;
  undefined **local_68;
  
  local_68 = &PTR_LAB_011ae9f8;
  local_6c = (uint)(DAT_01227974 == 0);
  local_78 = &PTR_LAB_011ae4f0;
  DAT_01227974 = 1;
  _objc_retain(param_3);
  puVar1 = PTR__OBJC_CLASS___UIAlertController_0114ef40;
  puVar2 = @selector(ytl_localized);
  _objc_msgSend(@"LocalImport",@selector(ytl_localized));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(@"FolderName",puVar2);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar1,@selector(alertControllerWithTitle:message:preferredStyle:),uVar5,uVar6,1);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar6);
  _objc_release(uVar5);
  _objc_msgSend(uVar7,@selector(addTextFieldWithConfigurationHandler:),
                &PTR___NSConcreteGlobalBlock_01062930);
  puVar1 = PTR__OBJC_CLASS___UIAlertAction_0114ef48;
  _objc_msgSend(@"ImportToFolder",puVar2);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  puVar3 = @selector(actionWithTitle:style:handler:);
  puStack_b0 = PTR___NSConcreteStackBlock_01060660;
  uStack_a8 = DAT_00c4c228;
  pcStack_a0 = FUN_001a80f8;
  puStack_98 = &UNK_01062950;
  uStack_90 = uVar7;
  IStack_88 = param_3;
  _objc_retain(param_3);
  _objc_retain(uVar7);
  _objc_msgSend(puVar1,puVar3,uVar5,0,&puStack_b0);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  puVar1 = @selector(addAction:);
  _objc_msgSend(uVar7,@selector(addAction:),uVar6);
  _objc_release(uVar6);
  _objc_release(uVar5);
  puVar4 = PTR__OBJC_CLASS___UIAlertAction_0114ef48;
  _objc_msgSend(@"Cancel",puVar2);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar4,puVar3,uVar5,1,&PTR___NSConcreteGlobalBlock_010629a0);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar7,puVar1,uVar6);
  _objc_release(uVar6);
  _objc_release(uVar5);
  _objc_msgSend(*(undefined8 *)(param_1 + 8),@selector(presentViewController:animated:completion:),uVar7,1
                ,0);
  _objc_release(IStack_88);
  _objc_release(uStack_90);
  _objc_release(param_3);
  _objc_release(uVar7);
  CallSupervisor(0x3eb0);
  return;
}



// -[DVNMediaPicker .cxx_destruct], 0x1a9500
/* Decompiled from supplied 5.2.2 arm package. VA 0x1a9500. .cxx_destruct */

/* Function Stack Size: 0x10 bytes */

void DVNMediaPicker::_cxx_destruct(ID param_1,SEL param_2)

{
  _objc_storeStrong(param_1 + 8,0);
  CallSupervisor(0x6a47);
  return;
}



// +[DVNMediaPicker sharedPicker], 0x1a31a0
/* Decompiled from supplied 5.2.2 arm package. VA 0x1a31a0. sharedPicker */

/* Function Stack Size: 0x10 bytes */

ID DVNMediaPicker::sharedPicker(ID param_1,SEL param_2)

{
  ID IVar1;
  SEL extraout_x1;
  undefined *local_48;
  undefined8 local_40;
  code *local_38;
  undefined *puStack_30;
  ID local_28;
  uint local_1c;
  undefined **local_18;
  
  local_18 = &PTR_LAB_011ae790;
  local_48 = PTR___NSConcreteGlobalBlock_01060658;
  local_40 = DAT_00c4c2a8;
  local_38 = FUN_001a3254;
  puStack_30 = &DAT_01062880;
  local_1c = (uint)(DAT_01227928 == -1);
  local_28 = param_1;
  if (DAT_01227928 != -1) {
    _dispatch_once((&PTR_LAB_011ae790)[local_1c] + (int)-(DAT_011ae7a0 ^ 0xa9705364),&DAT_01227928,
                   &local_48);
    param_2 = extraout_x1;
  }
  IVar1 = (*(code *)PTR__objc_retainAutoreleaseReturnValue_01061040)(DAT_01227930,param_2);
  return IVar1;
}


