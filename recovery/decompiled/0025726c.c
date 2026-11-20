/* Decompiled from supplied 5.2.2 arm package. VA 0x25726c. _av_dict_parse_string */

int _av_dict_parse_string
              (undefined8 param_1,char *param_2,char *param_3,undefined8 param_4,uint param_5)

{
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  size_t sVar4;
  char *local_58;
  char *local_50;
  char *pcStack_48;
  
  if (param_2 != (char *)0x0) {
    local_58 = param_2;
    while (*local_58 != '\0') {
      pcVar3 = (char *)_av_get_token(&local_58,param_3);
      pcVar1 = local_58;
      local_50 = (char *)0x0;
      pcStack_48 = pcVar3;
      if (((pcVar3 == (char *)0x0) || (*pcVar3 == '\0')) ||
         (sVar4 = _strspn(local_58,param_3), sVar4 == 0)) {
LAB_00257334:
        iVar2 = -0x16;
      }
      else {
        local_58 = pcVar1 + 1;
        local_50 = (char *)_av_get_token(&local_58,param_4);
        iVar2 = -0x16;
        if ((local_50 != (char *)0x0) && (*pcVar3 != '\0')) {
          if (*local_50 == '\0') goto LAB_00257334;
          iVar2 = _av_dict_set(param_1,pcVar3,local_50,param_5 & 0xfffffff3);
        }
      }
      _av_freep(&pcStack_48);
      _av_freep(&local_50);
      if (iVar2 < 0) {
        return iVar2;
      }
      if (*local_58 != '\0') {
        local_58 = local_58 + 1;
      }
    }
  }
  return 0;
}


