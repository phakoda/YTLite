/* Decompiled from supplied 5.2.2 arm package. VA 0x269598. _av_d2q */

ulong _av_d2q(double param_1,int param_2)

{
  uint uVar1;
  ulong uVar3;
  long lVar4;
  long lVar5;
  int local_4c;
  uint local_48;
  uint local_44;
  ulong uVar2;
  
  if (NAN(param_1)) {
    uVar2 = 0;
    uVar3 = 0;
    goto LAB_002696c8;
  }
  if (DAT_00c512e0 < ABS(param_1)) {
    uVar3 = 0;
    uVar1 = 0xffffffff;
    if (0.0 <= param_1) {
      uVar1 = 1;
    }
    uVar2 = (ulong)uVar1;
    goto LAB_002696c8;
  }
  _frexp(param_1,&local_4c);
  local_4c = local_4c + -1;
  if (local_4c < 1) {
    local_4c = 0;
  }
  lVar4 = 1L << ((ulong)(0x3d - local_4c) & 0x3f);
  lVar5 = (long)((double)lVar4 * param_1 + 0.5);
  _av_reduce(&local_48,(ulong)&local_48 | 4,lVar5,lVar4,(long)param_2);
  uVar2 = (ulong)local_48;
  if (local_48 == 0) {
    uVar2 = 0;
    if ((param_2 != 0x7fffffff) && (param_1 != 0.0 && 0 < param_2)) goto LAB_002696a4;
  }
  else if ((param_2 != 0x7fffffff && 0 < param_2) && ((param_1 != 0.0 && (local_44 == 0)))) {
LAB_002696a4:
    _av_reduce(&local_48,(ulong)&local_48 | 4,lVar5,lVar4,0x7fffffff);
    uVar2 = (ulong)local_48;
  }
  uVar3 = (ulong)local_44 << 0x20;
LAB_002696c8:
  return uVar3 | uVar2;
}


