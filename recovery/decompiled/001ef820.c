/* Decompiled from supplied 5.2.2 arm package. VA 0x1ef820. _calculateDetentHeight */

void _calculateDetentHeight(undefined8 param_1)

{
  undefined8 uVar1;
  ulong uVar2;
  long lVar3;
  undefined8 local_140;
  undefined8 uStack_138;
  undefined8 uStack_130;
  undefined8 uStack_128;
  undefined8 local_120;
  undefined8 uStack_118;
  undefined8 uStack_110;
  undefined8 uStack_108;
  uint local_f4;
  undefined **local_f0;
  undefined1 auStack_e8 [128];
  undefined8 local_68;
  
  local_68 = *(undefined8 *)PTR____stack_chk_guard_01060708;
  local_f0 = &PTR_LAB_011bd460;
  uVar1 = _objc_retain();
  uVar2 = _objc_msgSend(uVar1,PTR_s_count_0114b840);
  uStack_138 = 0;
  local_140 = 0;
  uStack_128 = 0;
  uStack_130 = 0;
  uStack_118 = 0;
  local_120 = 0;
  uStack_108 = 0;
  uStack_110 = 0;
  uVar1 = _objc_retain((double)uVar2,0x4044000000000000,0x4039000000000000,param_1);
  lVar3 = _objc_msgSend(uVar1,PTR_s_countByEnumeratingWithState_obje_0114b4e8,&local_140,auStack_e8,
                        0x10);
  local_f4 = (uint)(lVar3 == 0);
                    /* WARNING: Could not recover jumptable at 0x001ef91c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(local_f0[local_f4] + (int)-(DAT_011bd470 ^ 0xb861c2a3)))();
  return;
}


