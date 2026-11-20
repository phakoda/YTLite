/* Decompiled from supplied 5.2.2 arm package. VA 0x259808. FUN_00259808 */

int FUN_00259808(undefined8 *param_1,long param_2)

{
  undefined4 *puVar1;
  undefined **ppuVar2;
  int iVar3;
  size_t sVar4;
  char *pcVar5;
  char cVar6;
  undefined4 uVar7;
  char *pcVar8;
  undefined **ppuVar9;
  long lVar10;
  ulong uVar11;
  long lVar12;
  undefined8 uVar13;
  char *local_70;
  undefined4 *local_68;
  
  local_68 = (undefined4 *)_av_mallocz(0x40);
  local_70 = *(char **)(param_2 + 0x10);
  if (local_68 == (undefined4 *)0x0) {
    return -0xc;
  }
  uVar13 = _av_strtod(local_70,&local_70);
  puVar1 = local_68;
  pcVar5 = local_70;
  *(undefined8 *)(local_68 + 2) = uVar13;
  if (local_70 != *(char **)(param_2 + 0x10)) {
    *local_68 = 0;
    *(char **)(param_2 + 0x10) = local_70;
    *param_1 = local_68;
    return 0;
  }
  *(undefined8 *)(local_68 + 2) = 0x3ff0000000000000;
  lVar12 = *(long *)(param_2 + 0x20);
  if (lVar12 != 0) {
    for (lVar10 = 0; pcVar8 = *(char **)(lVar12 + lVar10 * 8), pcVar8 != (char *)0x0;
        lVar10 = lVar10 + 1) {
      iVar3 = FUN_0025a1d4(pcVar5,pcVar8);
      if (iVar3 != 0) {
        sVar4 = _strlen(pcVar8);
        *(char **)(param_2 + 0x10) = pcVar5 + sVar4;
        *puVar1 = 1;
        puVar1[4] = (int)lVar10;
        *param_1 = puVar1;
        return 0;
      }
    }
  }
  uVar11 = 0xffffffffffffffff;
  ppuVar2 = &PTR_s_E_010642f8;
  while (ppuVar9 = ppuVar2, uVar11 = uVar11 + 1, uVar11 < 4) {
    pcVar8 = *ppuVar9;
    iVar3 = FUN_0025a1d4(pcVar5,pcVar8);
    ppuVar2 = ppuVar9 + 2;
    if (iVar3 != 0) {
      sVar4 = _strlen(pcVar8);
      *(char **)(param_2 + 0x10) = pcVar5 + sVar4;
      *puVar1 = 0;
      *(undefined **)(puVar1 + 2) = ppuVar9[1];
      *param_1 = puVar1;
      return 0;
    }
  }
  pcVar8 = _strchr(pcVar5,0x28);
  *(char **)(param_2 + 0x10) = pcVar8;
  if (pcVar8 == (char *)0x0) {
    _av_log(param_2,0x10,"Undefined constant or missing \'(\' in \'%s\'\n");
    *(char **)(param_2 + 0x10) = local_70;
  }
  else {
    *(char **)(param_2 + 0x10) = pcVar8 + 1;
    if (*pcVar5 == '(') {
      _av_freep(&local_68);
      iVar3 = FUN_0025855c(&local_68,param_2);
      if (iVar3 < 0) {
        return iVar3;
      }
      if (**(char **)(param_2 + 0x10) == ')') {
        *(char **)(param_2 + 0x10) = *(char **)(param_2 + 0x10) + 1;
        goto LAB_0025a110;
      }
      pcVar5 = "Missing \')\' in \'%s\'\n";
    }
    else {
      iVar3 = FUN_0025855c(puVar1 + 8,param_2);
      if (iVar3 < 0) {
        _av_expr_free(local_68);
        return iVar3;
      }
      pcVar5 = *(char **)(param_2 + 0x10);
      cVar6 = *pcVar5;
      if (cVar6 == ',') {
        *(char **)(param_2 + 0x10) = pcVar5 + 1;
        FUN_0025855c(local_68 + 10,param_2);
        pcVar5 = *(char **)(param_2 + 0x10);
        cVar6 = *pcVar5;
        if (cVar6 == ',') {
          *(char **)(param_2 + 0x10) = pcVar5 + 1;
          FUN_0025855c(local_68 + 0xc,param_2);
          pcVar5 = *(char **)(param_2 + 0x10);
          cVar6 = *pcVar5;
        }
      }
      puVar1 = local_68;
      pcVar8 = local_70;
      if (cVar6 == ')') {
        *(char **)(param_2 + 0x10) = pcVar5 + 1;
        *local_68 = 2;
        iVar3 = FUN_0025a1d4(local_70,"sinh");
        if (iVar3 != 0) {
          *(undefined **)(puVar1 + 6) = PTR__sinh_01061238;
LAB_0025a110:
          *param_1 = local_68;
          return 0;
        }
        iVar3 = FUN_0025a1d4(pcVar8,"cosh");
        if (iVar3 != 0) {
          *(undefined **)(puVar1 + 6) = PTR__cosh_010608b8;
          goto LAB_0025a110;
        }
        iVar3 = FUN_0025a1d4(pcVar8,"tanh");
        if (iVar3 != 0) {
          *(undefined **)(puVar1 + 6) = PTR__tanh_01061340;
          goto LAB_0025a110;
        }
        iVar3 = FUN_0025a1d4(pcVar8,"sin");
        if (iVar3 != 0) {
          *(undefined **)(puVar1 + 6) = PTR__sin_01061228;
          goto LAB_0025a110;
        }
        iVar3 = FUN_0025a1d4(pcVar8,"cos");
        if (iVar3 != 0) {
          *(undefined **)(puVar1 + 6) = PTR__cos_010608a8;
          goto LAB_0025a110;
        }
        iVar3 = FUN_0025a1d4(pcVar8,"tan");
        if (iVar3 != 0) {
          *(undefined **)(puVar1 + 6) = PTR__tan_01061330;
          goto LAB_0025a110;
        }
        iVar3 = FUN_0025a1d4(pcVar8,"atan");
        if (iVar3 != 0) {
          *(undefined **)(puVar1 + 6) = PTR__atan_010607e0;
          goto LAB_0025a110;
        }
        iVar3 = FUN_0025a1d4(pcVar8,"asin");
        if (iVar3 != 0) {
          *(undefined **)(puVar1 + 6) = PTR__asin_010607c8;
          goto LAB_0025a110;
        }
        iVar3 = FUN_0025a1d4(pcVar8,"acos");
        if (iVar3 != 0) {
          *(undefined **)(puVar1 + 6) = PTR__acos_01060798;
          goto LAB_0025a110;
        }
        iVar3 = FUN_0025a1d4(pcVar8,"exp");
        if (iVar3 != 0) {
          *(undefined **)(puVar1 + 6) = PTR__exp_010609d0;
          goto LAB_0025a110;
        }
        iVar3 = FUN_0025a1d4(pcVar8,"log");
        if (iVar3 != 0) {
          *(undefined **)(puVar1 + 6) = PTR__log_01060ea8;
          goto LAB_0025a110;
        }
        iVar3 = FUN_0025a1d4(pcVar8,"abs");
        if (iVar3 != 0) {
          *(undefined **)(puVar1 + 6) = PTR__fabs_010609f0;
          goto LAB_0025a110;
        }
        iVar3 = FUN_0025a1d4(pcVar8,"time");
        if (iVar3 != 0) {
          *(code **)(puVar1 + 6) = FUN_0025a22c;
          goto LAB_0025a110;
        }
        iVar3 = FUN_0025a1d4(pcVar8,"squish");
        if (iVar3 != 0) {
          *puVar1 = 5;
          goto LAB_0025a110;
        }
        iVar3 = FUN_0025a1d4(pcVar8,"gauss");
        if (iVar3 != 0) {
          *puVar1 = 6;
          goto LAB_0025a110;
        }
        iVar3 = FUN_0025a1d4(pcVar8,"mod");
        if (iVar3 != 0) {
          *puVar1 = 10;
          goto LAB_0025a110;
        }
        iVar3 = FUN_0025a1d4(pcVar8,"max");
        if (iVar3 != 0) {
          *puVar1 = 0xb;
          goto LAB_0025a110;
        }
        iVar3 = FUN_0025a1d4(pcVar8,"min");
        if (iVar3 != 0) {
          *puVar1 = 0xc;
          goto LAB_0025a110;
        }
        iVar3 = FUN_0025a1d4(pcVar8,"eq");
        if (iVar3 != 0) {
          *puVar1 = 0xd;
          goto LAB_0025a110;
        }
        iVar3 = FUN_0025a1d4(pcVar8,"gte");
        if (iVar3 != 0) {
          *puVar1 = 0xf;
          goto LAB_0025a110;
        }
        iVar3 = FUN_0025a1d4(pcVar8,"gt");
        if (iVar3 != 0) {
          *puVar1 = 0xe;
          goto LAB_0025a110;
        }
        iVar3 = FUN_0025a1d4(pcVar8,"lte");
        if (iVar3 != 0) {
          *puVar1 = 0x10;
          goto LAB_0025a110;
        }
        iVar3 = FUN_0025a1d4(pcVar8,"lt");
        if (iVar3 != 0) {
          *puVar1 = 0x11;
          goto LAB_0025a110;
        }
        iVar3 = FUN_0025a1d4(pcVar8,"ld");
        if (iVar3 != 0) {
          *puVar1 = 7;
          goto LAB_0025a110;
        }
        iVar3 = FUN_0025a1d4(pcVar8,"isnan");
        if (iVar3 != 0) {
          *puVar1 = 8;
          goto LAB_0025a110;
        }
        iVar3 = FUN_0025a1d4(pcVar8,"isinf");
        if (iVar3 != 0) {
          *puVar1 = 9;
          goto LAB_0025a110;
        }
        iVar3 = FUN_0025a1d4(pcVar8,"st");
        if (iVar3 != 0) {
          *puVar1 = 0x17;
          goto LAB_0025a110;
        }
        iVar3 = FUN_0025a1d4(pcVar8,"while");
        if (iVar3 != 0) {
          *puVar1 = 0x18;
          goto LAB_0025a110;
        }
        iVar3 = FUN_0025a1d4(pcVar8,"taylor");
        if (iVar3 != 0) {
          *puVar1 = 0x19;
          goto LAB_0025a110;
        }
        iVar3 = FUN_0025a1d4(pcVar8,"root");
        if (iVar3 != 0) {
          *puVar1 = 0x1a;
          goto LAB_0025a110;
        }
        iVar3 = FUN_0025a1d4(pcVar8,"floor");
        if (iVar3 != 0) {
          *puVar1 = 0x1b;
          goto LAB_0025a110;
        }
        iVar3 = FUN_0025a1d4(pcVar8,"ceil");
        if (iVar3 != 0) {
          *puVar1 = 0x1c;
          goto LAB_0025a110;
        }
        iVar3 = FUN_0025a1d4(pcVar8,"trunc");
        if (iVar3 != 0) {
          *puVar1 = 0x1d;
          goto LAB_0025a110;
        }
        iVar3 = FUN_0025a1d4(pcVar8,"round");
        if (iVar3 != 0) {
          *puVar1 = 0x1e;
          goto LAB_0025a110;
        }
        iVar3 = FUN_0025a1d4(pcVar8,"sqrt");
        if (iVar3 != 0) {
          *puVar1 = 0x1f;
          goto LAB_0025a110;
        }
        iVar3 = FUN_0025a1d4(pcVar8,"not");
        if (iVar3 != 0) {
          *puVar1 = 0x20;
          goto LAB_0025a110;
        }
        iVar3 = FUN_0025a1d4(pcVar8,"pow");
        if (iVar3 != 0) {
          *puVar1 = 0x12;
          goto LAB_0025a110;
        }
        iVar3 = FUN_0025a1d4(pcVar8,"print");
        if (iVar3 != 0) {
          *puVar1 = 0x26;
          goto LAB_0025a110;
        }
        iVar3 = FUN_0025a1d4(pcVar8,"random");
        if (iVar3 != 0) {
          *puVar1 = 0x21;
          goto LAB_0025a110;
        }
        iVar3 = FUN_0025a1d4(pcVar8,"hypot");
        if (iVar3 != 0) {
          *puVar1 = 0x22;
          goto LAB_0025a110;
        }
        iVar3 = FUN_0025a1d4(pcVar8,"gcd");
        if (iVar3 != 0) {
          *puVar1 = 0x23;
          goto LAB_0025a110;
        }
        iVar3 = FUN_0025a1d4(pcVar8,"if");
        if (iVar3 != 0) {
          *puVar1 = 0x24;
          goto LAB_0025a110;
        }
        iVar3 = FUN_0025a1d4(pcVar8,"ifnot");
        if (iVar3 != 0) {
          *puVar1 = 0x25;
          goto LAB_0025a110;
        }
        iVar3 = FUN_0025a1d4(pcVar8,"bitand");
        if (iVar3 != 0) {
          *puVar1 = 0x27;
          goto LAB_0025a110;
        }
        iVar3 = FUN_0025a1d4(pcVar8,"bitor");
        if (iVar3 != 0) {
          *puVar1 = 0x28;
          goto LAB_0025a110;
        }
        iVar3 = FUN_0025a1d4(pcVar8,"between");
        if (iVar3 != 0) {
          *puVar1 = 0x29;
          goto LAB_0025a110;
        }
        iVar3 = FUN_0025a1d4(pcVar8,"clip");
        if (iVar3 != 0) {
          *puVar1 = 0x2a;
          goto LAB_0025a110;
        }
        iVar3 = FUN_0025a1d4(pcVar8,"atan2");
        if (iVar3 != 0) {
          *puVar1 = 0x2b;
          goto LAB_0025a110;
        }
        iVar3 = FUN_0025a1d4(pcVar8,"lerp");
        if (iVar3 != 0) {
          *puVar1 = 0x2c;
          goto LAB_0025a110;
        }
        iVar3 = FUN_0025a1d4(pcVar8,"sgn");
        if (iVar3 != 0) {
          *puVar1 = 0x2d;
          goto LAB_0025a110;
        }
        lVar12 = *(long *)(param_2 + 0x30);
        if (lVar12 != 0) {
          for (lVar10 = 0; *(long *)(lVar12 + lVar10 * 8) != 0; lVar10 = lVar10 + 1) {
            iVar3 = FUN_0025a1d4(pcVar8);
            if (iVar3 != 0) {
              *(undefined8 *)(puVar1 + 6) = *(undefined8 *)(*(long *)(param_2 + 0x28) + lVar10 * 8);
              uVar7 = 3;
              goto LAB_0025a1bc;
            }
          }
        }
        lVar12 = *(long *)(param_2 + 0x40);
        if (lVar12 != 0) {
          for (lVar10 = 0; *(long *)(lVar12 + lVar10 * 8) != 0; lVar10 = lVar10 + 1) {
            iVar3 = FUN_0025a1d4(pcVar8);
            if (iVar3 != 0) {
              *(undefined8 *)(puVar1 + 6) = *(undefined8 *)(*(long *)(param_2 + 0x38) + lVar10 * 8);
              uVar7 = 4;
LAB_0025a1bc:
              *local_68 = uVar7;
              local_68[4] = (int)lVar10;
              goto LAB_0025a110;
            }
          }
        }
        pcVar5 = "Unknown function in \'%s\'\n";
      }
      else {
        pcVar5 = "Missing \')\' or too many args in \'%s\'\n";
      }
    }
    _av_log(param_2,0x10,pcVar5);
  }
  _av_expr_free(local_68);
  return -0x16;
}


