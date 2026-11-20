/* Decompiled from supplied 5.2.2 arm package. VA 0x24e20c. FUN_0024e20c */

void FUN_0024e20c(long param_1,long param_2,short *param_3,int param_4,int param_5)

{
  undefined2 uVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  short *psVar5;
  int iVar6;
  short *psVar7;
  
  if (param_5 < 1) {
                    /* WARNING: Subroutine does not return */
    ___assert_rtn("WebRtcSpl_FilterARFastQ12","signal_processing/filter_ar_fast_q12.c",0x18,
                  "data_length > 0");
  }
  if (1 < param_4) {
    psVar5 = (short *)(param_2 + (1 - (long)param_4) * 2);
    for (lVar4 = 0; (int)lVar4 != param_5; lVar4 = lVar4 + 1) {
      iVar6 = 0;
      psVar7 = psVar5;
      lVar3 = (long)param_4;
      while (1 < lVar3) {
        iVar6 = iVar6 + (int)*psVar7 * (int)param_3[lVar3 + -1];
        psVar7 = psVar7 + 1;
        lVar3 = lVar3 + -1;
      }
      iVar6 = (int)*(short *)(param_1 + lVar4 * 2) * (int)*param_3 - iVar6;
      iVar2 = -0x8000000;
      if (-0x8000001 < iVar6) {
        iVar2 = iVar6;
      }
      uVar1 = 0x7fff;
      if (iVar6 < 0x7fff800) {
        uVar1 = (short)(iVar2 + 0x800U >> 0xc);
      }
      *(undefined2 *)(param_2 + lVar4 * 2) = uVar1;
      psVar5 = psVar5 + 1;
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___assert_rtn("WebRtcSpl_FilterARFastQ12","signal_processing/filter_ar_fast_q12.c",0x19,
                "coefficients_length > 1");
}


