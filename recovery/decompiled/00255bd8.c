/* Decompiled from supplied 5.2.2 arm package. VA 0x255bd8. FUN_00255bd8 */

undefined8 FUN_00255bd8(uint param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if ((-1 < (int)param_1) && (param_1 < 0x24)) {
    uVar1 = *(undefined8 *)
             ((long)&PTR_s_FL_010639f8 +
             (-(ulong)(param_1 >> 0x1f) & 0xfffffff000000000 | (ulong)param_1 << 4));
  }
  return uVar1;
}


