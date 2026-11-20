/* Decompiled from supplied 5.2.2 arm package. VA 0x2655d8. _av_set_options_string */

int _av_set_options_string(undefined8 param_1,char *param_2,char *param_3,undefined8 param_4)

{
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  size_t sVar4;
  void *pvVar5;
  int iVar6;
  char *local_70;
  char *local_68;
  
  if (param_2 == (char *)0x0) {
    iVar6 = 0;
  }
  else {
    iVar6 = 0;
    local_70 = param_2;
    while (*local_70 != '\0') {
      pcVar3 = (char *)_av_get_token(&local_70,param_3);
      pcVar1 = local_70;
      if (pcVar3 == (char *)0x0) {
        return -0xc;
      }
      local_68 = pcVar3;
      if ((*pcVar3 == '\0') || (sVar4 = _strspn(local_70,param_3), sVar4 == 0)) {
        _av_log(param_1,0x10,"Missing key or no key/value separator found after key \'%s\'\n");
        _av_free(pcVar3);
        return -0x16;
      }
      local_70 = pcVar1 + 1;
      pvVar5 = (void *)_av_get_token(&local_70,param_4);
      if (pvVar5 == (void *)0x0) {
        _av_freep(&local_68);
        return -0xc;
      }
      _av_log(param_1,0x30,"Setting entry with key \'%s\' to value \'%s\'\n");
      iVar2 = _av_opt_set(param_1,pcVar3,pvVar5,1);
      if (iVar2 == -0x54504ff8) {
        _av_log(param_1,0x10,"Key \'%s\' not found.\n");
      }
      _av_free(pcVar3);
      _av_free(pvVar5);
      if (iVar2 < 0) {
        return iVar2;
      }
      iVar6 = iVar6 + 1;
      if (*local_70 != '\0') {
        local_70 = local_70 + 1;
      }
    }
  }
  return iVar6;
}


