/* Decompiled from supplied 5.2.2 arm package. VA 0x253944. _av_strlcatf */

long _av_strlcatf(char *param_1,ulong param_2,undefined8 param_3)

{
  int iVar1;
  size_t sVar2;
  long lVar3;
  
  sVar2 = _strlen(param_1);
  lVar3 = param_2 - sVar2;
  if (param_2 <= sVar2) {
    lVar3 = 0;
  }
  iVar1 = ___vsnprintf_chk(param_1 + sVar2,lVar3,0,0xffffffffffffffff,param_3,&stack0x00000000);
  return sVar2 + (long)iVar1;
}


