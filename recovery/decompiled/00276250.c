/* Decompiled from supplied 5.2.2 arm package. VA 0x276250. FUN_00276250 */

void FUN_00276250(void)

{
  undefined4 *puVar1;
  double dVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  double dVar6;
  
  dVar2 = DAT_00c51eb0;
  lVar3 = 0x3fffc;
  lVar4 = 4;
  for (lVar5 = 0; lVar5 != 0x8001; lVar5 = lVar5 + 1) {
    dVar6 = (double)_cos((double)(int)lVar5 * dVar2);
    (&_ff_cos_131072_float)[lVar5] = (float)dVar6;
  }
  for (; lVar3 != 0x20000; lVar3 = lVar3 + -4) {
    puVar1 = (undefined4 *)((long)&_ff_cos_131072_float + lVar4);
    lVar4 = lVar4 + 4;
    *(undefined4 *)((long)&_ff_cos_131072_float + lVar3) = *puVar1;
  }
  return;
}


