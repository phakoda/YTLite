/* Decompiled from supplied 5.2.2 arm package. VA 0x262bb8. _av_opt_find2 */

/* WARNING: Type propagation algorithm not settling */

undefined8 *
_av_opt_find2(long *param_1,char *param_2,char *param_3,uint param_4,uint param_5,long *param_6)

{
  bool bVar1;
  int iVar2;
  undefined8 *puVar3;
  long lVar4;
  long local_60 [2];
  
  if ((param_1 == (long *)0x0) || (lVar4 = *param_1, lVar4 == 0)) {
LAB_00262cf4:
    puVar3 = (undefined8 *)0x0;
  }
  else if ((param_5 & 1) == 0) {
LAB_00262c80:
    puVar3 = (undefined8 *)0x0;
    do {
      while( true ) {
        do {
          puVar3 = (undefined8 *)_av_opt_next(param_1,puVar3);
          if (puVar3 == (undefined8 *)0x0) goto LAB_00262cf4;
          iVar2 = _strcmp((char *)*puVar3,param_2);
        } while ((iVar2 != 0) || ((*(uint *)(puVar3 + 6) & param_4) != param_4));
        bVar1 = *(int *)((long)puVar3 + 0x14) == 10;
        if (param_3 == (char *)0x0) break;
        if (((bVar1) && ((char *)puVar3[7] != (char *)0x0)) &&
           (iVar2 = _strcmp((char *)puVar3[7],param_3), iVar2 == 0)) goto LAB_00262ce4;
      }
    } while (bVar1);
LAB_00262ce4:
    if (param_6 != (long *)0x0) {
      if ((param_5 >> 1 & 1) == 0) {
        *param_6 = (long)param_1;
      }
      else {
        *param_6 = 0;
      }
    }
  }
  else if ((param_5 >> 1 & 1) == 0) {
    lVar4 = 0;
    do {
      lVar4 = _av_opt_child_next(param_1,lVar4);
      if (lVar4 == 0) goto LAB_00262c80;
      puVar3 = (undefined8 *)_av_opt_find2(lVar4,param_2,param_3,param_4,param_5,param_6);
    } while (puVar3 == (undefined8 *)0x0);
  }
  else {
    local_60[1] = 0;
    do {
      local_60[0] = _av_opt_child_class_iterate(lVar4,local_60 + 1);
      if (local_60[0] == 0) goto LAB_00262c80;
      puVar3 = (undefined8 *)_av_opt_find2(local_60,param_2,param_3,param_4,param_5,0);
    } while (puVar3 == (undefined8 *)0x0);
  }
  return puVar3;
}


