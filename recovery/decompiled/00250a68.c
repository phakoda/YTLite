/* Decompiled from supplied 5.2.2 arm package. VA 0x250a68. FUN_00250a68 */

void FUN_00250a68(undefined4 *param_1,undefined8 param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  puVar2 = param_1 + 4;
  uVar1 = FUN_00250bd8(param_2,*(undefined1 *)puVar2,
                       *(undefined1 *)((long)puVar2 + (long)param_3 * 4 + 1),
                       *(undefined1 *)((long)param_1 + 0x1a),
                       *(undefined1 *)((long)puVar2 + (long)param_4 * 4 + 3));
  *param_1 = uVar1;
  uVar1 = FUN_00250bd8(param_2,*(undefined1 *)(param_1 + 5),
                       *(undefined1 *)((long)puVar2 + (long)param_4 * 4 + -3),
                       *(undefined1 *)((long)param_1 + 0x1e),
                       *(undefined1 *)((long)puVar2 + (long)param_3 * 4 + -1));
  param_1[1] = uVar1;
  uVar1 = FUN_00250bd8(param_2,*(undefined1 *)(param_1 + 6),
                       *(undefined1 *)((long)puVar2 + (long)param_4 * 4 + 1),
                       *(undefined1 *)((long)param_1 + 0x12),
                       *(undefined1 *)((long)puVar2 + (long)param_3 * 4 + 3));
  param_1[2] = uVar1;
  uVar1 = FUN_00250bd8(param_2,*(undefined1 *)(param_1 + 7),
                       *(undefined1 *)((long)puVar2 + (long)param_3 * 4 + -3),
                       *(undefined1 *)((long)param_1 + 0x16),
                       *(undefined1 *)((long)puVar2 + (long)param_4 * 4 + -1));
  param_1[3] = uVar1;
  return;
}


