// Decompiled implementation evidence for ToastManager. Not compilable source.

// -[ToastManager init], 0x1c9bd0
/* Decompiled from supplied 5.2.2 arm package. VA 0x1c9bd0. init */

/* Function Stack Size: 0x10 bytes */

ID ToastManager::init(ID param_1,SEL param_2)

{
  ID IVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  ID local_40;
  undefined *puStack_38;
  uint local_2c;
  undefined **local_28;
  
  local_28 = &PTR_LAB_011b4e80;
  puStack_38 = PTR_ToastManager_0114f0f8;
  local_40 = param_1;
  IVar1 = _objc_msgSendSuper2(&local_40,@selector(init));
  local_2c = (uint)(IVar1 == 0);
  if (IVar1 != 0) {
    _objc_msgSend(PTR__OBJC_CLASS___NSMutableArray_0114eb90,@selector(array));
    uVar2 = _objc_retainAutoreleasedReturnValue();
    uVar3 = *(undefined8 *)(IVar1 + 0x10);
    *(undefined8 *)(IVar1 + 0x10) = uVar2;
    _objc_release(uVar3);
  }
  return IVar1;
}



// -[ToastManager registerToast:], 0x1c9d98
/* Decompiled from supplied 5.2.2 arm package. VA 0x1c9d98. registerToast: */

/* Function Stack Size: 0x18 bytes */

void ToastManager::registerToast_(ID param_1,SEL param_2,ID param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  _objc_retain(param_3);
  if (param_3 != 0) {
    uVar2 = *(undefined8 *)(param_1 + 0x10);
    _objc_retain((&PTR_LAB_011b4ea0)[param_3 == 0] + (int)-(DAT_011b4eb0 ^ 0x8e0cc28e),uVar2);
    _objc_sync_enter();
    iVar1 = FUN_001ca548(*(undefined8 *)(param_1 + 0x10),@selector(containsObject:),param_3);
    if (iVar1 == 0) {
      _objc_msgSend(*(undefined8 *)(param_1 + 0x10),@selector(addObject:),param_3);
      _objc_msgSend(param_1,@selector(updateAllToasts));
    }
    _objc_sync_exit(uVar2);
    _objc_release(uVar2);
  }
  _objc_release(param_3);
  CallSupervisor(0x37c6);
  return;
}



// -[ToastManager unregisterToast:], 0x1c9ee0
/* Decompiled from supplied 5.2.2 arm package. VA 0x1c9ee0. unregisterToast: */

/* Function Stack Size: 0x18 bytes */

void ToastManager::unregisterToast_(ID param_1,SEL param_2,ID param_3)

{
  undefined8 uVar1;
  
  _objc_retain(param_3);
  if (param_3 != 0) {
    uVar1 = *(undefined8 *)(param_1 + 0x10);
    _objc_retain((&PTR_LAB_011b4ed8)[param_3 == 0] + (int)-(DAT_011b4ee8 ^ 0x386a0bb),uVar1);
    _objc_sync_enter();
    _objc_msgSend(*(undefined8 *)(param_1 + 0x10),@selector(removeObject:),param_3);
    _objc_msgSend(param_1,@selector(updateAllToasts));
    _objc_sync_exit(uVar1);
    _objc_release(uVar1);
  }
  _objc_release(param_3);
  return;
}



// -[ToastManager updateAllToasts], 0x1c9fd8
/* Decompiled from supplied 5.2.2 arm package. VA 0x1c9fd8. updateAllToasts */

/* Function Stack Size: 0x10 bytes */

void ToastManager::updateAllToasts(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  long lVar4;
  undefined8 uVar5;
  undefined8 local_140;
  undefined8 *puStack_138;
  long *plStack_130;
  undefined8 uStack_128;
  undefined8 local_120;
  undefined8 uStack_118;
  undefined8 uStack_110;
  undefined8 uStack_108;
  uint local_fc;
  undefined **local_f8;
  undefined1 auStack_f0 [128];
  long local_70;
  
  local_70 = *(long *)PTR____stack_chk_guard_01060708;
  local_f8 = &PTR_LAB_011b4ef8;
  uVar2 = _objc_retain(*(undefined8 *)(param_1 + 0x10));
  _objc_sync_enter();
  puStack_138 = (undefined8 *)0x0;
  local_140 = 0;
  uStack_128 = 0;
  plStack_130 = (long *)0x0;
  uStack_118 = 0;
  local_120 = 0;
  uStack_108 = 0;
  uStack_110 = 0;
  uVar5 = *(undefined8 *)(param_1 + 0x10);
  uVar3 = _objc_retain(uVar5);
  lVar4 = _objc_msgSend(uVar3,@selector(countByEnumeratingWithState:objects:count:),&local_140,auStack_f0,
                        0x10);
  puVar1 = @selector(updateLayout);
  local_fc = (uint)(lVar4 == 0);
  if (lVar4 != 0) {
    if (*plStack_130 != *plStack_130) {
      _objc_enumerationMutation
                ((&PTR_LAB_011b4f20)[*plStack_130 == *plStack_130] +
                 (int)-(uRam00000000011b4f30 ^ 0xac7c3314),uVar5);
    }
    _objc_msgSend(*puStack_138,puVar1);
                    /* WARNING: Could not recover jumptable at 0x001ca164. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)((&PTR_LAB_011b4f38)[lVar4 == 1] + (int)-(uRam00000000011b4f48 ^ 0x90de16ec)))();
    return;
  }
  _objc_release(local_f8[local_fc] + (int)-(DAT_011b4f08 ^ 0x1c0760ac),uVar5);
  _objc_sync_exit(uVar2);
  _objc_release(uVar2);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_70) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  return;
}



// -[ToastManager toasts], 0x1ca260
/* Decompiled from supplied 5.2.2 arm package. VA 0x1ca260. toasts */

/* Function Stack Size: 0x10 bytes */

ID ToastManager::toasts(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + 0x10);
}



// -[ToastManager setToasts:], 0x1ca268
/* Decompiled from supplied 5.2.2 arm package. VA 0x1ca268. setToasts: */

/* Function Stack Size: 0x18 bytes */

void ToastManager::setToasts_(ID param_1,SEL param_2,ID param_3)

{
  _objc_storeStrong(param_1 + 0x10,param_3);
  CallSupervisor(0x5b3e);
  return;
}



// -[ToastManager offsetController], 0x1ca29c
/* Decompiled from supplied 5.2.2 arm package. VA 0x1ca29c. offsetController */

/* Function Stack Size: 0x10 bytes */

ID ToastManager::offsetController(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + 0x18);
}



// -[ToastManager setOffsetController:], 0x1ca2a4
/* Decompiled from supplied 5.2.2 arm package. VA 0x1ca2a4. setOffsetController: */

/* Function Stack Size: 0x18 bytes */

void ToastManager::setOffsetController_(ID param_1,SEL param_2,ID param_3)

{
  _objc_storeStrong(param_1 + 0x18,param_3);
  CallSupervisor(0xeddb);
  return;
}



// -[ToastManager isPinnedTop], 0x1ca2d8
/* Decompiled from supplied 5.2.2 arm package. VA 0x1ca2d8. isPinnedTop */

/* Function Stack Size: 0x10 bytes */

bool ToastManager::isPinnedTop(ID param_1,SEL param_2)

{
  return (bool)*(byte *)(param_1 + 8);
}



// -[ToastManager setIsPinnedTop:], 0x1ca2e0
/* Decompiled from supplied 5.2.2 arm package. VA 0x1ca2e0. setIsPinnedTop: */

/* Function Stack Size: 0x14 bytes */

void ToastManager::setIsPinnedTop_(ID param_1,SEL param_2,bool param_3)

{
  *(char *)(param_1 + 8) = (char)param_3;
  CallSupervisor(0xf856);
  return;
}



// -[ToastManager isFullscreen], 0x1ca300
/* Decompiled from supplied 5.2.2 arm package. VA 0x1ca300. isFullscreen */

/* Function Stack Size: 0x10 bytes */

bool ToastManager::isFullscreen(ID param_1,SEL param_2)

{
  return (bool)*(byte *)(param_1 + 9);
}



// -[ToastManager setIsFullscreen:], 0x1ca308
/* Decompiled from supplied 5.2.2 arm package. VA 0x1ca308. setIsFullscreen: */

/* Function Stack Size: 0x14 bytes */

void ToastManager::setIsFullscreen_(ID param_1,SEL param_2,bool param_3)

{
  *(char *)(param_1 + 9) = (char)param_3;
  CallSupervisor(0x2c29);
  return;
}



// -[ToastManager .cxx_destruct], 0x1ca328
/* Decompiled from supplied 5.2.2 arm package. VA 0x1ca328. .cxx_destruct */

/* Function Stack Size: 0x10 bytes */

void ToastManager::_cxx_destruct(ID param_1,SEL param_2)

{
  _objc_storeStrong(param_1 + 0x18,0);
  _objc_storeStrong(param_1 + 0x10,0);
  CallSupervisor(0xa6f9);
  return;
}



// +[ToastManager sharedManager], 0x1c9b1c
/* Decompiled from supplied 5.2.2 arm package. VA 0x1c9b1c. sharedManager */

/* Function Stack Size: 0x10 bytes */

ID ToastManager::sharedManager(ID param_1,SEL param_2)

{
  ID IVar1;
  SEL extraout_x1;
  
  if (DAT_01227c80 != -1) {
    _dispatch_once((&PTR_LAB_011b4e58)[DAT_01227c80 == -1] + (int)-(DAT_011b4e68 ^ 0xad99279f),
                   &DAT_01227c80,&PTR___NSConcreteGlobalBlock_01062ca0);
    param_2 = extraout_x1;
  }
  IVar1 = _objc_retainAutoreleaseReturnValue(DAT_01227c78,param_2);
  return IVar1;
}



// +[ToastManager showMessageWithText:isSuccess:], 0x1c9c8c
/* Decompiled from supplied 5.2.2 arm package. VA 0x1c9c8c. showMessageWithText:isSuccess: */

/* Function Stack Size: 0x1c bytes */

void ToastManager::showMessageWithText_isSuccess_(ID param_1,SEL param_2,ID param_3,bool param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined *local_68;
  undefined8 local_60;
  code *local_58;
  undefined *puStack_50;
  undefined8 local_48;
  ID local_40;
  undefined1 local_38;
  
  _objc_retain(param_3);
  uVar1 = _objc_alloc_init(PTR_ToastView_0114ec98);
  _objc_msgSend(PTR_ToastManager_0114ecd0,@selector(sharedManager));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(registerToast:),uVar1);
  _objc_release(uVar2);
  local_68 = PTR___NSConcreteStackBlock_01060660;
  local_60 = DAT_00c4c228;
  local_58 = FUN_001c9d80;
  puStack_50 = &DAT_01062cc0;
  local_38 = (undefined1)param_4;
  local_48 = uVar1;
  local_40 = param_3;
  _objc_retain(param_3);
  _objc_retain(uVar1);
  _dispatch_async(PTR___dispatch_main_q_01060760,&local_68);
  _objc_release(local_40);
  _objc_release(local_48);
  _objc_release(param_3);
  _objc_release(uVar1);
  return;
}


