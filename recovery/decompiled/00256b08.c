/* Decompiled from supplied 5.2.2 arm package. VA 0x256b08. FUN_00256b08 */

void FUN_00256b08(long param_1,undefined8 param_2)

{
  ulong uVar1;
  ulong uVar2;
  undefined8 uVar3;
  ulong uVar4;
  ulong uVar5;
  long lVar6;
  
  uVar2 = FUN_00256d3c(param_2,&DAT_00c506d8,0x38);
  for (lVar6 = 0; lVar6 != 0x10; lVar6 = lVar6 + 1) {
    uVar4 = uVar2 >> 0x1b & 0x10000001;
    uVar5 = (uVar2 & 0x7ffffffff7ffffff) << 1;
    uVar1 = uVar5 | uVar4;
    if ((1 < lVar6 && (int)lVar6 != 8) && (int)lVar6 != 0xf) {
      uVar1 = (uVar5 & 0x7ffffffff7ffffff | uVar4) << 1 | uVar2 >> 0x1a & 0x10000001;
    }
    uVar2 = uVar1;
    uVar3 = FUN_00256d3c(uVar2,&DAT_00c50710,0x30);
    *(undefined8 *)(param_1 + lVar6 * 8) = uVar3;
  }
  return;
}


