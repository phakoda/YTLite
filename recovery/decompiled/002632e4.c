/* Decompiled from supplied 5.2.2 arm package. VA 0x2632e4. FUN_002632e4 */

int FUN_002632e4(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = _av_parse_video_rate(param_3);
  if (iVar1 < 0) {
    _av_log(param_1,0x10,"Unable to parse option value \"%s\" as video rate\n");
  }
  return iVar1;
}


