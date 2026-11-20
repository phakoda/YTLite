/* Decompiled from supplied 5.2.2 arm package. VA 0x266d10. _av_parse_video_size */

undefined4 _av_parse_video_size(int *param_1,int *param_2,char *param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  long lVar4;
  char *local_48;
  
  lVar4 = 0;
  piVar3 = &DAT_01064824;
  do {
    if (0x34 < lVar4) {
      if ((int)lVar4 == 0x35) {
        lVar4 = _strtol(param_3,&local_48,10);
        iVar2 = (int)lVar4;
        if (*local_48 != '\0') {
          local_48 = local_48 + 1;
        }
        lVar4 = _strtol(local_48,&local_48,10);
        iVar1 = (int)lVar4;
        if (*local_48 == '\0') {
LAB_00266dc0:
          if (0 < iVar2 && 0 < iVar1) {
            *param_1 = iVar2;
            *param_2 = iVar1;
            return 0;
          }
        }
      }
      return 0xffffffea;
    }
    iVar1 = _strcmp(*(char **)(piVar3 + -3),param_3);
    if (iVar1 == 0) {
      iVar2 = piVar3[-1];
      iVar1 = *piVar3;
      goto LAB_00266dc0;
    }
    lVar4 = lVar4 + 1;
    piVar3 = piVar3 + 4;
  } while( true );
}


