/* Decompiled from supplied 5.2.2 arm package. VA 0x1c0f8. FUN_0001c0f8 */

void FUN_0001c0f8(long param_1)

{
  undefined *puVar1;
  int iVar2;
  
  puVar1 = PTR_s_remoteViewControllerWillDismiss__0114b260;
  DAT_01225c20 = 1;
  iVar2 = FUN_0001df48(*(undefined8 *)(param_1 + 0x20),PTR_s_respondsToSelector__0114af58,
                       PTR_s_remoteViewControllerWillDismiss__0114b260);
  if (iVar2 == 0) {
                    /* WARNING: Could not recover jumptable at 0x0001c438. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)((&PTR_LAB_011555f0)[lRam0000000001225b28 == 0] +
              (int)-(uRam0000000001155600 ^ 0x36f81e56)))();
    return;
  }
  _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_performSelector__0114b268,puVar1);
                    /* WARNING: Could not recover jumptable at 0x0001c484. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_011555f0)[lRam0000000001225b28 == 0] +
            (int)-(uRam0000000001155600 ^ 0x36f81e56)))();
  return;
}


