/* Decompiled from supplied 5.2.2 arm package. VA 0x26d7bc. _av_timecode_init_from_string */

undefined8
_av_timecode_init_from_string(int *param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  int iVar4;
  int local_44;
  int iStack_40;
  int local_3c;
  int iStack_38;
  char local_31;
  
  iVar2 = _sscanf(param_3,"%d:%d:%d%c%d");
  if (iVar2 == 5) {
    param_1[4] = 0;
    param_1[0] = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[1] = (uint)(local_31 != ':');
    *(undefined8 *)(param_1 + 2) = param_2;
    iVar2 = FUN_0026d6b0(param_2);
    param_1[4] = iVar2;
    uVar3 = FUN_0026d71c(param_4,param_1);
    if (-1 < (int)uVar3) {
      iVar2 = local_44 + (iStack_38 * 0xe10 + local_3c * 0x3c + iStack_40) * param_1[4];
      *param_1 = iVar2;
      uVar3 = 0;
      if ((*(byte *)(param_1 + 1) & 1) != 0) {
        iVar1 = local_3c + iStack_38 * 0x3c;
        iVar4 = 2;
        if (param_1[4] != 0x1e) {
          iVar4 = 4;
        }
        *param_1 = iVar2 - iVar4 * (iVar1 - iVar1 / 10);
      }
    }
  }
  else {
    _av_log(param_4,0x10,"Unable to parse timecode, syntax: hh:mm:ss[:;.]ff\n");
    uVar3 = 0xbebbb1b7;
  }
  return uVar3;
}


