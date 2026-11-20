/* Decompiled from supplied 5.2.2 arm package. VA 0x1944a4. setVideoDuration: */

/* Function Stack Size: 0x18 bytes */

void SBSegment::setVideoDuration_(ID param_1,SEL param_2,double param_3)

{
  *(double *)(param_1 + 0x40) = param_3;
  CallSupervisor(0xb16f);
  return;
}


