/* Decompiled from supplied 5.2.2 arm package. VA 0x26aef8. _av_get_sample_fmt */

int _av_get_sample_fmt(char *param_1)

{
  int iVar1;
  char *pcVar2;
  long lVar3;
  
  lVar3 = 0;
  pcVar2 = "u8";
  do {
    if (0xb < lVar3) {
      return -1;
    }
    iVar1 = _strcmp(pcVar2,param_1);
    lVar3 = lVar3 + 1;
    pcVar2 = pcVar2 + 0x14;
  } while (iVar1 != 0);
  return (int)lVar3 + -1;
}


