/* Decompiled from supplied 5.2.2 arm package. VA 0x265b38. _av_opt_set_dict2 */

int _av_opt_set_dict2(undefined8 param_1,undefined8 *param_2,undefined4 param_3)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 local_58;
  
  local_58 = 0;
  if (param_2 == (undefined8 *)0x0) {
    iVar1 = 0;
  }
  else {
    puVar2 = (undefined8 *)0x0;
    do {
      puVar2 = (undefined8 *)_av_dict_get(*param_2,"",puVar2,2);
      if (puVar2 == (undefined8 *)0x0) {
        _av_dict_free(param_2);
        *param_2 = local_58;
        return 0;
      }
      iVar1 = _av_opt_set(param_1,*puVar2,puVar2[1],param_3);
      if (iVar1 == -0x54504ff8) {
        iVar1 = _av_dict_set(&local_58,*puVar2,puVar2[1],0);
      }
    } while (-1 < iVar1);
    _av_log(param_1,0x10,"Error setting option %s to value %s.\n");
    _av_dict_free(&local_58);
  }
  return iVar1;
}


