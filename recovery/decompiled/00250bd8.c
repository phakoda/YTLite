/* Decompiled from supplied 5.2.2 arm package. VA 0x250bd8. FUN_00250bd8 */

uint FUN_00250bd8(long param_1,int param_2,int param_3,int param_4,int param_5)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = *(uint *)(param_1 + (long)param_3 * 4);
  uVar2 = *(uint *)(param_1 + (long)param_4 * 4);
  uVar3 = *(uint *)(param_1 + (long)param_5 * 4);
  return *(uint *)(param_1 + (long)param_2 * 4) ^ (uVar1 >> 0x18 | uVar1 << 8) ^
         (uVar2 >> 0x10 | uVar2 << 0x10) ^ (uVar3 >> 8 | uVar3 << 0x18);
}


