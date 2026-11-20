/* Decompiled from supplied 5.2.2 arm package. VA 0x2513ac. _av_sscanf */

int _av_sscanf(long param_1,byte *param_2)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  byte bVar6;
  char cVar7;
  int iVar8;
  undefined1 auVar9 [16];
  bool bVar10;
  bool bVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  undefined8 *puVar16;
  bool bVar17;
  uint uVar18;
  int iVar19;
  uint uVar20;
  uint uVar21;
  int *piVar22;
  byte *pbVar23;
  long lVar24;
  int iVar25;
  long lVar26;
  ulong uVar27;
  ulong uVar28;
  ulong uVar29;
  ulong uVar30;
  byte *pbVar31;
  byte *pbVar32;
  byte *pbVar33;
  int iVar34;
  long lVar35;
  ulong uVar36;
  int iVar37;
  int iVar38;
  uint uVar39;
  uint uVar40;
  long lVar41;
  undefined4 uVar42;
  double dVar43;
  double dVar44;
  undefined1 auVar45 [16];
  undefined1 auVar46 [16];
  undefined1 auVar47 [16];
  undefined1 auVar48 [16];
  undefined1 auVar49 [16];
  undefined1 auVar50 [16];
  undefined4 uVar51;
  double dVar52;
  double dVar53;
  double dVar54;
  undefined8 uVar55;
  undefined8 uVar56;
  undefined8 uVar57;
  int local_468;
  double local_450;
  double *local_418;
  undefined8 local_408;
  long local_400;
  byte *local_3f8;
  byte *local_3f0;
  byte *local_3e8;
  byte *local_3e0;
  byte *local_3d8;
  long local_3d0;
  code *pcStack_3c8;
  undefined8 *puVar58;
  undefined8 *local_3b8;
  undefined1 local_3a9;
  char acStack_3a8 [9];
  undefined4 local_39f;
  undefined1 local_39b;
  undefined1 local_388;
  bool local_37b;
  bool local_34b;
  uint uStack_2ac;
  undefined8 *local_2a8;
  uint local_b8;
  long local_a8;
  
  dVar15 = DAT_00c502d0;
  dVar14 = DAT_00c502c8;
  dVar13 = DAT_00c502c0;
  dVar12 = DAT_00c4c268;
  iVar38 = 0;
  pbVar31 = (byte *)0x0;
  uVar57 = 0;
  uVar56 = 0;
  local_450 = DAT_00c502b8;
  local_a8 = *(long *)PTR____stack_chk_guard_01060708;
  local_408 = 0;
  local_400 = param_1;
  local_3e0 = (byte *)0x0;
  local_3d8 = (byte *)0x0;
  local_3f0 = (byte *)0x0;
  local_3e8 = (byte *)0x0;
  local_3f8 = (byte *)0x0;
  local_3d0 = param_1;
  pcStack_3c8 = FUN_0025338c;
  dVar53 = DAT_00c502b8;
  puVar58 = (undefined8 *)register0x00000008;
LAB_0025148c:
  dVar43 = 1.0;
  bVar6 = *param_2;
  if (bVar6 != 0) {
    uVar18 = bVar6 - 9;
    if ((uVar18 < 0x18) && ((0x80001fU >> (ulong)(uVar18 & 0x1f) & 1) != 0)) {
      param_2 = param_2 + -1;
      do {
        pbVar23 = param_2 + 2;
        param_2 = param_2 + 1;
        if (0x17 < *pbVar23 - 9) break;
      } while ((0x80001fU >> (ulong)(*pbVar23 - 9 & 0x1f) & 1) != 0);
      local_3d8 = (byte *)(local_400 - (long)local_3f8);
      local_3e0 = (byte *)0x0;
      local_3e8 = local_3f0;
      do {
        if (local_3f8 == local_3e8) {
          uVar18 = FUN_00253410(&local_408);
        }
        else {
          uVar18 = (uint)*local_3f8;
          local_3f8 = local_3f8 + 1;
        }
      } while ((uVar18 - 9 < 0x18) && ((0x80001fU >> (ulong)(uVar18 - 9 & 0x1f) & 1) != 0));
      pbVar23 = local_3f8;
      pbVar32 = local_3d8;
      if (local_3e8 != (byte *)0x0) {
        local_3f8 = local_3f8 + -1;
        pbVar23 = local_3f8;
      }
LAB_00251684:
      pbVar31 = pbVar23 + (long)pbVar31 + (long)pbVar32 + -local_400;
      goto LAB_00251488;
    }
    if (bVar6 != 0x25) {
LAB_0025156c:
      local_3d8 = (byte *)(local_400 - (long)local_3f8);
      local_3e0 = (byte *)0x0;
      local_3e8 = local_3f0;
      if (*param_2 == 0x25) {
        do {
          if (local_3f8 == local_3e8) {
            uVar18 = FUN_00253410(&local_408);
          }
          else {
            uVar18 = (uint)*local_3f8;
            local_3f8 = local_3f8 + 1;
          }
        } while ((uVar18 - 9 < 0x18) && ((0x80001fU >> (ulong)(uVar18 - 9 & 0x1f) & 1) != 0));
        param_2 = param_2 + 1;
      }
      else if (local_3f8 == local_3f0) {
        uVar18 = FUN_00253410(&local_408);
      }
      else {
        uVar18 = (uint)*local_3f8;
        local_3f8 = local_3f8 + 1;
      }
      pbVar23 = local_3d8;
      pbVar32 = local_3f8;
      if (uVar18 == *param_2) goto LAB_00251684;
      if (local_3e8 != (byte *)0x0) {
        local_3f8 = local_3f8 + -1;
      }
      lVar26 = *(long *)PTR____stack_chk_guard_01060708;
      if ((iVar38 == 0) && ((int)uVar18 < 0)) {
LAB_002531c4:
        iVar38 = -1;
      }
      goto LAB_002531dc;
    }
    pbVar23 = param_2 + 1;
    bVar6 = *pbVar23;
    if (bVar6 == 0x2a) {
      local_418 = (double *)0x0;
      pbVar23 = param_2 + 2;
    }
    else {
      if (bVar6 == 0x25) goto LAB_0025156c;
      if ((bVar6 - 0x30 < 10) && (param_2[2] == 0x24)) {
        uVar18 = bVar6 - 0x2f;
        puVar16 = puVar58;
        do {
          local_3b8 = puVar16;
          uVar18 = uVar18 - 1;
          puVar16 = local_3b8 + 1;
        } while (1 < uVar18);
        local_418 = (double *)*local_3b8;
        pbVar23 = param_2 + 3;
        local_2a8 = puVar58;
      }
      else {
        local_418 = (double *)*puVar58;
        puVar58 = puVar58 + 1;
      }
    }
    iVar19 = 0;
    while( true ) {
      uVar18 = (uint)*pbVar23;
      if (9 < uVar18 - 0x30) break;
      iVar19 = uVar18 + iVar19 * 10 + -0x30;
      pbVar23 = pbVar23 + 1;
    }
    if (uVar18 == 0x6d) {
      pbVar23 = pbVar23 + 1;
    }
    pbVar32 = pbVar23 + 1;
    uVar18 = 3;
    param_2 = pbVar32;
    switch(*pbVar23) {
    case 0x41:
    case 0x43:
    case 0x45:
    case 0x46:
    case 0x47:
    case 0x53:
    case 0x58:
    case 0x5b:
    case 0x61:
    case 99:
    case 100:
    case 0x65:
    case 0x66:
    case 0x67:
    case 0x69:
    case 0x6e:
    case 0x6f:
    case 0x70:
    case 0x73:
    case 0x75:
    case 0x78:
      uVar18 = 0;
      param_2 = pbVar23;
      break;
    default:
      goto switchD_00251704_caseD_42;
    case 0x4c:
      uVar18 = 2;
      break;
    case 0x68:
      param_2 = pbVar23 + 2;
      if (pbVar23[1] != 0x68) {
        param_2 = pbVar32;
      }
      uVar18 = 0xfffffffe;
      if (pbVar23[1] != 0x68) {
        uVar18 = 0xffffffff;
      }
      break;
    case 0x6a:
      break;
    case 0x6c:
      param_2 = pbVar23 + 2;
      if (pbVar23[1] != 0x6c) {
        param_2 = pbVar32;
      }
      uVar18 = 3;
      if (pbVar23[1] != 0x6c) {
        uVar18 = 1;
      }
      break;
    case 0x74:
    case 0x7a:
      uVar18 = 1;
    }
    bVar6 = *param_2;
    uVar20 = bVar6 | 0x20;
    bVar17 = (bVar6 & 0x2f) != 3;
    if (bVar17) {
      uVar20 = (uint)bVar6;
    }
    uVar3 = 1;
    if (bVar17) {
      uVar3 = uVar18;
    }
    iVar37 = iVar19;
    if (uVar20 != 0x5b) {
      if (uVar20 == 0x6e) {
        FUN_002534f8(local_418,uVar3,pbVar31);
        goto LAB_00251488;
      }
      if (uVar20 == 99) {
        iVar37 = 1;
        if (0 < iVar19) {
          iVar37 = iVar19;
        }
      }
      else {
        local_3d8 = (byte *)(local_400 - (long)local_3f8);
        local_3e0 = (byte *)0x0;
        local_3e8 = local_3f0;
        do {
          if (local_3f8 == local_3e8) {
            uVar18 = FUN_00253410(&local_408);
          }
          else {
            uVar18 = (uint)*local_3f8;
            local_3f8 = local_3f8 + 1;
          }
        } while ((uVar18 - 9 < 0x18) && ((0x80001fU >> (ulong)(uVar18 - 9 & 0x1f) & 1) != 0));
        if (local_3e8 != (byte *)0x0) {
          local_3f8 = local_3f8 + -1;
        }
        pbVar31 = local_3f8 + (long)(pbVar31 + ((long)local_3d8 - local_400));
      }
    }
    pbVar23 = (byte *)(long)iVar37;
    local_3e0 = pbVar23;
    local_3d8 = (byte *)(local_400 - (long)local_3f8);
    local_3e8 = local_3f0;
    if ((iVar37 != 0) && ((long)pbVar23 < (long)local_3f0 - (long)local_3f8)) {
      local_3e8 = local_3f8 + (long)pbVar23;
    }
    if (local_3f8 == local_3e8) {
      iVar19 = FUN_00253410(&local_408);
      if (iVar19 < 0) {
switchD_00251704_caseD_42:
        lVar26 = *(long *)PTR____stack_chk_guard_01060708;
        if (iVar38 == 0) goto LAB_002531c4;
        goto LAB_002531dc;
      }
    }
    else {
      local_3f8 = local_3f8 + 1;
    }
    pbVar32 = local_3e8;
    if (local_3e8 != (byte *)0x0) {
      local_3f8 = local_3f8 + -1;
    }
    uVar18 = 0x10;
    switch(uVar20) {
    case 0x58:
    case 0x70:
    case 0x78:
      break;
    case 0x59:
    case 0x5a:
    case 0x5c:
    case 0x5d:
    case 0x5e:
    case 0x5f:
    case 0x60:
    case 0x62:
    case 0x68:
    case 0x6a:
    case 0x6b:
    case 0x6c:
    case 0x6d:
    case 0x6e:
    case 0x71:
    case 0x72:
    case 0x74:
    case 0x76:
    case 0x77:
      goto switchD_00251888_caseD_59;
    case 0x5b:
    case 99:
    case 0x73:
      if ((uVar20 & 0xef) != 99) {
        pbVar33 = param_2 + 1;
        bVar17 = *pbVar33 == 0x5e;
        if (bVar17) {
          pbVar33 = param_2 + 2;
        }
        _memset(&local_3a9,(uint)bVar17,0x101);
        local_3a9 = 0;
        if (*pbVar33 == 0x2d) {
          local_37b = !bVar17;
          param_2 = pbVar33 + 1;
        }
        else {
          param_2 = pbVar33;
          if (*pbVar33 == 0x5d) {
            local_34b = !bVar17;
            param_2 = pbVar33 + 1;
          }
        }
        do {
          local_3a9 = 0;
          uVar18 = (uint)*param_2;
          if (uVar18 == 0x2d) {
            pbVar33 = param_2 + 1;
            bVar6 = *pbVar33;
            uVar18 = 0x2d;
            if ((bVar6 != 0) && (bVar6 != 0x5d)) {
              for (uVar29 = (ulong)param_2[-1]; uVar18 = (uint)bVar6, param_2 = pbVar33,
                  (long)uVar29 < (long)(ulong)uVar18; uVar29 = uVar29 + 1) {
                acStack_3a8[uVar29] = !bVar17;
                bVar6 = *pbVar33;
              }
            }
          }
          else {
            if (uVar18 == 0) goto switchD_00251704_caseD_42;
            if (uVar18 == 0x5d) goto LAB_002520f4;
          }
          acStack_3a8[uVar18] = !bVar17;
          param_2 = param_2 + 1;
        } while( true );
      }
      _memset(&local_3a9,0xff,0x101);
      local_3a9 = 0;
      if (uVar20 == 0x73) {
        local_388 = 0;
        local_39b = 0;
        local_39f = 0;
      }
LAB_002520f4:
      local_3a9 = 0;
      if (local_418 == (double *)0x0) {
        do {
          pbVar33 = local_3f8;
          if (local_3f8 == pbVar32) {
            uVar18 = FUN_00253410(&local_408);
          }
          else {
            local_3f8 = local_3f8 + 1;
            uVar18 = (uint)*pbVar33;
          }
          pbVar32 = local_3e8;
        } while (acStack_3a8[(int)uVar18] != '\0');
        lVar26 = 0;
      }
      else {
        lVar26 = 0;
        while( true ) {
          pbVar33 = local_3f8;
          if (local_3f8 == pbVar32) {
            uVar18 = FUN_00253410(&local_408);
          }
          else {
            local_3f8 = local_3f8 + 1;
            uVar18 = (uint)*pbVar33;
          }
          if (acStack_3a8[(int)uVar18] == '\0') break;
          *(char *)((long)local_418 + lVar26) = (char)uVar18;
          lVar26 = lVar26 + 1;
          pbVar32 = local_3e8;
        }
      }
      if (local_3e8 != (byte *)0x0) {
        local_3f8 = local_3f8 + -1;
      }
      if ((local_3d8 + ((long)local_3f8 - local_400) != (byte *)0x0) &&
         (uVar20 != 99 || local_3d8 + ((long)local_3f8 - local_400) == pbVar23)) {
        if ((local_418 != (double *)0x0) && (uVar20 != 99)) {
          *(undefined1 *)((long)local_418 + lVar26) = 0;
        }
        goto switchD_00251888_caseD_59;
      }
      goto LAB_002531d0;
    case 0x61:
    case 0x65:
    case 0x66:
    case 0x67:
switchD_00251888_caseD_61:
      dVar54 = 0.0;
      if (uVar3 < 3) {
        uVar18 = *(uint *)(&UNK_00c50414 + (long)(int)uVar3 * 4);
        iVar19 = *(int *)(&UNK_00c50420 + (long)(int)uVar3 * 4);
        lVar26 = (long)iVar19;
        do {
          pbVar23 = local_3f8;
          if (local_3f8 == local_3e8) {
            uVar20 = FUN_00253410(&local_408);
          }
          else {
            local_3f8 = local_3f8 + 1;
            uVar20 = (uint)*pbVar23;
          }
          pbVar23 = local_3f8;
        } while ((uVar20 - 9 < 0x18) && ((0x80001fU >> (ulong)(uVar20 - 9 & 0x1f) & 1) != 0));
        if ((uVar20 == 0x2d) || (uVar20 == 0x2b)) {
          iVar37 = (uint)(uVar20 == 0x2d) * -2 + 1;
          if (local_3f8 == local_3e8) {
            uVar20 = FUN_00253410(&local_408);
          }
          else {
            local_3f8 = local_3f8 + 1;
            uVar20 = (uint)*pbVar23;
          }
        }
        else {
          iVar37 = 1;
        }
        for (uVar29 = 0;
            (pbVar23 = local_3f8, uVar29 < 8 && ((uVar20 | 0x20) == (int)"infinity"[uVar29]));
            uVar29 = uVar29 + 1) {
          if (uVar29 < 7) {
            if (local_3f8 == local_3e8) {
              uVar20 = FUN_00253410(&local_408);
            }
            else {
              local_3f8 = local_3f8 + 1;
              uVar20 = (uint)*pbVar23;
            }
          }
        }
        if (uVar29 == 0) {
          for (uVar29 = 0;
              (pbVar23 = local_3f8, uVar29 < 3 && ((uVar20 | 0x20) == (int)"nan"[uVar29]));
              uVar29 = uVar29 + 1) {
            if (uVar29 < 2) {
              if (local_3f8 == local_3e8) {
                uVar20 = FUN_00253410(&local_408);
              }
              else {
                local_3f8 = local_3f8 + 1;
                uVar20 = (uint)*pbVar23;
              }
            }
          }
LAB_00251d34:
          pbVar23 = local_3f8;
          if (uVar29 == 0) {
            if (uVar20 == 0x30) {
              if (local_3f8 == local_3e8) {
                uVar20 = FUN_00253410(&local_408);
              }
              else {
                local_3f8 = local_3f8 + 1;
                uVar20 = (uint)*pbVar23;
              }
              if ((uVar20 | 0x20) == 0x78) {
                if (local_3f8 == local_3e8) {
                  uVar20 = FUN_00253410(&local_408);
                }
                else {
                  uVar20 = (uint)*local_3f8;
                  local_3f8 = local_3f8 + 1;
                }
                bVar17 = false;
                while (uVar20 == 0x30) {
                  if (local_3f8 == local_3e8) {
                    uVar20 = FUN_00253410(&local_408);
                    bVar17 = true;
                  }
                  else {
                    uVar20 = (uint)*local_3f8;
                    bVar17 = true;
                    local_3f8 = local_3f8 + 1;
                  }
                }
                if (uVar20 == 0x2e) {
                  if (local_3f8 == local_3e8) {
                    uVar20 = FUN_00253410(&local_408);
                  }
                  else {
                    uVar20 = (uint)*local_3f8;
                    local_3f8 = local_3f8 + 1;
                  }
                  lVar35 = 0;
                  while (uVar20 == 0x30) {
                    if (local_3f8 == local_3e8) {
                      uVar20 = FUN_00253410(&local_408);
                    }
                    else {
                      uVar20 = (uint)*local_3f8;
                      local_3f8 = local_3f8 + 1;
                    }
                    lVar35 = lVar35 + -1;
                    bVar17 = true;
                  }
                  bVar10 = true;
                }
                else {
                  bVar10 = false;
                  lVar35 = 0;
                }
                bVar11 = false;
                uVar21 = 0;
                lVar41 = 0;
                dVar54 = 0.0;
LAB_002527c8:
                if (uVar20 - 0x30 < 10) {
LAB_00252800:
                  uVar40 = (uVar20 | 0x20) - 0x57;
                  if ((int)uVar20 < 0x3a) {
                    uVar40 = uVar20 - 0x30;
                  }
                  if (lVar41 < 8) {
                    uVar21 = uVar40 + uVar21 * 0x10;
                  }
                  else if (lVar41 < 0xe) {
                    dVar43 = dVar43 * dVar15;
                    dVar54 = dVar54 + dVar43 * (double)(int)uVar40;
                  }
                  else if ((!bVar11) && (uVar40 != 0)) {
                    dVar54 = dVar54 + dVar43 * 0.5;
                    bVar11 = true;
                  }
                  lVar41 = lVar41 + 1;
                  bVar17 = true;
                }
                else {
                  uVar40 = (uVar20 | 0x20) - 0x61;
                  if ((uVar20 != 0x2e && 4 < uVar40) && (uVar20 == 0x2e || uVar40 != 5))
                  goto LAB_0025287c;
                  if (uVar20 != 0x2e) goto LAB_00252800;
                  if (bVar10) goto LAB_00252878;
                  bVar10 = true;
                  lVar35 = lVar41;
                }
                if (local_3f8 == local_3e8) {
                  uVar20 = FUN_00253410(&local_408);
                }
                else {
                  uVar20 = (uint)*local_3f8;
                  local_3f8 = local_3f8 + 1;
                }
                goto LAB_002527c8;
              }
              if (local_3e8 != (byte *)0x0) {
                local_3f8 = local_3f8 + -1;
              }
              uVar20 = 0x30;
            }
            bVar17 = false;
            while (pbVar23 = local_3f8, uVar20 == 0x30) {
              if (local_3f8 == local_3e8) {
                uVar20 = FUN_00253410(&local_408);
                bVar17 = true;
              }
              else {
                local_3f8 = local_3f8 + 1;
                uVar20 = (uint)*pbVar23;
                bVar17 = true;
              }
            }
            if (uVar20 == 0x2e) {
              if (local_3f8 == local_3e8) {
                uVar20 = FUN_00253410(&local_408);
              }
              else {
                local_3f8 = local_3f8 + 1;
                uVar20 = (uint)*pbVar23;
              }
              uVar29 = 0;
              while (pbVar23 = local_3f8, uVar20 == 0x30) {
                uVar29 = uVar29 - 1;
                if (local_3f8 == local_3e8) {
                  uVar20 = FUN_00253410(&local_408);
                  bVar17 = true;
                }
                else {
                  local_3f8 = local_3f8 + 1;
                  uVar20 = (uint)*pbVar23;
                  bVar17 = true;
                }
              }
              bVar10 = true;
            }
            else {
              uVar29 = 0;
              bVar10 = false;
            }
            uVar30 = 0;
            local_468 = 0;
            uVar21 = 0;
            iVar25 = 0;
            local_2a8 = (undefined8 *)((ulong)local_2a8 & 0xffffffff00000000);
            while (pbVar23 = local_3f8, uVar40 = uVar20 - 0x30, uVar20 == 0x2e || uVar40 < 10) {
              if (uVar20 == 0x2e) {
                if (bVar10) goto LAB_002525a0;
                bVar10 = true;
                uVar29 = uVar30;
              }
              else {
                uVar30 = uVar30 + 1;
                if ((int)uVar21 < 0x7d) {
                  iVar34 = (int)uVar30;
                  if (uVar20 == 0x30) {
                    iVar34 = local_468;
                  }
                  if (iVar25 != 0) {
                    uVar40 = uVar40 + *(int *)((long)&local_2a8 + (long)(int)uVar21 * 4) * 10;
                  }
                  *(uint *)((long)&local_2a8 + (long)(int)uVar21 * 4) = uVar40;
                  if (iVar25 == 8) {
                    uVar21 = uVar21 + 1;
                  }
                  iVar8 = 0;
                  if (iVar25 != 8) {
                    iVar8 = iVar25 + 1;
                  }
                  bVar17 = true;
                  local_468 = iVar34;
                  iVar25 = iVar8;
                }
                else if (uVar20 != 0x30) {
                  local_b8 = local_b8 | 1;
                  local_468 = 0x45c;
                }
              }
              if (local_3f8 == local_3e8) {
                uVar20 = FUN_00253410(&local_408);
              }
              else {
                local_3f8 = local_3f8 + 1;
                uVar20 = (uint)*pbVar23;
              }
            }
            uVar36 = uVar30;
            if (bVar10) {
              uVar36 = uVar29;
            }
            if ((bVar17) && ((uVar20 | 0x20) == 0x65)) {
              lVar35 = FUN_00253554(&local_408);
              if (lVar35 == -0x8000000000000000) goto LAB_00252630;
              uVar36 = lVar35 + uVar36;
            }
            else {
              uVar29 = uVar36;
              if (-1 < (int)uVar20) {
LAB_002525a0:
                uVar36 = uVar29;
                if (local_3e8 != (byte *)0x0) {
                  local_3f8 = local_3f8 + -1;
                }
              }
              if (!bVar17) {
                piVar22 = ___error();
                *piVar22 = 0x16;
LAB_00252630:
                local_3e0 = (byte *)0x0;
                local_3d8 = (byte *)(local_400 - (long)local_3f8);
                local_3e8 = local_3f0;
                dVar54 = 0.0;
                goto LAB_00252b90;
              }
            }
            if ((uint)local_2a8 == 0) {
              dVar54 = (double)iVar37 * 0.0;
            }
            else if (((long)uVar30 < 10 && uVar36 == uVar30) &&
                    (((long)(int)uVar3 - 1U < 2 || ((uint)local_2a8 >> (ulong)(uVar18 & 0x1f) == 0))
                    )) {
              dVar54 = (double)iVar37;
              dVar43 = (double)((ulong)local_2a8 & 0xffffffff);
LAB_0025270c:
              dVar54 = dVar54 * dVar43;
            }
            else {
              iVar34 = iVar19;
              if (iVar19 < 0) {
                iVar34 = iVar19 + 1;
              }
              if ((long)-(iVar34 >> 1) < (long)uVar36) {
                piVar22 = ___error();
                *piVar22 = 0x22;
                dVar54 = (double)iVar37 * dVar14 * dVar14;
              }
              else if ((long)uVar36 < lVar26 + -0x6a) {
                piVar22 = ___error();
                *piVar22 = 0x22;
                dVar54 = (double)iVar37 * dVar13 * dVar13;
              }
              else {
                if (iVar25 != 0) {
                  iVar25 = iVar25 + -1;
                  while (iVar25 = iVar25 + 1, iVar25 < 9) {
                    *(int *)((long)&local_2a8 + (long)(int)uVar21 * 4) =
                         *(int *)((long)&local_2a8 + (long)(int)uVar21 * 4) * 10;
                  }
                  uVar21 = uVar21 + 1;
                }
                iVar25 = (int)uVar36;
                if ((8 < local_468 || iVar25 < local_468) || 0x11 < iVar25) {
LAB_00252c20:
                  uVar29 = (long)(int)uVar21 + 1;
                  uVar30 = -(ulong)(uVar21 - 1 >> 0x1f) & 0xfffffffc00000000 |
                           (ulong)(uVar21 - 1) << 2;
                  do {
                    uVar20 = uVar21;
                    piVar22 = (int *)((long)&local_2a8 + uVar30);
                    uVar29 = uVar29 - 1;
                    uVar30 = uVar30 - 4;
                    uVar21 = uVar20 - 1;
                  } while (*piVar22 == 0);
                  iVar34 = iVar25 % 9;
                  if (iVar34 == 0) {
                    iVar25 = 0;
                    uVar21 = 0;
                  }
                  else {
                    if (iVar25 < 0) {
                      iVar34 = iVar34 + 9;
                    }
                    uVar40 = *(uint *)(&DAT_00c503f4 + (long)(8 - iVar34) * 4);
                    uVar21 = 0;
                    iVar25 = 0;
                    for (uVar30 = 0; uVar20 != uVar30; uVar30 = uVar30 + 1) {
                      uVar4 = *(uint *)((long)&local_2a8 + uVar30 * 4);
                      iVar8 = 0;
                      if (uVar40 != 0) {
                        iVar8 = 1000000000 / (int)uVar40;
                      }
                      uVar39 = 0;
                      if (uVar40 != 0) {
                        uVar39 = uVar4 / uVar40;
                      }
                      iVar2 = uVar39 + iVar25;
                      *(int *)((long)&local_2a8 + uVar30 * 4) = iVar2;
                      iVar25 = iVar8 * (uVar4 - uVar39 * uVar40);
                      if ((uVar30 == uVar21) && (iVar2 == 0)) {
                        uVar21 = uVar21 + 1 & 0x7f;
                        uVar36 = (ulong)((int)uVar36 - 9);
                      }
                    }
                    if (iVar25 != 0) {
                      *(int *)((long)&local_2a8 + uVar29 * 4) = iVar25;
                      uVar29 = (ulong)((int)uVar29 + 1);
                    }
                    iVar25 = 0;
                    uVar36 = (ulong)(uint)((9 - iVar34) + (int)uVar36);
                  }
                  do {
                    do {
                      iVar34 = (int)uVar36;
                      if (0x11 < iVar34) {
                        if (iVar34 != 0x12) goto LAB_00252dec;
                        if (0x89705e < *(uint *)((long)&local_2a8 + (long)(int)uVar21 * 4)) {
                          uVar36 = 0x12;
                          goto LAB_00252dec;
                        }
                      }
                      uVar30 = 0;
                      uVar20 = (int)uVar29 + 0x7f;
                      do {
                        uVar40 = uVar20 & 0x7f;
                        uVar28 = (ulong)*(uint *)((long)&local_2a8 + (ulong)uVar40 * 4) * 0x20000000
                                 + (uVar30 & 0xffffffff);
                        if (uVar28 < 0x3b9aca01) {
                          uVar30 = 0;
                        }
                        else {
                          uVar30 = uVar28 / 1000000000;
                          uVar28 = uVar28 % 1000000000;
                        }
                        uVar39 = (uint)uVar29;
                        uVar20 = uVar40 - 1;
                        uVar4 = uVar40;
                        if ((int)uVar28 != 0) {
                          uVar4 = uVar39;
                        }
                        if (uVar40 != uVar21 && uVar40 == (uVar39 + 0x7f & 0x7f)) {
                          uVar39 = uVar4;
                        }
                        uVar29 = (ulong)uVar39;
                        *(int *)((long)&local_2a8 + (ulong)uVar40 * 4) = (int)uVar28;
                      } while (uVar40 != uVar21);
                      iVar25 = iVar25 + -0x1d;
                    } while ((int)uVar30 == 0);
                    uVar36 = (ulong)(iVar34 + 9);
                    uVar21 = uVar21 + 0x7f & 0x7f;
                    if (uVar21 == uVar39) {
                      uVar20 = uVar39 + 0x7f & 0x7f;
                      uVar40 = uVar39 + 0x7e & 0x7f;
                      *(uint *)((long)&local_2a8 + (ulong)uVar40 * 4) =
                           *(uint *)((long)&local_2a8 + (ulong)uVar40 * 4) |
                           *(uint *)((long)&local_2a8 + (ulong)uVar20 * 4);
                      uVar29 = (ulong)uVar20;
                    }
                    *(int *)((long)&local_2a8 + (ulong)uVar21 * 4) = (int)uVar30;
                  } while( true );
                }
                if (iVar25 == 9) {
                  dVar43 = (double)NEON_ucvtf((ulong)local_2a8 & 0xffffffff);
                  dVar54 = (double)iVar37 * dVar43;
                }
                else {
                  if (8 < iVar25) {
                    uVar20 = uVar18 + iVar25 * -3 + 0x1b;
                    if (((int)uVar20 < 0x1f) && ((uint)local_2a8 >> (ulong)(uVar20 & 0x1f) != 0))
                    goto LAB_00252c20;
                    dVar54 = (double)iVar37 * (double)((ulong)local_2a8 & 0xffffffff);
                    dVar43 = (double)*(int *)(&DAT_00c503f4 +
                                             ((long)((uVar36 << 0x20) + -0xa00000000) >> 0x1e));
                    goto LAB_0025270c;
                  }
                  dVar43 = (double)NEON_ucvtf((ulong)local_2a8 & 0xffffffff);
                  dVar54 = ((double)iVar37 * dVar43) /
                           (double)*(int *)(&DAT_00c503f4 +
                                           (-(ulong)(8U - iVar25 >> 0x1f) & 0xfffffffc00000000 |
                                           (ulong)(8U - iVar25) << 2));
                }
              }
            }
          }
          else if (uVar29 == 3) {
            if (local_3f8 == local_3e8) {
              uVar18 = FUN_00253410(&local_408);
            }
            else {
              uVar18 = (uint)*local_3f8;
              local_3f8 = local_3f8 + 1;
            }
            if (uVar18 == 0x28) {
              do {
                if (local_3f8 == local_3e8) {
                  uVar18 = FUN_00253410(&local_408);
                }
                else {
                  uVar18 = (uint)*local_3f8;
                  local_3f8 = local_3f8 + 1;
                }
              } while ((uVar18 - 0x30 < 10 || uVar18 - 0x41 < 0x1a) ||
                      (uVar18 == 0x5f || uVar18 - 0x61 < 0x1a));
              dVar54 = DAT_00c502d8;
              if (uVar18 != 0x29) goto LAB_002522c4;
            }
            else {
              dVar54 = DAT_00c502d8;
              if (local_3e8 != (byte *)0x0) {
                local_3f8 = local_3f8 + -1;
              }
            }
          }
          else {
LAB_002522c4:
            if (local_3e8 != (byte *)0x0) {
              local_3f8 = local_3f8 + -1;
            }
            piVar22 = ___error();
            *piVar22 = 0x16;
            local_3e0 = (byte *)0x0;
            local_3d8 = (byte *)(local_400 - (long)local_3f8);
            local_3e8 = local_3f0;
            dVar54 = 0.0;
          }
        }
        else {
          if (uVar29 != 8) {
            if (uVar29 != 3) goto LAB_00251d34;
            if (local_3e8 != (byte *)0x0) {
              local_3f8 = local_3f8 + -1;
            }
          }
          dVar54 = (double)((float)iVar37 * DAT_00c502b0);
        }
      }
      goto LAB_00252b90;
    case 100:
    case 0x75:
      uVar18 = 10;
      break;
    case 0x69:
      uVar18 = 0;
      break;
    case 0x6f:
      uVar18 = 8;
      break;
    default:
      if ((uVar20 - 0x45 < 3) || (uVar20 == 0x41)) goto switchD_00251888_caseD_61;
      goto switchD_00251888_caseD_59;
    }
    do {
      if (local_3f8 == local_3e8) {
        uVar21 = FUN_00253410(&local_408);
      }
      else {
        uVar21 = (uint)*local_3f8;
        local_3f8 = local_3f8 + 1;
      }
    } while ((uVar21 - 9 < 0x18) && ((0x80001fU >> (ulong)(uVar21 - 9 & 0x1f) & 1) != 0));
    if ((uVar21 == 0x2d) || (uVar21 == 0x2b)) {
      iVar19 = -(uint)(uVar21 == 0x2d);
      if (local_3f8 == local_3e8) {
        uVar21 = FUN_00253410(&local_408);
      }
      else {
        uVar21 = (uint)*local_3f8;
        local_3f8 = local_3f8 + 1;
      }
    }
    else {
      iVar19 = 0;
    }
    if (((uVar18 & 10) == 0) && (uVar21 == 0x30)) {
      if (local_3f8 == local_3e8) {
        uVar21 = FUN_00253410(&local_408);
      }
      else {
        uVar21 = (uint)*local_3f8;
        local_3f8 = local_3f8 + 1;
      }
      if ((uVar21 | 0x20) == 0x78) {
        if (local_3f8 == local_3e8) {
          uVar21 = FUN_00253410(&local_408);
        }
        else {
          uVar21 = (uint)*local_3f8;
          local_3f8 = local_3f8 + 1;
        }
        if (0xf < (byte)(&DAT_00c502e1)[(int)uVar21]) {
          if (local_3e8 != (byte *)0x0) {
            local_3f8 = local_3f8 + -1;
          }
          local_3d8 = (byte *)(local_400 - (long)local_3f8);
          local_3e0 = (byte *)0x0;
          dVar43 = 0.0;
          local_3e8 = local_3f0;
          goto LAB_00252214;
        }
        uVar40 = 0x10;
      }
      else {
        uVar40 = uVar18;
        if (uVar18 != 0) goto LAB_00251b60;
        uVar40 = 8;
      }
LAB_00251e10:
      if ((uVar40 - 1 & uVar40) == 0) {
        cVar7 = (&UNK_00c503e1)[uVar40 * 0x17 >> 5 & 7];
        uVar18 = 0;
        while ((bVar6 = (&DAT_00c502e1)[(int)uVar21], uVar18 >> 0x1b == 0 && (bVar6 < uVar40))) {
          uVar18 = (uint)bVar6 | uVar18 << (ulong)((int)cVar7 & 0x1f);
          if (local_3f8 == local_3e8) {
            uVar21 = FUN_00253410(&local_408);
          }
          else {
            uVar21 = (uint)*local_3f8;
            local_3f8 = local_3f8 + 1;
          }
        }
        uVar29 = (ulong)uVar18;
        while (uVar30 = (ulong)bVar6,
              bVar6 < uVar40 && uVar29 <= 0xffffffffffffffffU >> ((long)cVar7 & 0x3fU)) {
          uVar29 = uVar29 << ((long)cVar7 & 0x3fU) | uVar30;
          if (local_3f8 == local_3e8) {
            uVar18 = FUN_00253410(&local_408);
          }
          else {
            uVar18 = (uint)*local_3f8;
            local_3f8 = local_3f8 + 1;
          }
          bVar6 = (&DAT_00c502e1)[(int)uVar18];
        }
      }
      else {
        uVar18 = 0;
        while( true ) {
          bVar6 = (&DAT_00c502e1)[(int)uVar21];
          if (0x71c71c6 < uVar18 || uVar40 <= bVar6) break;
          uVar18 = (uint)bVar6 + uVar18 * uVar40;
          if (local_3f8 == local_3e8) {
            uVar21 = FUN_00253410(&local_408);
          }
          else {
            uVar21 = (uint)*local_3f8;
            local_3f8 = local_3f8 + 1;
          }
        }
        uVar29 = (ulong)uVar18;
        uVar36 = (ulong)uVar40;
        while( true ) {
          uVar30 = (ulong)bVar6;
          uVar28 = 0;
          if (uVar36 != 0) {
            uVar28 = 0xffffffffffffffff / uVar36;
          }
          uVar27 = uVar29 * uVar36;
          if ((uVar40 <= bVar6 || uVar28 < uVar29) || ~uVar30 <= uVar27 && uVar27 - ~uVar30 != 0)
          break;
          uVar29 = uVar27 + uVar30;
          if (local_3f8 == local_3e8) {
            uVar18 = FUN_00253410(&local_408);
          }
          else {
            uVar18 = (uint)*local_3f8;
            local_3f8 = local_3f8 + 1;
          }
          bVar6 = (&DAT_00c502e1)[(int)uVar18];
        }
      }
LAB_00251fa0:
      if ((uint)uVar30 < uVar40) {
        while ((uint)uVar30 < uVar40) {
          if (local_3f8 == local_3e8) {
            uVar18 = FUN_00253410(&local_408);
          }
          else {
            uVar18 = (uint)*local_3f8;
            local_3f8 = local_3f8 + 1;
          }
          uVar30 = (ulong)(byte)(&DAT_00c502e1)[(int)uVar18];
        }
        piVar22 = ___error();
        iVar19 = 0;
        *piVar22 = 0x22;
        uVar29 = 0xffffffffffffffff;
      }
LAB_00252008:
      if (local_3e8 != (byte *)0x0) {
        local_3f8 = local_3f8 + -1;
      }
      dVar43 = (double)((uVar29 ^ (long)iVar19) - (long)iVar19);
    }
    else {
      uVar40 = 10;
      if (uVar18 != 0) {
        uVar40 = uVar18;
      }
      if ((byte)(&DAT_00c502e1)[(int)uVar21] < uVar40) {
LAB_00251b60:
        if (uVar40 != 10) goto LAB_00251e10;
        uVar18 = 0;
        while (uVar21 - 0x30 < 10 && uVar18 < 0x19999999) {
          uVar18 = (uVar21 - 0x30) + uVar18 * 10;
          if (local_3f8 == local_3e8) {
            uVar21 = FUN_00253410(&local_408);
          }
          else {
            uVar21 = (uint)*local_3f8;
            local_3f8 = local_3f8 + 1;
          }
        }
        uVar29 = (ulong)uVar18;
        while( true ) {
          uVar18 = uVar21 - 0x30;
          uVar30 = uVar29 * 10;
          uVar36 = ~(long)(int)uVar18;
          if ((9 < uVar18 || 0x1999999999999999 < uVar29) ||
              uVar36 <= uVar30 && uVar30 - uVar36 != 0) break;
          uVar29 = uVar30 + (long)(int)uVar18;
          if (local_3f8 == local_3e8) {
            uVar21 = FUN_00253410(&local_408);
          }
          else {
            uVar21 = (uint)*local_3f8;
            local_3f8 = local_3f8 + 1;
          }
        }
        if (uVar18 < 10) {
          uVar30 = (ulong)(byte)(&DAT_00c502e1)[(int)uVar21];
          uVar40 = 10;
          goto LAB_00251fa0;
        }
        goto LAB_00252008;
      }
      if (local_3e8 != (byte *)0x0) {
        local_3f8 = local_3f8 + -1;
      }
      local_3d8 = (byte *)(local_400 - (long)local_3f8);
      local_3e0 = (byte *)0x0;
      local_3e8 = local_3f0;
      piVar22 = ___error();
      dVar43 = 0.0;
      *piVar22 = 0x16;
    }
LAB_00252214:
    if (local_3d8 != (byte *)(local_400 - (long)local_3f8)) {
      if ((local_418 == (double *)0x0) || (uVar20 != 0x70)) {
        FUN_002534f8(local_418,uVar3);
      }
      else {
        *local_418 = dVar43;
      }
      goto switchD_00251888_caseD_59;
    }
  }
LAB_002531d0:
  lVar26 = *(long *)PTR____stack_chk_guard_01060708;
LAB_002531dc:
  if (lVar26 != local_a8) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  return iVar38;
LAB_00252878:
  uVar20 = 0x2e;
LAB_0025287c:
  uVar56 = 0;
  dVar53 = local_450;
  if (bVar17) {
    lVar24 = lVar41 + -1;
    while (lVar24 = lVar24 + 1, lVar24 < 8) {
      uVar21 = uVar21 << 4;
    }
    if (bVar10) {
      lVar41 = lVar35;
    }
    if ((uVar20 | 0x20) == 0x70) {
      lVar35 = FUN_00253554(&local_408);
      if (lVar35 == -0x8000000000000000) {
        local_3d8 = (byte *)(local_400 - (long)local_3f8);
        local_3e0 = (byte *)0x0;
        local_3e8 = local_3f0;
        dVar54 = 0.0;
        goto LAB_00252b90;
      }
    }
    else if (local_3e8 == (byte *)0x0) {
      lVar35 = 0;
    }
    else {
      lVar35 = 0;
      local_3f8 = local_3f8 + -1;
    }
    if (uVar21 == 0) {
      dVar54 = (double)iVar37 * 0.0;
    }
    else {
      lVar24 = lVar35 + lVar41 * 4 + -0x20;
      if (-lVar26 < lVar24) {
        piVar22 = ___error();
        *piVar22 = 0x22;
        dVar54 = (double)iVar37 * dVar14 * dVar14;
      }
      else if (lVar24 < lVar26 + -0x6a) {
        piVar22 = ___error();
        *piVar22 = 0x22;
        dVar54 = (double)iVar37 * dVar13 * dVar13;
      }
      else {
        iVar19 = (int)lVar35 + (int)(lVar41 << 2) + -0x20;
        lVar26 = (lVar35 + lVar41 * 4) - lVar26;
        for (; -1 < (int)uVar21; uVar21 = ((uint)bVar17 | uVar21 << 1) ^ 1) {
          bVar17 = dVar54 < 0.5;
          iVar19 = iVar19 + -1;
          dVar43 = dVar54;
          if (!bVar17) {
            dVar43 = dVar54 + -1.0;
          }
          dVar54 = dVar54 + dVar43;
          lVar26 = lVar26 + -1;
        }
        uVar20 = 0;
        if (-1 < (int)(uint)lVar26) {
          uVar20 = (uint)lVar26;
        }
        if ((int)uVar18 <= lVar26) {
          uVar20 = uVar18;
        }
        if ((int)uVar20 < 0x35) {
          auVar46._8_8_ = uVar56;
          auVar46._0_8_ = 0x3ff0000000000000;
          uVar29 = _scalbn(auVar46,0x54 - uVar20);
          dVar43 = (double)(uVar29 ^ (uVar29 ^ (ulong)(double)iVar37) & 0x8000000000000000);
        }
        else {
          dVar43 = 0.0;
        }
        bVar17 = (uVar21 & 1) == 0;
        dVar52 = 0.0;
        if (!bVar17 || (dVar54 == 0.0 || (int)uVar20 >= 0x20)) {
          dVar52 = dVar54;
        }
        dVar43 = (dVar52 * (double)iVar37 +
                 (double)((bVar17 && (dVar54 != 0.0 && (int)uVar20 < 0x20)) + uVar21) *
                 (double)iVar37 + dVar43) - dVar43;
        uVar55 = 0;
        if (dVar43 == 0.0) {
          piVar22 = ___error();
          *piVar22 = 0x22;
        }
        auVar45._8_8_ = uVar55;
        auVar45._0_8_ = dVar43;
        auVar46 = _scalbn(auVar45,iVar19);
        dVar54 = auVar46._0_8_;
      }
    }
  }
  else {
    if (local_3e8 != (byte *)0x0) {
      local_3f8 = local_3f8 + -1;
    }
    local_3d8 = (byte *)(local_400 - (long)local_3f8);
    local_3e0 = (byte *)0x0;
    local_3e8 = local_3f0;
    dVar54 = (double)iVar37 * 0.0;
  }
LAB_00252b90:
  if (local_3d8 == (byte *)(local_400 - (long)local_3f8)) goto LAB_002531d0;
  if (local_418 != (double *)0x0) {
    if ((uVar3 == 2) || (uVar3 == 1)) {
      *local_418 = dVar54;
    }
    else if (uVar3 == 0) {
      *(float *)local_418 = (float)dVar54;
    }
  }
switchD_00251888_caseD_59:
  pbVar31 = local_3d8 + (long)pbVar31 + (long)local_3f8 + -local_400;
  if (local_418 != (double *)0x0) {
    iVar38 = iVar38 + 1;
  }
LAB_00251488:
  param_2 = param_2 + 1;
  goto LAB_0025148c;
LAB_00252dec:
  uVar40 = (uint)uVar29;
  uVar20 = uVar40 + 1 & 0x7f;
  uVar30 = (ulong)(uVar40 + 0x7f & 0x7f);
LAB_00252e0c:
  do {
    lVar26 = 0;
    do {
      if (1 < lVar26) {
LAB_00252e54:
        if ((int)uVar36 == 0x12 && (int)lVar26 == 2) {
          dVar43 = 0.0;
          for (iVar34 = 0; uVar20 = (uint)uVar29, iVar34 != 2; iVar34 = iVar34 + 1) {
            uVar40 = uVar21 + iVar34 & 0x7f;
            if (uVar40 == uVar20) {
              uVar29 = (ulong)(uVar20 + 1 & 0x7f);
              (&uStack_2ac)[uVar29] = 0;
            }
            dVar54 = (double)NEON_ucvtf((ulong)*(uint *)((long)&local_2a8 + (ulong)uVar40 * 4));
            dVar43 = dVar43 * dVar12 + dVar54;
          }
          dVar54 = (double)iVar37;
          dVar43 = dVar54 * dVar43;
          uVar4 = (iVar25 + 0x35U) - iVar19;
          uVar40 = 0;
          if (-1 < (int)uVar4) {
            uVar40 = uVar4;
          }
          bVar17 = (int)uVar4 < (int)uVar18;
          if ((int)uVar18 <= (int)uVar4) {
            uVar40 = uVar18;
          }
          if ((int)uVar40 < 0x35) {
            auVar47._8_8_ = uVar56;
            auVar47._0_8_ = 0x3ff0000000000000;
            auVar46 = _scalbn(auVar47,0x69 - uVar40);
            dVar52 = (double)(auVar46._0_8_ ^ (auVar46._0_8_ ^ (ulong)dVar43) & 0x8000000000000000);
            auVar48._8_8_ = uVar56;
            auVar48._0_8_ = 0x3ff0000000000000;
            uVar42 = _scalbn(auVar48,0x35 - uVar40);
            auVar9._8_8_ = 0;
            auVar9._0_8_ = dVar43;
            uVar55 = uVar57;
            auVar46 = _fmod(auVar9,uVar42);
            uVar57 = auVar46._8_8_;
            uVar42 = auVar46._0_4_;
            uVar51 = auVar46._4_4_;
            dVar43 = dVar52 + (dVar43 - auVar46._0_8_);
          }
          else {
            uVar42 = 0;
            uVar51 = 0;
            dVar52 = 0.0;
            uVar55 = uVar57;
          }
          dVar44 = (double)CONCAT44(uVar51,uVar42);
          uVar39 = uVar21 + 2 & 0x7f;
          if (uVar39 != uVar20) {
            uVar39 = *(uint *)((long)&local_2a8 + (ulong)uVar39 * 4);
            if (uVar39 < 500000000) {
              if ((uVar39 != 0) || ((uVar21 + 3 & 0x7f) != uVar20)) {
                dVar44 = 0.25;
LAB_00253080:
                dVar44 = dVar54 * dVar44 + (double)CONCAT44(uVar51,uVar42);
                uVar57 = 0;
              }
            }
            else {
              if ((500000000 < uVar39) || ((uVar21 + 3 & 0x7f) != uVar20)) {
                dVar44 = 0.75;
                goto LAB_00253080;
              }
              dVar44 = dVar54 * 0.5 + (double)CONCAT44(uVar51,uVar42);
              uVar57 = 0;
            }
            if ((1 < (int)(0x35 - uVar40)) &&
               (auVar49._8_8_ = uVar57, auVar49._0_8_ = dVar44, dVar54 = (double)_fmod(auVar49,0),
               dVar54 == 0.0)) {
              dVar44 = dVar44 + 1.0;
            }
          }
          dVar52 = (dVar43 + dVar44) - dVar52;
          if ((int)(-2 - (iVar19 + uVar18)) < (int)(iVar25 + 0x35U & 0x7fffffff)) {
            if (dVar53 <= ABS(dVar52)) {
              dVar52 = dVar52 * 0.5;
              bVar17 = (uVar40 != uVar4 || (int)uVar18 <= (int)uVar4) && bVar17;
              iVar25 = iVar25 + 1;
            }
            if (((int)-(iVar19 + uVar18) < iVar25 + 0x32) || ((dVar44 != 0.0 && (bVar17)))) {
              piVar22 = ___error();
              *piVar22 = 0x22;
            }
          }
          auVar50._8_8_ = 0;
          auVar50._0_8_ = dVar52;
          auVar46 = _scalbn(auVar50,iVar25);
          uVar57 = uVar55;
          local_450 = dVar53;
          dVar54 = auVar46._0_8_;
          goto LAB_00252b90;
        }
        break;
      }
      uVar4 = uVar21 + (int)lVar26 & 0x7f;
      if (uVar4 == uVar40) {
LAB_00252e50:
        lVar26 = 2;
        goto LAB_00252e54;
      }
      uVar4 = *(uint *)((long)&local_2a8 + (ulong)uVar4 * 4);
      puVar1 = &DAT_00c503ec + lVar26;
      if (uVar4 < *puVar1) goto LAB_00252e50;
      lVar26 = lVar26 + 1;
    } while (uVar4 <= *puVar1);
    iVar34 = 0;
    uVar4 = 9;
    if ((int)uVar36 < 0x1c) {
      uVar4 = 1;
    }
    for (uVar39 = uVar21; uVar39 != uVar40; uVar39 = uVar39 + 1 & 0x7f) {
      uVar5 = *(uint *)((long)&local_2a8 + (long)(int)uVar39 * 4);
      iVar8 = (uVar5 >> (ulong)uVar4) + iVar34;
      iVar34 = (uVar5 & (1 << (ulong)uVar4) - 1U) * (1000000000U >> (ulong)uVar4);
      *(int *)((long)&local_2a8 + (long)(int)uVar39 * 4) = iVar8;
      if ((uVar39 == uVar21) && (iVar8 == 0)) {
        uVar21 = uVar21 + 1 & 0x7f;
        uVar36 = (ulong)((int)uVar36 - 9);
      }
    }
    iVar25 = uVar4 + iVar25;
  } while (iVar34 == 0);
  if (uVar20 == uVar21) {
    *(uint *)((long)&local_2a8 + uVar30 * 4) = *(uint *)((long)&local_2a8 + uVar30 * 4) | 1;
    goto LAB_00252e0c;
  }
  *(int *)((long)&local_2a8 + (long)(int)uVar40 * 4) = iVar34;
  uVar29 = (ulong)uVar20;
  goto LAB_00252dec;
}


