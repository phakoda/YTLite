/* Decompiled from supplied 5.2.2 arm package. VA 0x25388c. _av_strlcpy */

long _av_strlcpy(long param_1,long param_2,ulong param_3)

{
  ulong uVar1;
  size_t sVar2;
  ulong uVar3;
  
  uVar3 = 0;
  while ((uVar1 = uVar3 + 1, uVar1 < param_3 && (*(char *)(param_2 + uVar3) != '\0'))) {
    *(char *)(param_1 + uVar3) = *(char *)(param_2 + uVar3);
    uVar3 = uVar1;
  }
  if (uVar1 <= param_3) {
    *(undefined1 *)(param_1 + uVar3) = 0;
  }
  sVar2 = _strlen((char *)(param_2 + uVar3));
  return sVar2 + uVar3;
}


