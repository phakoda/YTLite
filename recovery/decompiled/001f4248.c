/* Decompiled from supplied 5.2.2 arm package. VA 0x1f4248. init */

/* Function Stack Size: 0x10 bytes */

ID FFMpegHelper::init(ID param_1,SEL param_2)

{
  ID IVar1;
  dispatch_queue_t pdVar2;
  undefined8 uVar3;
  ID IStack_60;
  undefined *puStack_58;
  undefined **local_50;
  uint uStack_44;
  undefined **local_40;
  undefined **ppuStack_38;
  uint local_2c;
  undefined **local_28;
  
  local_28 = &PTR_LAB_011c1878;
  local_2c = (uint)(DAT_01227fc0 == 0);
  local_40 = &PTR_LAB_011c1898;
  ppuStack_38 = &PTR_LAB_011c1600;
  local_50 = &PTR_LAB_011c1600;
  DAT_01227fc0 = 1;
  puStack_58 = PTR_FFMpegHelper_0114f130;
  IStack_60 = param_1;
  IVar1 = _objc_msgSendSuper2(&IStack_60,PTR_s_init_0114d960);
  uStack_44 = (uint)(IVar1 == 0);
  if (IVar1 != 0) {
    pdVar2 = _dispatch_queue_create
                       (s_com_dvntm_ffmpeg_serialqueue_011bde50,(dispatch_queue_attr_t)0x0);
    uVar3 = *(undefined8 *)(IVar1 + 8);
    *(dispatch_queue_t *)(IVar1 + 8) = pdVar2;
    _objc_release(uVar3);
    *(undefined1 *)(IVar1 + 0x28) = 0;
  }
  return IVar1;
}


