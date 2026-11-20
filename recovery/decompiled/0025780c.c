/* Decompiled from supplied 5.2.2 arm package. VA 0x25780c. _av_display_matrix_flip */

/* WARNING: Removing unreachable block (ram,0x002578b8) */

void _av_display_matrix_flip(long param_1,int param_2,int param_3)

{
  long lVar1;
  int local_24 [3];
  undefined8 local_18;
  
  local_18 = *(undefined8 *)PTR____stack_chk_guard_01060708;
  local_24[0] = (uint)(param_2 != 0) * -2 + 1;
  local_24[1] = (uint)(param_3 != 0) * -2 + 1;
  local_24[2] = 1;
  if (param_3 != 0 || param_2 != 0) {
    for (lVar1 = 0; lVar1 != 9; lVar1 = lVar1 + 1) {
      *(int *)(param_1 + lVar1 * 4) = *(int *)(param_1 + lVar1 * 4) * local_24[(int)lVar1 % 3];
    }
  }
  return;
}


