/* Decompiled from supplied 5.2.2 arm package. VA 0x25d448. FUN_0025d448 */

void FUN_0025d448(undefined8 param_1,long param_2)

{
  code *pcVar1;
  long *plVar2;
  long local_28;
  
  pcVar1 = *(code **)(**(long **)(param_2 + 8) + 0x58);
  local_28 = param_2;
  if (pcVar1 != (code *)0x0) {
    (*pcVar1)(param_2);
  }
  if (*(code **)(param_2 + 0x20) != (code *)0x0) {
    (**(code **)(param_2 + 0x20))(param_2);
  }
  plVar2 = (long *)(param_2 + 8);
  _av_buffer_unref(*plVar2 + 0x10);
  _av_freep(param_2 + 0x18);
  _av_freep(*plVar2 + 8);
  _av_freep(plVar2);
  _av_freep(&local_28);
  return;
}


