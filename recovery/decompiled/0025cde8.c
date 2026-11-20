/* Decompiled from supplied 5.2.2 arm package. VA 0x25cde8. _av_hmac_alloc */

long * _av_hmac_alloc(undefined4 param_1)

{
  long *plVar1;
  long lVar2;
  undefined4 uVar3;
  code *pcVar4;
  
  plVar1 = (long *)_av_mallocz(0xb0);
  if (plVar1 == (long *)0x0) goto LAB_0025cf1c;
  switch(param_1) {
  case 0:
    *(undefined4 *)(plVar1 + 1) = 0x40;
    *(undefined4 *)((long)plVar1 + 0xc) = 0x10;
    plVar1[3] = (long)_av_md5_update;
    plVar1[4] = (long)_av_md5_init;
    plVar1[2] = (long)_av_md5_final;
    lVar2 = _av_md5_alloc();
    goto LAB_0025cf0c;
  case 1:
    uVar3 = 0x14;
    pcVar4 = FUN_0025cf48;
    break;
  case 2:
    uVar3 = 0x1c;
    pcVar4 = FUN_0025cf50;
    break;
  case 3:
    uVar3 = 0x20;
    pcVar4 = FUN_0025cf58;
    break;
  case 4:
    uVar3 = 0x30;
    pcVar4 = FUN_0025cf60;
    goto LAB_0025cee4;
  case 5:
    uVar3 = 0x40;
    pcVar4 = FUN_0025cf68;
LAB_0025cee4:
    *(undefined4 *)(plVar1 + 1) = 0x80;
    *(undefined4 *)((long)plVar1 + 0xc) = uVar3;
    plVar1[4] = (long)pcVar4;
    plVar1[3] = (long)_av_sha512_update;
    plVar1[2] = (long)_av_sha512_final;
    lVar2 = _av_sha512_alloc();
    goto LAB_0025cf0c;
  default:
    goto switchD_0025ce24_default;
  }
  *(undefined4 *)(plVar1 + 1) = 0x40;
  *(undefined4 *)((long)plVar1 + 0xc) = uVar3;
  plVar1[4] = (long)pcVar4;
  plVar1[3] = (long)_av_sha_update;
  plVar1[2] = (long)_av_sha_final;
  lVar2 = _av_sha_alloc();
LAB_0025cf0c:
  *plVar1 = lVar2;
  if (lVar2 == 0) {
switchD_0025ce24_default:
    _av_free(plVar1);
LAB_0025cf1c:
    plVar1 = (long *)0x0;
  }
  return plVar1;
}


