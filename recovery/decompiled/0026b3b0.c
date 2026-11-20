/* Decompiled from supplied 5.2.2 arm package. VA 0x26b3b0. _av_samples_set_silence */

undefined8 _av_samples_set_silence(long param_1,int param_2,int param_3,int param_4,uint param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  uint uVar6;
  
  if (param_5 < 0xc) {
    uVar6 = (uint)(0xbe0L >> ((long)(int)param_5 & 0x3fU)) & 1;
  }
  else {
    uVar6 = 0;
  }
  iVar2 = _av_get_bytes_per_sample(param_5);
  lVar5 = 0;
  iVar3 = 0x80;
  if (param_5 != 5 && param_5 != 0) {
    iVar3 = 0;
  }
  iVar1 = 1;
  if (uVar6 == 0) {
    iVar1 = param_4;
  }
  lVar4 = (long)param_4;
  if (uVar6 == 0) {
    lVar4 = 1;
  }
  for (; lVar5 < lVar4; lVar5 = lVar5 + 1) {
    _memset((void *)(*(long *)(param_1 + lVar5 * 8) + (long)(iVar2 * iVar1 * param_2)),iVar3,
            (long)(iVar2 * iVar1 * param_3));
  }
  return 0;
}


