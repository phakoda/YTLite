// Decompiled implementation evidence for SBManager. Not compilable source.

// -[SBManager init], 0x199940
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
  IVar1 = _objc_msgSendSuper2(&IStack_90,@selector(init));
  uStack_6c = (uint)(IVar1 == 0);
  if (IVar1 != 0) {
    ppuStack_e0 = @"sponsor";
    ppuStack_d8 = @"intro";
    ppuStack_d0 = @"outro";
    ppuStack_c8 = @"interaction";
    ppuStack_c0 = @"selfpromo";
    ppuStack_b8 = @"music_offtopic";
    ppuStack_b0 = @"preview";
    ppuStack_a8 = @"poi_highlight";
    ppuStack_a0 = @"filler";
    _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,@selector(arrayWithObjects:count:),
                  &ppuStack_e0,9);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(PTR__OBJC_CLASS___NSJSONSerialization_0114ebb0,
                  @selector(dataWithJSONObject:options:error:),uVar2,0,0);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    uVar4 = _objc_alloc(PTR__OBJC_CLASS___NSString_0114eb38);
    uVar4 = _objc_msgSend(uVar4,@selector(initWithData:encoding:),uVar3,4);
    _objc_msgSend(PTR__OBJC_CLASS___NSCharacterSet_0114eb70,
                  @selector(URLQueryAllowedCharacterSet));
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,@selector(stringByAddingPercentEncodingWithAllowedCharacters:),uVar5);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    uVar7 = *(undefined8 *)(IVar1 + 8);
    *(undefined8 *)(IVar1 + 8) = uVar6;
    _objc_release(uVar7);
    _objc_release(uVar5);
    _objc_msgSend(PTR__OBJC_CLASS___NSMutableDictionary_0114ed80,@selector(dictionary));
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(IVar1,@selector(setSegments:),uVar5);
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



// -[SBManager getSegmentsForID:], 0x19a168
/* Decompiled from supplied 5.2.2 arm package. VA 0x19a168. getSegmentsForID: */

/* Function Stack Size: 0x18 bytes */

void SBManager::getSegmentsForID_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined8 uVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined *puStack_a0;
  undefined8 uStack_98;
  code *pcStack_90;
  undefined *puStack_88;
  ID IStack_80;
  ID IStack_78;
  undefined **local_70;
  uint uStack_64;
  undefined **local_60;
  undefined **ppuStack_58;
  uint local_4c;
  undefined **local_48;
  
  local_48 = &PTR_LAB_011ab640;
  local_4c = (uint)(DAT_012278a4 == 0);
  local_60 = &PTR_LAB_011ab660;
  ppuStack_58 = &PTR_LAB_011ab4e0;
  local_70 = &PTR_LAB_011ab4e0;
  DAT_012278a4 = 1;
  uVar2 = _objc_retain(param_3);
  lVar3 = _objc_msgSend(uVar2,@selector(length));
  uStack_64 = (uint)(lVar3 == 0);
  if (lVar3 != 0) {
    _objc_msgSend(param_1,@selector(segments));
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar2,@selector(setObject:forKeyedSubscript:),0,param_3);
    _objc_release(uVar2);
    thunk_FUN_0019b414(PTR__OBJC_CLASS___NSString_0114eb38,@selector(stringWithFormat:),
                       @"https://sponsor.ajay.app/api/skipSegments?videoID=%@&categories=%@",param_3,
                       *(undefined8 *)(param_1 + 8));
    uVar2 = _objc_retainAutoreleasedReturnValue();
    puVar1 = PTR__OBJC_CLASS___NSURLRequest_0114eed0;
    _objc_msgSend(PTR__OBJC_CLASS___NSURL_0114eb78,@selector(URLWithString:),uVar2);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(puVar1,@selector(requestWithURL:),uVar4);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar4);
    _objc_msgSend(PTR__OBJC_CLASS___NSURLSession_0114eeb0,@selector(sharedSession));
    uVar4 = _objc_retainAutoreleasedReturnValue();
    puStack_a0 = PTR___NSConcreteStackBlock_01060660;
    uStack_98 = DAT_00c4c228;
    pcStack_90 = FUN_0019a7c8;
    puStack_88 = &UNK_010627c0;
    IStack_80 = param_1;
    _objc_retain(param_3);
    IStack_78 = param_3;
    _objc_msgSend(uVar4,@selector(dataTaskWithRequest:completionHandler:),uVar5,&puStack_a0);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,@selector(resume));
    _objc_release(uVar6);
    _objc_release(uVar4);
    _objc_release(IStack_78);
    _objc_release(uVar5);
    _objc_release(uVar2);
  }
  _objc_release(param_3);
  CallSupervisor(0xa443);
  return;
}



// -[SBManager segments], 0x19b1cc
/* Decompiled from supplied 5.2.2 arm package. VA 0x19b1cc. segments */

/* Function Stack Size: 0x10 bytes */

ID SBManager::segments(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + 0x10);
}



// -[SBManager setSegments:], 0x19b1d4
/* Decompiled from supplied 5.2.2 arm package. VA 0x19b1d4. setSegments: */

/* Function Stack Size: 0x18 bytes */

void SBManager::setSegments_(ID param_1,SEL param_2,ID param_3)

{
  _objc_storeStrong(param_1 + 0x10,param_3);
  CallSupervisor(0x9522);
  return;
}



// -[SBManager .cxx_destruct], 0x19b208
/* Decompiled from supplied 5.2.2 arm package. VA 0x19b208. .cxx_destruct */

/* Function Stack Size: 0x10 bytes */

void SBManager::_cxx_destruct(ID param_1,SEL param_2)

{
  _objc_storeStrong(param_1 + 0x10,0);
  _objc_storeStrong(param_1 + 8,0);
  CallSupervisor(0x2301);
  return;
}



// +[SBManager sharedManager], 0x199848
/* Decompiled from supplied 5.2.2 arm package. VA 0x199848. sharedManager */

/* Function Stack Size: 0x10 bytes */

ID SBManager::sharedManager(ID param_1,SEL param_2)

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
  
  local_18 = &PTR_LAB_011ab5d8;
  local_48 = PTR___NSConcreteGlobalBlock_01060658;
  local_40 = DAT_00c4c2a8;
  local_38 = FUN_001998fc;
  puStack_30 = &DAT_01062880;
  local_1c = (uint)(DAT_01227890 == -1);
  local_28 = param_1;
  if (DAT_01227890 != -1) {
    _dispatch_once((&PTR_LAB_011ab5d8)[local_1c] + (int)-(DAT_011ab5e8 ^ 0xa15b5db5),&DAT_01227890,
                   &local_48);
    param_2 = extraout_x1;
  }
  IVar1 = (*(code *)PTR__objc_retainAutoreleaseReturnValue_01061040)(DAT_01227888,param_2);
  return IVar1;
}


