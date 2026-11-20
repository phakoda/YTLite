/* Decompiled from supplied 5.2.2 arm package. VA 0xbf1b0. FUN_000bf1b0 */

void FUN_000bf1b0(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  undefined8 local_150;
  undefined8 uStack_148;
  undefined8 uStack_140;
  undefined8 uStack_138;
  undefined8 local_130;
  undefined8 uStack_128;
  undefined8 uStack_120;
  undefined8 uStack_118;
  uint local_104;
  undefined **local_100;
  undefined1 auStack_f8 [128];
  undefined8 local_78;
  
  local_78 = *(undefined8 *)PTR____stack_chk_guard_01060708;
  local_100 = &PTR_LAB_011827e8;
  uStack_148 = 0;
  local_150 = 0;
  uStack_138 = 0;
  uStack_140 = 0;
  uStack_128 = 0;
  local_130 = 0;
  uStack_118 = 0;
  uStack_120 = 0;
  uVar1 = _objc_retain(*(undefined8 *)(param_1 + 0x20));
  lVar2 = _objc_msgSend(uVar1,PTR_s_countByEnumeratingWithState_obje_0114b4e8,&local_150,auStack_f8,
                        0x10);
  local_104 = (uint)(lVar2 == 0);
                    /* WARNING: Could not recover jumptable at 0x000bf284. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(local_100[local_104] + (int)-(DAT_011827f8 ^ 0x8d21124f)))();
  return;
}


