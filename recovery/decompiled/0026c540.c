/* Decompiled from supplied 5.2.2 arm package. VA 0x26c540. _avpriv_slicethread_execute */

ulong _avpriv_slicethread_execute(long *param_1,int param_2,int param_3)

{
  pthread_mutex_t *ppVar1;
  long lVar2;
  int iVar3;
  uint uVar4;
  ulong uVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  
  if (param_2 < 1) {
    _av_log(0,0,"Assertion %s failed at %s:%d\n");
                    /* WARNING: Subroutine does not return */
    _abort();
  }
  iVar3 = (int)param_1[1];
  if (param_2 <= (int)param_1[1]) {
    iVar3 = param_2;
  }
  *(int *)((long)param_1 + 0xc) = iVar3;
  *(int *)(param_1 + 2) = param_2;
  *(undefined4 *)((long)param_1 + 0x14) = 0;
  *(int *)(param_1 + 3) = iVar3;
  lVar7 = param_1[0x15];
  lVar8 = -1;
  lVar6 = 0;
  while (lVar8 = lVar8 + 1, lVar8 < (int)(iVar3 - (uint)(param_3 == 0 || lVar7 == 0))) {
    lVar2 = *param_1 + lVar6;
    _pthread_mutex_lock((pthread_mutex_t *)(lVar2 + 8));
    *(undefined4 *)(lVar2 + 0x80) = 0;
    _pthread_cond_signal((pthread_cond_t *)(lVar2 + 0x48));
    _pthread_mutex_unlock((pthread_mutex_t *)(lVar2 + 8));
    lVar6 = lVar6 + 0x88;
  }
  if ((param_3 == 0) || ((code *)param_1[0x15] == (code *)0x0)) {
    uVar5 = FUN_0026c6ac(param_1);
    if ((int)uVar5 != 0) {
      return uVar5;
    }
  }
  else {
    (*(code *)param_1[0x15])(param_1[0x13]);
  }
  ppVar1 = (pthread_mutex_t *)(param_1 + 4);
  _pthread_mutex_lock(ppVar1);
  while ((int)param_1[0x12] == 0) {
    _pthread_cond_wait((pthread_cond_t *)(param_1 + 0xc),ppVar1);
  }
  *(undefined4 *)(param_1 + 0x12) = 0;
  uVar4 = _pthread_mutex_unlock(ppVar1);
  return (ulong)uVar4;
}


