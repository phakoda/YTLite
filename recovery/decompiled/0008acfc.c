/* Decompiled from supplied 5.2.2 arm package. VA 0x8acfc. FUN_0008acfc */

undefined1  [16] FUN_0008acfc(undefined8 param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined *puVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined1 auVar13 [16];
  
  (*DAT_01226498)();
  uVar8 = _objc_alloc(PTR__OBJC_CLASS___UITapGestureRecognizer_0114ed98);
  puVar4 = PTR_s_initWithTarget_action__0114c530;
  uVar8 = _objc_msgSend(uVar8,PTR_s_initWithTarget_action__0114c530,param_1,
                        PTR_s_handleTwoFingerTap__0114c008);
  _objc_msgSend(uVar8,PTR_s_setNumberOfTouchesRequired__0114c968,2);
  puVar1 = PTR_s_view_0114b090;
  _objc_msgSend(param_1,PTR_s_view_0114b090);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  puVar5 = PTR_s_addGestureRecognizer__0114c540;
  _objc_msgSend(uVar9,PTR_s_addGestureRecognizer__0114c540,uVar8);
  _objc_release(uVar9);
  uVar9 = _objc_alloc(PTR__OBJC_CLASS___UIPanGestureRecognizer_0114ed90);
  uVar9 = _objc_msgSend(uVar9,puVar4,param_1,PTR_s_handleFingerPan__0114c010);
  puVar6 = PTR_s_setMinimumNumberOfTouches__0114c870;
  _objc_msgSend(uVar9,PTR_s_setMinimumNumberOfTouches__0114c870,1);
  puVar7 = PTR_s_setMaximumNumberOfTouches__0114c878;
  _objc_msgSend(uVar9,PTR_s_setMaximumNumberOfTouches__0114c878,1);
  puVar2 = PTR_s_setDelegate__0114b7d8;
  _objc_msgSend(uVar9,PTR_s_setDelegate__0114b7d8,param_1);
  _objc_msgSend(param_1,puVar1);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar10,puVar5,uVar9);
  _objc_release(uVar10);
  uVar10 = _objc_alloc(PTR__OBJC_CLASS___UIPanGestureRecognizer_0114ed90);
  puVar3 = PTR_s_handleHorizontalPan__0114be78;
  uVar10 = _objc_msgSend(uVar10,puVar4,param_1,PTR_s_handleHorizontalPan__0114be78);
  _objc_msgSend(uVar10,puVar6,1);
  _objc_msgSend(uVar10,puVar7,1);
  uVar11 = _objc_alloc_init(PTR_DVNHorizontalPanDelegate_0114eda0);
  _objc_setAssociatedObject(param_1,puVar3,uVar11,1);
  _objc_msgSend(uVar10,puVar2,uVar11);
  _objc_msgSend(param_1,puVar1);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar12,puVar5,uVar10);
  _objc_release(uVar12);
  _objc_release(uVar11);
  _objc_release(uVar10);
  _objc_release(uVar9);
  _objc_release(uVar8);
  CallSupervisor(0xaf51);
  auVar13._8_8_ = 0x1f;
  auVar13._0_8_ = 0x1a;
  return auVar13;
}


