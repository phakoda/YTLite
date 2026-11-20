/* Decompiled from supplied 5.2.2 arm package. VA 0x25e33c. FUN_0025e33c */

undefined8 FUN_0025e33c(undefined8 param_1,char *param_2)

{
  if ((param_2 != (char *)0x0) && (*param_2 != '\0')) {
    _av_log(param_1,0x10,"Device selection unsupported.\n");
    return 0xb1b4b1ab;
  }
  return 0;
}


