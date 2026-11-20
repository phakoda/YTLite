/* Decompiled from supplied 5.2.2 arm package. VA 0x25d23c. _av_hwdevice_find_type_by_name */

ulong _av_hwdevice_find_type_by_name(char *param_1)

{
  int iVar1;
  ulong uVar2;
  
  for (uVar2 = 0; uVar2 < 0xc; uVar2 = uVar2 + 1) {
    if ((uVar2 != 0) && (iVar1 = _strcmp((char *)(&DAT_010645e8)[uVar2],param_1), iVar1 == 0))
    goto LAB_0025d288;
  }
  uVar2 = 0;
LAB_0025d288:
  return uVar2 & 0xffffffff;
}


