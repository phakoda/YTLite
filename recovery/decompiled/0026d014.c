/* Decompiled from supplied 5.2.2 arm package. VA 0x26d014. _av_gettime */

long _av_gettime(void)

{
  timeval local_20;
  
  _gettimeofday(&local_20,(void *)0x0);
  return (long)local_20.tv_usec + local_20.tv_sec * 1000000;
}


