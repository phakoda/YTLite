/* Decompiled from supplied 5.2.2 arm package. VA 0x265ac4. _av_opt_free */

void _av_opt_free(long param_1)

{
  int iVar1;
  long lVar2;
  
  lVar2 = 0;
LAB_00265ae8:
  while( true ) {
    lVar2 = _av_opt_next(param_1,lVar2);
    if (lVar2 == 0) {
      return;
    }
    iVar1 = *(int *)(lVar2 + 0x14);
    if (iVar1 == 5) break;
    if (iVar1 != 8) goto code_r0x00265b10;
    _av_dict_free(param_1 + *(int *)(lVar2 + 0x10));
  }
  goto LAB_00265adc;
code_r0x00265b10:
  if (iVar1 == 7) {
LAB_00265adc:
    _av_freep(param_1 + *(int *)(lVar2 + 0x10));
  }
  goto LAB_00265ae8;
}


