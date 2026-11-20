/* Decompiled from supplied 5.2.2 arm package. VA 0x266ea0. _av_parse_color */

void _av_parse_color(undefined2 *param_1,char *param_2,int param_3,undefined8 param_4)

{
  uint uVar1;
  long lVar2;
  bool bVar3;
  int iVar4;
  u_int32_t uVar5;
  size_t sVar6;
  char *pcVar7;
  ulong uVar8;
  undefined8 uVar9;
  void *pvVar10;
  long lVar11;
  uint uVar12;
  double dVar13;
  double dVar14;
  char *local_d8;
  char *local_d0;
  char acStack_c8 [128];
  long local_48;
  
  lVar11 = *(long *)PTR____stack_chk_guard_01060708;
  local_48 = lVar11;
  if (*param_2 == '#') {
    uVar12 = 1;
  }
  else {
    iVar4 = _strncmp(param_2,"0x",2);
    uVar12 = (uint)(iVar4 == 0) << 1;
  }
  if (param_3 < 0) {
    sVar6 = _strlen(param_2);
    param_3 = (int)sVar6;
  }
  uVar1 = (param_3 - uVar12) + 1;
  lVar2 = 0x80;
  if (uVar1 < 0x81) {
    lVar2 = (long)(int)uVar1;
  }
  _av_strlcpy(acStack_c8,param_2 + uVar12,lVar2);
  pcVar7 = _strchr(acStack_c8,0x40);
  local_d0 = pcVar7;
  if (pcVar7 != (char *)0x0) {
    local_d0 = pcVar7 + 1;
    *pcVar7 = '\0';
  }
  sVar6 = _strlen(acStack_c8);
  *(undefined1 *)((long)param_1 + 3) = 0xff;
  iVar4 = _av_strcasecmp(acStack_c8,"random");
  if ((iVar4 == 0) || (iVar4 = _av_strcasecmp(acStack_c8,"bikeshed"), iVar4 == 0)) {
    uVar5 = _av_get_random_seed();
    *(char *)param_1 = (char)(uVar5 >> 0x18);
    *(char *)((long)param_1 + 1) = (char)(uVar5 >> 0x10);
    *(char *)(param_1 + 1) = (char)(uVar5 >> 8);
    *(char *)((long)param_1 + 3) = (char)uVar5;
LAB_00267028:
    pcVar7 = local_d0;
    if (local_d0 == (char *)0x0) {
      uVar9 = 0;
      goto LAB_00267108;
    }
    iVar4 = _strncmp(local_d0,"0x",2);
    if (iVar4 == 0) {
      uVar8 = _strtoul(pcVar7,&local_d0,0x10);
      dVar14 = (double)uVar8;
    }
    else {
      dVar13 = _strtod(pcVar7,&local_d0);
      bVar3 = true;
      if ((dVar13 <= 1.0) && (bVar3 = false, !NAN(dVar13))) {
        bVar3 = dVar13 < 0.0;
      }
      dVar14 = DAT_00c511f0;
      if (!bVar3) {
        dVar14 = dVar13 * DAT_00c508e0;
      }
    }
    if ((((local_d0 != pcVar7) && (0.0 <= dVar14)) && (dVar14 <= DAT_00c508e0)) &&
       (*local_d0 == '\0')) {
      uVar9 = 0;
      *(char *)((long)param_1 + 3) = (char)(int)dVar14;
      goto LAB_00267108;
    }
    pcVar7 = "Invalid alpha value specifier \'%s\' in \'%s\'\n";
  }
  else {
    iVar4 = (int)sVar6;
    if ((uVar12 == 0) &&
       (sVar6 = _strspn(acStack_c8,"0123456789ABCDEFabcdef"), sVar6 != (long)iVar4)) {
      pvVar10 = _bsearch(acStack_c8,&PTR_s_AliceBlue_01064be8,0x8c,0x10,(int *)FUN_00267178);
      if (pvVar10 != (void *)0x0) {
        *(undefined1 *)(param_1 + 1) = *(undefined1 *)((long)pvVar10 + 10);
        *param_1 = *(undefined2 *)((long)pvVar10 + 8);
        goto LAB_00267028;
      }
      pcVar7 = "Cannot find color \'%s\'\n";
    }
    else {
      uVar8 = _strtoul(acStack_c8,&local_d8,0x10);
      if (*local_d8 == '\0') {
        if (iVar4 != 6) {
          if (iVar4 != 8) goto LAB_00267088;
          *(char *)((long)param_1 + 3) = (char)uVar8;
          uVar8 = uVar8 >> 8 & 0xffffff;
        }
        *(char *)param_1 = (char)(uVar8 >> 0x10);
        *(char *)((long)param_1 + 1) = (char)(uVar8 >> 8);
        *(char *)(param_1 + 1) = (char)uVar8;
        goto LAB_00267028;
      }
LAB_00267088:
      pcVar7 = "Invalid 0xRRGGBB[AA] color string: \'%s\'\n";
    }
  }
  _av_log(param_4,0x10,pcVar7);
  uVar9 = 0xffffffea;
LAB_00267108:
  if (lVar11 == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(uVar9);
}


