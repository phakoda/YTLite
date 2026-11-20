/* Decompiled from supplied 5.2.2 arm package. VA 0x21afe8. setCurrentTime: */

/* Function Stack Size: 0x18 bytes */

void RPCMedia::setCurrentTime_(ID param_1,SEL param_2,double param_3)

{
  *(double *)(param_1 + 0x30) = param_3;
  CallSupervisor(0xc545);
  return;
}


