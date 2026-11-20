/* Decompiled from supplied 5.2.2 arm package. VA 0x27ad6c. _av_int_list_length_for_size */

ulong _av_int_list_length_for_size(undefined4 param_1,long param_2,long param_3)

{
  ulong uVar1;
  uint uVar2;
  
  if (param_2 != 0) {
    uVar2 = (uint)param_3;
    switch(param_1) {
    case 1:
      uVar1 = 0xffffffff;
      do {
        uVar1 = (ulong)((int)uVar1 + 1);
      } while ((uint)*(byte *)(param_2 + uVar1) != (uVar2 & 0xff));
      break;
    case 2:
      uVar1 = 0xffffffff;
      do {
        uVar1 = (ulong)((int)uVar1 + 1);
      } while ((uint)*(ushort *)(param_2 + uVar1 * 2) != (uVar2 & 0xffff));
      break;
    default:
      _av_log(0,0,"Assertion %s failed at %s:%d\n");
                    /* WARNING: Subroutine does not return */
      _abort();
    case 4:
      uVar1 = 0xffffffff;
      do {
        uVar1 = (ulong)((int)uVar1 + 1);
      } while (*(uint *)(param_2 + uVar1 * 4) != uVar2);
      break;
    case 8:
      uVar1 = 0xffffffff;
      do {
        uVar1 = (ulong)((int)uVar1 + 1);
      } while (*(long *)(param_2 + uVar1 * 8) != param_3);
    }
    return uVar1;
  }
  return 0;
}


