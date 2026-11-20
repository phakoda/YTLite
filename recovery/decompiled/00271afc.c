/* Decompiled from supplied 5.2.2 arm package. VA 0x271afc. FUN_00271afc */

void FUN_00271afc(void)

{
  double dVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  undefined8 uVar5;
  
  dVar1 = DAT_00c51e48;
  lVar2 = 0x38;
  lVar3 = 8;
  for (lVar4 = 0; lVar4 != 5; lVar4 = lVar4 + 1) {
    uVar5 = _cos((double)(int)lVar4 * dVar1);
    (&_ff_cos_16_double)[lVar4] = uVar5;
  }
  for (; lVar3 != 0x20; lVar3 = lVar3 + 8) {
    *(undefined8 *)((long)&_ff_cos_16_double + lVar2) =
         *(undefined8 *)((long)&_ff_cos_16_double + lVar3);
    lVar2 = lVar2 + -8;
  }
  return;
}


