/* Decompiled from supplied 5.2.2 arm package. VA 0x25d680. FUN_0025d680 */

void FUN_0025d680(undefined8 param_1,long param_2)

{
  code *pcVar1;
  long local_28;
  
  local_28 = param_2;
  if (*(long *)(*(long *)(param_2 + 8) + 0x10) != 0) {
    _av_buffer_pool_uninit();
  }
  pcVar1 = *(code **)(**(long **)(param_2 + 8) + 0x70);
  if (pcVar1 != (code *)0x0) {
    (*pcVar1)(param_2);
  }
  if (*(code **)(param_2 + 0x28) != (code *)0x0) {
    (**(code **)(param_2 + 0x28))(param_2);
  }
  _av_buffer_unref(*(long *)(param_2 + 8) + 0x18);
  _av_buffer_unref(param_2 + 0x10);
  _av_freep(param_2 + 0x20);
  _av_freep(*(long *)(param_2 + 8) + 8);
  _av_freep((undefined8 *)(param_2 + 8));
  _av_freep(&local_28);
  return;
}


