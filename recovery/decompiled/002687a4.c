/* Decompiled from supplied 5.2.2 arm package. VA 0x2687a4. _av_pix_fmt_swap_endianness */

void _av_pix_fmt_swap_endianness(uint param_1)

{
  byte *pbVar1;
  int iVar2;
  undefined8 uVar3;
  size_t sVar4;
  char *pcVar5;
  long lVar6;
  byte abStack_48 [16];
  long local_38;
  
  lVar6 = *(long *)PTR____stack_chk_guard_01060708;
  uVar3 = 0xffffffff;
  local_38 = lVar6;
  if ((param_1 < 0xc6) && (&PTR_s_yuv420p_01065540 + (long)(int)param_1 * 0x14 != (undefined **)0x0)
     ) {
    pcVar5 = (&PTR_s_yuv420p_01065540)[(long)(int)param_1 * 0x14];
    sVar4 = _strlen(pcVar5);
    if (1 < sVar4) {
      _av_strlcpy(abStack_48,pcVar5,0x10);
      sVar4 = _strlen((char *)abStack_48);
      pbVar1 = abStack_48 + ((long)((sVar4 << 0x20) + -0x200000000) >> 0x20);
      iVar2 = _strcmp((char *)pbVar1,"be");
      if ((iVar2 == 0) || (iVar2 = _strcmp((char *)pbVar1,"le"), iVar2 == 0)) {
        *pbVar1 = *pbVar1 ^ 0xe;
        uVar3 = FUN_002680d0(abStack_48);
        goto LAB_00268870;
      }
    }
    uVar3 = 0xffffffff;
  }
LAB_00268870:
  if (lVar6 == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(uVar3);
}


