/* Decompiled from supplied 5.2.2 arm package. VA 0x133a1c. tableView:didSelectRowAtIndexPath: */

/* Function Stack Size: 0x20 bytes */

void TabbarVC::tableView_didSelectRowAtIndexPath_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  
  DAT_012273fc = 1;
  _objc_retain(param_3);
  uVar4 = _objc_retain(param_4);
  uVar7 = *(undefined8 *)(param_1 + (long)_sections);
  uVar4 = _objc_msgSend(uVar4,PTR_s_section_0114af60);
  puVar1 = PTR_s_objectAtIndexedSubscript__0114aeb0;
  _objc_msgSend(uVar7,PTR_s_objectAtIndexedSubscript__0114aeb0,uVar4);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  uVar7 = _objc_msgSend(param_4,PTR_s_row_0114af70);
  _objc_msgSend(uVar4,puVar1,uVar7);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar4);
  _objc_msgSend(uVar7,PTR_s_objectForKeyedSubscript__0114ae80,
                &PTR____CFConstantStringClassReference_0118f580);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_00137de4(uVar4,PTR_s_isEqualToString__0114ae48,
                       &PTR____CFConstantStringClassReference_0118f540);
  _objc_release(uVar4);
  if (iVar2 != 0) {
    _objc_msgSend(param_3,PTR_s_cellForRowAtIndexPath__0114d298,param_4);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,PTR_s_accessoryView_0114d3c0);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    uVar6 = _NSClassFromString(&PTR____CFConstantStringClassReference_0118f500);
    iVar2 = FUN_00137f94(uVar5,PTR_s_isKindOfClass__0114ad70,uVar6);
    if (iVar2 != 0) {
      _objc_msgSend(uVar5,PTR_s_prepareHapticFeedback_0114d488);
      uVar3 = FUN_00137e4c(uVar5,PTR_s_isOn_0114d490);
      _objc_msgSend(uVar5,PTR_s_setOn_animated_userGenerated__0114d498,uVar3 ^ 1,1,1);
      _objc_msgSend(uVar5,PTR_s_releaseHapticFeedback_0114d4a0);
      _objc_msgSend(uVar5,PTR_s_fireHapticFeedback_0114d4a8);
      _NSClassFromString(&PTR____CFConstantStringClassReference_0118f4c0);
      uVar6 = _objc_alloc_init();
      _objc_msgSend(uVar6,PTR_s_refreshPivotBar_0114b470);
      _objc_release(uVar6);
    }
    _objc_release(uVar5);
    _objc_release(uVar4);
  }
  _objc_msgSend(param_3,PTR_s_deselectRowAtIndexPath_animated__0114d480,param_4,1);
  _objc_release(uVar7);
  _objc_release(param_4);
  _objc_release(param_3);
  CallSupervisor(0x31a8);
  return;
}


