/* Decompiled from supplied 5.2.2 arm package. VA 0x26cb80. _av_thread_message_queue_alloc */

int _av_thread_message_queue_alloc(undefined8 *param_1,uint param_2,uint param_3)

{
  pthread_mutex_t *ppVar1;
  pthread_cond_t *ppVar2;
  uint uVar3;
  int iVar4;
  long *plVar5;
  long lVar6;
  
  uVar3 = 0;
  if (param_3 != 0) {
    uVar3 = 0x7fffffff / param_3;
  }
  if (uVar3 < param_2) {
    return -0x16;
  }
  plVar5 = (long *)_av_mallocz(0xc0);
  if (plVar5 != (long *)0x0) {
    ppVar1 = (pthread_mutex_t *)(plVar5 + 1);
    iVar4 = _pthread_mutex_init(ppVar1,(pthread_mutexattr_t *)0x0);
    if (iVar4 != 0) {
      _av_free(plVar5);
      return -iVar4;
    }
    ppVar2 = (pthread_cond_t *)(plVar5 + 9);
    iVar4 = _pthread_cond_init(ppVar2,(pthread_condattr_t *)0x0);
    if (iVar4 != 0) {
      _pthread_mutex_destroy(ppVar1);
      _av_free(plVar5);
      return -iVar4;
    }
    iVar4 = _pthread_cond_init((pthread_cond_t *)(plVar5 + 0xf),(pthread_condattr_t *)0x0);
    if (iVar4 != 0) {
      _pthread_cond_destroy(ppVar2);
      _pthread_mutex_destroy(ppVar1);
      _av_free(plVar5);
      return -iVar4;
    }
    lVar6 = _av_fifo_alloc(param_3 * param_2);
    *plVar5 = lVar6;
    if (lVar6 != 0) {
      *(uint *)(plVar5 + 0x16) = param_3;
      *param_1 = plVar5;
      return 0;
    }
    _pthread_cond_destroy((pthread_cond_t *)(plVar5 + 0xf));
    _pthread_cond_destroy(ppVar2);
    _pthread_mutex_destroy(ppVar1);
    _av_free(plVar5);
  }
  return -0xc;
}


