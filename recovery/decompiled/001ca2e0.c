/* Decompiled from supplied 5.2.2 arm package. VA 0x1ca2e0. setIsPinnedTop: */

/* Function Stack Size: 0x14 bytes */

void ToastManager::setIsPinnedTop_(ID param_1,SEL param_2,bool param_3)

{
  *(char *)(param_1 + 8) = (char)param_3;
  CallSupervisor(0xf856);
  return;
}


