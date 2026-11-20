/* Decompiled from supplied 5.2.2 arm package. VA 0x25fae4. _av_lfg_init */

void _av_lfg_init(long param_1,undefined4 param_2)

{
  undefined8 *puVar1;
  long lVar2;
  undefined8 local_40;
  undefined8 uStack_38;
  
  local_40 = 0;
  uStack_38 = 0;
  puVar1 = (undefined8 *)(param_1 + 0x20);
  for (lVar2 = 8; lVar2 < 0x40; lVar2 = lVar2 + 4) {
    local_40._0_5_ = CONCAT14((char)lVar2,param_2);
    _av_md5_sum(&local_40,&local_40,0x10);
    puVar1[1] = uStack_38;
    *puVar1 = local_40;
    puVar1 = puVar1 + 2;
  }
  *(undefined4 *)(param_1 + 0x100) = 0;
  return;
}


