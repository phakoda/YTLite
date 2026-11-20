/* Decompiled from supplied 5.2.2 arm package. VA 0x258370. _av_expr_free */

void _av_expr_free(long param_1)

{
  long local_28;
  
  if (param_1 != 0) {
    local_28 = param_1;
    _av_expr_free(*(undefined8 *)(param_1 + 0x20));
    _av_expr_free(*(undefined8 *)(param_1 + 0x28));
    _av_expr_free(*(undefined8 *)(param_1 + 0x30));
    _av_freep(param_1 + 0x38);
    _av_freep(&local_28);
  }
  return;
}


