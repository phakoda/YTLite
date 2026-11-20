/* Decompiled from supplied 5.2.2 arm package. VA 0x26ccc0. _av_thread_message_queue_free */

void _av_thread_message_queue_free(long *param_1)

{
  if (*param_1 != 0) {
    _av_thread_message_flush();
    _av_fifo_freep(*param_1);
    _pthread_cond_destroy((pthread_cond_t *)(*param_1 + 0x78));
    _pthread_cond_destroy((pthread_cond_t *)(*param_1 + 0x48));
    _pthread_mutex_destroy((pthread_mutex_t *)(*param_1 + 8));
    _av_freep(param_1);
    return;
  }
  return;
}


