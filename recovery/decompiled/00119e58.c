/* Decompiled from supplied 5.2.2 arm package. VA 0x119e58. cellExistsInModel:target: */

/* Function Stack Size: 0x20 bytes */

bool DVNTableViewController::cellExistsInModel_target_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  bool bVar1;
  undefined8 uVar2;
  long lVar3;
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
  local_180 = &PTR_LAB_0118d0e8;
  _objc_retain(param_4);
  uStack_1a8 = 0;
  local_1b0 = 0;
  uStack_198 = 0;
  uStack_1a0 = 0;
  uStack_1c8 = 0;
  local_1d0 = 0;
  uStack_1b8 = 0;
  uStack_1c0 = 0;
  _objc_msgSend(param_3,PTR_s_sections_0114d240);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  lVar3 = _objc_msgSend(uVar2,PTR_s_countByEnumeratingWithState_obje_0114b4e8,&local_1d0,auStack_f8,
                        0x10);
  local_184 = (uint)(lVar3 == 0);
                    /* WARNING: Could not recover jumptable at 0x00119fac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  bVar1 = (*(code *)(local_180[local_184] + (int)-(DAT_0118d0f8 ^ 0x2e843ed6)))();
  return bVar1;
}


