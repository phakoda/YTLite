/* Decompiled from supplied 5.2.2 arm package. VA 0x26cd24. _av_thread_message_flush */

int _av_thread_message_flush(undefined8 *param_1)

{
  int iVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = param_1[0x17];
  _pthread_mutex_lock((pthread_mutex_t *)(param_1 + 1));
  iVar1 = _av_fifo_size(*param_1);
  if (lVar3 != 0) {
    for (iVar2 = 0; iVar2 < iVar1; iVar2 = *(int *)(param_1 + 0x16) + iVar2) {
      _av_fifo_generic_peek_at(*param_1,param_1,iVar2,*(undefined4 *)(param_1 + 0x16),FUN_0026d008);
    }
  }
  _av_fifo_drain(*param_1,iVar1);
  _pthread_cond_broadcast((pthread_cond_t *)(param_1 + 0xf));
  iVar1 = _pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 1));
  return iVar1;
}


