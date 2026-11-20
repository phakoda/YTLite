/* Decompiled from supplied 5.2.2 arm package. VA 0x24fb40. _oggpack_adv1 */

void _oggpack_adv1(long *param_1)

{
  long lVar1;
  
  lVar1 = param_1[1];
  *(int *)(param_1 + 1) = (int)lVar1 + 1;
  if (6 < (int)lVar1) {
    *(undefined4 *)(param_1 + 1) = 0;
    param_1[3] = param_1[3] + 1;
    *param_1 = *param_1 + 1;
  }
  return;
}


