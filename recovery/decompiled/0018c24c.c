/* Decompiled from supplied 5.2.2 arm package. VA 0x18c24c. cellsMatching: */

/* Function Stack Size: 0x18 bytes */

ID DVNTableModel::cellsMatching_(ID param_1,SEL param_2,ID param_3,undefined4 param_4)

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
  local_180 = &PTR_LAB_011a8f08;
  _objc_retain(param_3,param_2,param_3,param_4);
  _objc_msgSend(PTR__OBJC_CLASS___NSMutableArray_0114eb90,PTR_s_array_0114c388);
  _objc_retainAutoreleasedReturnValue();
  uStack_1c8 = 0;
  local_1d0 = 0;
  uStack_1b8 = 0;
  uStack_1c0 = 0;
  uStack_1a8 = 0;
  local_1b0 = 0;
  uStack_198 = 0;
  uStack_1a0 = 0;
  _objc_msgSend(param_1,PTR_s_sections_0114d240);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  lVar2 = _objc_msgSend(uVar1,PTR_s_countByEnumeratingWithState_obje_0114b4e8,&local_1d0,auStack_f8,
                        0x10);
  local_184 = (uint)(lVar2 == 0);
                    /* WARNING: Could not recover jumptable at 0x0018c3a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IVar3 = (*(code *)(local_180[local_184] + (int)-(DAT_011a8f18 ^ 0x9bd8315)))();
  return IVar3;
}


