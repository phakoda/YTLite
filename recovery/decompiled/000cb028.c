/* Decompiled from supplied 5.2.2 arm package. VA 0xcb028. FUN_000cb028 */

uint FUN_000cb028(long param_1,undefined8 param_2)

{
  uint uVar1;
  undefined8 uVar2;
  long lVar3;
  undefined8 uVar4;
  
  uVar4 = *(undefined8 *)(param_1 + 0x20);
  _objc_msgSend(param_2,PTR_s_accessibilityIdentifier_0114aec0);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,PTR_s_objectForKeyedSubscript__0114ae80,uVar2);
  lVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar2);
  if (lVar3 == 0) {
    uVar1 = 1;
  }
  else {
    uVar1 = FUN_000ef974((&PTR_FUN_011837d8)[lVar3 == 0] + (int)-(DAT_011837e8 ^ 0x98f9562),lVar3);
    uVar1 = uVar1 ^ 1;
  }
  _objc_release(lVar3);
  return uVar1;
}


