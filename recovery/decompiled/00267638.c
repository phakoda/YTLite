/* Decompiled from supplied 5.2.2 arm package. VA 0x267638. _av_parse_time */

/* WARNING: Removing unreachable block (ram,0x00267aec) */

void _av_parse_time(long *param_1,byte *param_2,int param_3)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  byte *pbVar6;
  int *piVar7;
  byte *pbVar8;
  tm *ptVar9;
  long lVar10;
  int iVar11;
  byte *pbVar12;
  long lVar13;
  ulong uVar14;
  undefined1 *puVar15;
  tm tStack_118;
  tm local_e0;
  long local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined8 uStack_70;
  
  puVar15 = &LAB_000f4240;
  local_e0.tm_gmtoff._0_4_ = 0;
  local_e0.tm_gmtoff._4_4_ = 0;
  local_e0.tm_zone = (char *)0x0;
  local_e0.tm_wday = 0;
  local_e0.tm_yday = 0;
  local_e0.tm_isdst = 0;
  local_e0._36_4_ = 0;
  local_e0.tm_hour = 0;
  local_e0.tm_mday = 0;
  local_e0.tm_mon = 0;
  local_e0.tm_year = 0;
  local_e0.tm_sec = 0;
  local_e0.tm_min = 0;
  *param_1 = -0x8000000000000000;
  if (param_3 == 0) {
    lVar13 = _av_gettime();
    local_a8 = lVar13 / 1000000;
    iVar5 = _av_strcasecmp(param_2,"now");
    if (iVar5 == 0) {
      *param_1 = lVar13;
      return;
    }
    uVar14 = 0;
    do {
      if (1 < uVar14) {
        pbVar8 = (byte *)0x0;
        break;
      }
      pbVar8 = (byte *)_av_small_strptime(param_2,(&PTR_s__Y____m____d_010654a8)[uVar14],&local_e0);
      uVar14 = uVar14 + 1;
    } while (pbVar8 == (byte *)0x0);
    bVar3 = pbVar8 == (byte *)0x0;
    if (!bVar3) {
      param_2 = pbVar8;
    }
    bVar1 = *param_2;
    pbVar8 = param_2;
    if ((bVar1 | 0x20) == 0x74) {
      pbVar8 = param_2 + 1;
    }
    else {
      while (((int)(char)bVar1 - 9U < 0x18 &&
             ((0x80001fU >> (ulong)((int)(char)bVar1 - 9U & 0x1f) & 1) != 0))) {
        bVar1 = pbVar8[1];
        pbVar8 = pbVar8 + 1;
      }
    }
    uVar14 = 0;
    do {
      if (1 < uVar14) {
        bVar2 = false;
        pbVar6 = param_2;
        goto LAB_00267854;
      }
      pbVar6 = (byte *)_av_small_strptime(pbVar8,(&PTR_s__H__M__S_010654b8)[uVar14],&local_e0);
      param_2 = (byte *)0x0;
      uVar14 = uVar14 + 1;
    } while (pbVar6 == (byte *)0x0);
    bVar2 = false;
  }
  else {
    bVar2 = *param_2 == 0x2d;
    pbVar12 = param_2 + 1;
    if (!bVar2) {
      pbVar12 = param_2;
    }
    pbVar6 = (byte *)_av_small_strptime(pbVar12,"%J:%M:%S",&local_e0);
    if (pbVar6 == (byte *)0x0) {
      pbVar6 = (byte *)_av_small_strptime(pbVar12,"%M:%S",&local_e0);
      local_e0.tm_hour = 0;
      if (pbVar6 == (byte *)0x0) {
        piVar7 = ___error();
        *piVar7 = 0;
        pbVar8 = (byte *)_strtoll((char *)pbVar12,(char **)&local_a0,10);
        pbVar6 = local_a0;
        if (local_a0 == pbVar12) {
          return;
        }
        piVar7 = ___error();
        if (*piVar7 == 0x22) {
          return;
        }
        bVar3 = false;
LAB_00267854:
        if (pbVar6 == (byte *)0x0) {
          return;
        }
        goto LAB_00267858;
      }
    }
    bVar3 = false;
    pbVar8 = (byte *)((long)local_e0.tm_min * 0x3c + (long)(local_e0.tm_hour * 0xe10) +
                     (long)local_e0.tm_sec);
  }
LAB_00267858:
  bVar1 = *pbVar6;
  iVar5 = 0;
  if (bVar1 == 0x2e) {
    iVar11 = 100000;
    while ((0 < iVar11 && (pbVar12 = pbVar6 + 1, (int)(char)*pbVar12 - 0x30U < 10))) {
      pbVar6 = pbVar6 + 1;
      iVar5 = iVar5 + ((int)(char)*pbVar12 - 0x30U) * iVar11;
      iVar11 = iVar11 / 10 + (iVar11 >> 0x1f);
    }
    do {
      pbVar6 = pbVar6 + 1;
      bVar1 = *pbVar6;
    } while ((int)(char)bVar1 - 0x30U < 10);
  }
  if (param_3 == 0) {
    lVar13 = 0;
    bVar4 = (bVar1 & 0xdf) == 0x5a;
    if (bVar4) {
      pbVar6 = pbVar6 + 1;
    }
    if ((!bVar3) && ((bVar1 & 0xdf) != 0x5a)) {
      if ((*pbVar6 == 0x2d) || (*pbVar6 == 0x2b)) {
        uStack_78 = 0;
        uStack_74 = 0;
        uStack_70 = 0;
        uStack_88 = 0;
        uStack_84 = 0;
        uStack_80 = 0;
        uStack_7c = 0;
        uStack_98 = 0;
        local_90 = 0;
        local_a0 = (byte *)0x0;
        pbVar12 = pbVar6 + 1;
        bVar1 = *pbVar6;
        uVar14 = 0;
        pbVar8 = pbVar12;
        do {
          pbVar6 = pbVar8;
          if (2 < uVar14) {
            if (pbVar6 == (byte *)0x0) {
              return;
            }
            break;
          }
          pbVar6 = (byte *)_av_small_strptime(pbVar12,(&PTR_s__H__M_010654c8)[uVar14],&local_a0);
          uVar14 = uVar14 + 1;
          pbVar8 = (byte *)0x0;
        } while (pbVar6 == (byte *)0x0);
        iVar11 = 0x3c;
        if (bVar1 == 0x2b) {
          iVar11 = -0x3c;
        }
        lVar13 = (long)(iVar11 * (local_a0._4_4_ + (int)uStack_98 * 0x3c));
        bVar4 = true;
      }
      else {
        lVar13 = 0;
      }
    }
    if (bVar3) {
      if (bVar4) {
        ptVar9 = _gmtime_r(&local_a8,&tStack_118);
      }
      else {
        ptVar9 = _localtime_r(&local_a8,&tStack_118);
      }
      local_e0.tm_zone = ptVar9->tm_zone;
      uStack_7c = SUB84(local_e0.tm_zone,0);
      uStack_78 = (undefined4)((ulong)local_e0.tm_zone >> 0x20);
      uStack_80 = (undefined4)((ulong)ptVar9->tm_gmtoff >> 0x20);
      local_90._0_4_ = ptVar9->tm_yday;
      local_90._4_4_ = ptVar9->tm_isdst;
      uStack_88 = (undefined4)*(undefined8 *)&ptVar9->field_0x24;
      uStack_84 = (undefined4)((ulong)*(undefined8 *)&ptVar9->field_0x24 >> 0x20);
      uStack_98._0_4_ = ptVar9->tm_year;
      uStack_98._4_4_ = ptVar9->tm_wday;
      local_a0 = *(byte **)&ptVar9->tm_mday;
      local_e0.tm_gmtoff._4_4_ = uStack_80;
      local_e0.tm_mday = (int)local_a0;
      local_e0.tm_mon = (int)((ulong)local_a0 >> 0x20);
      local_e0.tm_year = (int)uStack_98;
      local_e0.tm_wday = uStack_98._4_4_;
      local_e0.tm_yday = (undefined4)local_90;
      local_e0._36_4_ = uStack_88;
      local_e0.tm_gmtoff._0_4_ = uStack_84;
    }
    local_e0.tm_isdst = -(uint)!bVar4;
    if (bVar4) {
      lVar10 = _av_timegm();
    }
    else {
      lVar10 = _mktime(&local_e0);
    }
    pbVar8 = (byte *)(lVar10 + lVar13);
    pbVar12 = pbVar6;
  }
  else {
    if (bVar1 == 0x75) {
      if (pbVar6[1] == 0x73) {
        iVar5 = 0;
        puVar15 = (undefined1 *)0x1;
        pbVar12 = pbVar6 + 2;
        goto LAB_00267a70;
      }
    }
    else if ((bVar1 == 0x6d) && (pbVar6[1] == 0x73)) {
      iVar5 = iVar5 / 1000;
      puVar15 = (undefined1 *)0x3e8;
      pbVar12 = pbVar6 + 2;
      goto LAB_00267a70;
    }
    pbVar12 = pbVar6 + 1;
    if (bVar1 != 0x73) {
      pbVar12 = pbVar6;
    }
  }
LAB_00267a70:
  if (*pbVar12 == 0) {
    uVar14 = 0;
    if (puVar15 != (undefined1 *)0x0) {
      uVar14 = 0x7fffffffffffffff / (ulong)puVar15;
    }
    if (((long)pbVar8 <= (long)uVar14) &&
       ((long)puVar15 * (long)pbVar8 <= 0x7fffffffffffffff - (long)iVar5)) {
      lVar13 = (long)puVar15 * (long)pbVar8 + (long)iVar5;
      lVar10 = -lVar13;
      if (!bVar2) {
        lVar10 = lVar13;
      }
      *param_1 = lVar10;
    }
  }
  return;
}


