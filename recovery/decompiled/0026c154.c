/* Decompiled from supplied 5.2.2 arm package. VA 0x26c154. _avpriv_slicethread_create */

int _avpriv_slicethread_create(long *param_1,long param_2,long param_3,long param_4,int param_5)

{
  pthread_mutex_t *ppVar1;
  pthread_cond_t *ppVar2;
  int iVar3;
  long *plVar4;
  long lVar5;
  int iVar6;
  long *plVar7;
  long lVar8;
  
  if (param_5 < 0) {
    _av_log(0,0,"Assertion %s failed at %s:%d\n");
                    /* WARNING: Subroutine does not return */
    _abort();
  }
  if (param_5 == 0) {
    iVar3 = _av_cpu_count();
    param_5 = 1;
    if (1 < iVar3) {
      param_5 = iVar3 + 1;
    }
  }
  plVar4 = (long *)_av_mallocz(0xb0);
  *param_1 = (long)plVar4;
  if (plVar4 == (long *)0x0) {
LAB_0026c1e8:
    param_5 = -0xc;
  }
  else {
    iVar3 = param_5 - (uint)(param_4 == 0);
    if (iVar3 == 0) {
      lVar8 = 0;
    }
    else {
      lVar8 = (long)iVar3;
      lVar5 = _av_calloc(lVar8,0x88);
      *plVar4 = lVar5;
      if (lVar5 == 0) {
        _av_freep(param_1);
        goto LAB_0026c1e8;
      }
    }
    plVar4[0x13] = param_2;
    plVar4[0x14] = param_3;
    plVar4[0x15] = param_4;
    *(int *)(plVar4 + 1) = param_5;
    *(undefined4 *)((long)plVar4 + 0x94) = 0;
    *(undefined8 *)((long)plVar4 + 0x14) = 0;
    *(undefined8 *)((long)plVar4 + 0xc) = 0;
    _pthread_mutex_init((pthread_mutex_t *)(plVar4 + 4),(pthread_mutexattr_t *)0x0);
    _pthread_cond_init((pthread_cond_t *)(plVar4 + 0xc),(pthread_condattr_t *)0x0);
    *(undefined4 *)(plVar4 + 0x12) = 0;
    for (lVar5 = 0; lVar5 < lVar8; lVar5 = lVar5 + 1) {
      plVar7 = (long *)(*plVar4 + lVar5 * 0x88);
      *plVar7 = (long)plVar4;
      ppVar1 = (pthread_mutex_t *)(plVar7 + 1);
      _pthread_mutex_init(ppVar1,(pthread_mutexattr_t *)0x0);
      ppVar2 = (pthread_cond_t *)(plVar7 + 9);
      _pthread_cond_init(ppVar2,(pthread_condattr_t *)0x0);
      _pthread_mutex_lock(ppVar1);
      *(int *)(plVar7 + 0x10) = 0;
      iVar3 = _pthread_create((pthread_t *)(plVar7 + 0xf),(pthread_attr_t *)0x0,
                              (void **)FUN_0026c364,plVar7);
      if (iVar3 != 0) {
        iVar6 = (int)lVar5;
        if (param_4 == 0) {
          iVar6 = iVar6 + 1;
        }
        *(int *)(plVar4 + 1) = iVar6;
        _pthread_mutex_unlock(ppVar1);
        _pthread_cond_destroy(ppVar2);
        _pthread_mutex_destroy(ppVar1);
        _avpriv_slicethread_free(param_1);
        return -iVar3;
      }
      while ((int)plVar7[0x10] == 0) {
        _pthread_cond_wait(ppVar2,ppVar1);
      }
      _pthread_mutex_unlock(ppVar1);
    }
  }
  return param_5;
}


