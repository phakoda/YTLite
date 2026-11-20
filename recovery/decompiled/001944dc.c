/* Decompiled from supplied 5.2.2 arm package. VA 0x1944dc. setVotes: */

/* Function Stack Size: 0x18 bytes */

void SBSegment::setVotes_(ID param_1,SEL param_2,long_long param_3)

{
  *(long_long *)(param_1 + 0x48) = param_3;
  CallSupervisor(0x8cc1);
  return;
}


