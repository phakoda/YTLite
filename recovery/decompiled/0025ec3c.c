/* Decompiled from supplied 5.2.2 arm package. VA 0x25ec3c. _av_image_alloc */

int _av_image_alloc(long *param_1,int *param_2,uint param_3,int param_4,undefined4 param_5,
                   int param_6)

{
  uint uVar1;
  size_t sVar2;
  int iVar3;
  long lVar4;
  void *pvVar5;
  long lVar6;
  ulong uVar7;
  
  lVar4 = _av_pix_fmt_desc_get(param_5);
  if (lVar4 == 0) {
LAB_0025ed90:
    iVar3 = -0x16;
  }
  else {
    iVar3 = _av_image_check_size(param_3,param_4,0,0);
    if (iVar3 < 0) {
      return iVar3;
    }
    uVar1 = param_3 + 7 & 0xfffffff8;
    if (param_6 < 8) {
      uVar1 = param_3;
    }
    iVar3 = _av_image_fill_linesizes(param_2,param_5,uVar1);
    if (iVar3 < 0) {
      return iVar3;
    }
    for (lVar6 = 0; lVar6 != 0x10; lVar6 = lVar6 + 4) {
      *(int *)((long)param_2 + lVar6) = param_6 + -1 + *(int *)((long)param_2 + lVar6) & -param_6;
    }
    iVar3 = _av_image_fill_pointers(param_1,param_5,param_4,0,param_2);
    if (iVar3 < 0) {
      return iVar3;
    }
    pvVar5 = (void *)_av_malloc((long)(iVar3 + param_6));
    if (pvVar5 == (void *)0x0) {
      return -0xc;
    }
    iVar3 = _av_image_fill_pointers(param_1,param_5,param_4,pvVar5,param_2);
    if (iVar3 < 0) {
      _av_free(pvVar5);
      return iVar3;
    }
    uVar7 = *(ulong *)(lVar4 + 0x10);
    if (((uint)uVar7 >> 1 & 1) == 0) {
      if ((((uint)uVar7 >> 6 & 1) != 0) && (lVar6 = param_1[1], lVar6 != 0)) goto LAB_0025ed6c;
    }
    else {
      lVar6 = param_1[1];
LAB_0025ed6c:
      _avpriv_set_systematic_pal2(lVar6,param_5);
      if (param_6 < 4) {
        _av_log(0,0x10,"Formats with a palette require a minimum alignment of 4\n");
        goto LAB_0025ed90;
      }
      uVar7 = *(ulong *)(lVar4 + 0x10);
    }
    if (((uVar7 & 0x42) != 0) && (param_1[1] != 0)) {
      lVar6 = param_1[1] - *param_1;
      lVar4 = (long)*param_2 * (long)param_4;
      sVar2 = lVar6 - lVar4;
      if (sVar2 != 0 && lVar4 <= lVar6) {
        _bzero((void *)(*param_1 + lVar4),sVar2);
      }
    }
  }
  return iVar3;
}


