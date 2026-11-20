/* Decompiled from supplied 5.2.2 arm package. VA 0x21558c. barsForStyle: */

/* Function Stack Size: 0x18 bytes */

ID YTPSleepTimer::barsForStyle_(ID param_1,SEL param_2,unsigned_long_long param_3)

{
  undefined8 uVar1;
  long lVar2;
  long lVar3;
  ID IVar4;
  
  _objc_msgSend(PTR__OBJC_CLASS___NSMutableArray_0114eb90,PTR_s_array_0114c388);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,PTR_s_playerSlimBar_0114e4d0);
  lVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,PTR_s_globalSlimBar_0114e4d8);
  lVar3 = _objc_retainAutoreleasedReturnValue();
  if (lVar2 != 0) {
    _objc_msgSend((&PTR_LAB_011cc998)[lVar2 == 0] + (int)-(DAT_011cc9a8 ^ 0x7dd9959f),uVar1,
                  PTR_s_addObject__0114b3a0,lVar2);
                    /* WARNING: Could not recover jumptable at 0x002156a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    IVar4 = (*(code *)((&PTR_LAB_011cc9b8)[param_3 == 1 || lVar3 == 0] +
                      (int)-(uRam00000000011cc9c8 ^ 0xc4a4f892)))();
    return IVar4;
  }
                    /* WARNING: Could not recover jumptable at 0x002156d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IVar4 = (*(code *)((&PTR_LAB_011cc9b8)[param_3 == 1 || lVar3 == 0] +
                    (int)-(uRam00000000011cc9c8 ^ 0xc4a4f892)))();
  return IVar4;
}


