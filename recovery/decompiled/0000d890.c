/* Decompiled from supplied 5.2.2 arm package. VA 0xd890. recovered_hook_0000d890 */

void recovered_hook_0000d890
               (undefined8 param_1,undefined8 param_2,undefined **param_3,undefined8 param_4,
               undefined8 param_5)

{
  undefined *puVar1;
  uint uVar2;
  undefined8 uVar3;
  
  uRam0000000001225934 = 1;
  _objc_retain(param_3);
  _objc_retain(param_4);
  _objc_retain(param_5);
  puVar1 = PTR_s_isEqualToString__0114ae48;
  uVar2 = FUN_000115e0(param_3,PTR_s_isEqualToString__0114ae48,
                       &PTR____CFConstantStringClassReference_011521a0);
  if (uVar2 != 0) {
    _objc_release((&PTR_LAB_01152a28)[uVar2] + (int)-(DAT_01152a38 ^ 0x17400027),param_3);
    param_3 = &PTR____CFConstantStringClassReference_01152020;
  }
  uVar2 = FUN_000115b8(param_3,puVar1,&PTR____CFConstantStringClassReference_011520a0);
  if (uVar2 != 0) {
    _objc_release((&PTR_LAB_01152a48)[uVar2] + (int)-(uRam0000000001152a58 ^ 0xc2e0324b),param_3);
    param_3 = &PTR____CFConstantStringClassReference_01152160;
  }
  uVar2 = FUN_00011540(param_3,puVar1,&PTR____CFConstantStringClassReference_01152120);
  if (uVar2 != 0) {
    _objc_release((&PTR_LAB_01152a68)[uVar2] + (int)-(uRam0000000001152a78 ^ 0xd2bb8244),param_3);
    param_3 = &PTR____CFConstantStringClassReference_01151fe0;
  }
  uVar2 = FUN_00011590(param_3,puVar1,&PTR____CFConstantStringClassReference_01152060);
  if (uVar2 != 0) {
    _objc_release((&PTR_LAB_01152a88)[uVar2] + (int)-(uRam0000000001152a98 ^ 0x24c6e7dc),param_3);
    param_3 = &PTR____CFConstantStringClassReference_01151fa0;
  }
  uVar2 = FUN_00011630(param_3,puVar1,&PTR____CFConstantStringClassReference_01151f20);
  if (uVar2 != 0) {
    _objc_release((&PTR_LAB_01152aa8)[uVar2] + (int)-(uRam0000000001152ab8 ^ 0x20c52860),param_3);
    param_3 = &PTR____CFConstantStringClassReference_01151f60;
  }
  uVar2 = FUN_00011518(param_3,puVar1,&PTR____CFConstantStringClassReference_01151ea0);
  if (uVar2 != 0) {
    _objc_release((&PTR_LAB_01152ac8)[uVar2] + (int)-(uRam0000000001152ad8 ^ 0xd9779764),param_3);
    param_3 = &PTR____CFConstantStringClassReference_01151e60;
  }
  uVar2 = FUN_00011568(param_3,puVar1,&PTR____CFConstantStringClassReference_01151e20);
  if (uVar2 != 0) {
    _objc_release((&PTR_LAB_01152ae8)[uVar2] + (int)-(uRam0000000001152af8 ^ 0xbce26e40),param_3);
    param_3 = &PTR____CFConstantStringClassReference_011520e0;
  }
  uVar2 = FUN_00011608(param_3,puVar1,&PTR____CFConstantStringClassReference_01151de0);
  if (uVar2 != 0) {
    _objc_release((&PTR_LAB_01152b08)[uVar2] + (int)-(uRam0000000001152b18 ^ 0x4fd8cec),param_3);
    param_3 = &PTR____CFConstantStringClassReference_01151ee0;
  }
  (*pcRam00000000012258e8)(param_1,param_2,param_3,param_4,param_5);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release(param_5);
  _objc_release(param_4);
  _objc_release(param_3);
  _objc_autoreleaseReturnValue(uVar3);
  return;
}


