/* Decompiled from supplied 5.2.2 arm package. VA 0x1f2dfc. openVideoWithID:handler: */

/* Function Stack Size: 0x20 bytes */

void YTPPlayerHelper::openVideoWithID_handler_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  
  DAT_01227fa0 = 1;
  _objc_retain(param_3);
  uVar3 = _objc_retain(param_4);
  puVar1 = PTR_s_valueForKey__0114ae90;
  _objc_msgSend(uVar3,PTR_s_valueForKey__0114ae90,&PTR____CFConstantStringClassReference_011bd9c0);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_node_0114ae98);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  uVar3 = _objc_msgSend(param_4,PTR_s_class_0114ae88);
  lVar5 = _class_getInstanceVariable(uVar3,s__context_011bd8d2);
  if (lVar5 == 0) {
    _objc_msgSend(param_1,PTR_s_openVideoWithID__0114e240,param_3);
  }
  else {
    _objc_msgSend((&PTR_LAB_011bdcb0)[lVar5 == 0] + (int)-(uRam00000000011bdcc0 ^ 0xebb355cb),
                  param_4,puVar1,&PTR____CFConstantStringClassReference_011bd980);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    puVar1 = PTR_s_parentResponder_0114aef0;
    _objc_msgSend(uVar3,PTR_s_parentResponder_0114aef0);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    uVar7 = _objc_getClass(s_YTElementsCellController_011bd8b0);
    uVar2 = FUN_001f3fbc(uVar6,PTR_s_isKindOfClass__0114ad70,uVar7);
    _objc_release(uVar6);
    if (uVar2 == 0) {
      _objc_msgSend(param_1,PTR_s_openVideoWithID__0114e240,param_3);
    }
    else {
      _objc_msgSend((&PTR_LAB_011bdcd0)[uVar2] + (int)-(uRam00000000011bdce0 ^ 0x7a351179),uVar3,
                    puVar1);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      uVar7 = _objc_getClass(s_YTICommand_011bd8e6);
      _objc_msgSend(uVar7,PTR_s_watchNavigationEndpointWithVideo_0114e248,param_3);
      lVar5 = _objc_retainAutoreleasedReturnValue();
      if (lVar5 == 0) {
        _objc_msgSend(param_1,PTR_s_openVideoWithID__0114e240,param_3);
      }
      else {
        uVar7 = _objc_getClass((&PTR_LAB_011bdcf0)[lVar5 == 0] +
                               (int)-(uRam00000000011bdd00 ^ 0x65faefad),
                               s_YTCommandResponderEvent_011bd930);
        _objc_msgSend(uVar4,PTR_s_view_0114b090);
        uVar8 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar6,PTR_s_elementEntry_0114e250);
        uVar9 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar7,PTR_s_eventWithCommand_fromView_entry__0114e258,lVar5,uVar8,uVar9,0,
                      uVar6);
        uVar7 = _objc_retainAutoreleasedReturnValue();
        _objc_release(uVar9);
        _objc_release(uVar8);
        _objc_msgSend(uVar7,PTR_s_send_0114e260);
        _objc_release(uVar7);
      }
      _objc_release(lVar5);
      _objc_release(uVar6);
    }
    _objc_release(uVar3);
  }
  _objc_release(uVar4);
  _objc_release(param_4);
  _objc_release(param_3);
  CallSupervisor(0x3cb8);
  return;
}


