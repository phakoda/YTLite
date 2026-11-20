/* Decompiled from supplied 5.2.2 arm package. VA 0x2696e8. _av_nearer_q */

int _av_nearer_q(long param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  long lVar2;
  int iVar3;
  uint uVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  int iVar8;
  
  iVar8 = (int)param_2;
  iVar3 = (int)param_3;
  lVar5 = (long)iVar8 * ((long)param_3 >> 0x20);
  lVar6 = (long)iVar3 * ((long)param_2 >> 0x20);
  lVar2 = lVar6 + lVar5;
  lVar7 = ((long)param_2 >> 0x20) * ((long)param_3 >> 0x20) * 2;
  lVar1 = _av_rescale_rnd(lVar2,param_1 >> 0x20,lVar7,3);
  lVar2 = _av_rescale_rnd(lVar2,param_1 >> 0x20,lVar7,2);
  lVar6 = lVar6 - lVar5;
  if (lVar6 == 0) {
    if ((((param_2 >> 0x20 == 0) || (uVar4 = 0, param_3 >> 0x20 == 0)) &&
        (uVar4 = 0x80000000, iVar8 != 0)) && (iVar3 != 0)) {
      uVar4 = (iVar3 >> 0x1f) - (iVar8 >> 0x1f);
    }
  }
  else {
    uVar4 = (int)((int)((uint)(param_3 >> 0x20) ^ (uint)(param_2 >> 0x20)) >> 0x1f ^
                 (uint)((ulong)lVar6 >> 0x20)) >> 0x1f | 1;
  }
  return uVar4 * ((uint)((int)param_1 < lVar1) - (uint)(lVar2 < (int)param_1));
}


