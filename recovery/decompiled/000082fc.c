/* Decompiled from supplied 5.2.2 arm package. VA 0x82fc. FUN_000082fc */

char * FUN_000082fc(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
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
    pcVar2 = (char *)(*DAT_01225828)();
    if ((*param_1 == '/') &&
       ((iVar1 = _access("/var/LIY",0), iVar1 != 0 ||
        (iVar1 = _strncmp(param_1,"/var/mobile",0xb), iVar1 != 0)))) {
      _strlcpy(param_2,pcVar2,0x400);
      _strlcat(param_2,param_1,0x400);
    }
    else {
      _strlcpy(param_2,param_1,0x400);
    }
  }
  return param_2;
}


