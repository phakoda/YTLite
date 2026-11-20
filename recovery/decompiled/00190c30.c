/* Decompiled from supplied 5.2.2 arm package. VA 0x190c30. setReloadsCell: */

/* Function Stack Size: 0x14 bytes */

void DVNCell::setReloadsCell_(ID param_1,SEL param_2,bool param_3)

{
  *(char *)(param_1 + 8) = (char)param_3;
  CallSupervisor(0xa540);
  return;
}


