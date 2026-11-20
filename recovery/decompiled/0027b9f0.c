/* Decompiled from supplied 5.2.2 arm package. VA 0x27b9f0. FUN_0027b9f0 */

undefined8 FUN_0027b9f0(long param_1,long param_2)

{
  int iVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  undefined8 uVar8;
  double dVar9;
  long local_78;
  
  lVar6 = *(long *)(*(long *)(param_1 + 0x10) + 0x48);
  lVar5 = **(long **)(*(long *)(param_1 + 0x10) + 0x38);
  iVar1 = *(int *)(param_2 + 0x70);
  local_78 = param_2;
  lVar3 = _ff_get_audio_buffer(lVar5,iVar1);
  if (lVar3 == 0) {
    _av_frame_free(&local_78);
    uVar8 = 0xfffffff4;
  }
  else {
    _av_frame_copy_props(lVar3,param_2);
    dVar9 = DAT_00c502d8;
    if (*(long *)(param_2 + 0x88) != -0x8000000000000000) {
      dVar9 = (double)*(long *)(param_2 + 0x88) *
              ((double)*(int *)(param_1 + 0x48) / (double)*(int *)(param_1 + 0x4c));
    }
    for (lVar7 = 0; lVar7 < iVar1; lVar7 = lVar7 + 1) {
      uVar8 = NEON_ucvtf(*(undefined8 *)(lVar6 + 0x60));
      *(undefined8 *)(lVar6 + 0x70) = uVar8;
      *(double *)(lVar6 + 0x88) = dVar9 + (double)(int)lVar7 / (double)*(int *)(param_1 + 0x40);
      iVar2 = *(int *)(param_1 + 0xc4);
      for (lVar4 = 0; lVar4 < iVar2; lVar4 = lVar4 + 1) {
        *(undefined8 *)(*(long *)(lVar6 + 0x98) + lVar4 * 8) =
             *(undefined8 *)(*(long *)(*(long *)(param_2 + 0x60) + lVar4 * 8) + lVar7 * 8);
      }
      for (lVar4 = 0; lVar4 < *(int *)(lVar5 + 0xc4); lVar4 = lVar4 + 1) {
        *(double *)(lVar6 + 0x68) = (double)(int)lVar4;
        uVar8 = _av_expr_eval(*(undefined8 *)(*(long *)(lVar6 + 0x40) + lVar4 * 8),lVar6 + 0x68,
                              lVar6);
        *(undefined8 *)(*(long *)(*(long *)(lVar3 + 0x60) + lVar4 * 8) + lVar7 * 8) = uVar8;
      }
      *(long *)(lVar6 + 0x60) = *(long *)(lVar6 + 0x60) + 1;
    }
    _av_frame_free(&local_78);
    uVar8 = _ff_filter_frame(lVar5,lVar3);
  }
  return uVar8;
}


