/* Decompiled from supplied 5.2.2 arm package. VA 0x25ee0c. _av_image_check_size2 */

undefined8
_av_image_check_size2
          (uint param_1,uint param_2,long param_3,undefined4 param_4,undefined4 param_5,
          undefined8 param_6)

{
  long lVar1;
  int iVar2;
  char *pcVar3;
  ulong uVar4;
  undefined **local_48;
  undefined4 local_40;
  undefined8 local_38;
  
  uVar4 = (ulong)param_1;
  local_48 = &PTR_s_IMGUTILS_010647c0;
  local_40 = param_5;
  local_38 = param_6;
  iVar2 = _av_image_get_linesize(param_4,uVar4,0);
  lVar1 = uVar4 << 3;
  if (0 < iVar2) {
    lVar1 = (long)iVar2;
  }
  if ((((int)param_1 < 1 || (int)param_2 < 1) || 0x7ffffffe < lVar1 + 0x400) ||
      0x7ffffffe < (lVar1 + 0x400) * (ulong)(param_2 + 0x80)) {
    pcVar3 = "Picture size %ux%u is invalid\n";
  }
  else {
    if ((param_3 == 0x7fffffffffffffff) ||
       (param_2 * uVar4 - param_3 == 0 || (long)(param_2 * uVar4) < param_3)) {
      return 0;
    }
    pcVar3 = 
    "Picture size %ux%u exceeds specified max pixel count %lld, see the documentation if you wish to increase it\n"
    ;
  }
  _av_log(&local_48,0x10,pcVar3);
  return 0xffffffea;
}


