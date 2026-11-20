/* Decompiled from supplied 5.2.2 arm package. VA 0x257d08. _av_encryption_init_info_alloc */

long * _av_encryption_init_info_alloc(int param_1,uint param_2,int param_3,int param_4)

{
  ulong uVar1;
  long *plVar2;
  long lVar3;
  undefined8 uVar4;
  uint uVar5;
  
  plVar2 = (long *)_av_mallocz(0x38);
  if (plVar2 != (long *)0x0) {
    lVar3 = _av_mallocz(param_1);
    *plVar2 = lVar3;
    *(int *)(plVar2 + 1) = param_1;
    if (param_3 == 0) {
      lVar3 = 0;
    }
    else {
      lVar3 = _av_mallocz_array(param_2,8);
    }
    plVar2[2] = lVar3;
    *(uint *)(plVar2 + 3) = param_2;
    *(int *)((long)plVar2 + 0x1c) = param_3;
    lVar3 = _av_mallocz(param_4);
    plVar2[4] = lVar3;
    *(int *)(plVar2 + 5) = param_4;
    if ((((param_1 == 0) || (*plVar2 != 0)) && ((param_4 == 0 || (lVar3 != 0)))) &&
       (((param_3 == 0 || (param_2 == 0)) || (plVar2[2] != 0)))) {
      if (param_3 == 0) {
        return plVar2;
      }
      uVar5 = 0;
      do {
        if (param_2 <= uVar5) {
          return plVar2;
        }
        uVar4 = _av_mallocz(param_3);
        *(undefined8 *)(plVar2[2] + (ulong)uVar5 * 8) = uVar4;
        uVar1 = (ulong)uVar5;
        uVar5 = uVar5 + 1;
      } while (*(long *)(plVar2[2] + uVar1 * 8) != 0);
    }
    _av_encryption_init_info_free(plVar2);
  }
  return (long *)0x0;
}


