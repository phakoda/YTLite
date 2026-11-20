/* Decompiled from supplied 5.2.2 arm package. VA 0x266aa0. FUN_00266aa0 */

void FUN_00266aa0(double param_1,undefined8 param_2)

{
  char *pcVar1;
  
  if (param_1 == DAT_00c4d5f8) {
    pcVar1 = "INT_MAX";
  }
  else if (param_1 == DAT_00c511f8) {
    pcVar1 = "INT_MIN";
  }
  else if (param_1 == DAT_00c51200) {
    pcVar1 = "UINT32_MAX";
  }
  else if (param_1 == DAT_00c511d8) {
    pcVar1 = "I64_MAX";
  }
  else if (param_1 == DAT_00c511e0) {
    pcVar1 = "I64_MIN";
  }
  else if (param_1 == DAT_00c51208) {
    pcVar1 = "FLT_MAX";
  }
  else if (param_1 == DAT_00c51210) {
    pcVar1 = "FLT_MIN";
  }
  else if (param_1 == DAT_00c51218) {
    pcVar1 = "-FLT_MAX";
  }
  else if (param_1 == DAT_00c51220) {
    pcVar1 = "-FLT_MIN";
  }
  else if (param_1 == DAT_00c502c8) {
    pcVar1 = "DBL_MAX";
  }
  else if (param_1 == DAT_00c502c0) {
    pcVar1 = "DBL_MIN";
  }
  else if (param_1 == DAT_00c508d8) {
    pcVar1 = "-DBL_MAX";
  }
  else if (param_1 == DAT_00c51228) {
    pcVar1 = "-DBL_MIN";
  }
  else {
    pcVar1 = "%g";
  }
  _av_log(param_2,0x20,pcVar1);
  return;
}


