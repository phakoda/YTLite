/* Decompiled from supplied 5.2.2 arm package. VA 0x260e84. FUN_00260e84 */

void FUN_00260e84(long *param_1,int param_2)

{
  undefined4 *puVar1;
  long lVar2;
  undefined4 *puVar3;
  int iVar4;
  
  if (param_2 < 0) {
    _av_log(0,0,"Assertion %s failed at %s:%d\n");
                    /* WARNING: Subroutine does not return */
    _abort();
  }
  puVar1 = (undefined4 *)*param_1;
  puVar3 = (undefined4 *)param_1[3];
  lVar2 = param_1[1] - (long)puVar1;
  if (lVar2 < param_2) {
    param_2 = (int)lVar2;
    if (lVar2 < 1) {
      param_2 = 0;
    }
    *(uint *)(param_1 + 5) = *(uint *)(param_1 + 5) | 1;
  }
  lVar2 = param_1[4] - (long)puVar3;
  if (lVar2 < param_2) {
    *(uint *)(param_1 + 5) = *(uint *)(param_1 + 5) | 2;
    if (lVar2 < 1) {
      *puVar3 = *puVar1;
      iVar4 = -4;
      goto LAB_00260f2c;
    }
    param_2 = (int)lVar2;
  }
  iVar4 = param_2 + -4;
  *puVar3 = *puVar1;
  if (4 < param_2) {
    _memcpy(puVar3 + 1,puVar1 + 1,(long)iVar4);
  }
LAB_00260f2c:
  *param_1 = (long)puVar1 + (long)iVar4 + 4;
  param_1[3] = (long)puVar3 + (long)iVar4 + 4;
  return;
}


