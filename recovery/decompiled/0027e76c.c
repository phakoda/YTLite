/* Decompiled from supplied 5.2.2 arm package. VA 0x27e76c. FUN_0027e76c */

void FUN_0027e76c(long param_1)

{
  long lVar1;
  long *plVar2;
  long lVar3;
  long lVar4;
  
  lVar3 = *(long *)(param_1 + 0x48);
  plVar2 = (long *)(lVar3 + 0x18);
  if (*plVar2 != 0) {
    lVar4 = -1;
    lVar1 = 0x10;
    while (lVar4 = lVar4 + 1, lVar4 < *(int *)(lVar3 + 0x20)) {
      _av_freep(*plVar2 + lVar1);
      lVar1 = lVar1 + 0x18;
    }
  }
  _av_freep(plVar2);
  return;
}


