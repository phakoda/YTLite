/* Decompiled from supplied 5.2.2 arm package. VA 0x271b7c. FUN_00271b7c */

void FUN_00271b7c(void)

{
  undefined8 *puVar1;
  double dVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  undefined8 uVar6;
  
  dVar2 = DAT_00c51e50;
  lVar3 = 0x78;
  lVar4 = 8;
  for (lVar5 = 0; lVar5 != 9; lVar5 = lVar5 + 1) {
    uVar6 = _cos((double)(int)lVar5 * dVar2);
    (&_ff_cos_32_double)[lVar5] = uVar6;
  }
  for (; lVar3 != 0x40; lVar3 = lVar3 + -8) {
    puVar1 = (undefined8 *)((long)&_ff_cos_32_double + lVar4);
    lVar4 = lVar4 + 8;
    *(undefined8 *)((long)&_ff_cos_32_double + lVar3) = *puVar1;
  }
  return;
}


