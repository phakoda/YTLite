/* Decompiled from supplied 5.2.2 arm package. VA 0x2554e0. FUN_002554e0 */

void FUN_002554e0(pthread_mutex_t *param_1)

{
  pthread_mutex_t *ppVar1;
  undefined8 *puVar2;
  code *pcVar3;
  undefined8 *local_30;
  pthread_mutex_t *local_28;
  
  local_28 = param_1;
  while (ppVar1 = local_28, puVar2 = (undefined8 *)local_28[1].__sig, puVar2 != (undefined8 *)0x0) {
    local_28[1].__sig = puVar2[4];
    local_30 = puVar2;
    (*(code *)puVar2[2])(puVar2[1],*puVar2);
    _av_freep(&local_30);
  }
  _pthread_mutex_destroy(local_28);
  pcVar3 = *(code **)(ppVar1[1].__opaque + 0x20);
  if (pcVar3 != (code *)0x0) {
    (*pcVar3)(*(undefined8 *)(ppVar1[1].__opaque + 8));
  }
  _av_freep(&local_28);
  return;
}


