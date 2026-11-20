/* Decompiled from supplied 5.2.2 arm package. VA 0x27b2f0. FUN_0027b2f0 */

void FUN_0027b2f0(long param_1)

{
  long *plVar1;
  long lVar2;
  long lVar3;
  
  lVar2 = *(long *)(param_1 + 0x48);
  plVar1 = (long *)(lVar2 + 0x40);
  for (lVar3 = 0; lVar3 < *(int *)(lVar2 + 0x28); lVar3 = lVar3 + 1) {
    _av_expr_free(*(undefined8 *)(*plVar1 + lVar3 * 8));
    *(undefined8 *)(*plVar1 + lVar3 * 8) = 0;
  }
  _av_freep(plVar1);
  _av_freep(lVar2 + 0x98);
  return;
}


