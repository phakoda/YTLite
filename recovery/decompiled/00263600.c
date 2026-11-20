/* Decompiled from supplied 5.2.2 arm package. VA 0x263600. FUN_00263600 */

int FUN_00263600(undefined8 param_1,long param_2,undefined8 param_3)

{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = _av_parse_color(param_3,param_2,0xffffffff,param_1);
    if (iVar1 < 0) {
      _av_log(param_1,0x10,"Unable to parse option value \"%s\" as color\n");
    }
  }
  return iVar1;
}


