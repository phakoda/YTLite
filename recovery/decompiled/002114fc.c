/* Decompiled from supplied 5.2.2 arm package. VA 0x2114fc. timerQueue */

/* Function Stack Size: 0x10 bytes */

ID YTPSleepTimer::timerQueue(ID param_1,SEL param_2)

{
  ID IVar1;
  
  if (DAT_01228108 != 0) {
    DAT_01228108 = 1;
                    /* WARNING: Could not recover jumptable at 0x002115b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    IVar1 = (*(code *)((&PTR_LAB_011cc3c0)[*(long *)(param_1 + 0x10) == 0] +
                      (int)-(uRam00000000011cc3d0 ^ 0xe9d8cb86)))();
    return IVar1;
  }
  s_com_dvn_ytpsleeptimer_queue_011cb280[0] = bRam00000000011cb260 ^ 0xb8;
  s_com_dvn_ytpsleeptimer_queue_011cb280[1] = bRam00000000011cb261 ^ 0xc6;
  s_com_dvn_ytpsleeptimer_queue_011cb280[2] = bRam00000000011cb262 ^ 8;
  s_com_dvn_ytpsleeptimer_queue_011cb280[3] = bRam00000000011cb263 ^ 0xbd;
  s_com_dvn_ytpsleeptimer_queue_011cb280[4] = bRam00000000011cb264 ^ 0x7a;
  s_com_dvn_ytpsleeptimer_queue_011cb280[5] = bRam00000000011cb265 ^ 0x8f;
  s_com_dvn_ytpsleeptimer_queue_011cb280[6] = bRam00000000011cb266 ^ 0x36;
  s_com_dvn_ytpsleeptimer_queue_011cb280[7] = bRam00000000011cb267 ^ 0x60;
  s_com_dvn_ytpsleeptimer_queue_011cb280[8] = bRam00000000011cb268 ^ 0xf4;
  s_com_dvn_ytpsleeptimer_queue_011cb280[9] = bRam00000000011cb269 ^ 0x69;
  s_com_dvn_ytpsleeptimer_queue_011cb280[10] = bRam00000000011cb26a ^ 0xc1;
  s_com_dvn_ytpsleeptimer_queue_011cb280[0xb] = bRam00000000011cb26b ^ 0x6c;
  s_com_dvn_ytpsleeptimer_queue_011cb280[0xc] = bRam00000000011cb26c ^ 0xfe;
  s_com_dvn_ytpsleeptimer_queue_011cb280[0xd] = bRam00000000011cb26d ^ 0xf6;
  s_com_dvn_ytpsleeptimer_queue_011cb280[0xe] = bRam00000000011cb26e ^ 0xa1;
  s_com_dvn_ytpsleeptimer_queue_011cb280[0xf] = bRam00000000011cb26f ^ 0x7d;
  s_com_dvn_ytpsleeptimer_queue_011cb280[0x10] = bRam00000000011cb270 ^ 0x58;
  s_com_dvn_ytpsleeptimer_queue_011cb280[0x11] = bRam00000000011cb271 ^ 0x7b;
  s_com_dvn_ytpsleeptimer_queue_011cb280[0x12] = bRam00000000011cb272 ^ 8;
  s_com_dvn_ytpsleeptimer_queue_011cb280[0x13] = bRam00000000011cb273 ^ 0x60;
  s_com_dvn_ytpsleeptimer_queue_011cb280[0x14] = bRam00000000011cb274 ^ 0x3c;
  s_com_dvn_ytpsleeptimer_queue_011cb280[0x15] = bRam00000000011cb275 ^ 0x30;
  s_com_dvn_ytpsleeptimer_queue_011cb280[0x16] = bRam00000000011cb276 ^ 0x25;
  s_com_dvn_ytpsleeptimer_queue_011cb280[0x17] = bRam00000000011cb277 ^ 0x6b;
  s_com_dvn_ytpsleeptimer_queue_011cb280[0x18] = bRam00000000011cb278 ^ 0xe1;
  s_com_dvn_ytpsleeptimer_queue_011cb280[0x19] = bRam00000000011cb279 ^ 0xba;
  s_com_dvn_ytpsleeptimer_queue_011cb280[0x1a] = bRam00000000011cb27a ^ 0xf7;
  s_com_dvn_ytpsleeptimer_queue_011cb280[0x1b] = bRam00000000011cb27b ^ 0x54;
  DAT_01228108 = 1;
                    /* WARNING: Could not recover jumptable at 0x00211794. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IVar1 = (*(code *)((&PTR_LAB_011cc3c0)[*(long *)(param_1 + 0x10) == 0] +
                    (int)-(uRam00000000011cc3d0 ^ 0xe9d8cb86)))();
  return IVar1;
}


