/* Decompiled from supplied 5.2.2 arm package. VA 0x25f0d8. FUN_0025f0d8 */

void FUN_0025f0d8(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
                 undefined4 param_5,int param_6,int param_7,code *param_8)

{
  int iVar1;
  int iVar2;
  long lVar3;
  void *pvVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  ulong uVar8;
  
  lVar3 = _av_pix_fmt_desc_get(param_5);
  if ((lVar3 != 0) && (((uint)*(ulong *)(lVar3 + 0x10) >> 3 & 1) == 0)) {
    if ((*(ulong *)(lVar3 + 0x10) & 0x42) == 0) {
      iVar5 = 0;
      iVar2 = *(byte *)(lVar3 + 8) + 1;
      piVar7 = (int *)(lVar3 + 0x18);
      while (iVar2 = iVar2 + -1, iVar2 != 0) {
        piVar6 = piVar7 + 8;
        iVar1 = *piVar7;
        piVar7 = piVar6;
        if (iVar5 <= iVar1 + 1) {
          iVar5 = iVar1 + 1;
        }
      }
      for (uVar8 = 0; (long)uVar8 < (long)iVar5; uVar8 = uVar8 + 1) {
        iVar2 = _av_image_get_linesize(param_5,param_6,uVar8 & 0xffffffff);
        if (iVar2 < 0) {
          _av_log(0,0x10,"av_image_get_linesize failed\n");
          return;
        }
        iVar1 = param_7;
        if ((int)uVar8 - 1U < 2) {
          iVar1 = -(-param_7 >> (*(byte *)(lVar3 + 10) & 0x1f));
        }
        (*param_8)(param_1[uVar8],param_2[uVar8],param_3[uVar8],param_4[uVar8],(long)iVar2,iVar1);
      }
    }
    else {
      (*param_8)(*param_1,*param_2,*param_3,*param_4,(long)param_6,param_7);
      if ((*(byte *)(lVar3 + 0x10) >> 1 & 1) == 0) {
        if ((void *)param_1[1] == (void *)0x0) {
          return;
        }
        pvVar4 = (void *)param_3[1];
        if (pvVar4 == (void *)0x0) {
          return;
        }
      }
      else {
        pvVar4 = (void *)param_3[1];
      }
      _memcpy((void *)param_1[1],pvVar4,0x400);
    }
  }
  return;
}


