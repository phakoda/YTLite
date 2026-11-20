/* Decompiled from supplied 5.2.2 arm package. VA 0x26d99c. _av_tree_insert */

long _av_tree_insert(long *param_1,long param_2,code *param_3,long *param_4)

{
  uint uVar1;
  bool bVar2;
  uint uVar3;
  long lVar4;
  ulong uVar5;
  int iVar6;
  long lVar7;
  long lVar8;
  long *plVar9;
  long alStack_78 [3];
  
  lVar8 = *(long *)PTR____stack_chk_guard_01060708;
  plVar9 = (long *)*param_1;
  alStack_78[2] = lVar8;
  if (plVar9 == (long *)0x0) {
    *param_1 = *param_4;
    *param_4 = 0;
    if (*param_1 != 0) {
      *(long *)(*param_1 + 0x10) = param_2;
      param_2 = 0;
    }
    goto LAB_0026db9c;
  }
  uVar3 = (*param_3)(plVar9[2],param_2);
  if (uVar3 == 0) {
    if (*param_4 != 0) {
      param_2 = plVar9[2];
      goto LAB_0026db9c;
    }
    if ((*plVar9 == 0) && (plVar9[1] == 0)) {
      param_2 = 0;
      *param_4 = (long)plVar9;
      *param_1 = 0;
      goto LAB_0026db9c;
    }
    bVar2 = *plVar9 == 0;
    uVar3 = -(uint)bVar2;
    _av_tree_find(plVar9[bVar2],param_2,param_3,alStack_78);
    param_2 = alStack_78[bVar2];
    plVar9[2] = param_2;
  }
  lVar4 = _av_tree_insert(plVar9 + (uVar3 >> 0x1f),param_2,param_3,param_4);
  if (lVar4 == 0) {
    uVar3 = (uint)(*param_4 != 0) ^ uVar3 >> 0x1f;
    uVar5 = (ulong)uVar3;
    uVar1 = ((int)plVar9[3] + uVar3 * 2) - 1;
    *(uint *)(plVar9 + 3) = uVar1;
    if ((uVar1 == 0) || ((uVar1 & 1) != 0)) {
      iVar6 = *(int *)(*param_1 + 0x18);
    }
    else {
      lVar7 = plVar9[uVar5];
      if (uVar1 + *(int *)(lVar7 + 0x18) * 2 == 0) {
        uVar3 = uVar3 ^ 1;
        lVar7 = *(long *)(lVar7 + (ulong)uVar3 * 8);
        *param_1 = lVar7;
        *(undefined8 *)(plVar9[uVar5] + (ulong)uVar3 * 8) = *(undefined8 *)(lVar7 + uVar5 * 8);
        *(long *)(*param_1 + uVar5 * 8) = plVar9[uVar5];
        plVar9[uVar5] = *(long *)(*param_1 + (ulong)uVar3 * 8);
        *(long **)(*param_1 + (ulong)uVar3 * 8) = plVar9;
        param_1 = (long *)*param_1;
        *(uint *)(*param_1 + 0x18) = -(uint)(0 < (int)param_1[3]);
        *(uint *)(param_1[1] + 0x18) = *(uint *)(param_1 + 3) >> 0x1f;
        *(undefined4 *)(param_1 + 3) = 0;
        if (*param_4 == 0) goto LAB_0026db9c;
        goto LAB_0026db98;
      }
      *param_1 = lVar7;
      plVar9[uVar5] = *(long *)(plVar9[uVar5] + (ulong)(uVar3 ^ 1) * 8);
      *(long **)(*param_1 + (ulong)(uVar3 ^ 1) * 8) = plVar9;
      lVar7 = *param_1;
      if (*(int *)(lVar7 + 0x18) == 0) {
        iVar6 = (int)plVar9[3] >> 1;
      }
      else {
        iVar6 = 0;
      }
      *(int *)(plVar9 + 3) = iVar6;
      iVar6 = -iVar6;
      *(int *)(lVar7 + 0x18) = iVar6;
    }
    if ((iVar6 == 0) != (*param_4 != 0)) goto LAB_0026db9c;
  }
LAB_0026db98:
  param_2 = lVar4;
LAB_0026db9c:
  if (lVar8 != alStack_78[2]) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  return param_2;
}


