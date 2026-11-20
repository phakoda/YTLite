/* Decompiled from supplied 5.2.2 arm package. VA 0x27e7d0. FUN_0027e7d0 */

undefined8 FUN_0027e7d0(undefined8 param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = _ff_all_channel_counts();
  if (lVar1 != 0) {
    uVar2 = _ff_set_common_channel_layouts(param_1,lVar1);
    if ((int)uVar2 < 0) {
      return uVar2;
    }
    lVar1 = _ff_make_format_list(&DAT_00c537ec);
    if (lVar1 != 0) {
      uVar2 = _ff_set_common_formats(param_1,lVar1);
      if ((int)uVar2 < 0) {
        return uVar2;
      }
      lVar1 = _ff_all_samplerates();
      if (lVar1 != 0) {
        uVar2 = _ff_set_common_samplerates(param_1,lVar1);
        return uVar2;
      }
    }
  }
  return 0xfffffff4;
}


