/* Decompiled from supplied 5.2.2 arm package. VA 0x26b534. _av_samples_copy */

undefined8
_av_samples_copy(ulong *param_1,ulong *param_2,int param_3,int param_4,int param_5,int param_6,
                uint param_7)

{
  long lVar1;
  int iVar2;
  int iVar3;
  ulong uVar4;
  ulong uVar5;
  long lVar6;
  long lVar7;
  uint uVar8;
  
  if (param_7 < 0xc) {
    uVar8 = (uint)(0xbe0L >> ((long)(int)param_7 & 0x3fU)) & 1;
  }
  else {
    uVar8 = 0;
  }
  iVar3 = _av_get_bytes_per_sample(param_7);
  lVar7 = 0;
  uVar4 = *param_1;
  uVar5 = *param_2;
  lVar1 = uVar5 - uVar4;
  if (uVar5 <= uVar4) {
    lVar1 = uVar4 - uVar5;
  }
  lVar6 = (long)param_6;
  iVar2 = 1;
  if (uVar8 == 0) {
    lVar6 = 1;
    iVar2 = param_6;
  }
  iVar3 = iVar3 * iVar2;
  param_5 = iVar3 * param_5;
  if (lVar1 < param_5) {
    for (; lVar7 < lVar6; lVar7 = lVar7 + 1) {
      _memmove((void *)(param_1[lVar7] + (long)(iVar3 * param_3)),
               (void *)(param_2[lVar7] + (long)(iVar3 * param_4)),(long)param_5);
    }
  }
  else {
    for (; lVar7 < lVar6; lVar7 = lVar7 + 1) {
      _memcpy((void *)(param_1[lVar7] + (long)(iVar3 * param_3)),
              (void *)(param_2[lVar7] + (long)(iVar3 * param_4)),(long)param_5);
    }
  }
  return 0;
}


