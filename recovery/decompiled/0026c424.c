/* Decompiled from supplied 5.2.2 arm package. VA 0x26c424. _avpriv_slicethread_free */

void _avpriv_slicethread_free(undefined8 *param_1)

{
  long lVar1;
  long *plVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  
  if ((param_1 != (undefined8 *)0x0) && (plVar2 = (long *)*param_1, plVar2 != (long *)0x0)) {
    *(undefined4 *)((long)plVar2 + 0x94) = 1;
    lVar4 = (long)(int)plVar2[1] - (ulong)(plVar2[0x15] == 0);
    lVar5 = -1;
    lVar3 = 0;
    while (lVar5 = lVar5 + 1, lVar5 < lVar4) {
      lVar1 = *plVar2 + lVar3;
      _pthread_mutex_lock((pthread_mutex_t *)(lVar1 + 8));
      *(undefined4 *)(lVar1 + 0x80) = 0;
      _pthread_cond_signal((pthread_cond_t *)(lVar1 + 0x48));
      _pthread_mutex_unlock((pthread_mutex_t *)(lVar1 + 8));
      lVar3 = lVar3 + 0x88;
    }
    lVar5 = 0;
    lVar3 = -1;
    while (lVar3 = lVar3 + 1, lVar3 < lVar4) {
      lVar1 = *plVar2 + lVar5;
      lVar5 = lVar5 + 0x88;
      _pthread_join(*(pthread_t *)(lVar1 + 0x78),(void **)0x0);
      _pthread_cond_destroy((pthread_cond_t *)(lVar1 + 0x48));
      _pthread_mutex_destroy((pthread_mutex_t *)(lVar1 + 8));
    }
    _pthread_cond_destroy((pthread_cond_t *)(plVar2 + 0xc));
    _pthread_mutex_destroy((pthread_mutex_t *)(plVar2 + 4));
    _av_freep(plVar2);
    _av_freep(param_1);
    return;
  }
  return;
}


