/* Decompiled from supplied 5.2.2 arm package. VA 0x13432c. toggleSwitch: */

/* Function Stack Size: 0x18 bytes */

void TabbarVC::toggleSwitch_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined8 uVar2;
  ulong uVar3;
  long lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  DAT_01227404 = 1;
  uVar2 = _objc_retain(param_3);
  uVar3 = _objc_msgSend(uVar2,PTR_s_tag_0114b868);
  puVar1 = PTR_s_objectAtIndexedSubscript__0114aeb0;
  _objc_msgSend(*(undefined8 *)(param_1 + (long)_sections),PTR_s_objectAtIndexedSubscript__0114aeb0,
                (long)uVar3 >> 0x10);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,puVar1,uVar3 & 0xffff);
  lVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar2);
  if (lVar4 != 0) {
    _objc_msgSend(PTR_YTLUserDefaults_0114ead8,PTR_s_standardUserDefaults_0114afa0);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    uVar5 = FUN_00138224(param_3,PTR_s_isOn_0114d490);
    _objc_msgSend(lVar4,PTR_s_objectForKeyedSubscript__0114ae80,
                  &PTR____CFConstantStringClassReference_0118f6c0);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar2,PTR_s_setBool_forKey__0114add8,uVar5,uVar6);
    _objc_release(uVar6);
    _objc_release(uVar2);
  }
  _NSClassFromString(&PTR____CFConstantStringClassReference_0118f680);
  uVar2 = _objc_alloc_init();
  _objc_msgSend(uVar2,PTR_s_refreshPivotBar_0114b470);
  _objc_release(uVar2);
  _objc_release(lVar4);
  _objc_release(param_3);
  CallSupervisor(0x30f6);
  return;
}


