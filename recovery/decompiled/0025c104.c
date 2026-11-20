/* Decompiled from supplied 5.2.2 arm package. VA 0x25c104. _av_frame_move_ref */

void _av_frame_move_ref(void *param_1,void *param_2)

{
  _memcpy(param_1,param_2,0x218);
  if (*(void **)((long)param_2 + 0x60) == param_2) {
    *(void **)((long)param_1 + 0x60) = param_1;
  }
  _bzero(param_2,0x218);
  FUN_0025b53c(param_2);
  return;
}


