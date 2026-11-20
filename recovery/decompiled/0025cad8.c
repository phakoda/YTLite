/* Decompiled from supplied 5.2.2 arm package. VA 0x25cad8. _av_hash_final */

void _av_hash_final(undefined8 *param_1,uint *param_2)

{
  uint uVar1;
  
  switch(*(undefined4 *)(param_1 + 1)) {
  case 0:
    _av_md5_final(*param_1);
    return;
  case 1:
    _av_murmur3_final(*param_1);
    return;
  case 2:
  case 3:
  case 4:
  case 5:
    _av_ripemd_final(*param_1);
    return;
  case 6:
  case 7:
  case 8:
    _av_sha_final(*param_1);
    return;
  case 9:
  case 10:
  case 0xb:
  case 0xc:
    _av_sha512_final(*param_1);
    return;
  case 0xd:
    uVar1 = (~*(uint *)(param_1 + 3) & 0xff00ff00) >> 8 | (~*(uint *)(param_1 + 3) & 0xff00ff) << 8;
    uVar1 = uVar1 >> 0x10 | uVar1 << 0x10;
    break;
  case 0xe:
    uVar1 = (*(uint *)(param_1 + 3) & 0xff00ff00) >> 8 | (*(uint *)(param_1 + 3) & 0xff00ff) << 8;
    uVar1 = uVar1 >> 0x10 | uVar1 << 0x10;
    break;
  default:
    goto switchD_0025caf4_default;
  }
  *param_2 = uVar1;
switchD_0025caf4_default:
  return;
}


