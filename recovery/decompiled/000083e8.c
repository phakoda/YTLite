/* Decompiled from supplied 5.2.2 arm package. VA 0x83e8. FUN_000083e8 */

char * FUN_000083e8(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  size_t sVar4;
  
  if (param_1 == (char *)0x0) {
    param_2 = (char *)0x0;
  }
  else {
    if (param_2 == (char *)0x0) {
      param_2 = _malloc(0x400);
    }
    if (DAT_01225848 != -1) {
      _dispatch_once(&DAT_01225848,&PTR___NSConcreteGlobalBlock_010613c0);
    }
    pcVar2 = (char *)(*DAT_01225820)();
    if (DAT_01225848 != -1) {
      _dispatch_once(&DAT_01225848,&PTR___NSConcreteGlobalBlock_010613c0);
    }
    pcVar3 = (char *)(*DAT_01225828)();
    sVar4 = _strlen(pcVar3);
    if (*param_1 == '/') {
      iVar1 = _strncmp(param_1,pcVar3,sVar4);
      if (iVar1 != 0) {
        _strlcpy(param_2,pcVar2,0x400);
        _strlcat(param_2,param_1,0x400);
        return param_2;
      }
      param_1 = param_1 + sVar4;
    }
    _strlcpy(param_2,param_1,0x400);
  }
  return param_2;
}


