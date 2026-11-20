/* Decompiled from supplied 5.2.2 arm package. VA 0x25aa00. _avpriv_tempfile */

int _avpriv_tempfile(char *param_1,long *param_2,undefined4 param_3,undefined8 param_4)

{
  int iVar1;
  size_t sVar2;
  long lVar3;
  int *piVar4;
  undefined **local_48;
  undefined4 local_40;
  undefined8 local_38;
  
  local_48 = &PTR_s_TEMPFILE_01064390;
  local_40 = param_3;
  local_38 = param_4;
  sVar2 = _strlen(param_1);
  lVar3 = _av_malloc(sVar2 + 0xc);
  *param_2 = lVar3;
  if (lVar3 == 0) {
    _av_log(&local_48,0x10,"ff_tempfile: Cannot allocate file name\n");
    iVar1 = -0xc;
  }
  else {
    ___snprintf_chk(lVar3,sVar2 + 0xc,0,0xffffffffffffffff,"/tmp/%sXXXXXX");
    iVar1 = _mkstemp((char *)*param_2);
    if (iVar1 < 0) {
      piVar4 = ___error();
      iVar1 = -*piVar4;
      _av_log(&local_48,0x10,"ff_tempfile: Cannot open temporary file %s\n");
      _av_freep(param_2);
    }
  }
  return iVar1;
}


