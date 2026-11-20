/* Decompiled from supplied 5.2.2 arm package. VA 0x25e2f0. _av_map_videotoolbox_format_from_pixfmt2 */

undefined4 _av_map_videotoolbox_format_from_pixfmt2(int param_1,byte param_2)

{
  undefined4 *puVar1;
  bool bVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  uVar3 = 0;
  puVar1 = (undefined4 *)&UNK_00c50e34;
  do {
    puVar4 = puVar1;
    bVar2 = uVar3 == 4;
    if (4 < uVar3) {
      return 0;
    }
    uVar3 = uVar3 + 1;
    puVar1 = puVar4 + 3;
  } while ((((bVar2 ^ param_2) & 1) != 0) || (puVar4[5] != param_1));
  return *puVar1;
}


