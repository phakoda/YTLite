/* Decompiled from supplied 5.2.2 arm package. VA 0x260b04. FUN_00260b04 */

int FUN_00260b04(long *param_1)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *param_1;
  if (lVar2 == 0) {
    return 0x10;
  }
  iVar1 = 0x10;
  if ((0x333aff < (int)*(uint *)(lVar2 + 0x18)) && (99 < (*(uint *)(lVar2 + 0x18) & 0xfc))) {
    if (0x2d < *(uint *)(lVar2 + 0x38)) {
      return 0x10;
    }
    if (*(code **)(lVar2 + 0x40) != (code *)0x0) {
      iVar1 = (**(code **)(lVar2 + 0x40))(param_1);
      return iVar1 + 0x10;
    }
    iVar1 = *(uint *)(lVar2 + 0x38) + 0x10;
  }
  return iVar1;
}


