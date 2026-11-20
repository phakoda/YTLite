/* Decompiled from supplied 5.2.2 arm package. VA 0x1c2878. isHidden */

/* Function Stack Size: 0x10 bytes */

bool ToastView::isHidden(ID param_1,SEL param_2)

{
  bool bVar1;
  dispatch_time_t dVar2;
  ID local_30;
  undefined *puStack_28;
  
  puStack_28 = PTR_ToastView_0114f0e8;
  local_30 = param_1;
  bVar1 = FUN_001c7b1c(&local_30,PTR_s_isHidden_0114c930);
  dVar2 = _dispatch_time(0,300000000);
  _dispatch_after(dVar2,PTR___dispatch_main_q_01060760,&PTR___NSConcreteGlobalBlock_01062c80);
  return bVar1;
}


