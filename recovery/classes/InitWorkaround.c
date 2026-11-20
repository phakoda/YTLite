// Decompiled implementation evidence for InitWorkaround. Not compilable source.

// -[InitWorkaround viewDidLoad], 0x14cc0
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
  _objc_msgSendSuper2(&local_40,@selector(viewDidLoad));
  _isYTPFirstTime = 0;
  uVar2 = _objc_alloc(PTR__OBJC_CLASS___UIActivityIndicatorView_0114eb20);
  uVar2 = _objc_msgSend(uVar2,@selector(initWithActivityIndicatorStyle:),0x65);
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(whiteColor));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(setColor:),uVar3);
  _objc_release(uVar3);
  puVar1 = @selector(view);
  _objc_msgSend(param_1,@selector(view));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(center));
  _objc_msgSend(uVar2,@selector(setCenter:));
  _objc_release(uVar3);
  _objc_msgSend(param_1,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(addSubview:),uVar2);
  _objc_release(uVar3);
  _objc_msgSend(uVar2,@selector(startAnimating));
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



// -[InitWorkaround completion], 0x15148
/* Decompiled from supplied 5.2.2 arm package. VA 0x15148. completion */

/* Function Stack Size: 0x10 bytes */

ID InitWorkaround::completion(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + (long)_completion);
}



// -[InitWorkaround setCompletion:], 0x15158
/* Decompiled from supplied 5.2.2 arm package. VA 0x15158. setCompletion: */

/* Function Stack Size: 0x18 bytes */

void InitWorkaround::setCompletion_(ID param_1,SEL param_2,ID param_3,undefined4 param_4)

{
  _objc_setProperty_nonatomic_copy();
  CallSupervisor(0x2b3c);
  return;
}



// -[InitWorkaround .cxx_destruct], 0x1518c
/* Decompiled from supplied 5.2.2 arm package. VA 0x1518c. .cxx_destruct */

/* Function Stack Size: 0x10 bytes */

void InitWorkaround::_cxx_destruct(ID param_1,SEL param_2)

{
  _objc_storeStrong(param_1 + (long)_completion,0);
  return;
}


