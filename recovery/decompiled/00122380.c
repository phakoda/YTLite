/* Decompiled from supplied 5.2.2 arm package. VA 0x122380. segmentForItems:isCompact: */

/* Function Stack Size: 0x1c bytes */

ID DVNTableViewController::segmentForItems_isCompact_
             (ID param_1,SEL param_2,ID param_3,bool param_4)

{
  undefined8 uVar1;
  long lVar2;
  ID IVar3;
  undefined8 local_1d0;
  undefined8 uStack_1c8;
  undefined8 uStack_1c0;
  undefined8 uStack_1b8;
  undefined8 local_1b0;
  undefined8 uStack_1a8;
  undefined8 uStack_1a0;
  undefined8 uStack_198;
  uint local_184;
  undefined **local_180;
  undefined1 auStack_f8 [128];
  undefined8 local_78;
  
  local_78 = *(undefined8 *)PTR____stack_chk_guard_01060708;
  local_180 = &PTR_LAB_0118de40;
  _objc_retain(param_3);
  uVar1 = _objc_alloc(PTR__OBJC_CLASS___UISegmentedControl_0114ee48);
  uVar1 = _objc_msgSend(uVar1,PTR_s_initWithItems__0114d590,param_3);
  _objc_msgSend(uVar1,PTR_s_setTranslatesAutoresizingMaskInt_0114b590,param_4);
  uStack_1a8 = 0;
  local_1b0 = 0;
  uStack_198 = 0;
  uStack_1a0 = 0;
  uStack_1c8 = 0;
  local_1d0 = 0;
  uStack_1b8 = 0;
  uStack_1c0 = 0;
  _objc_msgSend(uVar1);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  lVar2 = _objc_msgSend(uVar1,PTR_s_countByEnumeratingWithState_obje_0114b4e8,&local_1d0,auStack_f8,
                        0x10);
  local_184 = (uint)(lVar2 == 0);
                    /* WARNING: Could not recover jumptable at 0x001224f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IVar3 = (*(code *)(local_180[local_184] + (int)-(DAT_0118de50 ^ 0x6fb13ebe)))();
  return IVar3;
}


