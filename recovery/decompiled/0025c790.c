/* Decompiled from supplied 5.2.2 arm package. VA 0x25c790. _av_hash_alloc */

undefined8 _av_hash_alloc(undefined8 *param_1,undefined8 param_2)

{
  int iVar1;
  long *plVar2;
  long lVar3;
  ulong uVar4;
  undefined **ppuVar5;
  
  uVar4 = 0;
  *param_1 = 0;
  ppuVar5 = &PTR_s_MD5_010644f8;
  while( true ) {
    if (0xe < (long)uVar4) {
      return 0xffffffea;
    }
    iVar1 = _av_strcasecmp(param_2,*ppuVar5);
    if (iVar1 == 0) break;
    uVar4 = uVar4 + 1;
    ppuVar5 = ppuVar5 + 2;
  }
  plVar2 = (long *)_av_mallocz(0x20);
  if (plVar2 == (long *)0x0) {
    return 0xfffffff4;
  }
  *(int *)(plVar2 + 1) = (int)uVar4;
  switch(uVar4 & 0xffffffff) {
  case 0:
    lVar3 = _av_md5_alloc();
    *plVar2 = lVar3;
    goto LAB_0025c840;
  case 1:
    lVar3 = _av_murmur3_alloc();
    *plVar2 = lVar3;
    goto LAB_0025c840;
  case 2:
  case 3:
  case 4:
  case 5:
    lVar3 = _av_ripemd_alloc();
    break;
  case 6:
  case 7:
  case 8:
    lVar3 = _av_sha_alloc();
    break;
  case 9:
  case 10:
  case 0xb:
  case 0xc:
    lVar3 = _av_sha512_alloc();
    break;
  case 0xd:
    lVar3 = _av_crc_get_table(4);
    plVar2[2] = lVar3;
    goto LAB_0025c878;
  default:
    goto switchD_0025c80c_default;
  }
  *plVar2 = lVar3;
switchD_0025c80c_default:
  if (1 < (int)uVar4 - 0xdU) {
    lVar3 = *plVar2;
LAB_0025c840:
    if (lVar3 == 0) {
      _av_free(plVar2);
      return 0xfffffff4;
    }
  }
LAB_0025c878:
  *param_1 = plVar2;
  return 0;
}


