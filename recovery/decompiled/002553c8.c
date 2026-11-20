/* Decompiled from supplied 5.2.2 arm package. VA 0x2553c8. _av_buffer_pool_init2 */

pthread_mutex_t *
_av_buffer_pool_init2(undefined4 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  pthread_mutex_t *ppVar1;
  
  ppVar1 = (pthread_mutex_t *)_av_mallocz(0x70);
  if (ppVar1 == (pthread_mutex_t *)0x0) {
    ppVar1 = (pthread_mutex_t *)0x0;
  }
  else {
    _pthread_mutex_init(ppVar1,(pthread_mutexattr_t *)0x0);
    *(undefined8 *)(ppVar1[1].__opaque + 0x18) = param_3;
    *(undefined8 *)(ppVar1[1].__opaque + 0x20) = param_4;
    *(undefined8 *)(ppVar1[1].__opaque + 8) = param_2;
    *(code **)(ppVar1[1].__opaque + 0x10) = _av_buffer_alloc;
    ppVar1[1].__opaque[0] = '\x01';
    ppVar1[1].__opaque[1] = '\0';
    ppVar1[1].__opaque[2] = '\0';
    ppVar1[1].__opaque[3] = '\0';
    *(undefined4 *)(ppVar1[1].__opaque + 4) = param_1;
  }
  return ppVar1;
}


