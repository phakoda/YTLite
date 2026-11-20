/* Decompiled from supplied 5.2.2 arm package. VA 0x268f34. _av_color_space_from_name */

int _av_color_space_from_name(char *param_1)

{
  int iVar1;
  size_t sVar2;
  char *pcVar3;
  ulong uVar4;
  
  uVar4 = 0;
  do {
    if (0xe < uVar4) {
      return -0x16;
    }
    pcVar3 = (&PTR_s_gbr_0106d268)[uVar4];
    sVar2 = _strlen(pcVar3);
    iVar1 = _strncmp(pcVar3,param_1,sVar2);
    uVar4 = uVar4 + 1;
  } while (iVar1 != 0);
  return (int)uVar4 + -1;
}


