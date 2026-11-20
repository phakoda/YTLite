/* Decompiled from supplied 5.2.2 arm package. VA 0x26eb0. FUN_00026eb0 */

void FUN_00026eb0(void)

{
  if (DAT_01225d78 != -1) {
    _dispatch_once((&PTR_LAB_011594b8)[DAT_01225d78 == -1] + (int)-(DAT_011594c8 ^ 0xf7b404c7),
                   &DAT_01225d78,&PTR___NSConcreteGlobalBlock_01061680);
                    /* WARNING: Could not recover jumptable at 0x00026f74. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)((&PTR_LAB_011594e0)[bRam0000000001225d80] + (int)-(uRam00000000011594f0 ^ 0x4a10df9))
    )();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00026ff8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_011594e0)[bRam0000000001225d80] + (int)-(uRam00000000011594f0 ^ 0x4a10df9)))
            ();
  return;
}


