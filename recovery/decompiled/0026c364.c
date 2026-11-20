/* Decompiled from supplied 5.2.2 arm package. VA 0x26c364. FUN_0026c364 */

undefined8 FUN_0026c364(long *param_1)

{
  pthread_mutex_t *ppVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = *param_1;
  ppVar1 = (pthread_mutex_t *)(param_1 + 1);
  _pthread_mutex_lock(ppVar1);
  _pthread_cond_signal((pthread_cond_t *)(param_1 + 9));
  while( true ) {
    *(undefined4 *)(param_1 + 0x10) = 1;
    iVar2 = 1;
    while (iVar2 != 0) {
      _pthread_cond_wait((pthread_cond_t *)(param_1 + 9),ppVar1);
      iVar2 = (int)param_1[0x10];
    }
    if (*(int *)(lVar3 + 0x94) != 0) break;
    iVar2 = FUN_0026c6ac(lVar3);
    if (iVar2 != 0) {
      _pthread_mutex_lock((pthread_mutex_t *)(lVar3 + 0x20));
      *(undefined4 *)(lVar3 + 0x90) = 1;
      _pthread_cond_signal((pthread_cond_t *)(lVar3 + 0x60));
      _pthread_mutex_unlock((pthread_mutex_t *)(lVar3 + 0x20));
    }
  }
  _pthread_mutex_unlock(ppVar1);
  return 0;
}


