/* Decompiled from supplied 5.2.2 arm package. VA 0x263258. FUN_00263258 */

int FUN_00263258(undefined8 param_1,char *param_2,undefined8 *param_3)

{
  int iVar1;
  
  if ((param_2 == (char *)0x0) || (iVar1 = _strcmp(param_2,"none"), iVar1 == 0)) {
    iVar1 = 0;
    *param_3 = 0;
  }
  else {
    iVar1 = _av_parse_video_size(param_3,(long)param_3 + 4,param_2);
    if (iVar1 < 0) {
      _av_log(param_1,0x10,"Unable to parse option value \"%s\" as image size\n");
    }
  }
  return iVar1;
}


