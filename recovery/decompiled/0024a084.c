/* Decompiled from supplied 5.2.2 arm package. VA 0x24a084. FUN_0024a084 */

void FUN_0024a084(long param_1)

{
  ushort uVar1;
  short sVar2;
  long lVar3;
  
  lVar3 = 0;
  do {
    if (lVar3 == 4) {
      return;
    }
    uVar1 = *(ushort *)(param_1 + 8 + lVar3);
    if (uVar1 - 0x2c < 0x40) {
      sVar2 = 0x40;
LAB_0024a0c4:
      *(ushort *)(param_1 + 8 + lVar3) = uVar1 + sVar2;
    }
    else if (uVar1 - 0x6c < 0x14) {
      sVar2 = 0x80;
      goto LAB_0024a0c4;
    }
    lVar3 = lVar3 + 2;
  } while( true );
}


