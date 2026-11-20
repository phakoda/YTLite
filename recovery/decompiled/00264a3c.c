/* Decompiled from supplied 5.2.2 arm package. VA 0x264a3c. FUN_00264a3c */

void FUN_00264a3c(undefined8 param_1,undefined8 param_2,char *param_3,uint param_4,uint param_5,
                 int param_6)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  char *pcVar4;
  long lVar5;
  ulong uVar6;
  undefined8 *puVar7;
  long *plVar8;
  long local_278;
  long *local_270;
  char local_268 [512];
  long local_68;
  
  puVar7 = (undefined8 *)0x0;
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
LAB_00264ab4:
  do {
    do {
      puVar7 = (undefined8 *)_av_opt_next(param_1,puVar7);
      if (puVar7 == (undefined8 *)0x0) {
        if (*(long *)PTR____stack_chk_guard_01060708 != local_68) {
                    /* WARNING: Subroutine does not return */
          ___stack_chk_fail();
        }
        return;
      }
    } while (((*(uint *)(puVar7 + 6) & param_4) == 0) || ((*(uint *)(puVar7 + 6) & param_5) != 0));
    bVar2 = *(int *)((long)puVar7 + 0x14) == 10;
    if (param_3 == (char *)0x0) goto LAB_00264b18;
  } while ((!bVar2) || (iVar3 = _strcmp(param_3,(char *)puVar7[7]), iVar3 != 0));
  pcVar4 = "     %-15s ";
  goto LAB_00264b4c;
LAB_00264b18:
  if (bVar2) goto LAB_00264ab4;
  pcVar4 = "  %s%-17s ";
LAB_00264b4c:
  _av_log(param_2,0x20,pcVar4);
  switch(*(undefined4 *)((long)puVar7 + 0x14)) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  case 5:
    break;
  case 6:
    break;
  case 7:
    break;
  case 8:
    break;
  case 9:
    break;
  case 10:
    if (param_6 != 1) break;
    pcVar4 = "%-12lld ";
    goto LAB_00264cd0;
  case 0xb:
    break;
  case 0xc:
    break;
  case 0xd:
    break;
  case 0xe:
    break;
  case 0xf:
    break;
  case 0x10:
    break;
  case 0x11:
    break;
  case 0x12:
  }
  pcVar4 = "%-12s ";
LAB_00264cd0:
  _av_log(param_2,0x20,pcVar4);
  _av_log(param_2,0x20,"%c");
  _av_log(param_2,0x20,"%c");
  _av_log(param_2,0x20,"%c");
  _av_log(param_2,0x20,"%c");
  _av_log(param_2,0x20,"%c");
  _av_log(param_2,0x20,"%c");
  _av_log(param_2,0x20,"%c");
  _av_log(param_2,0x20,"%c");
  _av_log(param_2,0x20,"%c");
  _av_log(param_2,0x20,"%c");
  if (puVar7[1] != 0) {
    _av_log(param_2,0x20," %s");
  }
  iVar3 = _av_opt_query_ranges(&local_270,param_1,*puVar7,2);
  if (-1 < iVar3) {
    uVar1 = *(int *)((long)puVar7 + 0x14) - 1;
    if ((uVar1 < 9) && ((0x12fU >> (ulong)(uVar1 & 0x1f) & 1) != 0)) {
      for (lVar5 = 0; lVar5 < (int)local_270[1]; lVar5 = lVar5 + 1) {
        _av_log(param_2,0x20," (from ");
        FUN_00266aa0(*(undefined8 *)(*(long *)(*local_270 + lVar5 * 8) + 8),param_2);
        _av_log(param_2,0x20," to ");
        FUN_00266aa0(*(undefined8 *)(*(long *)(*local_270 + lVar5 * 8) + 0x10),param_2);
        _av_log(param_2,0x20,")");
      }
    }
    _av_opt_freep_ranges(&local_270);
  }
  if (*(uint *)((long)puVar7 + 0x14) < 0x11) {
    uVar1 = 1 << (ulong)(*(uint *)((long)puVar7 + 0x14) & 0x1f);
    if ((uVar1 & 0x14920) == 0) {
      if ((uVar1 & 0x480) != 0) goto LAB_002652e8;
    }
    else if (puVar7[3] == 0) goto LAB_002652e8;
  }
  _av_log(param_2,0x20," (default ");
  switch(*(undefined4 *)((long)puVar7 + 0x14)) {
  case 0:
    pcVar4 = (char *)puVar7[7];
    uVar6 = puVar7[3];
    local_268[0] = '\0';
    if (pcVar4 == (char *)0x0) {
LAB_00265258:
      local_278 = 0;
    }
    else {
      lVar5 = 0;
      while (lVar5 = _av_opt_next(param_1,lVar5), lVar5 != 0) {
        if (((*(int *)(lVar5 + 0x14) == 10) &&
            (iVar3 = _strcmp(*(char **)(lVar5 + 0x38),pcVar4), iVar3 == 0)) &&
           ((*(ulong *)(lVar5 + 0x18) & uVar6) != 0)) {
          if (local_268[0] != '\0') {
            _av_strlcatf(local_268,0x200,"+");
          }
          _av_strlcatf(local_268,0x200,"%s");
        }
      }
      if (local_268[0] == '\0') goto LAB_00265258;
      local_278 = _av_strdup(local_268);
      if (local_278 != 0) {
        _av_log(param_2,0x20,"%s");
        _av_freep(&local_278);
        goto switchD_00264f90_caseD_7;
      }
    }
    pcVar4 = "%llX";
    break;
  case 1:
  case 2:
  case 9:
    pcVar4 = (char *)puVar7[7];
    lVar5 = puVar7[3];
    if (pcVar4 != (char *)0x0) {
      plVar8 = (long *)0x0;
      do {
        plVar8 = (long *)_av_opt_next(param_1,plVar8);
        if (plVar8 == (long *)0x0) goto LAB_00265028;
      } while (((*(int *)((long)plVar8 + 0x14) != 10) ||
               (iVar3 = _strcmp((char *)plVar8[7],pcVar4), iVar3 != 0)) || (plVar8[3] != lVar5));
      if (*plVar8 != 0) {
        _av_log(param_2,0x20,"%s");
        goto switchD_00264f90_caseD_7;
      }
    }
LAB_00265028:
    if (lVar5 < 0x7fffffff) {
      if (lVar5 == -0x8000000000000000) {
        pcVar4 = "I64_MIN";
      }
      else if (lVar5 == -0x80000000) {
        pcVar4 = "INT_MIN";
      }
      else {
LAB_002652b8:
        pcVar4 = "%lld";
      }
    }
    else if (lVar5 == 0x7fffffffffffffff) {
      pcVar4 = "I64_MAX";
    }
    else if (lVar5 == 0xffffffff) {
      pcVar4 = "UINT32_MAX";
    }
    else {
      if (lVar5 != 0x7fffffff) goto LAB_002652b8;
      pcVar4 = "INT_MAX";
    }
    _av_log(param_2,0x20,pcVar4);
    goto switchD_00264f90_caseD_7;
  case 3:
  case 4:
    FUN_00266aa0(puVar7[3],param_2);
    goto switchD_00264f90_caseD_7;
  case 5:
  case 8:
  case 0xb:
  case 0xe:
  case 0x10:
    pcVar4 = "\"%s\"";
    break;
  case 6:
    _av_d2q(puVar7[3],0x7fffffff);
    pcVar4 = "%d/%d";
    break;
  default:
    goto switchD_00264f90_caseD_7;
  case 0xc:
    _av_get_pix_fmt_name(*(undefined4 *)(puVar7 + 3));
    goto LAB_002651fc;
  case 0xd:
    _av_get_sample_fmt_name(*(undefined4 *)(puVar7 + 3));
    goto LAB_002651fc;
  case 0xf:
    FUN_002641a8(local_268,0x19,puVar7[3]);
    goto LAB_002651fc;
  case 0x11:
    pcVar4 = "0x%llx";
    break;
  case 0x12:
LAB_002651fc:
    pcVar4 = "%s";
  }
  _av_log(param_2,0x20,pcVar4);
switchD_00264f90_caseD_7:
  _av_log(param_2,0x20,")");
LAB_002652e8:
  _av_log(param_2,0x20,"\n");
  if ((puVar7[7] != 0) && (*(int *)((long)puVar7 + 0x14) != 10)) {
    FUN_00264a3c(param_1,param_2,puVar7[7],param_4,param_5);
  }
  goto LAB_00264ab4;
}


