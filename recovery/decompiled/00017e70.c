/* Decompiled from supplied 5.2.2 arm package. VA 0x17e70. FUN_00017e70 */

void FUN_00017e70(void)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uStack_c0;
  undefined8 uStack_b8;
  undefined8 uStack_b0;
  undefined8 uStack_a8;
  undefined **local_a0;
  undefined **ppuStack_98;
  undefined **local_88;
  undefined **local_80;
  uint uStack_74;
  undefined **local_70;
  undefined **local_68;
  uint local_5c;
  undefined **local_58;
  
  local_58 = &PTR_LAB_01155180;
  local_5c = (uint)(DAT_01225b7c == 0);
  local_70 = &PTR_LAB_011551a0;
  local_88 = &PTR_LAB_011551c0;
  local_68 = &PTR_LAB_01154cd0;
  local_80 = &PTR_LAB_01154cd0;
  local_a0 = &PTR_LAB_01154cd0;
  ppuStack_98 = &PTR_LAB_01154cd0;
  DAT_01225b7c = 1;
  _objc_msgSend(PTR__OBJC_CLASS___NSThread_0114eb30,PTR_s_callStackReturnAddresses_0114b210);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  uStack_b8 = 0;
  uStack_c0 = 0;
  uStack_a8 = 0;
  uStack_b0 = 0;
  _objc_msgSend(uVar2,PTR_s_objectAtIndexedSubscript__0114aeb0,2);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  uVar3 = _objc_msgSend(uVar2,PTR_s_longLongValue_0114b218);
  iVar1 = _dladdr(uVar3,&uStack_c0);
  _objc_release(uVar2);
  uStack_74 = (uint)(iVar1 == 0);
                    /* WARNING: Could not recover jumptable at 0x00018118. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(local_70[uStack_74] + (int)-(uRam00000000011551b0 ^ 0xef9c6336)))();
  return;
}


