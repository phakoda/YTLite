/* Decompiled from supplied 5.2.2 arm package. VA 0x101fac. FUN_00101fac */

undefined1  [16] FUN_00101fac(long param_1)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined *local_58;
  undefined8 local_50;
  code *local_48;
  undefined *puStack_40;
  undefined8 local_38;
  
  _objc_msgSend(PTR__OBJC_CLASS___AVPlayer_0114ed10,PTR_s_playerWithURL__0114c438,
                *(undefined8 *)(param_1 + 0x20));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  uVar3 = _objc_alloc_init(PTR__OBJC_CLASS___AVPlayerViewController_0114edf8);
  _objc_msgSend(uVar3,PTR_s_setPlayer__0114cfe8,uVar2);
  _objc_msgSend(*(undefined8 *)(param_1 + 0x28),PTR_s_pause_0114c4c0);
  puVar1 = PTR_s_presentViewController_animated_c_0114b298;
  uVar4 = *(undefined8 *)(param_1 + 0x28);
  local_58 = PTR___NSConcreteStackBlock_01060660;
  local_50 = DAT_00c4c228;
  local_48 = FUN_001020b8;
  puStack_40 = &DAT_01061420;
  local_38 = uVar2;
  _objc_retain(uVar2);
  _objc_msgSend(uVar4,puVar1,uVar3,1,&local_58);
  _objc_release(local_38);
  _objc_release(uVar2);
  _objc_release(uVar3);
  CallSupervisor(0xda32);
  return ZEXT816(0x1f);
}


