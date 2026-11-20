/* Decompiled from supplied 5.2.2 arm package. VA 0x271efc. FUN_00271efc */

void FUN_00271efc(void)

{
  undefined8 *puVar1;
  double dVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  undefined8 uVar6;
  
  dVar2 = DAT_00c51e88;
  lVar3 = 0x3ff8;
  lVar4 = 8;
  for (lVar5 = 0; lVar5 != 0x401; lVar5 = lVar5 + 1) {
    uVar6 = _cos((double)(int)lVar5 * dVar2);
    (&_ff_cos_4096_double)[lVar5] = uVar6;
  }
  for (; lVar3 != 0x2000; lVar3 = lVar3 + -8) {
    puVar1 = (undefined8 *)((long)&_ff_cos_4096_double + lVar4);
    lVar4 = lVar4 + 8;
    *(undefined8 *)((long)&_ff_cos_4096_double + lVar3) = *puVar1;
  }
  return;
}


