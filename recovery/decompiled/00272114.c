/* Decompiled from supplied 5.2.2 arm package. VA 0x272114. FUN_00272114 */

void FUN_00272114(void)

{
  undefined8 *puVar1;
  double dVar2;
  long lVar3;
  long lVar4;
  undefined *puVar5;
  undefined8 uVar6;
  
  dVar2 = DAT_00c51ea8;
  lVar3 = 0x3fff8;
  lVar4 = 8;
  for (puVar5 = (undefined *)0x0; puVar5 != &UNK_00004001; puVar5 = puVar5 + 1) {
    uVar6 = _cos((double)(int)puVar5 * dVar2);
    (&_ff_cos_65536_double)[(long)puVar5] = uVar6;
  }
  for (; lVar3 != 0x20000; lVar3 = lVar3 + -8) {
    puVar1 = (undefined8 *)((long)&_ff_cos_65536_double + lVar4);
    lVar4 = lVar4 + 8;
    *(undefined8 *)((long)&_ff_cos_65536_double + lVar3) = *puVar1;
  }
  return;
}


