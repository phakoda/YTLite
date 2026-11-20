/* Decompiled from supplied 5.2.2 arm package. VA 0x217198. updateSlimBarTitle:style: */

/* Function Stack Size: 0x20 bytes */

void YTPSleepTimer::updateSlimBarTitle_style_
               (ID param_1,SEL param_2,ID param_3,unsigned_long_long param_4)

{
  undefined8 uVar1;
  long lVar2;
  undefined8 local_150;
  undefined8 uStack_148;
  undefined8 local_140;
  undefined8 uStack_138;
  undefined8 uStack_130;
  undefined8 uStack_128;
  undefined8 local_120;
  undefined8 uStack_118;
  uint local_104;
  undefined **local_100;
  undefined1 auStack_f8 [128];
  undefined8 local_78;
  
  local_78 = *(undefined8 *)PTR____stack_chk_guard_01060708;
  local_100 = &PTR_LAB_011ccbe8;
  _objc_retain(param_3);
  uStack_118 = 0;
  local_120 = 0;
  uStack_138 = 0;
  local_140 = 0;
  uStack_128 = 0;
  uStack_130 = 0;
  uStack_148 = 0;
  local_150 = 0;
  _objc_msgSend(param_1,PTR_s_barsForStyle__0114e528,param_4);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  lVar2 = _objc_msgSend(uVar1,PTR_s_countByEnumeratingWithState_obje_0114b4e8,&local_150,auStack_f8,
                        0x10);
  local_104 = (uint)(lVar2 == 0);
                    /* WARNING: Could not recover jumptable at 0x002172a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(local_100[local_104] + (int)-(DAT_011ccbf8 ^ 0x3015ab43)))();
  return;
}


