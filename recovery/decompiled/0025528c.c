/* Decompiled from supplied 5.2.2 arm package. VA 0x25528c. _av_buffer_realloc */

undefined8 _av_buffer_realloc(long *param_1,int param_2)

{
  int iVar1;
  long lVar2;
  long *plVar3;
  long *plVar4;
  long local_38;
  
  plVar4 = (long *)*param_1;
  if (plVar4 == (long *)0x0) {
    local_38 = _av_realloc(0,(long)param_2);
    if (local_38 != 0) {
      plVar4 = (long *)_av_buffer_create(local_38,param_2,_av_buffer_default_free,0,0);
      if (plVar4 != (long *)0x0) {
        *(uint *)(*plVar4 + 0x24) = *(uint *)(*plVar4 + 0x24) | 1;
        *param_1 = (long)plVar4;
        return 0;
      }
      _av_freep(&local_38);
    }
  }
  else {
    if ((int)plVar4[2] == param_2) {
      return 0;
    }
    if ((((*(byte *)(*plVar4 + 0x24) & 1) == 0) ||
        (iVar1 = _av_buffer_is_writable(plVar4), iVar1 == 0)) || (plVar4[1] != *(long *)*plVar4)) {
      local_38 = 0;
      _av_buffer_realloc(&local_38,param_2);
      if (local_38 != 0) {
        iVar1 = (int)plVar4[2];
        if (param_2 <= (int)plVar4[2]) {
          iVar1 = param_2;
        }
        _memcpy(*(void **)(local_38 + 8),(void *)plVar4[1],(long)iVar1);
        FUN_00255160(param_1,&local_38);
        return 0;
      }
    }
    else {
      lVar2 = _av_realloc(plVar4[1],(long)param_2);
      if (lVar2 != 0) {
        plVar3 = (long *)*plVar4;
        plVar4[1] = lVar2;
        *plVar3 = lVar2;
        *(int *)(plVar4 + 2) = param_2;
        *(int *)(plVar3 + 1) = param_2;
        return 0;
      }
    }
  }
  return 0xfffffff4;
}


