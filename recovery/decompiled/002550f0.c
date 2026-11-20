/* Decompiled from supplied 5.2.2 arm package. VA 0x2550f0. _av_buffer_ref */

long * _av_buffer_ref(long *param_1)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  long *plVar4;
  long lVar5;
  
  plVar4 = (long *)_av_mallocz(0x18);
  if (plVar4 == (long *)0x0) {
    plVar4 = (long *)0x0;
  }
  else {
    plVar4[2] = param_1[2];
    lVar5 = *param_1;
    plVar4[1] = param_1[1];
    *plVar4 = lVar5;
    piVar1 = (int *)(*param_1 + 0xc);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar3) {
        *piVar1 = *piVar1 + 1;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
  }
  return plVar4;
}


