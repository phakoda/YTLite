/* Decompiled from supplied 5.2.2 arm package. VA 0x4a3a8. _isShorts */

uint _isShorts(undefined8 param_1,undefined8 param_2)

{
  undefined *puVar1;
  long lVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined *puVar7;
  
  DAT_01226944 = 1;
  _objc_retain(param_1);
  _objc_retain(param_2);
  iVar3 = FUN_000cfa9c(&PTR____CFConstantStringClassReference_0115dbd0);
  puVar1 = PTR_s_containsString__0114af08;
  uVar4 = 0;
  if (iVar3 != 0) {
    uVar4 = FUN_000cfaec(param_1,PTR_s_containsString__0114af08,
                         &PTR____CFConstantStringClassReference_0115db90);
    puVar7 = (&PTR_LAB_01179f90)[uVar4] + (int)-(uRam0000000001179fa0 ^ 0x3ea85845);
    if (uVar4 == 0) {
      uVar4 = FUN_000cfa0c(puVar7,param_1,puVar1,&PTR____CFConstantStringClassReference_0115da90);
      puVar7 = (&PTR_LAB_01179fa8)[uVar4] + (int)-(uRam0000000001179fb8 ^ 0x419b9e05);
      if (uVar4 == 0) {
        uVar4 = FUN_000cfa78(puVar7,param_1,puVar1,&PTR____CFConstantStringClassReference_0115db10);
        puVar7 = (&PTR_LAB_01179fc0)[uVar4] + (int)-(uRam0000000001179fd0 ^ 0xff4eda9b);
        if (uVar4 == 0) {
          uVar5 = FUN_000cfb5c(puVar7,param_1,puVar1,&PTR____CFConstantStringClassReference_0115da10
                              );
          uVar4 = 0;
          puVar7 = (&PTR_LAB_01179fd8)[uVar5] + (int)-(uRam0000000001179fe8 ^ 0x5ebb5856);
          if (uVar5 == 0) goto LAB_0004b044;
        }
      }
    }
    iVar3 = FUN_000cfac4(puVar7,param_1,puVar1,&PTR____CFConstantStringClassReference_0115db50);
    uVar4 = 0;
    if (iVar3 == 0) {
      if (lRam0000000001226830 == 0) {
        lRam0000000001226830 =
             _objc_getClass((&PTR_LAB_0117a008)[lRam0000000001226830 == 0] +
                            (int)-(uRam000000000117a018 ^ 0xa44680e8),
                            s_YTSectionListViewController_0115d8d0);
      }
      lVar2 = lRam0000000001226830;
      _objc_retainAutorelease(lRam0000000001226830);
      iVar3 = FUN_000cfb84(param_2,PTR_s_isKindOfClass__0114ad70,lVar2);
      uVar4 = 1;
      if (iVar3 != 0) {
        _objc_msgSend(param_2,PTR_s_valueForKey__0114ae90,
                      &PTR____CFConstantStringClassReference_0115dad0);
        uVar6 = _objc_retainAutoreleasedReturnValue();
        uVar5 = FUN_000cfb34(uVar6,PTR_s_isEqualToString__0114ae48,
                             &PTR____CFConstantStringClassReference_0115d9d0);
        if (uVar5 != 0) {
          uVar4 = FUN_000cfa50((&PTR_LAB_0117a040)[uVar5] + (int)-(DAT_0117a050 ^ 0xbb10fa8d),
                               &PTR____CFConstantStringClassReference_0115da50);
          uVar4 = uVar4 ^ 1;
        }
        _objc_release(uVar6);
      }
    }
  }
LAB_0004b044:
  _objc_release(param_2);
  _objc_release(param_1);
  return uVar4;
}


