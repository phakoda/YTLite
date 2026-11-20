/* Decompiled from supplied 5.2.2 arm package. VA 0x27b738. FUN_0027b738 */

int FUN_0027b738(long param_1,int param_2)

{
  undefined **ppuVar1;
  int *piVar2;
  long *plVar3;
  undefined **ppuVar4;
  int iVar5;
  void *pvVar6;
  int iVar7;
  long lVar8;
  long lVar9;
  void *local_68;
  
  lVar8 = *(long *)(param_1 + 0x48);
  pvVar6 = (void *)_av_strdup(*(undefined8 *)(lVar8 + 0x48));
  if (pvVar6 == (void *)0x0) {
    return -0xc;
  }
  if (*(long *)(lVar8 + 0x48) == 0) {
    _av_log(param_1,0x10,"Channels expressions list is empty\n");
    return -0x16;
  }
  iVar5 = _strcmp((char *)**(undefined8 **)(param_1 + 8),"aeval");
  lVar9 = 0;
  ppuVar1 = &PTR_FUN_0106da28;
  piVar2 = (int *)(lVar8 + 0x28);
  if (iVar5 != 0) {
    ppuVar1 = (undefined **)0x0;
  }
  plVar3 = (long *)(lVar8 + 0x40);
  for (; lVar9 < *piVar2; lVar9 = lVar9 + 1) {
    _av_expr_free(*(undefined8 *)(*plVar3 + lVar9 * 8));
    *(undefined8 *)(*plVar3 + lVar9 * 8) = 0;
  }
  ppuVar4 = &PTR_s_val_0106da38;
  if (iVar5 != 0) {
    ppuVar4 = (undefined **)0x0;
  }
  _av_freep(plVar3);
  iVar5 = 0;
  *piVar2 = 0;
  lVar8 = 0;
  local_68 = pvVar6;
  do {
    lVar9 = _av_strtok(local_68,"|",&local_68);
    if (lVar9 == 0) {
      if (param_2 <= *piVar2) goto LAB_0027b98c;
      iVar7 = *piVar2 + -1;
      goto LAB_0027b8e4;
    }
    lVar8 = _av_dynarray2_add(plVar3,piVar2,8,0);
    if (lVar8 == 0) {
      iVar5 = -0xc;
      break;
    }
    lVar8 = (long)*piVar2 * 8 + -8;
    *(undefined8 *)(*plVar3 + lVar8) = 0;
    iVar5 = _av_expr_parse(*plVar3 + lVar8,lVar9,&PTR_s_ch_0106da48,ppuVar4,ppuVar1,0,0,0,param_1);
    lVar8 = lVar9;
  } while (-1 < iVar5);
  goto LAB_0027b960;
LAB_0027b98c:
  if ((0 < param_2) && (*piVar2 != param_2)) {
    _av_log(param_1,0x10,
            "Mismatch between the specified number of channel expressions \'%d\' and the number of expected output channels \'%d\' for the specified channel layout\n"
           );
    iVar5 = -0x16;
  }
  goto LAB_0027b960;
  while( true ) {
    lVar9 = (long)*piVar2 * 8 + -8;
    *(undefined8 *)(*plVar3 + lVar9) = 0;
    iVar5 = _av_expr_parse(*plVar3 + lVar9,lVar8,&PTR_s_ch_0106da48,ppuVar4,ppuVar1,0,0,0,param_1);
    if (iVar5 < 0) break;
LAB_0027b8e4:
    iVar7 = iVar7 + 1;
    if (param_2 <= iVar7) goto LAB_0027b98c;
    lVar9 = _av_dynarray2_add(plVar3,piVar2,8,0);
    if (lVar9 == 0) {
      iVar5 = -0xc;
      break;
    }
  }
LAB_0027b960:
  _av_free(pvVar6);
  return iVar5;
}


