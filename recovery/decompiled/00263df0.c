/* Decompiled from supplied 5.2.2 arm package. VA 0x263df0. _av_opt_get */

undefined4 _av_opt_get(undefined8 param_1,undefined8 param_2,uint param_3,long *param_4)

{
  long *plVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  long lVar5;
  undefined1 *puVar6;
  size_t sVar7;
  char *pcVar8;
  ulong uVar9;
  int iVar10;
  long lVar11;
  long local_e0;
  char local_d8 [128];
  long local_58;
  
  lVar11 = *(long *)PTR____stack_chk_guard_01060708;
  uVar4 = 0xabafb008;
  local_58 = lVar11;
  lVar5 = _av_opt_find2(param_1,param_2,0,0,param_3,&local_e0);
  if (((lVar5 == 0) || (local_e0 == 0)) ||
     (uVar9 = *(ulong *)(lVar5 + 0x10),
     (int)uVar9 < 1 && (uVar9 & 0xffffffff00000000) != 0xa00000000)) goto LAB_00264100;
  if ((*(byte *)(lVar5 + 0x32) >> 1 & 1) != 0) {
    _av_log(param_1,0x18,"The \"%s\" option is deprecated: %s\n");
    uVar9 = (ulong)*(uint *)(lVar5 + 0x10);
  }
  local_d8[0] = '\0';
  if (0x12 < *(uint *)(lVar5 + 0x14)) goto LAB_002640e0;
  plVar1 = (long *)(local_e0 + (int)uVar9);
  switch(*(uint *)(lVar5 + 0x14)) {
  case 0:
    pcVar8 = "0x%08X";
    break;
  case 1:
    pcVar8 = "%d";
    break;
  case 2:
    pcVar8 = "%lld";
    break;
  case 3:
    goto LAB_00263fe8;
  case 4:
    goto LAB_00263fe8;
  case 5:
    pcVar8 = (char *)*plVar1;
    if (pcVar8 == (char *)0x0) {
      if ((param_3 >> 2 & 1) != 0) goto LAB_00263fc8;
      pcVar8 = "";
    }
    goto LAB_002640ec;
  default:
    pcVar8 = "%d/%d";
    break;
  case 7:
    if (((param_3 >> 2 & 1) == 0) || (*plVar1 != 0)) {
      iVar2 = (int)plVar1[1];
      if (((ulong)(long)iVar2 >> 0x1e & 0x1ffffffff) == 0) {
        puVar6 = (undefined1 *)_av_malloc((long)(int)(iVar2 << 1 | 1));
        *param_4 = (long)puVar6;
        if (puVar6 == (undefined1 *)0x0) {
          uVar4 = 0xfffffff4;
        }
        else if (iVar2 == 0) {
          uVar4 = 0;
          *puVar6 = 0;
        }
        else {
          iVar10 = 0;
          for (lVar5 = 0; lVar5 < iVar2; lVar5 = lVar5 + 1) {
            ___snprintf_chk(*param_4 + (long)iVar10,3,0,0xffffffffffffffff,"%02X");
            iVar10 = iVar10 + 2;
          }
          uVar4 = 0;
        }
        goto LAB_00264100;
      }
      goto LAB_002640e0;
    }
    goto LAB_00263fc8;
  case 8:
    if (((param_3 >> 2 & 1) == 0) || (*plVar1 != 0)) {
      uVar4 = _av_dict_get_string(*plVar1,param_4,0x3d,0x3a);
      goto LAB_00264100;
    }
LAB_00263fc8:
    uVar4 = 0;
    *param_4 = 0;
    goto LAB_00264100;
  case 9:
    pcVar8 = "%llu";
    break;
  case 10:
LAB_00263fe8:
    pcVar8 = "%f";
    break;
  case 0xb:
    pcVar8 = "%dx%d";
    break;
  case 0xc:
    _av_get_pix_fmt_name((int)*plVar1);
    goto LAB_002640b8;
  case 0xd:
    _av_get_sample_fmt_name((int)*plVar1);
    goto LAB_002640b8;
  case 0xf:
    FUN_002641a8(local_d8,0x80,*plVar1);
    sVar7 = _strlen(local_d8);
    uVar3 = (uint)sVar7;
    goto LAB_002640d8;
  case 0x10:
    pcVar8 = "0x%02x%02x%02x%02x";
    break;
  case 0x11:
    pcVar8 = "0x%llx";
    break;
  case 0x12:
LAB_002640b8:
    pcVar8 = "%s";
  }
  uVar3 = ___snprintf_chk(local_d8,0x80,0,0x80,pcVar8);
LAB_002640d8:
  if (uVar3 < 0x80) {
    pcVar8 = local_d8;
LAB_002640ec:
    lVar5 = _av_strdup(pcVar8);
    *param_4 = lVar5;
    uVar4 = 0;
    if (lVar5 == 0) {
      uVar4 = 0xfffffff4;
    }
  }
  else {
LAB_002640e0:
    uVar4 = 0xffffffea;
  }
LAB_00264100:
  if (lVar11 != local_58) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  return uVar4;
}


