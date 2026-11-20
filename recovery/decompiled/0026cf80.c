/* Decompiled from supplied 5.2.2 arm package. VA 0x26cf80. _av_thread_message_queue_set_err_send */

int _av_thread_message_queue_set_err_send(long param_1,undefined4 param_2)

{
  int iVar1;
  
  _pthread_mutex_lock((pthread_mutex_t *)(param_1 + 8));
  *(undefined4 *)(param_1 + 0xa8) = param_2;
  _pthread_cond_broadcast((pthread_cond_t *)(param_1 + 0x78));
  iVar1 = _pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 8));
  return iVar1;
}


