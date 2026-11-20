/* Decompiled from supplied 5.2.2 arm package. VA 0x25b2a0. _av_frame_remove_side_data */

void _av_frame_remove_side_data(long param_1,int param_2)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  ulong uVar4;
  
  uVar1 = *(int *)(param_1 + 0x178) - 1;
  uVar4 = -(ulong)(uVar1 >> 0x1f) & 0xfffffff800000000 | (ulong)uVar1 << 3;
  lVar3 = (long)*(int *)(param_1 + 0x178);
  while (0 < lVar3) {
    if (**(int **)(*(long *)(param_1 + 0x170) + uVar4) == param_2) {
      FUN_0025c40c();
      lVar2 = (long)*(int *)(param_1 + 0x178) + -1;
      *(undefined8 *)(*(long *)(param_1 + 0x170) + uVar4) =
           *(undefined8 *)(*(long *)(param_1 + 0x170) + lVar2 * 8);
      *(int *)(param_1 + 0x178) = (int)lVar2;
    }
    uVar4 = uVar4 - 8;
    lVar3 = lVar3 + -1;
  }
  return;
}


