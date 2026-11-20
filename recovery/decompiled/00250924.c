/* Decompiled from supplied 5.2.2 arm package. VA 0x250924. FUN_00250924 */

void FUN_00250924(long param_1,int *param_2,long param_3,long param_4,long param_5)

{
  long lVar1;
  ulong uVar2;
  
  for (lVar1 = 0; lVar1 != 0x100; lVar1 = lVar1 + 1) {
    if ((ulong)*(byte *)(param_5 + lVar1) != 0) {
      uVar2 = (ulong)*(byte *)(param_3 + (ulong)*(byte *)(param_5 + lVar1));
      *(uint *)(param_1 + lVar1 * 4) =
           CONCAT13(*(undefined1 *)(param_4 + *(byte *)(param_3 + param_2[3]) + uVar2),
                    CONCAT12(*(undefined1 *)(param_4 + *(byte *)(param_3 + param_2[2]) + uVar2),
                             CONCAT11(*(undefined1 *)
                                       (param_4 + *(byte *)(param_3 + param_2[1]) + uVar2),
                                      *(undefined1 *)
                                       (param_4 + *(byte *)(param_3 + *param_2) + uVar2))));
    }
  }
  return;
}


