/* Decompiled from supplied 5.2.2 arm package. VA 0x26dbe0. _av_tree_destroy */

void _av_tree_destroy(undefined8 *param_1)

{
  if (param_1 != (undefined8 *)0x0) {
    _av_tree_destroy(*param_1);
    _av_tree_destroy(param_1[1]);
    _av_free(param_1);
    return;
  }
  return;
}


