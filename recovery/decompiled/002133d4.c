/* Decompiled from supplied 5.2.2 arm package. VA 0x2133d4. startTimer */

/* Function Stack Size: 0x10 bytes */

void YTPSleepTimer::startTimer(ID param_1,SEL param_2)

{
  undefined8 uVar1;
  undefined *puVar2;
  dispatch_queue_t queue;
  dispatch_object_t object;
  dispatch_time_t start;
  undefined8 uVar3;
  undefined *local_a0;
  undefined8 local_98;
  code *local_90;
  undefined *puStack_88;
  undefined1 auStack_80 [8];
  undefined1 auStack_78 [8];
  undefined *local_70;
  undefined8 local_68;
  code *local_60;
  undefined *puStack_58;
  ID local_50;
  undefined8 local_48;
  
  local_48 = _objc_msgSend(param_1,PTR_s_remainingSeconds_0114e3f8);
  puVar2 = PTR___NSConcreteStackBlock_01060660;
  uVar1 = DAT_00c4c228;
  local_70 = PTR___NSConcreteStackBlock_01060660;
  local_68 = DAT_00c4c228;
  local_60 = FUN_00213554;
  puStack_58 = &DAT_01061810;
  local_50 = param_1;
  _dispatch_async(PTR___dispatch_main_q_01060760,&local_70);
  _objc_msgSend(param_1,PTR_s_timerQueue_0114e410);
  queue = (dispatch_queue_t)_objc_retainAutoreleasedReturnValue();
  object._os_obj =
       (_os_object_s *)
       _dispatch_source_create
                 ((dispatch_source_type_t)PTR___dispatch_source_type_timer_01060768,0,0,queue);
  _objc_release(queue);
  uVar3 = *(undefined8 *)(param_1 + 8);
  ((dispatch_object_t *)(param_1 + 8))->_os_obj = (_os_object_s *)object;
  _objc_retain(object._os_obj);
  _objc_release(uVar3);
  start = _dispatch_time(0,0);
  _dispatch_source_set_timer((dispatch_source_t)object._os_obj,start,1000000000,100000000);
  _objc_initWeak(auStack_78,param_1);
  local_a0 = puVar2;
  local_98 = uVar1;
  local_90 = FUN_0021373c;
  puStack_88 = &DAT_010627f0;
  _objc_copyWeak(auStack_80,auStack_78);
  _dispatch_source_set_event_handler(object._os_obj,&local_a0);
  _dispatch_resume(object);
  _objc_release(object._os_obj);
  _objc_destroyWeak(auStack_80);
  _objc_destroyWeak(auStack_78);
  CallSupervisor(0x4ed1);
  return;
}


