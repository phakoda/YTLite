/* Decompiled from supplied 5.2.2 arm package. VA 0x1c2944. hideWithCompletion: */

/* Function Stack Size: 0x18 bytes */

void ToastView::hideWithCompletion_(ID param_1,SEL param_2,ID param_3,undefined4 param_4)

{
  bool bVar1;
  double dVar2;
  undefined *puStack_60;
  undefined8 uStack_58;
  code *pcStack_50;
  undefined *puStack_48;
  ID IStack_40;
  ID IStack_38;
  uint local_2c;
  undefined **local_28;
  
  local_28 = &PTR_LAB_011b4528;
  _objc_retain(param_3,param_2,param_3,param_4);
  bVar1 = *(char *)(param_1 + (long)_isAnimating) == '\0';
  local_2c = (uint)bVar1;
  if ((bVar1) && (dVar2 = (double)_objc_msgSend(param_1,PTR_s_alpha_0114c9d8), dVar2 == 0.0)) {
                    /* WARNING: Could not recover jumptable at 0x001c2acc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)((&PTR_LAB_011b4558)[param_3 == 0] + (int)-(uRam00000000011b4568 ^ 0x8411f74c)))();
    return;
  }
  puStack_60 = PTR___NSConcreteStackBlock_01060660;
  uStack_58 = DAT_00c4c228;
  pcStack_50 = FUN_001c2ae0;
  puStack_48 = &UNK_01062c50;
  IStack_40 = param_1;
  _objc_retain(param_3);
  IStack_38 = param_3;
  _dispatch_async(PTR___dispatch_main_q_01060760,&puStack_60);
  _objc_release(IStack_38);
  _objc_release(param_3);
  CallSupervisor(0xdc27);
  return;
}


