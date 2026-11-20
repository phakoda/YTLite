/* Decompiled from supplied 5.2.2 arm package. VA 0xc9c70. FUN_000c9c70 */

void FUN_000c9c70(long param_1)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  long lVar4;
  
  puVar1 = PTR_s_backgroundColor_0114c520;
  _objc_msgSend(*(undefined8 *)(param_1 + 0x28),PTR_s_backgroundColor_0114c520);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_ytlIcon_0114be80);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_setBackgroundColor__0114b550,uVar2);
  _objc_release(uVar3);
  _objc_release(uVar2);
  _objc_msgSend(*(undefined8 *)(param_1 + 0x28),puVar1);
  lVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release();
                    /* WARNING: Could not recover jumptable at 0x000c9d4c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_01183578)[lVar4 == 0] + (int)-(DAT_01183588 ^ 0x8438d23e)))();
  return;
}


