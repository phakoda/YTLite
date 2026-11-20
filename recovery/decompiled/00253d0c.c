/* Decompiled from supplied 5.2.2 arm package. VA 0x253d0c. _av_strncasecmp */

int _av_strncasecmp(char *param_1,char *param_2,long param_3)

{
  char cVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_3 == 0) {
    return 0;
  }
  param_3 = -param_3;
  do {
    param_3 = param_3 + 1;
    cVar1 = *param_1;
    cVar2 = *param_2;
    uVar3 = (int)cVar1 ^ 0x20;
    uVar4 = (int)cVar2 ^ 0x20;
    if (0x19 < (int)cVar1 - 0x41U) {
      uVar3 = (uint)cVar1;
    }
    if (0x19 < (int)cVar2 - 0x41U) {
      uVar4 = (uint)cVar2;
    }
    uVar3 = uVar3 & 0xff;
    if ((param_3 == 0) || (uVar3 == 0)) break;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
  } while (uVar3 == (uVar4 & 0xff));
  return uVar3 - (uVar4 & 0xff);
}


