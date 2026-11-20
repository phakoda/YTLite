/* Decompiled from supplied 5.2.2 arm package. VA 0x263678. FUN_00263678 */

int FUN_00263678(long param_1,undefined8 *param_2)

{
  int iVar1;
  undefined8 local_28;
  
  local_28 = 0;
  if (param_1 != 0) {
    iVar1 = _av_dict_parse_string(&local_28,param_1,"=",":",0);
    if (iVar1 < 0) {
      _av_dict_free(&local_28);
      return iVar1;
    }
  }
  _av_dict_free(param_2);
  *param_2 = local_28;
  return 0;
}


