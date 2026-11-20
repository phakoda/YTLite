/* Decompiled from supplied 5.2.2 arm package. VA 0x271ffc. FUN_00271ffc */

void FUN_00271ffc(void)

{
  undefined8 *puVar1;
  double dVar2;
  long lVar3;
  long lVar4;
  char *pcVar5;
  undefined8 uVar6;
  
  dVar2 = DAT_00c51e98;
  lVar3 = 0xfff8;
  lVar4 = 8;
  for (pcVar5 = (char *)0x0; pcVar5 != "ramework/AudioToolbox"; pcVar5 = pcVar5 + 1) {
    uVar6 = _cos((double)(int)pcVar5 * dVar2);
    (&_ff_cos_16384_double)[(long)pcVar5] = uVar6;
  }
  for (; lVar3 != 0x8000; lVar3 = lVar3 + -8) {
    puVar1 = (undefined8 *)((long)&_ff_cos_16384_double + lVar4);
    lVar4 = lVar4 + 8;
    *(undefined8 *)((long)&_ff_cos_16384_double + lVar3) = *puVar1;
  }
  return;
}


