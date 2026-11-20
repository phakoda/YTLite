/* Decompiled from supplied 5.2.2 arm package. VA 0x2554ac. _av_buffer_pool_uninit */

void _av_buffer_pool_uninit(long *param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  long lVar5;
  
  if ((param_1 != (long *)0x0) && (lVar5 = *param_1, lVar5 != 0)) {
    *param_1 = 0;
    piVar1 = (int *)(lVar5 + 0x48);
    do {
      iVar2 = *piVar1;
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar4) {
        *piVar1 = iVar2 + -1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    if (iVar2 + -1 == 0) {
      FUN_002554e0();
      return;
    }
  }
  return;
}


