/* Decompiled from supplied 5.2.2 arm package. VA 0x256bc4. FUN_00256bc4 */

void FUN_00256bc4(long param_1,ulong *param_2,ulong *param_3,int param_4,ulong *param_5,int param_6,
                 int param_7)

{
  int iVar1;
  undefined8 uVar2;
  ulong uVar3;
  ulong *puVar4;
  ulong uVar5;
  ulong uVar6;
  
  if (param_5 == (ulong *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = (*param_5 & 0xff00ff00ff00ff00) >> 8 | (*param_5 & 0xff00ff00ff00ff) << 8;
    uVar5 = (uVar5 & 0xffff0000ffff0000) >> 0x10 | (uVar5 & 0xffff0000ffff) << 0x10;
    uVar5 = uVar5 >> 0x20 | uVar5 << 0x20;
  }
  while (puVar4 = param_2, iVar1 = param_4 + -1, 0 < param_4) {
    if (param_3 == (ulong *)0x0) {
      uVar6 = 0;
    }
    else {
      uVar6 = (*param_3 & 0xff00ff00ff00ff00) >> 8 | (*param_3 & 0xff00ff00ff00ff) << 8;
      uVar6 = (uVar6 & 0xffff0000ffff0000) >> 0x10 | (uVar6 & 0xffff0000ffff) << 0x10;
      uVar6 = uVar6 >> 0x20 | uVar6 << 0x20;
    }
    if (param_6 == 0) {
      uVar3 = FUN_00256d6c(uVar6 ^ uVar5,param_1,0);
      uVar5 = uVar3;
      if (*(int *)(param_1 + 0x180) != 0) {
        uVar2 = FUN_00256d6c(uVar3,param_1 + 0x80,1);
        uVar3 = FUN_00256d6c(uVar2,param_1 + 0x100,0);
        uVar5 = uVar3;
      }
    }
    else {
      uVar3 = uVar6;
      if (*(int *)(param_1 + 0x180) != 0) {
        uVar2 = FUN_00256d6c(uVar6,param_1 + 0x100,1);
        uVar3 = FUN_00256d6c(uVar2,param_1 + 0x80,0);
      }
      uVar3 = FUN_00256d6c(uVar3,param_1,1);
      uVar3 = uVar3 ^ uVar5;
      uVar5 = uVar6;
    }
    uVar6 = (uVar3 & 0xff00ff00ff00ff00) >> 8 | (uVar3 & 0xff00ff00ff00ff) << 8;
    uVar6 = (uVar6 & 0xffff0000ffff0000) >> 0x10 | (uVar6 & 0xffff0000ffff) << 0x10;
    param_3 = param_3 + 1;
    if (param_5 == (ulong *)0x0) {
      uVar5 = 0;
    }
    *puVar4 = uVar6 >> 0x20 | uVar6 << 0x20;
    param_2 = puVar4 + 1;
    param_4 = iVar1;
    if (param_7 != 0) {
      param_2 = puVar4;
    }
  }
  if (param_5 != (ulong *)0x0) {
    uVar5 = (uVar5 & 0xff00ff00ff00ff00) >> 8 | (uVar5 & 0xff00ff00ff00ff) << 8;
    uVar5 = (uVar5 & 0xffff0000ffff0000) >> 0x10 | (uVar5 & 0xffff0000ffff) << 0x10;
    *param_5 = uVar5 >> 0x20 | uVar5 << 0x20;
  }
  return;
}


