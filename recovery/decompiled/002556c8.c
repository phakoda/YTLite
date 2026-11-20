/* Decompiled from supplied 5.2.2 arm package. VA 0x2556c8. FUN_002556c8 */

ulong FUN_002556c8(long param_1)

{
  char *pcVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  uint uVar5;
  ulong uVar6;
  pthread_mutex_t *ppVar7;
  
  ppVar7 = *(pthread_mutex_t **)(param_1 + 0x18);
  _pthread_mutex_lock(ppVar7);
  *(long *)(param_1 + 0x20) = ppVar7[1].__sig;
  ppVar7[1].__sig = param_1;
  uVar5 = _pthread_mutex_unlock(ppVar7);
  pcVar1 = ppVar7[1].__opaque;
  do {
    iVar2 = *(int *)pcVar1;
    cVar3 = '\x01';
    bVar4 = (bool)ExclusiveMonitorPass(pcVar1,0x10);
    if (bVar4) {
      *(int *)pcVar1 = iVar2 + -1;
      cVar3 = ExclusiveMonitorsStatus();
    }
  } while (cVar3 != '\0');
  if (iVar2 + -1 == 0) {
    uVar6 = FUN_002554e0(ppVar7);
    return uVar6;
  }
  return (ulong)uVar5;
}


