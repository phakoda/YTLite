/* Decompiled from supplied 5.2.2 arm package. VA 0x27b1c8. FUN_0027b1c8 */

int FUN_0027b1c8(long param_1)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  char *pcVar4;
  long lVar5;
  
  lVar5 = *(long *)(param_1 + 0x48);
  pcVar4 = *(char **)(lVar5 + 0x20);
  if (pcVar4 == (char *)0x0) {
    iVar1 = FUN_0027b738(param_1,0xffffffff);
    if (iVar1 < 0) {
      return iVar1;
    }
    lVar3 = _av_get_default_channel_layout(*(undefined4 *)(lVar5 + 0x28));
    *(long *)(lVar5 + 0x18) = lVar3;
    if ((lVar3 == 0) && (*(int *)(lVar5 + 0x28) < 1)) {
      _av_log(param_1,0x10,"Invalid number of channels \'%d\' provided\n");
      return -0x16;
    }
  }
  else {
    iVar1 = _strcmp(pcVar4,"same");
    if ((iVar1 == 0) &&
       (iVar1 = _strcmp((char *)**(undefined8 **)(param_1 + 8),"aeval"), iVar1 == 0)) {
      iVar1 = 0;
      *(undefined4 *)(lVar5 + 0x30) = 1;
    }
    else {
      iVar1 = _ff_parse_channel_layout((undefined8 *)(lVar5 + 0x18),0,pcVar4,param_1);
      if (iVar1 < 0) {
        return iVar1;
      }
      uVar2 = _av_get_channel_layout_nb_channels(*(undefined8 *)(lVar5 + 0x18));
      iVar1 = FUN_0027b738(param_1,uVar2);
      if (iVar1 < 0) {
        return iVar1;
      }
    }
  }
  if (*(long *)(lVar5 + 8) != 0) {
    iVar1 = _ff_parse_sample_rate(lVar5 + 0x10,*(long *)(lVar5 + 8),param_1);
    if (iVar1 != 0) {
      return iVar1;
    }
    iVar1 = 0;
  }
  *(undefined8 *)(lVar5 + 0x60) = 0;
  return iVar1;
}


