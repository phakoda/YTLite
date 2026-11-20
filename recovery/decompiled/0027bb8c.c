/* Decompiled from supplied 5.2.2 arm package. VA 0x27bb8c. FUN_0027bb8c */

ulong FUN_0027bb8c(long *param_1)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  uint uVar4;
  long lVar5;
  long lVar6;
  
  lVar2 = *param_1;
  lVar5 = *(long *)(lVar2 + 0x48);
  lVar6 = **(long **)(lVar2 + 0x20);
  if (*(int *)(lVar5 + 0x30) != 0) {
    *(undefined8 *)(lVar5 + 0x18) = *(undefined8 *)(lVar6 + 0x38);
    uVar3 = FUN_0027b738(lVar2,*(undefined4 *)(lVar6 + 0xc4));
    if ((int)uVar3 < 0) {
      return uVar3;
    }
  }
  *(undefined8 *)(lVar5 + 0x60) = 0;
  iVar1 = *(int *)(lVar6 + 0xc4);
  *(int *)(lVar5 + 0x2c) = iVar1;
  *(double *)(lVar5 + 0x78) = (double)iVar1;
  *(double *)(lVar5 + 0x80) = (double)*(int *)((long)param_1 + 0xc4);
  *(double *)(lVar5 + 0x90) = (double)*(int *)(lVar6 + 0x40);
  *(undefined8 *)(lVar5 + 0x88) = 0x7ff8000000000000;
  lVar2 = _av_realloc_f(*(undefined8 *)(lVar5 + 0x98),(long)iVar1,8);
  *(long *)(lVar5 + 0x98) = lVar2;
  uVar4 = 0xfffffff4;
  if (lVar2 != 0) {
    uVar4 = 0;
  }
  return (ulong)uVar4;
}


