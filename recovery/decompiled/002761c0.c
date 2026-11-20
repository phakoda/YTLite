/* Decompiled from supplied 5.2.2 arm package. VA 0x2761c0. FUN_002761c0 */

void FUN_002761c0(void)

{
  undefined4 *puVar1;
  double dVar2;
  long lVar3;
  long lVar4;
  undefined *puVar5;
  double dVar6;
  
  dVar2 = DAT_00c51ea8;
  lVar3 = 0x1fffc;
  lVar4 = 4;
  for (puVar5 = (undefined *)0x0; puVar5 != &UNK_00004001; puVar5 = puVar5 + 1) {
    dVar6 = (double)_cos((double)(int)puVar5 * dVar2);
    (&_ff_cos_65536_float)[(long)puVar5] = (float)dVar6;
  }
  for (; lVar3 != 0x10000; lVar3 = lVar3 + -4) {
    puVar1 = (undefined4 *)((long)&_ff_cos_65536_float + lVar4);
    lVar4 = lVar4 + 4;
    *(undefined4 *)((long)&_ff_cos_65536_float + lVar3) = *puVar1;
  }
  return;
}


