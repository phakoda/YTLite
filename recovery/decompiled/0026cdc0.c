/* Decompiled from supplied 5.2.2 arm package. VA 0x26cdc0. _av_thread_message_queue_nb_elems */

uint _av_thread_message_queue_nb_elems(undefined8 *param_1)

{
  uint uVar1;
  uint uVar2;
  
  _pthread_mutex_lock((pthread_mutex_t *)(param_1 + 1));
  uVar2 = _av_fifo_size(*param_1);
  _pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 1));
  uVar1 = 0;
  if (*(uint *)(param_1 + 0x16) != 0) {
    uVar1 = uVar2 / *(uint *)(param_1 + 0x16);
  }
  return uVar1;
}


