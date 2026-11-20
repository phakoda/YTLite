/* Decompiled from supplied 5.2.2 arm package. VA 0x254438. _av_base64_decode */

int _av_base64_decode(long param_1,byte *param_2,int param_3)

{
  int iVar1;
  undefined1 *puVar2;
  uint uVar3;
  byte bVar4;
  uint uVar5;
  long lVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  
  puVar7 = (undefined1 *)(param_1 + param_3);
  for (lVar6 = 0; puVar8 = (undefined1 *)(param_1 + lVar6), 3 < (long)puVar7 - (long)puVar8;
      lVar6 = lVar6 + 3) {
    bVar4 = (&DAT_00c50444)[*param_2];
    uVar5 = (uint)bVar4;
    if ((char)bVar4 < '\0') {
LAB_002544b4:
      puVar8 = (undefined1 *)(param_1 + lVar6);
      goto LAB_00254594;
    }
    bVar4 = (&DAT_00c50444)[param_2[1]];
    if ((char)bVar4 < '\0') goto LAB_002544b4;
    uVar5 = (uint)bVar4 + uVar5 * 0x40;
    bVar4 = (&DAT_00c50444)[param_2[2]];
    if ((char)bVar4 < '\0') {
      puVar8 = (undefined1 *)(param_1 + lVar6);
      goto LAB_0025458c;
    }
    uVar5 = (uint)bVar4 + uVar5 * 0x40;
    bVar4 = (&DAT_00c50444)[param_2[3]];
    if ((char)bVar4 < '\0') goto LAB_00254574;
    param_2 = param_2 + 4;
    uVar5 = ((uint)bVar4 + uVar5 * 0x40) * 0x100;
    uVar3 = (uVar5 & 0xff00ff00) >> 8;
    *(uint *)(param_1 + lVar6) = (uVar3 | (uVar5 & 0xff00ff) << 8) >> 0x10 | uVar3 << 0x10;
  }
  if (lVar6 == param_3) {
LAB_00254538:
    do {
      bVar4 = (&DAT_00c50444)[*param_2];
      puVar8 = puVar7;
      if ((((char)bVar4 < '\0') || (bVar4 = (&DAT_00c50444)[param_2[1]], (char)bVar4 < '\0')) ||
         (bVar4 = (&DAT_00c50444)[param_2[2]], (char)bVar4 < '\0')) break;
      bVar4 = (&DAT_00c50444)[param_2[3]];
      param_2 = param_2 + 4;
    } while (-1 < (char)bVar4);
  }
  else {
    bVar4 = (&DAT_00c50444)[*param_2];
    uVar5 = (uint)bVar4;
    if (((char)bVar4 < '\0') || (bVar4 = (&DAT_00c50444)[param_2[1]], (char)bVar4 < '\0'))
    goto LAB_00254594;
    uVar5 = (uint)bVar4 + uVar5 * 0x40;
    bVar4 = (&DAT_00c50444)[param_2[2]];
    if (-1 < (char)bVar4) {
      uVar5 = (uint)bVar4 + uVar5 * 0x40;
      bVar4 = (&DAT_00c50444)[param_2[3]];
      if (-1 < (char)bVar4) {
        iVar1 = (uint)bVar4 + uVar5 * 0x40;
        puVar2 = (undefined1 *)(param_1 + lVar6);
        *puVar2 = (char)((uint)iVar1 >> 0x10);
        puVar8 = puVar7;
        if (lVar6 - param_3 != -1) {
          puVar2[1] = (char)((uint)iVar1 >> 8);
          puVar8 = puVar2 + 2;
        }
        if (puVar7 != puVar8) {
          puVar7 = puVar8 + 1;
          *puVar8 = (char)iVar1;
        }
        param_2 = param_2 + 4;
        goto LAB_00254538;
      }
LAB_00254574:
      puVar8 = (undefined1 *)(param_1 + lVar6) + 1;
      *(undefined1 *)(param_1 + lVar6) = (char)(uVar5 >> 10);
      uVar5 = uVar5 << 2;
    }
LAB_0025458c:
    *puVar8 = (char)(uVar5 >> 4);
    puVar8 = puVar8 + 1;
  }
LAB_00254594:
  iVar1 = (int)puVar8 - (int)param_1;
  if ((bVar4 & 1) != 0) {
    iVar1 = -0x41444e49;
  }
  return iVar1;
}


