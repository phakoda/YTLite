/* Decompiled from supplied 5.2.2 arm package. VA 0x26ce0c. _av_thread_message_queue_send */

int _av_thread_message_queue_send(undefined8 *param_1,undefined8 param_2,uint param_3)

{
  pthread_mutex_t *ppVar1;
  uint uVar2;
  int iVar3;
  
  ppVar1 = (pthread_mutex_t *)(param_1 + 1);
  _pthread_mutex_lock(ppVar1);
  do {
    iVar3 = *(int *)(param_1 + 0x15);
    if (iVar3 != 0) {
LAB_0026ce9c:
      _pthread_mutex_unlock(ppVar1);
      return iVar3;
    }
    uVar2 = _av_fifo_space(*param_1);
    if (*(uint *)(param_1 + 0x16) <= uVar2) {
      iVar3 = *(int *)(param_1 + 0x15);
      if (iVar3 == 0) {
        _av_fifo_generic_write(*param_1,param_2,*(uint *)(param_1 + 0x16),0);
        _pthread_cond_signal((pthread_cond_t *)(param_1 + 9));
        iVar3 = 0;
      }
      goto LAB_0026ce9c;
    }
    if ((param_3 & 1) != 0) {
      iVar3 = -0x23;
      goto LAB_0026ce9c;
    }
    _pthread_cond_wait((pthread_cond_t *)(param_1 + 0xf),ppVar1);
  } while( true );
}


