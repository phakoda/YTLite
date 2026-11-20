/* Decompiled from supplied 5.2.2 arm package. VA 0x53748. FUN_00053748 */

void FUN_00053748(undefined8 param_1)

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
  local_100 = &PTR_LAB_0117a8c0;
  _objc_getAssociatedObject(param_1,PTR_s_playLottieAnimation_0114ba80);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  uStack_148 = 0;
  local_150 = 0;
  uStack_138 = 0;
  uStack_140 = 0;
  uStack_128 = 0;
  local_130 = 0;
  uStack_118 = 0;
  uStack_120 = 0;
  lVar2 = _objc_msgSend(uVar1,PTR_s_countByEnumeratingWithState_obje_0114b4e8,&local_150,auStack_f8,
                        0x10);
  local_104 = (uint)(lVar2 == 0);
                    /* WARNING: Could not recover jumptable at 0x0005382c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(local_100[local_104] + (int)-(DAT_0117a8d0 ^ 0x8c086bf7)))();
  return;
}


