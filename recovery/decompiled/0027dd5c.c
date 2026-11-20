/* Decompiled from supplied 5.2.2 arm package. VA 0x27dd5c. FUN_0027dd5c */

void FUN_0027dd5c(double param_1,long param_2,undefined8 param_3,void *param_4,long param_5,
                 void *param_6,long param_7,long param_8,long param_9)

{
  int iVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  double *pdVar5;
  long lVar6;
  double *pdVar7;
  double dVar8;
  
  dVar8 = *(double *)(param_2 + 0x18);
  _bzero(param_4,(long)*(int *)(param_2 + 0x44) << 3);
  iVar1 = *(int *)(param_2 + 0x44);
  lVar3 = (long)*(int *)(param_2 + 0x3c);
  pdVar5 = (double *)(param_8 + lVar3 * 8);
  for (lVar4 = lVar3; lVar4 < iVar1; lVar4 = lVar4 + 1) {
    pdVar7 = pdVar5;
    for (lVar6 = 0; lVar6 <= lVar3; lVar6 = lVar6 + 1) {
      *(double *)((long)param_4 + lVar4 * 8) =
           *(double *)((long)param_4 + lVar4 * 8) + *(double *)(param_5 + lVar6 * 8) * *pdVar7;
      pdVar7 = pdVar7 + -1;
    }
    pdVar5 = pdVar5 + 1;
  }
  for (lVar4 = 0; lVar4 < iVar1; lVar4 = lVar4 + 1) {
    *(bool *)((long)param_6 + lVar4) = dVar8 * param_1 < ABS(*(double *)((long)param_4 + lVar4 * 8))
    ;
    *(undefined8 *)(param_9 + lVar4 * 8) = *(undefined8 *)(param_8 + lVar4 * 8);
    iVar1 = *(int *)(param_2 + 0x44);
  }
  iVar2 = -1;
  for (lVar4 = 0; lVar4 < iVar1; lVar4 = lVar4 + 1) {
    if (*(char *)((long)param_6 + lVar4) != '\0') {
      if (((-1 < iVar2) && (iVar2 + 1 < lVar4)) && (lVar4 <= *(int *)(param_2 + 0x40) + iVar2)) {
        for (lVar3 = (long)(iVar2 + 1); lVar3 < lVar4; lVar3 = lVar3 + 1) {
          *(undefined1 *)((long)param_6 + lVar3) = 1;
        }
        iVar1 = *(int *)(param_2 + 0x44);
      }
      iVar2 = (int)lVar4;
    }
  }
  _bzero(param_6,(long)*(int *)(param_2 + 0x3c));
  _bzero((void *)((long)param_6 + ((long)*(int *)(param_2 + 0x44) - (long)*(int *)(param_2 + 0x3c)))
         ,(long)*(int *)(param_2 + 0x3c));
  iVar2 = *(int *)(param_2 + 0x3c);
  iVar1 = 0;
  for (lVar4 = (long)iVar2; lVar4 < (long)*(int *)(param_2 + 0x44) - (long)iVar2; lVar4 = lVar4 + 1)
  {
    if (*(char *)((long)param_6 + lVar4) != '\0') {
      *(int *)(param_7 + (long)iVar1 * 4) = (int)lVar4;
      iVar2 = *(int *)(param_2 + 0x3c);
      iVar1 = iVar1 + 1;
    }
  }
  return;
}


