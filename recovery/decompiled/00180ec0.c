/* Decompiled from supplied 5.2.2 arm package. VA 0x180ec0. getCacheSize */

/* Function Stack Size: 0x10 bytes */

ID YTPSettingsBuilder::getCacheSize(ID param_1,SEL param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  long lVar3;
  ID IVar4;
  undefined8 local_1e0;
  undefined8 uStack_1d8;
  undefined8 local_1d0;
  undefined8 uStack_1c8;
  undefined8 local_1c0;
  undefined8 uStack_1b8;
  undefined8 local_1b0;
  undefined8 uStack_1a8;
  uint local_194;
  undefined **local_190;
  undefined1 auStack_108 [128];
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  
  local_78 = *(undefined8 *)PTR____stack_chk_guard_01060708;
  local_190 = &PTR_LAB_011a8a70;
  thunk_FUN_0018b4c8(0xd,1,1);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_firstObject_0114b748);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar1);
  _NSTemporaryDirectory();
  uStack_80 = _objc_retainAutoreleasedReturnValue();
  local_88 = uVar2;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,PTR_s_arrayWithObjects_count__0114b600,&local_88,
                2);
  _objc_retainAutoreleasedReturnValue();
  uStack_1d8 = 0;
  local_1e0 = 0;
  uStack_1c8 = 0;
  local_1d0 = 0;
  uStack_1b8 = 0;
  local_1c0 = 0;
  uStack_1a8 = 0;
  local_1b0 = 0;
  uVar1 = _objc_retain();
  lVar3 = _objc_msgSend(uVar1,PTR_s_countByEnumeratingWithState_obje_0114b4e8,&local_1e0,auStack_108
                        ,0x10);
  local_194 = (uint)(lVar3 == 0);
                    /* WARNING: Could not recover jumptable at 0x00181048. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IVar4 = (*(code *)(local_190[lVar3 == 0] + (int)-(DAT_011a8a80 ^ 0x252a0dfc)))();
  return IVar4;
}


