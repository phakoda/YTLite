/* Decompiled from supplied 5.2.2 arm package. VA 0x19458. FUN_00019458 */

void FUN_00019458(void)

{
  undefined8 uVar1;
  undefined8 uVar2;
  long lVar3;
  
  DAT_01225bb0 = 1;
  (*DAT_01225a60)();
  _objc_msgSend(PTR__OBJC_CLASS___UIDevice_0114eb58,PTR_s_currentDevice_0114b2b0);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  uVar2 = _objc_msgSend(uVar1,PTR_s_class_0114ae88);
  lVar3 = _class_getInstanceVariable(uVar2,s_doc_symbolName_01154473);
  _objc_release(uVar1);
                    /* WARNING: Could not recover jumptable at 0x00019940. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_011553c0)[lVar3 == 0] + (int)-(DAT_011553d0 ^ 0x86840f4c)))();
  return;
}


