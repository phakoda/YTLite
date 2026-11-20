/* Decompiled from supplied 5.2.2 arm package. VA 0x2583c4. _av_expr_parse */

int _av_expr_parse(long *param_1,char *param_2,undefined8 param_3,undefined8 param_4,
                  undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined4 param_8,
                  undefined8 param_9)

{
  char cVar1;
  uint uVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  size_t sVar6;
  char *pcVar7;
  long lVar8;
  char *pcVar9;
  long local_d0;
  undefined **local_c8;
  undefined4 local_c0;
  char *local_b8;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined4 local_78;
  undefined8 local_70;
  
  _memset(&local_c8,0,0x68);
  local_d0 = 0;
  sVar6 = _strlen(param_2);
  pcVar7 = (char *)_av_malloc(sVar6 + 1);
  pcVar9 = pcVar7;
  if (pcVar7 == (char *)0x0) {
    return -0xc;
  }
  while( true ) {
    cVar1 = *param_2;
    if (cVar1 == 0) break;
    param_2 = param_2 + 1;
    uVar2 = (int)cVar1 - 9;
    if ((0x17 < uVar2) || ((0x80001fU >> (ulong)(uVar2 & 0x1f) & 1) == 0)) {
      *pcVar9 = cVar1;
      pcVar9 = pcVar9 + 1;
    }
  }
  *pcVar9 = '\0';
  local_c8 = &PTR_s_Eval_010642a0;
  local_c0 = 100;
  local_70 = param_9;
  local_b8 = pcVar7;
  local_a8 = param_3;
  uStack_a0 = param_5;
  local_98 = param_4;
  uStack_90 = param_7;
  local_88 = param_6;
  local_78 = param_8;
  iVar4 = FUN_0025855c(&local_d0,&local_c8);
  lVar3 = local_d0;
  if (-1 < iVar4) {
    if (*local_b8 == '\0') {
      iVar5 = FUN_00258644(local_d0);
      if (iVar5 != 0) {
        lVar8 = _av_mallocz(0x50);
        *(long *)(lVar3 + 0x38) = lVar8;
        if (lVar8 == 0) {
          iVar4 = -0xc;
        }
        else {
          *param_1 = lVar3;
          local_d0 = 0;
        }
        goto LAB_00258520;
      }
    }
    else {
      _av_log(&local_c8,0x10,"Invalid chars \'%s\' at the end of expression \'%s\'\n");
    }
    iVar4 = -0x16;
  }
LAB_00258520:
  _av_expr_free(local_d0);
  _av_free(pcVar7);
  return iVar4;
}


