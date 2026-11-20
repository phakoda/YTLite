/* Decompiled from supplied 5.2.2 arm package. VA 0x1ca308. setIsFullscreen: */

/* Function Stack Size: 0x14 bytes */

void ToastManager::setIsFullscreen_(ID param_1,SEL param_2,bool param_3)

{
  *(char *)(param_1 + 9) = (char)param_3;
  CallSupervisor(0x2c29);
  return;
}


