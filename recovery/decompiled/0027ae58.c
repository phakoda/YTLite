/* Decompiled from supplied 5.2.2 arm package. VA 0x27ae58. _av_fourcc_make_string */

long _av_fourcc_make_string(long param_1,uint param_2)

{
  uint uVar1;
  char *pcVar2;
  bool bVar3;
  int iVar4;
  void *pvVar5;
  ulong uVar6;
  long lVar7;
  int iVar8;
  
  iVar8 = -1;
  uVar6 = 0x20;
  lVar7 = param_1;
  while( true ) {
    iVar8 = iVar8 + 1;
    if (3 < iVar8) {
      return param_1;
    }
    uVar1 = param_2 & 0xff;
    if ((param_2 & 0xdf) - 0x41 < 0x1a || uVar1 - 0x30 < 10) {
      bVar3 = true;
    }
    else if (uVar1 == 0) {
      bVar3 = false;
    }
    else {
      pvVar5 = _memchr(". -_",uVar1,5);
      bVar3 = pvVar5 != (void *)0x0;
    }
    pcVar2 = "%c";
    if (!bVar3) {
      pcVar2 = "[%d]";
    }
    iVar4 = ___snprintf_chk(lVar7,uVar6,0,0xffffffffffffffff,pcVar2);
    if (iVar4 < 0) break;
    lVar7 = lVar7 + iVar4;
    bVar3 = uVar6 < (ulong)(long)iVar4;
    uVar6 = uVar6 - (long)iVar4;
    if (bVar3 || uVar6 == 0) {
      uVar6 = 0;
    }
    param_2 = param_2 >> 8;
  }
  return param_1;
}


