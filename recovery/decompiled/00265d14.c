/* Decompiled from supplied 5.2.2 arm package. VA 0x265d14. _av_opt_copy */

int _av_opt_copy(long *param_1,long *param_2)

{
  long *plVar1;
  long *plVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  uint uVar8;
  long lVar9;
  
  if (((param_2 == (long *)0x0) || (*param_2 == 0)) || (*param_2 != *param_1)) {
    iVar5 = -0x16;
  }
  else {
    lVar9 = 0;
    iVar3 = 0;
switchD_00265ddc_caseD_a:
    iVar5 = iVar3;
    lVar9 = _av_opt_next(param_2,lVar9);
    if (lVar9 != 0) {
      lVar7 = *(long *)(lVar9 + 0x10);
      plVar1 = (long *)((long)param_1 + (long)(int)lVar7);
      plVar2 = (long *)((long)param_2 + (long)(int)lVar7);
      uVar8 = (uint)((ulong)lVar7 >> 0x20);
      iVar3 = iVar5;
      switch(uVar8) {
      case 5:
        lVar7 = *plVar1;
        if (lVar7 != *plVar2) {
          _av_freep(plVar1);
          lVar7 = *plVar2;
        }
        lVar7 = _av_strdup(lVar7);
        *plVar1 = lVar7;
        iVar3 = -0xc;
        if (*plVar2 == 0 || lVar7 != 0) {
          iVar3 = iVar5;
        }
        break;
      default:
        if (uVar8 < 0x13) {
          iVar3 = *(int *)(&DAT_00c51290 + (lVar7 >> 0x20) * 4);
          if ((lVar7 >> 0x20 & 0xfffffffffffffffdU) != 8) {
            _memcpy(plVar1,plVar2,(long)*(int *)(&DAT_00c51290 + (lVar7 >> 0x20) * 4));
            iVar3 = iVar5;
          }
        }
        else {
          iVar3 = -0x16;
        }
        break;
      case 7:
        lVar7 = *plVar1;
        iVar6 = (int)plVar2[1];
        if (lVar7 != *plVar2) {
          _av_freep(plVar1);
          lVar7 = *plVar2;
        }
        lVar7 = _av_memdup(lVar7,(long)iVar6);
        *plVar1 = lVar7;
        iVar3 = -0xc;
        iVar4 = 0;
        if (iVar6 == 0 || lVar7 != 0) {
          iVar3 = iVar5;
          iVar4 = iVar6;
        }
        *(int *)(plVar1 + 1) = iVar4;
        break;
      case 8:
        if (*plVar2 != *plVar1) {
          _av_dict_free(plVar1);
        }
        *plVar1 = 0;
        _av_dict_copy(plVar1,*plVar2,0);
        iVar5 = _av_dict_count(*plVar2);
        iVar6 = _av_dict_count(*plVar1);
        if (iVar5 != iVar6) {
          iVar3 = -0xc;
        }
        break;
      case 10:
        break;
      }
      goto switchD_00265ddc_caseD_a;
    }
  }
  return iVar5;
}


