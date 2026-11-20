/* Decompiled from supplied 5.2.2 arm package. VA 0x25e278. _ff_hwframe_map_replace */

void _ff_hwframe_map_replace(long param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  
  puVar1 = *(undefined8 **)(*(long *)(param_1 + 0x120) + 8);
  _av_frame_unref(*puVar1);
  _av_frame_ref(*puVar1,param_2);
  return;
}


