/* Decompiled from supplied 5.2.2 arm package. VA 0x25d4c8. _av_hwdevice_ctx_init */

int _av_hwdevice_ctx_init(long param_1)

{
  int iVar1;
  code *pcVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 8);
  pcVar2 = *(code **)(**(long **)(lVar3 + 8) + 0x50);
  if (pcVar2 != (code *)0x0) {
    iVar1 = (*pcVar2)(lVar3);
    if (iVar1 < 0) {
      pcVar2 = *(code **)(**(long **)(lVar3 + 8) + 0x58);
      if (pcVar2 == (code *)0x0) {
        return iVar1;
      }
      (*pcVar2)(lVar3);
      return iVar1;
    }
  }
  return 0;
}


