/* Decompiled from supplied 5.2.2 arm package. VA 0x218070. finishTimerAndCleanup */

/* Function Stack Size: 0x10 bytes */

void YTPSleepTimer::finishTimerAndCleanup(ID param_1,SEL param_2)

{
  uint uVar1;
  undefined *puVar2;
  dispatch_source_t source;
  undefined8 uVar3;
  undefined *puStack_68;
  undefined8 uStack_60;
  code *pcStack_58;
  undefined *puStack_50;
  ID IStack_48;
  uint local_3c;
  undefined **local_38;
  
  local_38 = &PTR_LAB_011ccdb0;
  *(undefined8 *)(param_1 + 0x20) = 0;
  *(undefined1 *)(param_1 + 0x30) = 0;
  source = *(dispatch_source_t *)(param_1 + 8);
  local_3c = (uint)(source == (dispatch_source_t)0x0);
  puVar2 = (&PTR_LAB_011ccdb0)[local_3c];
  uVar1 = DAT_011ccdc0 ^ 0x35cfe4c9;
  if (source != (dispatch_source_t)0x0) {
    uVar3 = *(undefined8 *)(param_1 + 8);
    *(undefined8 *)(param_1 + 8) = 0;
    _objc_retain(puVar2 + (int)-uVar1,source);
    _objc_release(uVar3);
    _dispatch_source_cancel(source);
    _objc_release(source);
  }
  puStack_68 = PTR___NSConcreteStackBlock_01060660;
  uStack_60 = DAT_00c4c228;
  pcStack_58 = FUN_00218170;
  puStack_50 = &DAT_01061420;
  IStack_48 = param_1;
  _dispatch_async(PTR___dispatch_main_q_01060760,&puStack_68);
  CallSupervisor(0x5e26);
  return;
}


