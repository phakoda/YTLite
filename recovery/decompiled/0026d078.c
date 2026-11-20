/* Decompiled from supplied 5.2.2 arm package. VA 0x26d078. _av_usleep */

undefined8 _av_usleep(uint param_1)

{
  int iVar1;
  int *piVar2;
  timespec local_20;
  
  local_20.tv_sec = (ulong)param_1 / 1000000;
  local_20.tv_nsec = (long)((param_1 % 1000000) * 1000);
  do {
    iVar1 = _nanosleep(&local_20,&local_20);
    if (-1 < iVar1) {
      return 0;
    }
    piVar2 = ___error();
  } while (*piVar2 == 4);
  return 0;
}


