/* Decompiled from supplied 5.2.2 arm package. VA 0x25555c. _av_buffer_pool_get */

long * _av_buffer_pool_get(pthread_mutex_t *param_1)

{
  char *pcVar1;
  code *pcVar2;
  char cVar3;
  bool bVar4;
  long *plVar5;
  undefined4 uVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  long *local_38;
  
  _pthread_mutex_lock(param_1);
  puVar8 = (undefined8 *)param_1[1].__sig;
  if (puVar8 != (undefined8 *)0x0) {
    plVar5 = (long *)_av_buffer_create(*puVar8,*(undefined4 *)(param_1[1].__opaque + 4),FUN_002556c8
                                       ,puVar8,0);
    if (plVar5 == (long *)0x0) {
      _pthread_mutex_unlock(param_1);
      return (long *)0x0;
    }
    param_1[1].__sig = puVar8[4];
    puVar8[4] = 0;
    _pthread_mutex_unlock(param_1);
    goto LAB_00255660;
  }
  pcVar2 = *(code **)(param_1[1].__opaque + 0x18);
  if (*(code **)(param_1[1].__opaque + 0x10) == (code *)0x0) {
    if (pcVar2 == (code *)0x0) {
      _av_log(0,0,"Assertion %s failed at %s:%d\n");
                    /* WARNING: Subroutine does not return */
      _abort();
    }
    uVar6 = *(undefined4 *)(param_1[1].__opaque + 4);
LAB_002555ec:
    plVar5 = (long *)(*pcVar2)(*(undefined8 *)(param_1[1].__opaque + 8),uVar6);
  }
  else {
    uVar6 = *(undefined4 *)(param_1[1].__opaque + 4);
    if (pcVar2 != (code *)0x0) goto LAB_002555ec;
    plVar5 = (long *)(**(code **)(param_1[1].__opaque + 0x10))(uVar6);
  }
  local_38 = plVar5;
  if (plVar5 == (long *)0x0) {
LAB_00255650:
    plVar5 = (long *)0x0;
  }
  else {
    puVar8 = (undefined8 *)_av_mallocz(0x28);
    if (puVar8 == (undefined8 *)0x0) {
      _av_buffer_unref(&local_38);
      goto LAB_00255650;
    }
    puVar7 = (undefined8 *)*plVar5;
    *puVar8 = *puVar7;
    puVar8[1] = puVar7[3];
    puVar8[2] = puVar7[2];
    puVar8[3] = param_1;
    puVar7[3] = puVar8;
    *(code **)(*local_38 + 0x10) = FUN_002556c8;
    plVar5 = local_38;
  }
  _pthread_mutex_unlock(param_1);
  if (plVar5 == (long *)0x0) {
    return (long *)0x0;
  }
LAB_00255660:
  pcVar1 = param_1[1].__opaque;
  do {
    cVar3 = '\x01';
    bVar4 = (bool)ExclusiveMonitorPass(pcVar1,0x10);
    if (bVar4) {
      *(int *)pcVar1 = *(int *)pcVar1 + 1;
      cVar3 = ExclusiveMonitorsStatus();
    }
  } while (cVar3 != '\0');
  return plVar5;
}


