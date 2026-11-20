/* Decompiled from supplied 5.2.2 arm package. VA 0x14cc0. viewDidLoad */

/* Function Stack Size: 0x10 bytes */

void InitWorkaround::viewDidLoad(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  dispatch_time_t dVar4;
  undefined *local_68;
  undefined8 local_60;
  code *local_58;
  undefined *puStack_50;
  ID local_48;
  ID local_40;
  undefined *puStack_38;
  
  puStack_38 = PTR_InitWorkaround_0114f088;
  local_40 = param_1;
  _objc_msgSendSuper2(&local_40,PTR_s_viewDidLoad_0114b070);
  _isYTPFirstTime = 0;
  uVar2 = _objc_alloc(PTR__OBJC_CLASS___UIActivityIndicatorView_0114eb20);
  uVar2 = _objc_msgSend(uVar2,PTR_s_initWithActivityIndicatorStyle__0114b078,0x65);
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_whiteColor_0114b080);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_setColor__0114b088,uVar3);
  _objc_release(uVar3);
  puVar1 = PTR_s_view_0114b090;
  _objc_msgSend(param_1,PTR_s_view_0114b090);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_center_0114b098);
  _objc_msgSend(uVar2,PTR_s_setCenter__0114b0a0);
  _objc_release(uVar3);
  _objc_msgSend(param_1,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_addSubview__0114b0a8,uVar2);
  _objc_release(uVar3);
  _objc_msgSend(uVar2,PTR_s_startAnimating_0114b0b0);
  dVar4 = _dispatch_time(0,2000000000);
  local_68 = PTR___NSConcreteStackBlock_01060660;
  local_60 = DAT_00c4c228;
  local_58 = FUN_00014e60;
  puStack_50 = &DAT_01061420;
  local_48 = param_1;
  _dispatch_after(dVar4,PTR___dispatch_main_q_01060760,&local_68);
  _objc_release(uVar2);
  CallSupervisor(0xc9ff);
  return;
}


