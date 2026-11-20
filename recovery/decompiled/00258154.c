/* Decompiled from supplied 5.2.2 arm package. VA 0x258154. _av_strerror */

int _av_strerror(int param_1,char *param_2,size_t param_3)

{
  int *piVar1;
  int iVar2;
  ulong uVar3;
  int *piVar4;
  int iVar5;
  
  uVar3 = 0xffffffffffffffff;
  piVar1 = &DAT_01064000;
  do {
    piVar4 = piVar1;
    uVar3 = uVar3 + 1;
    if (0x1b < uVar3) goto LAB_002581c0;
    piVar1 = piVar4 + 6;
  } while (*piVar4 != param_1);
  if ((dword *)(piVar4 + 6) == &MACH_HEADER.flags) {
LAB_002581c0:
    iVar2 = _strerror_r(-param_1,param_2,param_3);
    iVar5 = -iVar2;
    if (0 < iVar2) {
      ___snprintf_chk(param_2,param_3,0,0xffffffffffffffff,"Error number %d occurred");
    }
  }
  else {
    _av_strlcpy(param_2,*(undefined8 *)(piVar4 + 4),param_3);
    iVar5 = 0;
  }
  return iVar5;
}


