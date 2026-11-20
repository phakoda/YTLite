/* Decompiled from supplied 5.2.2 arm package. VA 0x231990. genImageFromLayer:backgroundColor:completionHandler: */

/* Function Stack Size: 0x28 bytes */

void YTLHelper::genImageFromLayer_backgroundColor_completionHandler_
               (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,undefined4 param_6)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 in_d2;
  undefined8 uVar4;
  undefined8 in_d3;
  
  _objc_retain(param_5);
  puVar1 = PTR_s_frame_0114c8b0;
  _objc_retain(param_4);
  uVar2 = _objc_retain(param_3);
  _objc_msgSend(uVar2,puVar1);
  uVar4 = 0;
  thunk_FUN_002345ec(in_d2,in_d3,0,0);
  uVar2 = _UIGraphicsGetCurrentContext();
  uVar3 = _objc_retainAutorelease(param_4);
  uVar3 = _objc_msgSend(uVar3,PTR_s_CGColor_0114c8c0);
  _objc_release(param_4);
  _CGContextSetFillColorWithColor(uVar2,uVar3);
  _objc_msgSend(param_3,puVar1);
  _objc_msgSend(param_3,puVar1);
  _CGContextFillRect(0,0,uVar4,uVar2);
  _objc_msgSend(param_3,PTR_s_renderInContext__0114b948,uVar2);
  _objc_release(param_3);
  _UIGraphicsGetImageFromCurrentImageContext();
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _UIGraphicsEndImageContext();
  if (param_5 != 0) {
    (**(code **)(param_5 + 0x10))(param_5,uVar2);
  }
  _objc_release(uVar2);
  _objc_release(param_5);
  CallSupervisor(0x1dc7);
  return;
}


