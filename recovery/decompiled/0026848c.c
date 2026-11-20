/* Decompiled from supplied 5.2.2 arm package. VA 0x26848c. _ff_check_pixfmt_descriptors */

void _ff_check_pixfmt_descriptors(void)

{
  ulong uVar1;
  uint uVar2;
  ulong uVar3;
  uint *puVar4;
  uint *puVar5;
  undefined **ppuVar6;
  undefined4 uVar7;
  short local_e4;
  short local_e2;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined1 *puStack_d0;
  undefined1 *local_c8;
  undefined1 *local_c0;
  undefined1 *local_b8;
  undefined1 auStack_ac [17];
  undefined1 auStack_9b [17];
  undefined1 auStack_8a [17];
  undefined1 auStack_79 [17];
  long local_68;
  
  uVar3 = 0;
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  puVar5 = &DAT_01065568;
  do {
    if (0xc5 < uVar3) {
      if (*(long *)PTR____stack_chk_guard_01060708 != local_68) {
                    /* WARNING: Subroutine does not return */
        ___stack_chk_fail();
      }
      return;
    }
    ppuVar6 = &PTR_s_yuv420p_01065540 + uVar3 * 0x14;
    _memset(auStack_ac,0,0x44);
    puStack_d0 = auStack_ac;
    local_d8 = 0;
    local_e0 = 0;
    local_c8 = auStack_9b;
    local_c0 = auStack_8a;
    local_b8 = auStack_79;
    if (*ppuVar6 == (char *)0x0) {
      if (((((&DAT_01065548)[uVar3 * 0xa0] != 0) || ((&DAT_01065549)[uVar3 * 0xa0] != '\0')) ||
          ((&DAT_0106554a)[uVar3 * 0xa0] != '\0')) || ((&DAT_01065550)[uVar3 * 0x14] != 0))
      goto LAB_00268730;
    }
    else {
      if (**ppuVar6 == '\0') {
LAB_00268730:
        _av_log(0,0,"Assertion %s failed at %s:%d\n");
                    /* WARNING: Subroutine does not return */
        _abort();
      }
      puVar4 = puVar5;
      for (uVar1 = 0; uVar1 < 4; uVar1 = uVar1 + 1) {
        if ((long)uVar1 < (long)(ulong)(byte)(&DAT_01065548)[uVar3 * 0xa0]) {
          if ((*(byte *)(&DAT_01065550 + uVar3 * 0x14) >> 2 & 1) == 0) {
            uVar2 = *puVar4;
            if ((int)(puVar4[-3] * 8) < (int)uVar2) goto LAB_00268730;
          }
          else {
            uVar2 = *puVar4;
            if ((int)puVar4[-3] < (int)uVar2) goto LAB_00268730;
          }
          if (0xb < uVar3 - 0x8d) {
            uVar7 = 2;
            _av_read_image_line2
                      (&local_e4,&puStack_d0,&local_e0,ppuVar6,0,0,uVar1 & 0xffffffff,2,0x200000000)
            ;
            if (local_e4 != 0 || local_e2 != 0) goto LAB_00268730;
            local_e4 = (short)(1 << (ulong)(uVar2 & 0x1f)) + -1;
            local_e2 = local_e4;
            _av_write_image_line2
                      (&local_e4,&puStack_d0,&local_e0,ppuVar6,0,0,uVar1 & 0xffffffff,2,
                       CONCAT44(uVar7,2));
          }
        }
        else if (((puVar4[-4] != 0) || (puVar4[-3] != 0)) ||
                ((puVar4[-2] != 0 || ((puVar4[-1] != 0 || (*puVar4 != 0)))))) goto LAB_00268730;
        puVar4 = puVar4 + 8;
      }
    }
    uVar3 = uVar3 + 1;
    puVar5 = puVar5 + 0x28;
  } while( true );
}


