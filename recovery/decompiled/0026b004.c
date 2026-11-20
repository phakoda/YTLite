/* Decompiled from supplied 5.2.2 arm package. VA 0x26b004. _av_get_sample_fmt_string */

/* WARNING: Removing unreachable block (ram,0x0026b0bc) */

undefined8 _av_get_sample_fmt_string(undefined8 param_1,int param_2,int param_3)

{
  char *pcVar1;
  
  if (param_3 < 0) {
    pcVar1 = "name   depth";
  }
  else {
    if (0xb < param_3) {
      return param_1;
    }
    pcVar1 = "%-6s   %2d ";
  }
  ___snprintf_chk(param_1,(long)param_2,0,0xffffffffffffffff,pcVar1);
  return param_1;
}


