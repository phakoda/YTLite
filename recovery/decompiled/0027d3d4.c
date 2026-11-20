/* Decompiled from supplied 5.2.2 arm package. VA 0x27d3d4. FUN_0027d3d4 */

undefined8 FUN_0027d3d4(undefined8 param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = _ff_make_format_list(&DAT_00c537e0);
  if (lVar1 != 0) {
    uVar2 = _ff_set_common_formats(param_1,lVar1);
    if ((int)uVar2 < 0) {
      return uVar2;
    }
    lVar1 = _ff_all_channel_counts();
    if (lVar1 != 0) {
      uVar2 = _ff_set_common_channel_layouts(param_1,lVar1);
      if ((int)uVar2 < 0) {
        return uVar2;
      }
      uVar2 = _ff_all_samplerates();
      uVar2 = _ff_set_common_samplerates(param_1,uVar2);
      return uVar2;
    }
  }
  return 0xfffffff4;
}


