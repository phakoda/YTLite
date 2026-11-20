/* Decompiled from supplied 5.2.2 arm package. VA 0x25c8c8. _av_hash_init */

void _av_hash_init(undefined8 *param_1)

{
  undefined4 uVar1;
  
  switch(*(undefined4 *)(param_1 + 1)) {
  case 0:
    _av_md5_init(*param_1);
    return;
  case 1:
    _av_murmur3_init(*param_1);
    return;
  case 2:
    _av_ripemd_init(*param_1,0x80);
    return;
  case 3:
    _av_ripemd_init(*param_1,0xa0);
    return;
  case 4:
    _av_ripemd_init(*param_1,0x100);
    return;
  case 5:
    _av_ripemd_init(*param_1,0x140);
    return;
  case 6:
    _av_sha_init(*param_1,0xa0);
    return;
  case 7:
    _av_sha_init(*param_1,0xe0);
    return;
  case 8:
    _av_sha_init(*param_1,0x100);
    return;
  case 9:
    _av_sha512_init(*param_1,0xe0);
    return;
  case 10:
    _av_sha512_init(*param_1,0x100);
    return;
  case 0xb:
    _av_sha512_init(*param_1,0x180);
    return;
  case 0xc:
    _av_sha512_init(*param_1,0x200);
    return;
  case 0xd:
    uVar1 = 0xffffffff;
    break;
  case 0xe:
    uVar1 = 1;
    break;
  default:
    goto switchD_0025c8e4_default;
  }
  *(undefined4 *)(param_1 + 3) = uVar1;
switchD_0025c8e4_default:
  return;
}


