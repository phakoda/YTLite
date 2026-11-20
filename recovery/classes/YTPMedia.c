// Decompiled implementation evidence for YTPMedia. Not compilable source.

// -[YTPMedia setCairo:], 0x1b6a04
/* Decompiled from supplied 5.2.2 arm package. VA 0x1b6a04. setCairo: */

/* Function Stack Size: 0x14 bytes */

void YTPMedia::setCairo_(ID param_1,SEL param_2,bool param_3)

{
  undefined1 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  long lVar4;
  
  DAT_01227ab0 = 1;
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(mainBundle));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(objectForInfoDictionaryKey:),
                @"CFBundleShortVersionString");
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar2);
  lVar4 = _objc_msgSend(uVar3,@selector(compare:options:),
                        @"20.12.4",0x40);
  uVar1 = 0;
  if (lVar4 != -1) {
    uVar1 = (char)param_3;
  }
  *(undefined1 *)(param_1 + 8) = uVar1;
  _objc_release(uVar3);
  CallSupervisor(0xfc79);
  return;
}



// -[YTPMedia isCairo], 0x1b6d3c
/* Decompiled from supplied 5.2.2 arm package. VA 0x1b6d3c. isCairo */

/* Function Stack Size: 0x10 bytes */

bool YTPMedia::isCairo(ID param_1,SEL param_2)

{
  return (bool)*(byte *)(param_1 + 8);
}



// +[YTPMedia sharedMedia], 0x1aa774
/* Decompiled from supplied 5.2.2 arm package. VA 0x1aa774. sharedMedia */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::sharedMedia(ID param_1,SEL param_2)

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
  
  local_18 = &PTR_LAB_011b25a8;
  local_48 = PTR___NSConcreteGlobalBlock_01060658;
  local_40 = DAT_00c4c2a8;
  local_38 = FUN_001aa828;
  puStack_30 = &DAT_01062880;
  local_1c = (uint)(DAT_01227990 == -1);
  local_28 = param_1;
  if (DAT_01227990 != -1) {
    _dispatch_once((&PTR_LAB_011b25a8)[local_1c] + (int)-(DAT_011b25b8 ^ 0x977fa464),&DAT_01227990,
                   &local_48);
    param_2 = extraout_x1;
  }
  IVar1 = (*(code *)PTR__objc_retainAutoreleaseReturnValue_01061040)(DAT_01227988,param_2);
  return IVar1;
}



// +[YTPMedia pageStyle], 0x1aa86c
/* Decompiled from supplied 5.2.2 arm package. VA 0x1aa86c. pageStyle */

/* Function Stack Size: 0x10 bytes */

long_long YTPMedia::pageStyle(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  long_long lVar7;
  
  _objc_msgSend(PTR__OBJC_CLASS___UIApplication_0114ebc8,@selector(sharedApplication));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,@selector(delegate));
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar5);
  puVar3 = @selector(responderRoot);
  puVar1 = @selector(respondsToSelector:);
  uVar4 = FUN_001b7254(uVar6,@selector(respondsToSelector:),@selector(responderRoot));
  lVar7 = 0xffffffffffffffff;
  if (uVar4 != 0) {
    _objc_msgSend((&PTR_LAB_011b25d0)[uVar4] + (int)-(DAT_011b25e0 ^ 0xf6833f2a),uVar6,puVar3);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    puVar2 = @selector(pageStyle);
    uVar4 = FUN_001b729c(uVar5,puVar1,@selector(pageStyle));
    _objc_release(uVar5);
    lVar7 = 0xffffffffffffffff;
    if (uVar4 != 0) {
      _objc_msgSend((&PTR_LAB_011b25e8)[uVar4] + (int)-(uRam00000000011b25f8 ^ 0x2c5eead0),uVar6,
                    puVar3);
      uVar5 = _objc_retainAutoreleasedReturnValue();
      lVar7 = _objc_msgSend(uVar5,puVar2);
      _objc_release(uVar5);
    }
  }
  _objc_release(uVar6);
  return lVar7;
}



// +[YTPMedia adaptiveBackgroundColor], 0x1aa9f0
/* Decompiled from supplied 5.2.2 arm package. VA 0x1aa9f0. adaptiveBackgroundColor */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::adaptiveBackgroundColor(ID param_1,SEL param_2)

{
  ID IVar1;
  undefined *puStack_80;
  undefined8 uStack_78;
  code *pcStack_70;
  undefined *puStack_68;
  ID IStack_60;
  undefined1 uStack_58;
  undefined **local_48;
  uint local_3c;
  undefined **local_38;
  
  local_38 = &PTR_LAB_011b2608;
  local_3c = (uint)(DAT_012279ac == 0);
  local_48 = &PTR_LAB_011b20a0;
  DAT_012279ac = 1;
  uStack_58 = FUN_001b7304(PTR_YTLUserDefaults_0114ead8,@selector(boolForKey:),
                           @"oledTheme");
  puStack_80 = PTR___NSConcreteStackBlock_01060660;
  uStack_78 = DAT_00c4c230;
  pcStack_70 = FUN_001aaba4;
  puStack_68 = &UNK_010629c0;
  IStack_60 = param_1;
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(colorWithDynamicProvider:),
                &puStack_80);
  _objc_retainAutoreleasedReturnValue();
  IVar1 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)();
  return IVar1;
}



// +[YTPMedia oledForColor:], 0x1aacd4
/* Decompiled from supplied 5.2.2 arm package. VA 0x1aacd4. oledForColor: */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Function Stack Size: 0x18 bytes */

ID YTPMedia::oledForColor_(ID param_1,SEL param_2,ID param_3)

{
  bool bVar1;
  uint uVar2;
  long lVar3;
  ID IVar4;
  undefined *puVar5;
  double dStack_60;
  double dStack_58;
  double dStack_50;
  double dStack_48;
  uint local_3c;
  undefined **local_38;
  
  local_38 = &PTR_LAB_011b2670;
  _objc_retain(param_3);
  lVar3 = _objc_msgSend(param_1,@selector(pageStyle));
  bVar1 = lVar3 == 1;
  local_3c = (uint)bVar1;
  puVar5 = local_38[bVar1] + (int)-(DAT_011b2680 ^ 0x4f39ca87);
  if (bVar1) {
    uVar2 = FUN_001b740c(param_3,@selector(getRed:green:blue:alpha:),&dStack_48,&dStack_50,
                         &dStack_58,&dStack_60);
    puVar5 = (&PTR_LAB_011b2690)[uVar2] + (int)-(uRam00000000011b26a0 ^ 0xd7fae96);
    if (uVar2 != 0) {
      if ((ABS(dStack_48 - _UNK_00c4c3a0) < DAT_00c4c398) &&
         (ABS(dStack_50 - _UNK_00c4c3a0) < DAT_00c4c398)) {
        uVar2 = (uint)(DAT_00c4c398 <= ABS(dStack_58 - _UNK_00c4c3a0));
        if (DAT_00c4c398 <= ABS(dStack_60 + -1.0)) {
          uVar2 = 1;
        }
                    /* WARNING: Could not recover jumptable at 0x001aaecc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        IVar4 = (*(code *)((&PTR_LAB_011b26e8)[uVar2] + (int)-(uRam00000000011b26f8 ^ 0x71014bf9)))
                          ();
        return IVar4;
      }
                    /* WARNING: Could not recover jumptable at 0x001aaf00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      IVar4 = (*(code *)(PTR_LAB_011b2708 + (int)-(uRam00000000011b2710 ^ 0xf455bd71)))();
      return IVar4;
    }
  }
  _objc_retain(puVar5,param_3);
  _objc_release(param_3);
  IVar4 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(param_3);
  return IVar4;
}



// +[YTPMedia imageWithName:], 0x1ab020
/* Decompiled from supplied 5.2.2 arm package. VA 0x1ab020. imageWithName: */

/* Function Stack Size: 0x18 bytes */

ID YTPMedia::imageWithName_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  ID IVar6;
  
  puVar2 = PTR_YTPMedia_0114eae0;
  puVar1 = @selector(sharedMedia);
  DAT_012279bc = 1;
  _objc_retain(param_3);
  _objc_msgSend(puVar2,puVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  iVar3 = FUN_001b74d4(uVar4,@selector(isCairo));
  _objc_release(uVar4);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  if (iVar3 == 0) {
    _objc_msgSend(uVar4,@selector(imageWithName:),param_3);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    IVar6 = param_3;
  }
  else {
    _objc_msgSend(param_3,@selector(stringByAppendingString:),
                  @"_cairo");
    IVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_release(param_3);
    _objc_msgSend(uVar4,@selector(imageWithName:),IVar6);
    uVar5 = _objc_retainAutoreleasedReturnValue();
  }
  _objc_release(IVar6);
  _objc_release(uVar4);
  IVar6 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar5);
  return IVar6;
}



// +[YTPMedia historyTab], 0x1ab254
/* Decompiled from supplied 5.2.2 arm package. VA 0x1ab254. historyTab */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::historyTab(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_012279c0 = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b755c(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"FEhistory_cairo";
  if (iVar2 == 0) {
    ppuVar1 = @"FEhistory";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = _objc_autoreleaseReturnValue(uVar4);
  return IVar5;
}



// +[YTPMedia historyTabSelected], 0x1ab508
/* Decompiled from supplied 5.2.2 arm package. VA 0x1ab508. historyTabSelected */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::historyTabSelected(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_012279c4 = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b75e4(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"FEhistory_cairo_selected";
  if (iVar2 == 0) {
    ppuVar1 = @"FEhistory_selected";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = _objc_autoreleaseReturnValue(uVar4);
  return IVar5;
}



// +[YTPMedia watchLaterTab], 0x1ab8b8
/* Decompiled from supplied 5.2.2 arm package. VA 0x1ab8b8. watchLaterTab */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::watchLaterTab(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_012279c8 = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b766c(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"VLWL_cairo";
  if (iVar2 == 0) {
    ppuVar1 = @"VLWL";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = _objc_autoreleaseReturnValue(uVar4);
  return IVar5;
}



// +[YTPMedia watchLaterTabSelected], 0x1abadc
/* Decompiled from supplied 5.2.2 arm package. VA 0x1abadc. watchLaterTabSelected */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::watchLaterTabSelected(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_012279cc = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b76f4(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"VLWL_cairo_selected";
  if (iVar2 == 0) {
    ppuVar1 = @"VLWL_selected";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = _objc_autoreleaseReturnValue(uVar4);
  return IVar5;
}



// +[YTPMedia postsTab], 0x1abdf8
/* Decompiled from supplied 5.2.2 arm package. VA 0x1abdf8. postsTab */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::postsTab(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_012279d0 = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b777c(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"FEpost_home_cairo";
  if (iVar2 == 0) {
    ppuVar1 = @"FEpost_home";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = _objc_autoreleaseReturnValue(uVar4);
  return IVar5;
}



// +[YTPMedia postsTabSelected], 0x1ac0f4
/* Decompiled from supplied 5.2.2 arm package. VA 0x1ac0f4. postsTabSelected */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::postsTabSelected(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_012279d4 = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b7804(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"FEpost_home_cairo_selected";
  if (iVar2 == 0) {
    ppuVar1 = @"FEpost_home_selected";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = _objc_autoreleaseReturnValue(uVar4);
  return IVar5;
}



// +[YTPMedia hypeTab], 0x1ac4f0
/* Decompiled from supplied 5.2.2 arm package. VA 0x1ac4f0. hypeTab */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::hypeTab(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_012279d8 = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b788c(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"FEhype_leaderboard_cairo";
  if (iVar2 == 0) {
    ppuVar1 = @"FEhype_leaderboard";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return IVar5;
}



// +[YTPMedia hypeTabSelected], 0x1ac8a8
/* Decompiled from supplied 5.2.2 arm package. VA 0x1ac8a8. hypeTabSelected */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::hypeTabSelected(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_012279dc = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b7914(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"FEhype_leaderboard_cairo_selected";
  if (iVar2 == 0) {
    ppuVar1 = @"FEhype_leaderboard_selected";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return IVar5;
}



// +[YTPMedia musicTab], 0x1acd54
/* Decompiled from supplied 5.2.2 arm package. VA 0x1acd54. musicTab */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::musicTab(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_012279e0 = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b799c(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"UC-9-kyTW8ZkZNDHQJ6FgpwQ_cairo";
  if (iVar2 == 0) {
    ppuVar1 = @"UC-9-kyTW8ZkZNDHQJ6FgpwQ";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return IVar5;
}



// +[YTPMedia musicTabSelected], 0x1ad1c0
/* Decompiled from supplied 5.2.2 arm package. VA 0x1ad1c0. musicTabSelected */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::musicTabSelected(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_012279e4 = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b7a24(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"UC-9-kyTW8ZkZNDHQJ6FgpwQ_cairo_selected";
  if (iVar2 == 0) {
    ppuVar1 = @"UC-9-kyTW8ZkZNDHQJ6FgpwQ_selected";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return IVar5;
}



// +[YTPMedia liveTab], 0x1ad724
/* Decompiled from supplied 5.2.2 arm package. VA 0x1ad724. liveTab */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::liveTab(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_012279e8 = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b7aac(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"UC4R8DWoMoI7CAwX8_LjQHig_cairo";
  if (iVar2 == 0) {
    ppuVar1 = @"UC4R8DWoMoI7CAwX8_LjQHig";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = _objc_autoreleaseReturnValue(uVar4);
  return IVar5;
}



// +[YTPMedia liveTabSelected], 0x1adb88
/* Decompiled from supplied 5.2.2 arm package. VA 0x1adb88. liveTabSelected */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::liveTabSelected(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_012279ec = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b7b34(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"UC4R8DWoMoI7CAwX8_LjQHig_cairo_selected";
  if (iVar2 == 0) {
    ppuVar1 = @"UC4R8DWoMoI7CAwX8_LjQHig_selected";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return IVar5;
}



// +[YTPMedia gamingTab], 0x1ae0d0
/* Decompiled from supplied 5.2.2 arm package. VA 0x1ae0d0. gamingTab */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::gamingTab(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_012279f0 = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b7bbc(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"UCOpNcN46UbXVtpKMrmU4Abg_cairo";
  if (iVar2 == 0) {
    ppuVar1 = @"UCOpNcN46UbXVtpKMrmU4Abg";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = _objc_autoreleaseReturnValue(uVar4);
  return IVar5;
}



// +[YTPMedia gamingTabSelected], 0x1ae530
/* Decompiled from supplied 5.2.2 arm package. VA 0x1ae530. gamingTabSelected */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::gamingTabSelected(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_012279f4 = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b7c44(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"UCOpNcN46UbXVtpKMrmU4Abg_cairo_selected";
  if (iVar2 == 0) {
    ppuVar1 = @"UCOpNcN46UbXVtpKMrmU4Abg_selected";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = _objc_autoreleaseReturnValue(uVar4);
  return IVar5;
}



// +[YTPMedia sportsTab], 0x1aeaa4
/* Decompiled from supplied 5.2.2 arm package. VA 0x1aeaa4. sportsTab */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::sportsTab(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_012279f8 = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b7ccc(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"UCEgdi0XIXXZ-qJOFPf4JSKw_cairo";
  if (iVar2 == 0) {
    ppuVar1 = @"UCEgdi0XIXXZ-qJOFPf4JSKw";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return IVar5;
}



// +[YTPMedia sportsTabSelected], 0x1aef00
/* Decompiled from supplied 5.2.2 arm package. VA 0x1aef00. sportsTabSelected */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::sportsTabSelected(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_012279fc = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b7d54(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"UCEgdi0XIXXZ-qJOFPf4JSKw_cairo_selected";
  if (iVar2 == 0) {
    ppuVar1 = @"UCEgdi0XIXXZ-qJOFPf4JSKw_selected";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return IVar5;
}



// +[YTPMedia notificationsTab], 0x1af460
/* Decompiled from supplied 5.2.2 arm package. VA 0x1af460. notificationsTab */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::notificationsTab(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_01227a00 = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b7ddc(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"FEnotifications_inbox_cairo";
  if (iVar2 == 0) {
    ppuVar1 = @"FEnotifications_inbox";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = _objc_autoreleaseReturnValue(uVar4);
  return IVar5;
}



// +[YTPMedia notificationsTabSelected], 0x1af858
/* Decompiled from supplied 5.2.2 arm package. VA 0x1af858. notificationsTabSelected */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::notificationsTabSelected(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_01227a04 = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b7e64(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"FEnotifications_inbox_cairo_selected";
  if (iVar2 == 0) {
    ppuVar1 = @"FEnotifications_inbox_selected";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return IVar5;
}



// +[YTPMedia ytPlus], 0x1afd64
/* Decompiled from supplied 5.2.2 arm package. VA 0x1afd64. ytPlus */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::ytPlus(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_01227a08 = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b7eec(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"ytl_cairo";
  if (iVar2 == 0) {
    ppuVar1 = @"ytl_outline";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return IVar5;
}



// +[YTPMedia ytPlusShorts], 0x1affe0
/* Decompiled from supplied 5.2.2 arm package. VA 0x1affe0. ytPlusShorts */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::ytPlusShorts(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  ID IVar6;
  
  DAT_01227a0c = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b7f74(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(whiteColor));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"ytl_cairo";
  if (iVar2 == 0) {
    ppuVar1 = @"ytl_icon";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:tintColor:),ppuVar1,uVar4);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar4);
  _objc_release(uVar3);
  IVar6 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar5);
  return IVar6;
}



// +[YTPMedia sponsorblock], 0x1b025c
/* Decompiled from supplied 5.2.2 arm package. VA 0x1b025c. sponsorblock */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::sponsorblock(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_01227a10 = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b801c(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"sponsorblock_cairo";
  if (iVar2 == 0) {
    ppuVar1 = @"sponsorblock";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return IVar5;
}



// +[YTPMedia lock], 0x1b0558
/* Decompiled from supplied 5.2.2 arm package. VA 0x1b0558. lock */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::lock(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_01227a14 = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b80a4(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"lock_cairo";
  if (iVar2 == 0) {
    ppuVar1 = @"lock";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return IVar5;
}



// +[YTPMedia volumeOff], 0x1b0770
/* Decompiled from supplied 5.2.2 arm package. VA 0x1b0770. volumeOff */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::volumeOff(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_01227a18 = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b812c(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"vol_off_cairo";
  if (iVar2 == 0) {
    ppuVar1 = @"vol_off";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = _objc_autoreleaseReturnValue(uVar4);
  return IVar5;
}



// +[YTPMedia volumeOn], 0x1b09f0
/* Decompiled from supplied 5.2.2 arm package. VA 0x1b09f0. volumeOn */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::volumeOn(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_01227a1c = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b81b4(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"vol_on_cairo";
  if (iVar2 == 0) {
    ppuVar1 = @"vol_on";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return IVar5;
}



// +[YTPMedia moon], 0x1b0c4c
/* Decompiled from supplied 5.2.2 arm package. VA 0x1b0c4c. moon */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::moon(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_01227a20 = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b823c(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"sleep";
  if (iVar2 == 0) {
    ppuVar1 = @"moon";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return IVar5;
}



// +[YTPMedia downloading], 0x1b0e28
/* Decompiled from supplied 5.2.2 arm package. VA 0x1b0e28. downloading */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::downloading(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_01227a24 = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b82c4(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"downloading_cairo";
  if (iVar2 == 0) {
    ppuVar1 = @"downloading";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return IVar5;
}



// +[YTPMedia credits], 0x1b110c
/* Decompiled from supplied 5.2.2 arm package. VA 0x1b110c. credits */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::credits(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_01227a28 = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b834c(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"credits_cairo";
  if (iVar2 == 0) {
    ppuVar1 = @"credits";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return IVar5;
}



// +[YTPMedia donor], 0x1b137c
/* Decompiled from supplied 5.2.2 arm package. VA 0x1b137c. donor */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::donor(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_01227a2c = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b83d4(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"donor_cairo";
  if (iVar2 == 0) {
    ppuVar1 = @"donor";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return IVar5;
}



// +[YTPMedia feed], 0x1b15c0
/* Decompiled from supplied 5.2.2 arm package. VA 0x1b15c0. feed */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::feed(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_01227a30 = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b845c(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"feed_cairo";
  if (iVar2 == 0) {
    ppuVar1 = @"feed";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return IVar5;
}



// +[YTPMedia FEshorts], 0x1b17e8
/* Decompiled from supplied 5.2.2 arm package. VA 0x1b17e8. FEshorts */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::FEshorts(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_01227a34 = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b84e4(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"FEshorts_cairo";
  if (iVar2 == 0) {
    ppuVar1 = @"FEshorts";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return IVar5;
}



// +[YTPMedia interface], 0x1b1a78
/* Decompiled from supplied 5.2.2 arm package. VA 0x1b1a78. interface */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::interface(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_01227a38 = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b856c(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"interface_cairo";
  if (iVar2 == 0) {
    ppuVar1 = @"interface";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return IVar5;
}



// +[YTPMedia libs], 0x1b1d30
/* Decompiled from supplied 5.2.2 arm package. VA 0x1b1d30. libs */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::libs(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_01227a3c = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b85f4(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"libs_cairo";
  if (iVar2 == 0) {
    ppuVar1 = @"libs";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return IVar5;
}



// +[YTPMedia localization], 0x1b1f50
/* Decompiled from supplied 5.2.2 arm package. VA 0x1b1f50. localization */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::localization(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_01227a40 = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b867c(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"localization_cairo";
  if (iVar2 == 0) {
    ppuVar1 = @"localization";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return IVar5;
}



// +[YTPMedia navbar], 0x1b2264
/* Decompiled from supplied 5.2.2 arm package. VA 0x1b2264. navbar */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::navbar(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_01227a44 = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b8704(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"navbar_cairo";
  if (iVar2 == 0) {
    ppuVar1 = @"navbar";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return IVar5;
}



// +[YTPMedia open_new], 0x1b24bc
/* Decompiled from supplied 5.2.2 arm package. VA 0x1b24bc. open_new */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::open_new(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_01227a48 = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b878c(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"open_new_cairo";
  if (iVar2 == 0) {
    ppuVar1 = @"open_new";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return IVar5;
}



// +[YTPMedia player], 0x1b2758
/* Decompiled from supplied 5.2.2 arm package. VA 0x1b2758. player */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::player(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_01227a4c = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b8814(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"player_cairo";
  if (iVar2 == 0) {
    ppuVar1 = @"player";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = _objc_autoreleaseReturnValue(uVar4);
  return IVar5;
}



// +[YTPMedia support], 0x1b29ac
/* Decompiled from supplied 5.2.2 arm package. VA 0x1b29ac. support */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::support(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_01227a50 = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b889c(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"support_cairo";
  if (iVar2 == 0) {
    ppuVar1 = @"support";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = _objc_autoreleaseReturnValue(uVar4);
  return IVar5;
}



// +[YTPMedia tabbar], 0x1b2c1c
/* Decompiled from supplied 5.2.2 arm package. VA 0x1b2c1c. tabbar */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::tabbar(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_01227a54 = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b8924(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"tabbar_cairo";
  if (iVar2 == 0) {
    ppuVar1 = @"tabbar";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return IVar5;
}



// +[YTPMedia ytl_settings], 0x1b2e80
/* Decompiled from supplied 5.2.2 arm package. VA 0x1b2e80. ytl_settings */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::ytl_settings(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_01227a58 = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b89ac(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"ytl_settings_cairo";
  if (iVar2 == 0) {
    ppuVar1 = @"ytl_settings";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = _objc_autoreleaseReturnValue(uVar4);
  return IVar5;
}



// +[YTPMedia captions], 0x1b3188
/* Decompiled from supplied 5.2.2 arm package. VA 0x1b3188. captions */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::captions(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_01227a5c = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b8a34(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"captions_cairo";
  if (iVar2 == 0) {
    ppuVar1 = @"captions";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return IVar5;
}



// +[YTPMedia FElibrary], 0x1b3424
/* Decompiled from supplied 5.2.2 arm package. VA 0x1b3424. FElibrary */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::FElibrary(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_01227a60 = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b8abc(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"FElibrary_cairo";
  if (iVar2 == 0) {
    ppuVar1 = @"FElibrary";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return IVar5;
}



// +[YTPMedia FEsubscriptions], 0x1b36cc
/* Decompiled from supplied 5.2.2 arm package. VA 0x1b36cc. FEsubscriptions */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::FEsubscriptions(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_01227a64 = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b8b44(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"FEsubscriptions_cairo";
  if (iVar2 == 0) {
    ppuVar1 = @"FEsubscriptions";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return IVar5;
}



// +[YTPMedia FEuploads], 0x1b3a3c
/* Decompiled from supplied 5.2.2 arm package. VA 0x1b3a3c. FEuploads */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::FEuploads(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_01227a68 = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b8bcc(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"FEuploads_cairo";
  if (iVar2 == 0) {
    ppuVar1 = @"FEuploads";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return IVar5;
}



// +[YTPMedia FEwhat_to_watch], 0x1b3cf8
/* Decompiled from supplied 5.2.2 arm package. VA 0x1b3cf8. FEwhat_to_watch */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::FEwhat_to_watch(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_01227a6c = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b8c54(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"FEwhat_to_watch_cairo";
  if (iVar2 == 0) {
    ppuVar1 = @"FEwhat_to_watch";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return IVar5;
}



// +[YTPMedia link], 0x1b404c
/* Decompiled from supplied 5.2.2 arm package. VA 0x1b404c. link */

/* Function Stack Size: 0x10 bytes */

int YTPMedia::link(char *param_1,char *param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  DAT_01227a70 = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b8cdc(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"link_cairo";
  if (iVar2 == 0) {
    ppuVar1 = @"link";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  iVar2 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return iVar2;
}



// +[YTPMedia x_prefs], 0x1b4280
/* Decompiled from supplied 5.2.2 arm package. VA 0x1b4280. x_prefs */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::x_prefs(ID param_1,SEL param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  ID IVar3;
  
  DAT_01227a74 = 1;
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,@selector(imageWithName:),@"x_prefs")
  ;
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar1);
  IVar3 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar2);
  return IVar3;
}



// +[YTPMedia box_checkmark], 0x1b43cc
/* Decompiled from supplied 5.2.2 arm package. VA 0x1b43cc. box_checkmark */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::box_checkmark(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_01227a78 = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b8da4(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"box_checkmark_cairo";
  if (iVar2 == 0) {
    ppuVar1 = @"box_checkmark";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return IVar5;
}



// +[YTPMedia box_empty], 0x1b46f8
/* Decompiled from supplied 5.2.2 arm package. VA 0x1b46f8. box_empty */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::box_empty(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_01227a7c = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b8e2c(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"box_empty_cairo";
  if (iVar2 == 0) {
    ppuVar1 = @"box_empty";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = _objc_autoreleaseReturnValue(uVar4);
  return IVar5;
}



// +[YTPMedia copy], 0x1b49a8
/* Decompiled from supplied 5.2.2 arm package. VA 0x1b49a8. copy */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::copy(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  ID IVar4;
  
  DAT_01227a80 = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b8eb4(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"copy_cairo";
  if (iVar2 == 0) {
    ppuVar1 = @"copy";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  IVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  return IVar4;
}



// +[YTPMedia image_library], 0x1b4bcc
/* Decompiled from supplied 5.2.2 arm package. VA 0x1b4bcc. image_library */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::image_library(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_01227a84 = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b8f3c(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"image_library_cairo";
  if (iVar2 == 0) {
    ppuVar1 = @"image_library";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return IVar5;
}



// +[YTPMedia image], 0x1b4eec
/* Decompiled from supplied 5.2.2 arm package. VA 0x1b4eec. image */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::image(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_01227a88 = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b8fc4(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"image_cairo";
  if (iVar2 == 0) {
    ppuVar1 = @"image";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return IVar5;
}



// +[YTPMedia message], 0x1b5130
/* Decompiled from supplied 5.2.2 arm package. VA 0x1b5130. message */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::message(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_01227a8c = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b904c(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"message_cairo";
  if (iVar2 == 0) {
    ppuVar1 = @"message";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return IVar5;
}



// +[YTPMedia music], 0x1b53a4
/* Decompiled from supplied 5.2.2 arm package. VA 0x1b53a4. music */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::music(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_01227a90 = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b90d4(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"music_cairo";
  if (iVar2 == 0) {
    ppuVar1 = @"music";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return IVar5;
}



// +[YTPMedia play_circle], 0x1b55d8
/* Decompiled from supplied 5.2.2 arm package. VA 0x1b55d8. play_circle */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::play_circle(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_01227a94 = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b915c(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"play_circle_cairo";
  if (iVar2 == 0) {
    ppuVar1 = @"play_circle";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = _objc_autoreleaseReturnValue(uVar4);
  return IVar5;
}



// +[YTPMedia show_image], 0x1b58ac
/* Decompiled from supplied 5.2.2 arm package. VA 0x1b58ac. show_image */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::show_image(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_01227a98 = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b91e4(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"show_image_cairo";
  if (iVar2 == 0) {
    ppuVar1 = @"show_image";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return IVar5;
}



// +[YTPMedia star_half], 0x1b5b7c
/* Decompiled from supplied 5.2.2 arm package. VA 0x1b5b7c. star_half */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::star_half(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_01227a9c = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b926c(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"star_half_cairo";
  if (iVar2 == 0) {
    ppuVar1 = @"star_half";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return IVar5;
}



// +[YTPMedia youtube_logo], 0x1b5e28
/* Decompiled from supplied 5.2.2 arm package. VA 0x1b5e28. youtube_logo */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::youtube_logo(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_01227aa0 = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b92f4(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"youtube_logo_cairo";
  if (iVar2 == 0) {
    ppuVar1 = @"youtube_logo";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return IVar5;
}



// +[YTPMedia check], 0x1b6130
/* Decompiled from supplied 5.2.2 arm package. VA 0x1b6130. check */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::check(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_01227aa4 = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b937c(uVar3,@selector(isCairo));
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"check_cairo";
  if (iVar2 == 0) {
    ppuVar1 = @"check";
  }
  _objc_msgSend(uVar3,@selector(imageWithName:),ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return IVar5;
}



// +[YTPMedia empty], 0x1b636c
/* Decompiled from supplied 5.2.2 arm package. VA 0x1b636c. empty */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::empty(ID param_1,SEL param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  ID IVar3;
  
  DAT_01227aa8 = 1;
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,@selector(imageWithName:),@"empty")
  ;
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar1);
  IVar3 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar2);
  return IVar3;
}



// +[YTPMedia adaptiveDiscord], 0x1b64a4
/* Decompiled from supplied 5.2.2 arm package. VA 0x1b64a4. adaptiveDiscord */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::adaptiveDiscord(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  undefined **ppuVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  ID IVar7;
  
  DAT_01227aac = 1;
  iVar3 = FUN_001b9424(PTR_YTLUserDefaults_0114ead8,@selector(boolForKey:),
                       @"discordRPC");
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  iVar4 = FUN_001b946c(uVar5,@selector(isCairo));
  _objc_release(uVar5);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"discord_fill";
  if (iVar3 == 0) {
    ppuVar1 = @"discord";
  }
  ppuVar2 = @"discord_fill_cairo";
  if (iVar3 == 0) {
    ppuVar2 = @"discord_cairo";
  }
  if (iVar4 == 0) {
    ppuVar2 = ppuVar1;
  }
  _objc_msgSend(uVar5,@selector(imageWithName:),ppuVar2);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar5);
  IVar7 = _objc_autoreleaseReturnValue(uVar6);
  return IVar7;
}


