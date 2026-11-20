/* Decompiled from supplied 5.2.2 arm package. VA 0x27db9c. FUN_0027db9c */

int FUN_0027db9c(long param_1,long param_2,undefined8 param_3,undefined8 param_4,void *param_5,
                long param_6,long param_7,long param_8)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  ulong uVar6;
  long lVar7;
  uint *puVar8;
  void *pvVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  
  dVar12 = *(double *)(param_1 + 0x18);
  _av_fast_malloc(param_2 + 0x70,param_2 + 0x78,(long)*(int *)(param_1 + 0x34) << 2);
  pvVar9 = *(void **)(param_2 + 0x70);
  if (pvVar9 == (void *)0x0) {
    iVar3 = -0xc;
  }
  else {
    _bzero(pvVar9,(long)*(int *)(param_1 + 0x34) << 2);
    for (lVar7 = 0; uVar6 = (ulong)*(int *)(param_1 + 0x44), lVar7 < (long)uVar6; lVar7 = lVar7 + 1)
    {
      dVar10 = *(double *)(param_7 + lVar7 * 8);
      dVar11 = (double)NEON_fminnm(ABS(dVar10),0x3ff0000000000000);
      uVar4 = (uint)(dVar11 * (double)(*(int *)(param_1 + 0x34) + -1));
      *(int *)((long)pvVar9 + (ulong)uVar4 * 4) = *(int *)((long)pvVar9 + (ulong)uVar4 * 4) + 1;
      *(double *)(param_8 + lVar7 * 8) = dVar10;
      *(undefined1 *)((long)param_5 + lVar7) = 0;
    }
    uVar4 = *(uint *)(param_1 + 0x34);
    lVar7 = ((ulong)uVar4 << 0x20) + -0x100000000;
    puVar8 = (uint *)((long)pvVar9 + (long)(int)(uVar4 - 1) * 4);
    iVar3 = uVar4 - 1;
    do {
      iVar5 = iVar3;
      if (iVar5 < 2) goto LAB_0027dce4;
      uVar1 = *puVar8;
      lVar7 = lVar7 + -0x100000000;
      puVar8 = puVar8 + -1;
      iVar3 = iVar5 + -1;
    } while (uVar1 == 0);
    uVar2 = *(uint *)((long)pvVar9 + (lVar7 >> 0x1e));
    if (uVar2 < 2) {
      uVar2 = 1;
    }
    if ((dVar12 < (double)uVar1 / (double)uVar2) && (0.0 < (double)iVar5 / (double)(int)uVar4)) {
      for (lVar7 = 0; lVar7 < (int)uVar6; lVar7 = lVar7 + 1) {
        *(bool *)((long)param_5 + lVar7) =
             (double)iVar5 / (double)(int)uVar4 <= ABS(*(double *)(param_7 + lVar7 * 8));
        uVar6 = (ulong)*(uint *)(param_1 + 0x44);
      }
    }
LAB_0027dce4:
    _bzero(param_5,(long)*(int *)(param_1 + 0x3c));
    _bzero((void *)((long)param_5 +
                   ((long)*(int *)(param_1 + 0x44) - (long)*(int *)(param_1 + 0x3c))),
           (long)*(int *)(param_1 + 0x3c));
    iVar5 = *(int *)(param_1 + 0x3c);
    iVar3 = 0;
    for (lVar7 = (long)iVar5; lVar7 < (long)*(int *)(param_1 + 0x44) - (long)iVar5;
        lVar7 = lVar7 + 1) {
      if (*(char *)((long)param_5 + lVar7) != '\0') {
        *(int *)(param_6 + (long)iVar3 * 4) = (int)lVar7;
        iVar5 = *(int *)(param_1 + 0x3c);
        iVar3 = iVar3 + 1;
      }
    }
  }
  return iVar3;
}


