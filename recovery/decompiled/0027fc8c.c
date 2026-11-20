/* Decompiled from supplied 5.2.2 arm package. VA 0x27fc8c. FUN_0027fc8c */

undefined8 FUN_0027fc8c(long *param_1)

{
  int iVar1;
  double dVar2;
  long lVar3;
  undefined8 uVar4;
  long lVar5;
  code *pcVar6;
  int iVar7;
  long *plVar8;
  long lVar9;
  float fVar10;
  
  dVar2 = DAT_00c4c4a0;
  lVar3 = *param_1;
  lVar9 = *(long *)(lVar3 + 0x48);
  fVar10 = 1.0;
  for (lVar5 = 0; lVar5 < *(int *)(lVar9 + 0x30); lVar5 = lVar5 + 1) {
    iVar7 = (int)((double)(*(float *)(*(long *)(lVar9 + 0x20) + lVar5 * 4) * (float)(int)param_1[8])
                 / dVar2);
    *(int *)(*(long *)(lVar9 + 0x48) + lVar5 * 4) = iVar7;
    iVar1 = *(int *)(lVar9 + 0x40);
    if (*(int *)(lVar9 + 0x40) <= iVar7) {
      iVar1 = iVar7;
    }
    *(int *)(lVar9 + 0x40) = iVar1;
    fVar10 = fVar10 + *(float *)(*(long *)(lVar9 + 0x28) + lVar5 * 4);
  }
  if (*(int *)(lVar9 + 0x40) < 1) {
    _av_log(lVar3,0x10,"Nothing to echo - missing delay samples.\n");
    return 0xffffffea;
  }
  *(int *)(lVar9 + 0x44) = *(int *)(lVar9 + 0x40);
  if (1.0 < fVar10 * *(float *)(lVar9 + 8) * *(float *)(lVar9 + 0xc)) {
    _av_log(lVar3,0x18,"out_gain %f can cause saturation of output\n");
  }
  switch(*(undefined4 *)((long)param_1 + 0x44)) {
  case 6:
    pcVar6 = FUN_00280010;
    break;
  case 7:
    pcVar6 = FUN_00280124;
    break;
  case 8:
    pcVar6 = FUN_0027ff14;
    break;
  case 9:
    pcVar6 = FUN_0027fe24;
    break;
  default:
    goto switchD_0027fd74_default;
  }
  *(code **)(lVar9 + 0x60) = pcVar6;
switchD_0027fd74_default:
  plVar8 = (long *)(lVar9 + 0x38);
  if (*plVar8 != 0) {
    _av_freep();
  }
  _av_freep(plVar8);
  uVar4 = _av_samples_alloc_array_and_samples
                    (plVar8,0,*(undefined4 *)((long)param_1 + 0xc4),*(undefined4 *)(lVar9 + 0x40),
                     *(undefined4 *)((long)param_1 + 0x44),0);
  return uVar4;
}


