/* Decompiled from supplied 5.2.2 arm package. VA 0x261658. _av_md5_update */

void _av_md5_update(ulong *param_1,void *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  ulong uVar3;
  
  uVar3 = *param_1;
  uVar1 = (uint)uVar3 & 0x3f;
  *param_1 = uVar3 + (long)(int)param_3;
  if ((uVar3 & 0x3f) != 0) {
    uVar2 = 0x40 - uVar1;
    if ((int)param_3 <= (int)(0x40 - uVar1)) {
      uVar2 = param_3;
    }
    _memcpy((void *)((long)param_1 + (ulong)uVar1 + 8),param_2,(long)(int)uVar2);
    if ((int)(uVar2 + uVar1) < 0x40) {
      return;
    }
    param_3 = param_3 - uVar2;
    param_2 = (void *)((long)param_2 + (long)(int)uVar2);
    FUN_0026172c(param_1 + 9,param_1 + 1,1);
  }
  uVar1 = param_3 + 0x3f;
  if (-1 < (int)param_3) {
    uVar1 = param_3;
  }
  FUN_0026172c(param_1 + 9,param_2,(int)uVar1 >> 6);
  if ((param_3 & 0x3f) != 0) {
    _memcpy(param_1 + 1,(void *)((long)param_2 + (long)(int)(param_3 & 0xffffffc0)),
            (ulong)(param_3 & 0x3f));
  }
  return;
}


