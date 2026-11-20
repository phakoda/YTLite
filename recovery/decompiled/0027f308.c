/* Decompiled from supplied 5.2.2 arm package. VA 0x27f308. FUN_0027f308 */

undefined8 FUN_0027f308(long param_1)

{
  undefined *puVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  
  iVar2 = _strcmp((char *)**(undefined8 **)(param_1 + 8),"aintegral");
  puVar1 = &DAT_00c53804;
  if (iVar2 == 0) {
    puVar1 = &DAT_00c53818;
  }
  lVar3 = _ff_make_format_list(puVar1);
  if (lVar3 != 0) {
    uVar4 = _ff_set_common_formats(param_1,lVar3);
    if ((int)uVar4 < 0) {
      return uVar4;
    }
    lVar3 = _ff_all_channel_counts();
    if (lVar3 != 0) {
      uVar4 = _ff_set_common_channel_layouts(param_1,lVar3);
      if ((int)uVar4 < 0) {
        return uVar4;
      }
      uVar4 = _ff_all_samplerates();
      uVar4 = _ff_set_common_samplerates(param_1,uVar4);
      return uVar4;
    }
  }
  return 0xfffffff4;
}


