/* Decompiled from supplied 5.2.2 arm package. VA 0xb4f94. FUN_000b4f94 */

void FUN_000b4f94(void)

{
  undefined8 uVar1;
  double dVar2;
  
  DAT_01226eac = 1;
  _objc_msgSend(PTR_PlayerToast_0114eda8,PTR_s_sharedToast_0114c9c0);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  dVar2 = (double)_objc_msgSend(uVar1,PTR_s_alpha_0114c9d8);
  _objc_release(uVar1);
                    /* WARNING: Could not recover jumptable at 0x000b5294. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_01181a10)[dVar2 == 1.0] + (int)-(DAT_01181a20 ^ 0x76043541)))();
  return;
}


