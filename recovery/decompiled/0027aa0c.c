/* Decompiled from supplied 5.2.2 arm package. VA 0x27aa0c. FUN_0027aa0c */

void FUN_0027aa0c(void)

{
  undefined4 *puVar1;
  double dVar2;
  double dVar3;
  undefined4 uVar4;
  long lVar5;
  long lVar6;
  char *pcVar7;
  double dVar8;
  
  dVar3 = DAT_00c51f00;
  dVar2 = DAT_00c51e98;
  lVar5 = 0x7ffc;
  lVar6 = 4;
  for (pcVar7 = (char *)0x0; pcVar7 != "ramework/AudioToolbox"; pcVar7 = pcVar7 + 1) {
    dVar8 = (double)_cos((double)(int)pcVar7 * dVar2);
    uVar4 = _lrintf((float)(dVar8 * dVar3));
    (&_ff_cos_16384_int32)[(long)pcVar7] = uVar4;
  }
  for (; lVar5 != 0x4000; lVar5 = lVar5 + -4) {
    puVar1 = (undefined4 *)((long)&_ff_cos_16384_int32 + lVar6);
    lVar6 = lVar6 + 4;
    *(undefined4 *)((long)&_ff_cos_16384_int32 + lVar5) = *puVar1;
  }
  return;
}


