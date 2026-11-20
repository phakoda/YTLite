/* Decompiled from supplied 5.2.2 arm package. VA 0x255440. _av_buffer_pool_init */

pthread_mutex_t * _av_buffer_pool_init(undefined4 param_1,code *param_2)

{
  pthread_mutex_t *ppVar1;
  
  ppVar1 = (pthread_mutex_t *)_av_mallocz(0x70);
  if (ppVar1 == (pthread_mutex_t *)0x0) {
    ppVar1 = (pthread_mutex_t *)0x0;
  }
  else {
    _pthread_mutex_init(ppVar1,(pthread_mutexattr_t *)0x0);
    if (param_2 == (code *)0x0) {
      param_2 = _av_buffer_alloc;
    }
    *(code **)(ppVar1[1].__opaque + 0x10) = param_2;
    ppVar1[1].__opaque[0] = '\x01';
    ppVar1[1].__opaque[1] = '\0';
    ppVar1[1].__opaque[2] = '\0';
    ppVar1[1].__opaque[3] = '\0';
    *(undefined4 *)(ppVar1[1].__opaque + 4) = param_1;
  }
  return ppVar1;
}


