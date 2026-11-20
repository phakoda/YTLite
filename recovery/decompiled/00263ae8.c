/* Decompiled from supplied 5.2.2 arm package. VA 0x263ae8. _av_opt_set_video_rate */

undefined8
_av_opt_set_video_rate(undefined8 param_1,undefined8 param_2,ulong param_3,undefined4 param_4)

{
  bool bVar1;
  bool bVar2;
  long lVar3;
  undefined8 uVar4;
  int iVar5;
  long local_38;
  
  lVar3 = _av_opt_find2(param_1,param_2,0,0,param_4,&local_38);
  uVar4 = 0xabafb008;
  if ((lVar3 != 0) && (local_38 != 0)) {
    if (*(int *)(lVar3 + 0x14) == 0xe) {
      bVar1 = true;
      bVar2 = false;
      if (0 < (int)param_3) {
        iVar5 = (int)(param_3 >> 0x20);
        bVar2 = SBORROW4(iVar5,1);
        bVar1 = iVar5 + -1 < 0;
      }
      if (bVar1 == bVar2) {
        uVar4 = FUN_0026388c((double)(int)param_3,param_1,param_2,param_3 >> 0x20,1,param_4);
        return uVar4;
      }
    }
    else {
      _av_log(param_1,0x10,"The value set by option \'%s\' is not a video rate.\n");
    }
    uVar4 = 0xffffffea;
  }
  return uVar4;
}


