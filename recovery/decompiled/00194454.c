/* Decompiled from supplied 5.2.2 arm package. VA 0x194454. setStart: */

/* Function Stack Size: 0x18 bytes */

void SBSegment::setStart_(ID param_1,SEL param_2,double param_3)

{
  *(double *)(param_1 + 0x30) = param_3;
  CallSupervisor(0x199f);
  return;
}


