/* Decompiled from supplied 5.2.2 arm package. VA 0x25737c. _av_dict_free */

void _av_dict_free(undefined8 *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)*param_1;
  if (piVar3 != (int *)0x0) {
    while( true ) {
      iVar1 = *piVar3;
      iVar2 = iVar1 + -1;
      *piVar3 = iVar2;
      if (iVar1 == 0) break;
      _av_freep(*(long *)(piVar3 + 2) + (long)iVar2 * 0x10);
      _av_freep(*(long *)(piVar3 + 2) + (long)*piVar3 * 0x10 + 8);
    }
    _av_freep(piVar3 + 2);
  }
  _av_freep(param_1);
  return;
}


