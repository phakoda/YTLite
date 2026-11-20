/* Decompiled from supplied 5.2.2 arm package. VA 0x25a970. _avpriv_open */

int _avpriv_open(char *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = _open(param_1,param_2 | 0x1000000);
  if ((iVar1 != -1) && (iVar2 = _fcntl(iVar1,2), iVar2 == -1)) {
    _av_log(0,0x30,"Failed to set close on exec\n");
  }
  return iVar1;
}


