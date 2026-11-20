/* Decompiled from supplied 5.2.2 arm package. VA 0x255968. _av_get_extended_channel_layout */

undefined8 _av_get_extended_channel_layout(char *param_1,long *param_2,int *param_3)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  int *piVar4;
  char *local_38;
  
  lVar2 = _av_get_channel_layout();
  if (lVar2 == 0) {
    lVar2 = _strtol(param_1,&local_38,10);
    piVar4 = ___error();
    if ((*piVar4 == 0) && (*local_38 == 'C')) {
      uVar3 = 0xffffffea;
      if (((int)lVar2 - 1U < 0x3f) && (local_38[1] == '\0')) {
        uVar3 = 0;
        *param_2 = 0;
        *param_3 = (int)lVar2;
      }
    }
    else {
      uVar3 = 0xffffffea;
    }
  }
  else {
    *param_2 = lVar2;
    iVar1 = _av_get_channel_layout_nb_channels();
    uVar3 = 0;
    *param_3 = iVar1;
  }
  return uVar3;
}


