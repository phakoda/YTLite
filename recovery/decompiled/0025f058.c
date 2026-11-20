/* Decompiled from supplied 5.2.2 arm package. VA 0x25f058. _av_image_copy */

void _av_image_copy(undefined8 param_1,long param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  long lVar2;
  long local_68 [4];
  long local_48 [4];
  long local_28;
  
  lVar2 = *(long *)PTR____stack_chk_guard_01060708;
  local_28 = lVar2;
  for (lVar1 = 0; lVar1 != 4; lVar1 = lVar1 + 1) {
    local_48[lVar1] = (long)*(int *)(param_2 + lVar1 * 4);
    local_68[lVar1] = (long)*(int *)(param_4 + lVar1 * 4);
  }
  FUN_0025f0d8(param_1,local_48,param_3,local_68);
  if (lVar2 == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


