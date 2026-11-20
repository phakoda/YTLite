/* Decompiled from supplied 5.2.2 arm package. VA 0x24f6d4. FUN_0024f6d4 */

void FUN_0024f6d4(long *param_1,void *param_2,ulong param_3,code *UNRECOVERED_JUMPTABLE,int param_5)

{
  ulong uVar1;
  long lVar2;
  void *pvVar3;
  byte bVar4;
  int iVar5;
  size_t sVar6;
  long lVar7;
  
  iVar5 = (int)param_1[1];
  uVar1 = param_3 + 7;
  if (-1 < (long)param_3) {
    uVar1 = param_3;
  }
  lVar7 = (long)iVar5 + param_3;
  lVar2 = lVar7 + 7;
  if (-1 < lVar7) {
    lVar2 = lVar7;
  }
  lVar7 = *param_1 + (lVar2 >> 3);
  if (lVar7 < param_1[4]) {
LAB_0024f76c:
    sVar6 = (long)uVar1 >> 3;
    if (iVar5 == 0) {
      _memmove((void *)param_1[3],param_2,sVar6);
      lVar7 = param_1[3];
      param_1[3] = lVar7 + sVar6;
      *param_1 = *param_1 + sVar6;
      *(undefined1 *)(lVar7 + sVar6) = 0;
    }
    else {
      for (lVar7 = 0; lVar7 < (long)sVar6; lVar7 = lVar7 + 1) {
        (*UNRECOVERED_JUMPTABLE)(param_1,*(undefined1 *)((long)param_2 + lVar7),8);
      }
    }
    if ((uVar1 & 0xfffffffffffffff8) != param_3) {
      bVar4 = *(byte *)((long)param_2 + sVar6);
      if (param_5 != 0) {
        bVar4 = bVar4 >> (ulong)(8U - (int)((long)param_3 % 8) & 0x1f);
      }
                    /* WARNING: Could not recover jumptable at 0x0024f850. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE)(param_1,bVar4);
      return;
    }
    return;
  }
  if ((param_1[3] != 0) && (sVar6 = lVar7 + 0x100, param_1[4] <= (long)sVar6)) {
    param_1[4] = sVar6;
    pvVar3 = _realloc((void *)param_1[2],sVar6);
    if (pvVar3 != (void *)0x0) {
      iVar5 = (int)param_1[1];
      param_1[2] = (long)pvVar3;
      param_1[3] = (long)pvVar3 + *param_1;
      goto LAB_0024f76c;
    }
  }
  _oggpack_writeclear(param_1);
  return;
}


