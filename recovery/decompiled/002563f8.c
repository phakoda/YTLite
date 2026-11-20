/* Decompiled from supplied 5.2.2 arm package. VA 0x2563f8. _av_cpu_count */

undefined4 _av_cpu_count(void)

{
  int iVar1;
  size_t local_38;
  int aiStack_30 [3];
  undefined4 local_24;
  
  local_24 = 1;
  local_38 = 4;
  aiStack_30[0] = 6;
  aiStack_30[1] = 3;
  iVar1 = _sysctl(aiStack_30,2,&local_24,&local_38,(void *)0x0,0);
  if (iVar1 == -1) {
    local_24 = 0;
  }
  if (DAT_01228fb0 == 0) {
    _av_log(0,0x30,"detected %d logical cores\n");
    DAT_01228fb0 = 1;
  }
  return local_24;
}


