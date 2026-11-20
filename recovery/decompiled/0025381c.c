/* Decompiled from supplied 5.2.2 arm package. VA 0x25381c. _av_strnstr */

void * _av_strnstr(void *param_1,char *param_2,ulong param_3)

{
  int iVar1;
  size_t sVar2;
  
  sVar2 = _strlen(param_2);
  if (sVar2 != 0) {
    for (; sVar2 <= param_3; param_3 = param_3 - 1) {
      iVar1 = _memcmp(param_1,param_2,sVar2);
      if (iVar1 == 0) {
        return param_1;
      }
      param_1 = (void *)((long)param_1 + 1);
    }
    param_1 = (void *)0x0;
  }
  return param_1;
}


