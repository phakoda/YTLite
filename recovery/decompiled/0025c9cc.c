/* Decompiled from supplied 5.2.2 arm package. VA 0x25c9cc. _av_hash_update */

void _av_hash_update(undefined8 *param_1,undefined8 param_2,int param_3)

{
  undefined4 uVar1;
  
  switch(*(undefined4 *)(param_1 + 1)) {
  case 0:
    _av_md5_update(*param_1,param_2);
    return;
  case 1:
    _av_murmur3_update(*param_1,param_2);
    return;
  case 2:
  case 3:
  case 4:
  case 5:
    _av_ripemd_update(*param_1,param_2);
    return;
  case 6:
  case 7:
  case 8:
    _av_sha_update(*param_1,param_2);
    return;
  case 9:
  case 10:
  case 0xb:
  case 0xc:
    _av_sha512_update(*param_1,param_2);
    return;
  case 0xd:
    uVar1 = _av_crc(param_1[2],*(undefined4 *)(param_1 + 3),param_2,(long)param_3);
    *(undefined4 *)(param_1 + 3) = uVar1;
    break;
  case 0xe:
    uVar1 = _av_adler32_update(*(undefined4 *)(param_1 + 3),param_2);
    *(undefined4 *)(param_1 + 3) = uVar1;
  }
  return;
}


