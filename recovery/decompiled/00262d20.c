/* Decompiled from supplied 5.2.2 arm package. VA 0x262d20. FUN_00262d20 */

undefined4 FUN_00262d20(undefined8 param_1,long *param_2)

{
  long lVar1;
  undefined4 uVar2;
  
  _av_freep(param_2);
  lVar1 = _av_strdup(param_1);
  uVar2 = 0;
  if (lVar1 == 0) {
    uVar2 = 0xfffffff4;
  }
  *param_2 = lVar1;
  return uVar2;
}


