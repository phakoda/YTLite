/* Decompiled from supplied 5.2.2 arm package. VA 0x1db00c. tableView:didSelectRowAtIndexPath: */

/* Function Stack Size: 0x20 bytes */

void SbWhitelistVC::tableView_didSelectRowAtIndexPath_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  uint uVar2;
  undefined8 uVar3;
  long lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  DAT_01227dd4 = 1;
  _objc_retain(param_3);
  uVar3 = _objc_retain(param_4);
  uVar6 = *(undefined8 *)(param_1 + (long)_sections);
  uVar3 = _objc_msgSend(uVar3,PTR_s_section_0114af60);
  puVar1 = PTR_s_objectAtIndexedSubscript__0114aeb0;
  _objc_msgSend(uVar6,PTR_s_objectAtIndexedSubscript__0114aeb0,uVar3);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  uVar6 = _objc_msgSend(param_4,PTR_s_row_0114af70);
  _objc_msgSend(uVar3,puVar1,uVar6);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  puVar1 = PTR_s_objectForKeyedSubscript__0114ae80;
  _objc_msgSend(uVar6,PTR_s_objectForKeyedSubscript__0114ae80,
                &PTR____CFConstantStringClassReference_011b8a10);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  uVar2 = FUN_001ddda4(uVar3,PTR_s_isEqualToString__0114ae48,
                       &PTR____CFConstantStringClassReference_011b89d0);
  _objc_release(uVar3);
  if (uVar2 != 0) {
    _objc_msgSend((&PTR_slimBarVisibilityChange__011b9318)[uVar2] +
                  (int)-(DAT_011b9328 ^ 0x940769df),uVar6,puVar1,
                  &PTR____CFConstantStringClassReference_011b8990);
    lVar4 = _objc_retainAutoreleasedReturnValue();
    if (lVar4 != 0) {
      _objc_msgSend(PTR__OBJC_CLASS___UIApplication_0114ebc8,PTR_s_sharedApplication_0114b528);
      uVar3 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(PTR__OBJC_CLASS___NSURL_0114eb78,PTR_s_URLWithString__0114b3d0,lVar4);
      uVar5 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar3,PTR_s_openURL_options_completionHandle_0114b878,uVar5,
                    *(undefined8 *)PTR____NSDictionary0___01060678,0);
      _objc_release(uVar5);
      _objc_release(uVar3);
    }
    _objc_release(lVar4);
  }
  _objc_msgSend(param_3,PTR_s_deselectRowAtIndexPath_animated__0114d480,param_4,1);
  _objc_release(uVar6);
  _objc_release(param_4);
  _objc_release(param_3);
  CallSupervisor(0xb12a);
  return;
}


