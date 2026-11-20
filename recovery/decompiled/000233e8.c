/* Decompiled from supplied 5.2.2 arm package. VA 0x233e8. _ptnRegisterBlock */

void _ptnRegisterBlock(void)

{
  _objc_retain();
  if (DAT_01225d30 != -1) {
    _dispatch_once((&PTR_LAB_01159138)[DAT_01225d30 == -1] + (int)-(DAT_01159148 ^ 0x4eb1e8cb),
                   &DAT_01225d30,&PTR___NSConcreteGlobalBlock_01061540);
  }
  _objc_retain(DAT_01225d28);
  _objc_sync_enter();
                    /* WARNING: Could not recover jumptable at 0x000234d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_01159160)[bRam0000000001225d10] + (int)-(uRam0000000001159170 ^ 0xabf7c77e)))
            ();
  return;
}


