/* Decompiled from supplied 5.2.2 arm package. VA 0x268e0c. _av_color_primaries_from_name */

ulong _av_color_primaries_from_name(char *param_1)

{
  int iVar1;
  size_t sVar2;
  ulong uVar3;
  char *pcVar4;
  
  for (uVar3 = 0; uVar3 < 0x17; uVar3 = uVar3 + 1) {
    if (8 < uVar3 - 0xd) {
      pcVar4 = (&PTR_s_reserved_0106d118)[uVar3];
      sVar2 = _strlen(pcVar4);
      iVar1 = _strncmp(pcVar4,param_1,sVar2);
      if (iVar1 == 0) goto LAB_00268e74;
    }
  }
  uVar3 = 0xffffffea;
LAB_00268e74:
  return uVar3 & 0xffffffff;
}


