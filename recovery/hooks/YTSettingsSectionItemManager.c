// Decompiled hook evidence for YTSettingsSectionItemManager. This is not compilable Logos source.

// -[YTSettingsSectionItemManager updateYTLiteSectionWithEntry:], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x13858. FUN_00013858 */

void FUN_00013858(undefined8 param_1)

{
  undefined *puVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  DAT_012259a4 = 1;
  _objc_msgSend(param_1,@selector(valueForKey:),@"_settingsViewControllerDelegate")
  ;
  uVar3 = _objc_retainAutoreleasedReturnValue();
  if (lRam0000000001225988 == 0) {
    lRam0000000001225988 =
         _objc_getClass((&PTR_LAB_011534a0)[lRam0000000001225988 == 0] +
                        (int)-(uRam00000000011534b0 ^ 0x6a85064a),s_YTIIcon_011530a2);
  }
  uVar4 = _objc_retainAutorelease();
  uVar4 = _objc_msgSend(uVar4,@selector(new));
  _objc_msgSend(uVar4,@selector(setIconType:),0x212);
  puVar1 = @selector(setSectionItems:forCategory:title:icon:titleDescription:headerHidden:);
  uVar2 = FUN_000147b4(uVar3,@selector(respondsToSelector:),
                       @selector(setSectionItems:forCategory:title:icon:titleDescription:headerHidden:));
  if (uVar2 == 0) {
    _objc_msgSend(uVar3,@selector(setSectionItems:forCategory:title:titleDescription:headerHidden:),0,0x315,
                  @"YouTube Plus",0,0);
  }
  else {
    _objc_msgSend((&PTR_LAB_011534c0)[uVar2] + (int)-(uRam00000000011534d0 ^ 0x7753c9f4),uVar3,
                  puVar1,0,0x315,@"YouTube Plus",uVar4,0,0);
  }
  _objc_release(uVar4);
  (*(code *)PTR__objc_release_01061028)(uVar3);
  return;
}



// -[YTSettingsSectionItemManager updateSectionForCategory:withEntry:], original IMP slot 0x1225968
/* Decompiled from supplied 5.2.2 arm package. VA 0x13d6c. FUN_00013d6c */

undefined1  [16] FUN_00013d6c(undefined8 param_1,undefined8 param_2,long param_3,undefined8 param_4)

{
  undefined1 auVar1 [16];
  
  if (param_3 == 0x315) {
    _objc_msgSend(param_1,@selector(updateYTLiteSectionWithEntry:),param_4);
  }
  else {
    (*pcRam0000000001225968)();
  }
  CallSupervisor(0x57ff);
  auVar1._8_8_ = 0x1f;
  auVar1._0_8_ = 0x1a;
  return auVar1;
}



// -[YTSettingsSectionItemManager updatePremiumEarlyAccessSectionWithEntry:], original IMP slot 0x012261a8
/* Decompiled from supplied 5.2.2 arm package. VA 0x6e654. FUN_0006e654 */

void FUN_0006e654(void)

{
  return;
}


