// Decompiled hook evidence for YTELMResourceLoader. This is not compilable Logos source.

// -[YTELMResourceLoader imageWithName:color:bundleId:], original IMP slot 0x12258e8
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
  puVar1 = @selector(isEqualToString:);
  uVar2 = FUN_000115e0(param_3,@selector(isEqualToString:),
                       @"ic_shorts_like_outline_32dp");
  if (uVar2 != 0) {
    _objc_release((&PTR_LAB_01152a28)[uVar2] + (int)-(DAT_01152a38 ^ 0x17400027),param_3);
    param_3 = @"ic_shorts_thumb_up_filled_style_c";
  }
  uVar2 = FUN_000115b8(param_3,puVar1,@"ic_shorts_like_fill_32dp");
  if (uVar2 != 0) {
    _objc_release((&PTR_LAB_01152a48)[uVar2] + (int)-(uRam0000000001152a58 ^ 0xc2e0324b),param_3);
    param_3 = @"ic_shorts_thumb_up_colored_style_c";
  }
  uVar2 = FUN_00011540(param_3,puVar1,@"ic_shorts_dislike_outline_32dp");
  if (uVar2 != 0) {
    _objc_release((&PTR_LAB_01152a68)[uVar2] + (int)-(uRam0000000001152a78 ^ 0xd2bb8244),param_3);
    param_3 = @"ic_shorts_thumb_down_filled_style_c";
  }
  uVar2 = FUN_00011590(param_3,puVar1,@"ic_shorts_dislike_fill_32dp");
  if (uVar2 != 0) {
    _objc_release((&PTR_LAB_01152a88)[uVar2] + (int)-(uRam0000000001152a98 ^ 0x24c6e7dc),param_3);
    param_3 = @"ic_shorts_thumb_down_colored_style_c";
  }
  uVar2 = FUN_00011630(param_3,puVar1,@"ic_shorts_comment_outline_32dp");
  if (uVar2 != 0) {
    _objc_release((&PTR_LAB_01152aa8)[uVar2] + (int)-(uRam0000000001152ab8 ^ 0x20c52860),param_3);
    param_3 = @"ic_shorts_comment_filled_style_c";
  }
  uVar2 = FUN_00011518(param_3,puVar1,@"ic_shorts_share_outline_32dp");
  if (uVar2 != 0) {
    _objc_release((&PTR_LAB_01152ac8)[uVar2] + (int)-(uRam0000000001152ad8 ^ 0xd9779764),param_3);
    param_3 = @"ic_shorts_share_filled_style_c";
  }
  uVar2 = FUN_00011568(param_3,puVar1,@"ic_shorts_remix_outline_32dp");
  if (uVar2 != 0) {
    _objc_release((&PTR_LAB_01152ae8)[uVar2] + (int)-(uRam0000000001152af8 ^ 0xbce26e40),param_3);
    param_3 = @"ic_remix_filled";
  }
  uVar2 = FUN_00011608(param_3,puVar1,@"youtube_shorts_24_cairo");
  if (uVar2 != 0) {
    _objc_release((&PTR_LAB_01152b08)[uVar2] + (int)-(uRam0000000001152b18 ^ 0x4fd8cec),param_3);
    param_3 = @"youtube_shorts_24";
  }
  (*pcRam00000000012258e8)(param_1,param_2,param_3,param_4,param_5);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release(param_5);
  _objc_release(param_4);
  _objc_release(param_3);
  _objc_autoreleaseReturnValue(uVar3);
  return;
}


