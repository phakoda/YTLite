/* Decompiled from supplied 5.2.2 arm package. VA 0x25c318. _av_frame_get_plane_buffer */

long _av_frame_get_plane_buffer(long param_1,int param_2)

{
  int iVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  ulong uVar5;
  ulong uVar6;
  
  if (*(int *)(param_1 + 0x70) == 0) {
    iVar4 = 4;
  }
  else {
    iVar4 = *(int *)(param_1 + 0x1bc);
    if (iVar4 == 0) {
      return 0;
    }
    iVar1 = _av_sample_fmt_is_planar(*(undefined4 *)(param_1 + 0x74));
    if (iVar1 == 0) {
      iVar4 = 1;
    }
  }
  if (-1 < param_2) {
    if (iVar4 <= param_2) {
      return 0;
    }
    uVar5 = *(ulong *)(*(long *)(param_1 + 0x60) + (long)param_2 * 8);
    if (uVar5 != 0) {
      for (uVar6 = 0; (uVar6 < 8 && (lVar2 = *(long *)(param_1 + 0x120 + uVar6 * 8), lVar2 != 0));
          uVar6 = uVar6 + 1) {
        if ((*(ulong *)(lVar2 + 8) <= uVar5) &&
           (uVar5 < *(ulong *)(lVar2 + 8) + (long)*(int *)(lVar2 + 0x10))) {
          return lVar2;
        }
      }
      for (lVar2 = 0; lVar2 < *(int *)(param_1 + 0x168); lVar2 = lVar2 + 1) {
        lVar3 = *(long *)(*(long *)(param_1 + 0x160) + lVar2 * 8);
        if ((*(ulong *)(lVar3 + 8) <= uVar5) &&
           (uVar5 < *(ulong *)(lVar3 + 8) + (long)*(int *)(lVar3 + 0x10))) {
          return lVar3;
        }
      }
    }
    return 0;
  }
  return 0;
}


