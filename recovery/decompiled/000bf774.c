/* Decompiled from supplied 5.2.2 arm package. VA 0xbf774. FUN_000bf774 */

undefined8 FUN_000bf774(undefined8 param_1)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  
  DAT_01226f6c = 1;
  _objc_retain(param_1);
  iVar2 = FUN_000ec7f8(&PTR____CFConstantStringClassReference_01171f80);
  puVar1 = PTR_s_yt_showEngagementPanelEndpoint_0114bb60;
  uVar7 = 0;
  if (iVar2 != 0) {
    uVar3 = FUN_000ec7d4(param_1,PTR_s_respondsToSelector__0114af58,
                         PTR_s_yt_showEngagementPanelEndpoint_0114bb60);
    uVar7 = 0;
    if (uVar3 != 0) {
      _objc_msgSend((&PTR_LAB_01182910)[uVar3] + (int)-(uRam0000000001182920 ^ 0x71a303ad),param_1,
                    puVar1);
      uVar4 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar4,PTR_s_identifier_0114c500);
      uVar5 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar5,PTR_s_tag_0114b868);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      uVar7 = FUN_000ec7ac(uVar6,PTR_s_isEqualToString__0114ae48,
                           &PTR____CFConstantStringClassReference_01171f40);
      _objc_release(uVar6);
      _objc_release(uVar5);
      _objc_release(uVar4);
    }
  }
  _objc_release(param_1);
  return uVar7;
}


