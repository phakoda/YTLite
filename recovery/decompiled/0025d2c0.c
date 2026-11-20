/* Decompiled from supplied 5.2.2 arm package. VA 0x25d2c0. _av_hwdevice_iterate_types */

uint _av_hwdevice_iterate_types(uint param_1)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  uint in_w12;
  uint uVar5;
  
  bVar4 = false;
  bVar3 = false;
  while (uVar5 = in_w12, bVar2 = bVar3, !bVar4) {
    if ((param_1 == 0) ||
       (bVar4 = true, bVar3 = bVar2, in_w12 = uVar5,
       param_1 < *(uint *)PTR__ff_hwcontext_type_videotoolbox_01064648)) {
      uVar1 = *(uint *)PTR__ff_hwcontext_type_videotoolbox_01064648;
      bVar4 = true;
      bVar3 = true;
      in_w12 = uVar1;
      if ((bVar2) && (bVar3 = bVar2, in_w12 = uVar5, uVar1 < uVar5)) {
        bVar3 = true;
        in_w12 = uVar1;
      }
    }
  }
  if (!bVar2) {
    uVar5 = 0;
  }
  return uVar5;
}


