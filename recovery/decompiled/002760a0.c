/* Decompiled from supplied 5.2.2 arm package. VA 0x2760a0. FUN_002760a0 */

void FUN_002760a0(void)

{
  undefined4 *puVar1;
  double dVar2;
  long lVar3;
  long lVar4;
  char *pcVar5;
  double dVar6;
  
  dVar2 = DAT_00c51e98;
  lVar3 = 0x7ffc;
  lVar4 = 4;
  for (pcVar5 = (char *)0x0; pcVar5 != "ramework/AudioToolbox"; pcVar5 = pcVar5 + 1) {
    dVar6 = (double)_cos((double)(int)pcVar5 * dVar2);
    (&_ff_cos_16384_float)[(long)pcVar5] = (float)dVar6;
  }
  for (; lVar3 != 0x4000; lVar3 = lVar3 + -4) {
    puVar1 = (undefined4 *)((long)&_ff_cos_16384_float + lVar4);
    lVar4 = lVar4 + 4;
    *(undefined4 *)((long)&_ff_cos_16384_float + lVar3) = *puVar1;
  }
  return;
}


