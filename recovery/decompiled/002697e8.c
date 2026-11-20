/* Decompiled from supplied 5.2.2 arm package. VA 0x2697e8. _av_find_nearest_q_idx */

int _av_find_nearest_q_idx(undefined8 param_1,long param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  iVar4 = 0;
  iVar3 = 0;
  for (piVar5 = (int *)(param_2 + 4); *piVar5 != 0; piVar5 = piVar5 + 2) {
    iVar2 = _av_nearer_q(param_1,*(undefined8 *)(piVar5 + -1),
                         *(undefined8 *)(param_2 + (long)iVar3 * 8));
    iVar1 = iVar4;
    if (iVar2 < 1) {
      iVar1 = iVar3;
    }
    iVar4 = iVar4 + 1;
    iVar3 = iVar1;
  }
  return iVar3;
}


