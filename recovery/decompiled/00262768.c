/* Decompiled from supplied 5.2.2 arm package. VA 0x262768. _av_opt_next */

long * _av_opt_next(long *param_1,long param_2)

{
  long *plVar1;
  
  if (param_1 != (long *)0x0) {
    if (((param_2 == 0) && (*param_1 != 0)) &&
       (plVar1 = *(long **)(*param_1 + 0x10), plVar1 != (long *)0x0)) {
      if (*plVar1 == 0) {
        plVar1 = (long *)0x0;
      }
      return plVar1;
    }
    if (param_2 != 0) {
      plVar1 = (long *)0x0;
      if (*(long *)(param_2 + 0x40) != 0) {
        plVar1 = (long *)(param_2 + 0x40);
      }
      return plVar1;
    }
  }
  return (long *)0x0;
}


