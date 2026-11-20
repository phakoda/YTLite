/* Decompiled from supplied 5.2.2 arm package. VA 0x119580. navigateToCell: */

/* Function Stack Size: 0x18 bytes */

void DVNTableViewController::navigateToCell_(ID param_1,SEL param_2,ID param_3)

{
  undefined8 uVar1;
  long lVar2;
  
  _objc_retain(param_3);
  _objc_msgSend(*(undefined8 *)(param_1 + (long)_model));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  lVar2 = _objc_msgSend();
  _objc_release(uVar1);
                    /* WARNING: Could not recover jumptable at 0x001196d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0118cf90)[lVar2 == 0] + (int)-(DAT_0118cfa0 ^ 0xcc2d0334)))();
  return;
}


