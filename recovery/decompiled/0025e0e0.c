/* Decompiled from supplied 5.2.2 arm package. VA 0x25e0e0. FUN_0025e0e0 */

void FUN_0025e0e0(undefined8 param_1,void *param_2)

{
  if (*(code **)((long)param_2 + 0x10) != (code *)0x0) {
    (**(code **)((long)param_2 + 0x10))(param_1,param_2);
  }
  _av_frame_free(param_2);
  _av_buffer_unref((long)param_2 + 8);
  _av_free(param_2);
  return;
}


