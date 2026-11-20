/* Decompiled from supplied 5.2.2 arm package. VA 0x271e7c. FUN_00271e7c */

void FUN_00271e7c(void)

{
  double dVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  undefined8 uVar5;
  
  dVar1 = DAT_00c51e80;
  lVar2 = 0x1ff8;
  lVar3 = 8;
  for (lVar4 = 0; lVar4 != 0x201; lVar4 = lVar4 + 1) {
    uVar5 = _cos((double)(int)lVar4 * dVar1);
    (&_ff_cos_2048_double)[lVar4] = uVar5;
  }
  for (; lVar3 != 0x1000; lVar3 = lVar3 + 8) {
    *(undefined8 *)((long)&_ff_cos_2048_double + lVar2) =
         *(undefined8 *)((long)&_ff_cos_2048_double + lVar3);
    lVar2 = lVar2 + -8;
  }
  return;
}


