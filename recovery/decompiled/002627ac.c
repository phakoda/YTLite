/* Decompiled from supplied 5.2.2 arm package. VA 0x2627ac. _av_opt_set */

ulong _av_opt_set(undefined8 param_1,undefined8 param_2,long param_3,undefined4 param_4)

{
  long lVar1;
  long lVar2;
  ulong uVar3;
  uint uVar4;
  long local_50 [2];
  
  lVar1 = _av_opt_find2(param_1,param_2,0,0,param_4,local_50);
  uVar4 = 0xabafb008;
  if ((lVar1 != 0) && (local_50[0] != 0)) {
    if (param_3 == 0) {
      uVar4 = 0xffffffea;
      if ((0x12 < *(uint *)(lVar1 + 0x14)) ||
         ((1 << (ulong)(*(uint *)(lVar1 + 0x14) & 0x1f) & 0x7b820U) == 0)) goto LAB_00262b44;
    }
    if ((*(uint *)(lVar1 + 0x30) >> 7 & 1) == 0) {
      lVar2 = lVar1;
      if ((*(uint *)(lVar1 + 0x30) >> 0x11 & 1) != 0) {
        lVar2 = _av_log(param_1,0x18,"The \"%s\" option is deprecated: %s\n");
      }
      if ((uint)(*(ulong *)(lVar1 + 0x10) >> 0x20) < 0x13) {
                    /* WARNING: Could not recover jumptable at 0x0026287c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar3 = (*(code *)(&DAT_00262b6c +
                          *(int *)(&DAT_00262b6c + (*(ulong *)(lVar1 + 0x10) >> 0x20) * 4)))
                          (lVar2,local_50[0]);
        return uVar3;
      }
      _av_log(param_1,0x10,"Invalid option type.\n");
    }
    uVar4 = 0xffffffea;
  }
LAB_00262b44:
  return (ulong)uVar4;
}


