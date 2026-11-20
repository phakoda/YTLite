/* Decompiled from supplied 5.2.2 arm package. VA 0x26cebc. _av_thread_message_queue_recv */

undefined4 _av_thread_message_queue_recv(undefined8 *param_1,undefined8 param_2,uint param_3)

{
  pthread_mutex_t *ppVar1;
  uint uVar2;
  undefined4 uVar3;
  
  ppVar1 = (pthread_mutex_t *)(param_1 + 1);
  _pthread_mutex_lock(ppVar1);
  while (*(int *)((long)param_1 + 0xac) == 0) {
    uVar2 = _av_fifo_size(*param_1);
    if (*(uint *)(param_1 + 0x16) <= uVar2) break;
    if ((param_3 & 1) != 0) {
      uVar3 = 0xffffffdd;
      goto LAB_0026cf60;
    }
    _pthread_cond_wait((pthread_cond_t *)(param_1 + 9),ppVar1);
  }
  uVar2 = _av_fifo_size(*param_1);
  if (uVar2 < *(uint *)(param_1 + 0x16)) {
    uVar3 = *(undefined4 *)((long)param_1 + 0xac);
  }
  else {
    _av_fifo_generic_read(*param_1,param_2,*(uint *)(param_1 + 0x16),0);
    _pthread_cond_signal((pthread_cond_t *)(param_1 + 0xf));
    uVar3 = 0;
  }
LAB_0026cf60:
  _pthread_mutex_unlock(ppVar1);
  return uVar3;
}


