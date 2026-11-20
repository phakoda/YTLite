/* Decompiled from supplied 5.2.2 arm package. VA 0x262e3c. FUN_00262e3c */

void FUN_00262e3c(undefined8 param_1,undefined8 param_2,long param_3,byte *param_4,
                 undefined8 param_5)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  ulong uVar8;
  undefined8 *puVar9;
  char *pcVar10;
  double dVar11;
  undefined8 *in_stack_fffffffffffffa48;
  ulong local_578;
  double local_570;
  undefined8 local_568 [64];
  double local_368 [64];
  byte local_168 [256];
  long local_68;
  
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  if ((*(uint *)(param_3 + 0x14) | 8) == 0xe) {
    in_stack_fffffffffffffa48 = local_568;
    iVar5 = _sscanf((char *)param_4,"%d%*1[:/]%d%c");
    if ((iVar5 == 2) &&
       (iVar5 = FUN_00263340(0x3ff0000000000000,param_1,param_3,param_5,(undefined4)local_568[0],
                             (long)local_368[0]._0_4_), -1 < iVar5)) goto LAB_0026321c;
  }
  do {
    local_578 = 1;
    if (*(int *)(param_3 + 0x14) == 0) {
      bVar2 = *param_4;
      if ((bVar2 == 0x2d) || (bVar2 == 0x2b)) {
        param_4 = param_4 + 1;
      }
      else {
        bVar2 = 0;
      }
      for (uVar8 = 0; uVar8 < 0xff; uVar8 = uVar8 + 1) {
        bVar3 = param_4[uVar8];
        if ((bVar3 < 0x2e) && ((1L << ((ulong)bVar3 & 0x3f) & 0x280000000001U) != 0)) break;
        local_168[uVar8] = bVar3;
      }
      local_168[uVar8] = 0;
    }
    else {
      uVar8 = 0;
      bVar2 = 0;
    }
    iVar5 = (int)uVar8;
    pbVar1 = local_168;
    if (iVar5 == 0) {
      pbVar1 = param_4;
    }
    lVar7 = _av_opt_find2(param_2,pbVar1,*(undefined8 *)(param_3 + 0x38),0,
                          *(uint *)(param_3 + 0x30) >> 0x12 & 1,0);
    if ((lVar7 == 0) || (*(int *)(lVar7 + 0x14) != 10)) {
      pcVar10 = *(char **)(param_3 + 0x38);
      if (pcVar10 == (char *)0x0) {
        lVar7 = 0;
      }
      else {
        puVar9 = (undefined8 *)0x0;
        lVar7 = 0;
        while (puVar9 = (undefined8 *)_av_opt_next(param_2,puVar9), puVar9 != (undefined8 *)0x0) {
          if (((*(int *)((long)puVar9 + 0x14) == 10) && ((char *)puVar9[7] != (char *)0x0)) &&
             (iVar6 = _strcmp((char *)puVar9[7],pcVar10), iVar6 == 0)) {
            if (0x3f < (int)lVar7 + 6U) {
              _av_log(param_1,0x10,"const_values array too small for %s\n");
              goto LAB_00263214;
            }
            local_568[lVar7] = *puVar9;
            local_368[lVar7] = (double)(long)puVar9[3];
            lVar7 = lVar7 + 1;
          }
        }
      }
      iVar6 = (int)lVar7;
      local_568[iVar6] = "default";
      if ((*(uint *)(param_3 + 0x14) < 0xb) &&
         ((1 << (ulong)(*(uint *)(param_3 + 0x14) & 0x1f) & 0x607U) != 0)) {
        dVar11 = (double)*(long *)(param_3 + 0x18);
      }
      else {
        dVar11 = *(double *)(param_3 + 0x18);
      }
      local_368[iVar6] = dVar11;
      local_568[(long)iVar6 + 1] = "max";
      local_368[(long)iVar6 + 1] = *(double *)(param_3 + 0x28);
      local_568[(long)iVar6 + 2] = "min";
      local_368[(long)iVar6 + 2] = *(double *)(param_3 + 0x20);
      local_568[(long)iVar6 + 3] = "none";
      local_568[(long)iVar6 + 4] = "all";
      local_568[(long)iVar6 + 5] = 0;
      local_368[(long)iVar6 + 3] = 0.0;
      local_368[(long)iVar6 + 4] = -1.0;
      local_368[(long)iVar6 + 5] = 0.0;
      in_stack_fffffffffffffa48 =
           (undefined8 *)((ulong)in_stack_fffffffffffffa48 & 0xffffffff00000000);
      iVar6 = _av_expr_parse_and_eval
                        (&local_570,pbVar1,local_568,local_368,0,0,0,0,0,in_stack_fffffffffffffa48,
                         param_1);
      if (-1 < iVar6) goto LAB_0026314c;
      _av_log(param_1,0x10,"Unable to parse option value \"%s\"\n");
LAB_00263214:
      bVar4 = true;
    }
    else {
      local_570 = (double)*(long *)(lVar7 + 0x18);
LAB_0026314c:
      if (*(int *)(param_3 + 0x14) == 0) {
        FUN_00266578(param_3,param_5,0,0,&local_578);
        if (bVar2 == 0x2d) {
          uVar8 = local_578 & ((long)local_570 ^ 0xffffffffffffffffU);
        }
        else {
          if (bVar2 != 0x2b) goto LAB_002631cc;
          uVar8 = (long)local_570 | local_578;
        }
        local_570 = (double)(long)uVar8;
      }
LAB_002631cc:
      bVar4 = true;
      iVar6 = FUN_00263340(local_570,param_1,param_3,param_5,1,1);
      if (-1 < iVar6) {
        param_4 = param_4 + iVar5;
        if (iVar5 == 0) goto LAB_00263214;
        bVar4 = *param_4 == 0;
      }
    }
  } while (!bVar4);
LAB_0026321c:
  if (*(long *)PTR____stack_chk_guard_01060708 != local_68) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  return;
}


