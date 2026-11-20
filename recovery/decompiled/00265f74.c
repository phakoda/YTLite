/* Decompiled from supplied 5.2.2 arm package. VA 0x265f74. _av_opt_query_ranges_default */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
_av_opt_query_ranges_default
          (undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  void *pvVar3;
  long lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  
  puVar1 = (undefined8 *)_av_mallocz(0x10);
  puVar2 = (undefined8 *)_av_mallocz(8);
  pvVar3 = (void *)_av_mallocz(0x30);
  lVar4 = _av_opt_find2(param_2,param_3,0,0,param_4,0);
  *param_1 = 0;
  uVar5 = 0xfffffff4;
  if ((((lVar4 == 0) || (puVar2 == (undefined8 *)0x0)) || (puVar1 == (undefined8 *)0x0)) ||
     (pvVar3 == (void *)0x0)) {
switchD_0026603c_caseD_7:
    _av_free(puVar1);
    _av_free(pvVar3);
    _av_free(puVar2);
    return uVar5;
  }
  *puVar1 = puVar2;
  *puVar2 = pvVar3;
  *(undefined4 *)(puVar1 + 1) = 1;
  *(undefined4 *)((long)puVar1 + 0xc) = 1;
  *(undefined4 *)((long)pvVar3 + 0x28) = 1;
  *(undefined8 *)((long)pvVar3 + 8) = *(undefined8 *)(lVar4 + 0x20);
  *(undefined8 *)((long)pvVar3 + 0x10) = *(undefined8 *)(lVar4 + 0x28);
  uVar8 = _DAT_00c51260;
  uVar7 = _UNK_00c51238;
  uVar6 = _DAT_00c51230;
  uVar5 = 0xffffffb2;
  switch(*(undefined4 *)(lVar4 + 0x14)) {
  case 1:
  case 2:
  case 3:
  case 4:
  case 9:
  case 0xc:
  case 0xd:
  case 0xf:
  case 0x10:
  case 0x11:
  case 0x12:
    break;
  case 5:
    uVar5 = _DAT_00c51270;
    uVar6 = _UNK_00c51278;
    uVar7 = _DAT_00c51280;
    uVar8 = _UNK_00c51288;
    goto LAB_00266090;
  case 6:
    *(undefined8 *)((long)pvVar3 + 0x20) = _UNK_00c51268;
    *(undefined8 *)((long)pvVar3 + 0x18) = uVar8;
    break;
  default:
    goto switchD_0026603c_caseD_7;
  case 0xb:
    uVar5 = _DAT_00c51240;
    uVar6 = _UNK_00c51248;
    uVar7 = _DAT_00c51250;
    uVar8 = _UNK_00c51258;
LAB_00266090:
    *(undefined8 *)((long)pvVar3 + 0x20) = uVar6;
    *(undefined8 *)((long)pvVar3 + 0x18) = uVar5;
    *(undefined8 *)((long)pvVar3 + 0x10) = uVar8;
    *(undefined8 *)((long)pvVar3 + 8) = uVar7;
    break;
  case 0xe:
    *(undefined8 *)((long)pvVar3 + 0x20) = _UNK_00c51238;
    *(undefined8 *)((long)pvVar3 + 0x18) = uVar6;
    *(undefined8 *)((long)pvVar3 + 0x10) = uVar7;
    *(undefined8 *)((long)pvVar3 + 8) = uVar6;
  }
  *param_1 = puVar1;
  return 1;
}


