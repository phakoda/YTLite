/* Decompiled from supplied 5.2.2 arm package. VA 0x2658bc. _av_opt_set_from_string */

int _av_opt_set_from_string
              (undefined8 param_1,char *param_2,long *param_3,undefined8 param_4,undefined8 param_5)

{
  void *pvVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  long *plVar6;
  long *plVar7;
  void *pvVar8;
  void *local_c8;
  void *local_c0;
  long local_b8;
  char *local_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar5 = *(long *)PTR____stack_chk_guard_01060708;
  local_68 = lVar5;
  local_b8 = 0;
  local_b0 = param_2;
  iVar3 = 0;
  if (param_2 != (char *)0x0) {
    plVar6 = &local_b8;
    iVar4 = iVar3;
    if (param_3 != (long *)0x0) {
      plVar6 = param_3;
    }
    while (iVar3 = iVar4, *param_2 != '\0') {
      iVar3 = _av_opt_get_key_value(&local_b0,param_4,param_5,*plVar6 != 0,&local_c0,&local_c8);
      pvVar2 = local_c0;
      pvVar1 = local_c8;
      if (iVar3 < 0) {
        lVar5 = *(long *)PTR____stack_chk_guard_01060708;
        if (iVar3 == -0x16) {
          _av_log(param_1,0x10,"No option name near \'%s\'\n");
          iVar3 = -0x16;
        }
        else {
          local_78 = 0;
          uStack_70 = 0;
          local_88 = 0;
          uStack_80 = 0;
          local_98 = 0;
          uStack_90 = 0;
          local_a8 = 0;
          uStack_a0 = 0;
          _av_strerror(iVar3,&local_a8,0x40);
          _av_log(param_1,0x10,"Unable to parse \'%s\': %s\n");
        }
        goto LAB_00265a90;
      }
      if (*local_b0 != '\0') {
        local_b0 = local_b0 + 1;
      }
      param_2 = local_b0;
      if (local_c0 == (void *)0x0) {
        plVar7 = plVar6 + 1;
        pvVar8 = (void *)*plVar6;
      }
      else {
        plVar7 = plVar6 + -1;
        do {
          plVar7 = plVar7 + 1;
          pvVar8 = local_c0;
        } while (*plVar7 != 0);
      }
      _av_log(param_1,0x30,"Setting \'%s\' to value \'%s\'\n");
      iVar3 = _av_opt_set(param_1,pvVar8,pvVar1,0);
      if (iVar3 < 0) {
        if (iVar3 == -0x54504ff8) {
          _av_log(param_1,0x10,"Option \'%s\' not found\n");
        }
        _av_free(pvVar1);
        _av_free(pvVar2);
        break;
      }
      _av_free(pvVar1);
      _av_free(pvVar2);
      plVar6 = plVar7;
      iVar4 = iVar4 + 1;
    }
    lVar5 = *(long *)PTR____stack_chk_guard_01060708;
  }
LAB_00265a90:
  if (lVar5 != local_68) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  return iVar3;
}


