/* Decompiled from supplied 5.2.2 arm package. VA 0x26d8f8. _av_tree_find */

undefined8 _av_tree_find(undefined8 *param_1,undefined8 param_2,code *param_3,long param_4)

{
  uint uVar1;
  
  while( true ) {
    if (param_1 == (undefined8 *)0x0) {
      return 0;
    }
    uVar1 = (*param_3)(param_2,param_1[2]);
    if (uVar1 == 0) break;
    if (param_4 != 0) {
      *(undefined8 *)(param_4 + (ulong)(uVar1 >> 0x1f) * 8) = param_1[2];
    }
    param_1 = (undefined8 *)param_1[uVar1 >> 0x1f ^ 1];
  }
  if (param_4 != 0) {
    _av_tree_find(*param_1,param_2,param_3,param_4);
    _av_tree_find(param_1[1],param_2,param_3,param_4);
  }
  return param_1[2];
}


