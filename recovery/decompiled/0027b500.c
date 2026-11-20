/* Decompiled from supplied 5.2.2 arm package. VA 0x27b500. FUN_0027b500 */

ulong FUN_0027b500(long *param_1)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  uint uVar4;
  long lVar5;
  int iVar6;
  long lVar7;
  long lVar8;
  double dVar9;
  undefined8 uVar10;
  
  lVar7 = *(long *)(*param_1 + 0x48);
  lVar5 = *(long *)(lVar7 + 0x58);
  if (lVar5 < 0) {
    iVar6 = *(int *)(lVar7 + 0x50);
  }
  else {
    iVar6 = *(int *)(lVar7 + 0x10);
    uVar4 = 0xdfb9b0bb;
    lVar2 = _av_rescale(*(undefined8 *)(lVar7 + 0x60),&LAB_000f4240,(long)iVar6);
    if (lVar5 <= lVar2) goto LAB_0027b658;
    iVar1 = *(int *)(lVar7 + 0x50);
    lVar5 = _av_rescale(lVar5,(long)iVar6,&LAB_000f4240);
    lVar5 = lVar5 - *(long *)(lVar7 + 0x38);
    iVar6 = (int)lVar5;
    if (iVar1 <= lVar5) {
      iVar6 = iVar1;
    }
    if (iVar6 == 0) goto LAB_0027b658;
  }
  lVar5 = _ff_get_audio_buffer(param_1,iVar6);
  if (lVar5 != 0) {
    for (lVar2 = 0; lVar2 < iVar6; lVar2 = lVar2 + 1) {
      lVar8 = 0;
      dVar9 = (double)NEON_ucvtf(*(undefined8 *)(lVar7 + 0x60));
      *(double *)(lVar7 + 0x70) = dVar9;
      *(double *)(lVar7 + 0x88) = dVar9 / (double)*(int *)(lVar7 + 0x10);
      for (; lVar8 < *(int *)(lVar7 + 0x28); lVar8 = lVar8 + 1) {
        uVar10 = _av_expr_eval(*(undefined8 *)(*(long *)(lVar7 + 0x40) + lVar8 * 8),lVar7 + 0x68,0);
        *(undefined8 *)(*(long *)(*(long *)(lVar5 + 0x60) + lVar8 * 8) + lVar2 * 8) = uVar10;
      }
      *(long *)(lVar7 + 0x60) = *(long *)(lVar7 + 0x60) + 1;
    }
    lVar2 = *(long *)(lVar7 + 0x38);
    *(long *)(lVar5 + 0x88) = lVar2;
    *(undefined4 *)(lVar5 + 0x110) = *(undefined4 *)(lVar7 + 0x10);
    *(long *)(lVar7 + 0x38) = lVar2 + iVar6;
    uVar3 = _ff_filter_frame(param_1,lVar5);
    return uVar3;
  }
  uVar4 = 0xfffffff4;
LAB_0027b658:
  return (ulong)uVar4;
}


