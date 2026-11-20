/* Decompiled from supplied 5.2.2 arm package. VA 0x267af0. _av_find_info_tag */

void _av_find_info_tag(byte *param_1,int param_2,char *param_3,byte *param_4)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  undefined8 uVar4;
  byte *pbVar5;
  byte *pbVar6;
  long lVar7;
  byte *pbVar8;
  byte local_e8 [128];
  long local_68;
  
  lVar7 = *(long *)PTR____stack_chk_guard_01060708;
  pbVar8 = param_4 + 1;
  if (*param_4 != 0x3f) {
    pbVar8 = param_4;
  }
  pbVar5 = local_e8;
  local_68 = lVar7;
  do {
    bVar2 = *pbVar8;
    if ((bVar2 < 0x3e) && ((1L << ((ulong)bVar2 & 0x3f) & 0x2000004000000001U) != 0)) {
      *pbVar5 = 0;
      pbVar5 = param_1;
      if (*pbVar8 == 0x3d) {
        do {
          pbVar6 = pbVar8;
          do {
            pbVar8 = pbVar6 + 1;
            bVar2 = *pbVar8;
            if ((bVar2 == 0) || (bVar2 == 0x26)) {
              pbVar8 = pbVar6 + 1;
              goto LAB_00267bd0;
            }
            pbVar6 = pbVar8;
          } while ((long)(param_2 + -1) <= (long)pbVar5 - (long)param_1);
          bVar1 = 0x20;
          if (bVar2 != 0x2b) {
            bVar1 = bVar2;
          }
          *pbVar5 = bVar1;
          pbVar5 = pbVar5 + 1;
        } while( true );
      }
LAB_00267bd0:
      *pbVar5 = 0;
      iVar3 = _strcmp((char *)local_e8,param_3);
      if (iVar3 == 0) {
        uVar4 = 1;
        goto LAB_00267c18;
      }
      if (*pbVar8 != 0x26) {
        uVar4 = 0;
LAB_00267c18:
        if (lVar7 != local_68) {
                    /* WARNING: Subroutine does not return */
          ___stack_chk_fail(uVar4);
        }
        return;
      }
      pbVar6 = local_e8;
    }
    else {
      pbVar6 = pbVar5;
      if ((ulong)((long)pbVar5 - (long)local_e8) < 0x7f) {
        pbVar6 = pbVar5 + 1;
        *pbVar5 = bVar2;
      }
    }
    pbVar8 = pbVar8 + 1;
    pbVar5 = pbVar6;
  } while( true );
}


