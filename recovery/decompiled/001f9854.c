/* Decompiled from supplied 5.2.2 arm package. VA 0x1f9854. setActive */

/* Function Stack Size: 0x10 bytes */

void FFMpegHelper::setActive(ID param_1,SEL param_2)

{
  _objc_msgSend(PTR_MobileFFmpegConfig_0114efe8,PTR_s_setLogDelegate__0114e2a0,param_1);
  _objc_msgSend(PTR_MobileFFmpegConfig_0114efe8,PTR_s_setStatisticsDelegate__0114e2e0,param_1);
  CallSupervisor(0x1f03);
  return;
}


