/* Decompiled from supplied 5.2.2 arm package. VA 0x24f504. _oggpackB_write */

void _oggpackB_write(long *param_1,ulong param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  void *pvVar4;
  ulong uVar5;
  byte *pbVar6;
  
  if (param_3 < 0x21) {
    pbVar6 = (byte *)param_1[3];
    lVar3 = param_1[4];
    if (lVar3 + -4 <= *param_1) {
      if (pbVar6 == (byte *)0x0) {
        return;
      }
      if ((0x7ffffffffffffeff < lVar3) ||
         (pvVar4 = _realloc((void *)param_1[2],lVar3 + 0x100), pvVar4 == (void *)0x0))
      goto LAB_0024f628;
      pbVar6 = (byte *)((long)pvVar4 + *param_1);
      param_1[4] = param_1[4] + 0x100;
      param_1[2] = (long)pvVar4;
      param_1[3] = (long)pbVar6;
    }
    uVar1 = (int)param_1[1] + param_3;
    uVar5 = (*(ulong *)(&DAT_00c50150 + (long)(int)param_3 * 8) & param_2) <<
            ((ulong)(0x20 - param_3) & 0x3f);
    *pbVar6 = *pbVar6 | (byte)(uVar5 >> ((ulong)((int)param_1[1] + 0x18) & 0x3f));
    if ((((7 < (int)uVar1) &&
         (*(char *)(param_1[3] + 1) = (char)(uVar5 >> ((ulong)((int)param_1[1] + 0x10) & 0x3f)),
         0xf < (int)uVar1)) &&
        (*(char *)(param_1[3] + 2) = (char)(uVar5 >> ((ulong)((int)param_1[1] + 8) & 0x3f)),
        0x17 < (int)uVar1)) &&
       (*(char *)(param_1[3] + 3) = (char)(uVar5 >> ((ulong)*(uint *)(param_1 + 1) & 0x3f)),
       0x1f < (int)uVar1)) {
      if ((int)param_1[1] == 0) {
        *(undefined1 *)(param_1[3] + 4) = 0;
      }
      else {
        *(char *)(param_1[3] + 4) = (char)(uVar5 << ((ulong)(8 - (int)param_1[1]) & 0x3f));
      }
    }
    uVar2 = uVar1 + 7;
    if (-1 < (int)uVar1) {
      uVar2 = uVar1;
    }
    *param_1 = *param_1 + (long)((int)uVar2 >> 3);
    param_1[3] = param_1[3] + (long)((int)uVar2 >> 3);
    *(uint *)(param_1 + 1) = uVar1 & 7;
    return;
  }
LAB_0024f628:
  _oggpack_writeclear(param_1);
  return;
}


