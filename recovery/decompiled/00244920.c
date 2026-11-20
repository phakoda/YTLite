/* Decompiled from supplied 5.2.2 arm package. VA 0x244920. _shine_subband_initialise */

void _shine_subband_initialise(long param_1)

{
  bool bVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  long lVar5;
  long lVar6;
  int iVar7;
  double dVar8;
  double local_78;
  
  *(undefined4 *)(_objc_msgSend + param_1) = 0;
  _bzero(&UNK_00016e98 + param_1,0x800);
  *(undefined4 *)(param_1 + 0x14690) = 0;
  _bzero(&LAB_00016698 + param_1,0x800);
  dVar4 = DAT_00c4d6f8;
  dVar3 = DAT_00c4d6f0;
  dVar2 = DAT_00c4c268;
  lVar5 = 0x1f;
  do {
    iVar7 = 0x40;
    lVar6 = 0x3f;
    do {
      local_78 = (double)_cos((double)(int)((0x11 - iVar7) * ((uint)(lVar5 << 1) | 1)) * dVar3);
      local_78 = local_78 * dVar2;
      if (0.0 <= local_78) {
        dVar8 = local_78 + 0.5;
      }
      else {
        dVar8 = local_78 + -0.5;
      }
      _modf(dVar8,&local_78);
      *(int *)(param_1 + lVar5 * 0x100 + lVar6 * 4 + 0x14698) = (int)(local_78 * dVar4);
      iVar7 = (int)lVar6;
      bVar1 = lVar6 != 0;
      lVar6 = lVar6 + -1;
    } while (bVar1);
    bVar1 = lVar5 != 0;
    lVar5 = lVar5 + -1;
  } while (bVar1);
  return;
}


