/* Decompiled from supplied 5.2.2 arm package. VA 0x275b78. FUN_00275b78 */

void FUN_00275b78(void)

{
  undefined4 *puVar1;
  double dVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  double dVar6;
  
  dVar2 = DAT_00c51e48;
  lVar3 = 0x1c;
  lVar4 = 4;
  for (lVar5 = 0; lVar5 != 5; lVar5 = lVar5 + 1) {
    dVar6 = (double)_cos((double)(int)lVar5 * dVar2);
    (&_ff_cos_16_float)[lVar5] = (float)dVar6;
  }
  for (; lVar3 != 0x10; lVar3 = lVar3 + -4) {
    puVar1 = (undefined4 *)((long)&_ff_cos_16_float + lVar4);
    lVar4 = lVar4 + 4;
    *(undefined4 *)((long)&_ff_cos_16_float + lVar3) = *puVar1;
  }
  return;
}


