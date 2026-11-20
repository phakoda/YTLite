/* Decompiled from supplied 5.2.2 arm package. VA 0x256a8c. _av_des_init */

undefined8 _av_des_init(long param_1,ulong *param_2,uint param_3)

{
  ulong uVar1;
  undefined8 uVar2;
  
  if ((param_3 | 0x80) == 0xc0) {
    *(uint *)(param_1 + 0x180) = (uint)(0x40 < (int)param_3);
    uVar1 = (*param_2 & 0xff00ff00ff00ff00) >> 8 | (*param_2 & 0xff00ff00ff00ff) << 8;
    uVar1 = (uVar1 & 0xffff0000ffff0000) >> 0x10 | (uVar1 & 0xffff0000ffff) << 0x10;
    FUN_00256b08(param_1,uVar1 >> 0x20 | uVar1 << 0x20);
    if (*(int *)(param_1 + 0x180) != 0) {
      uVar1 = (param_2[1] & 0xff00ff00ff00ff00) >> 8 | (param_2[1] & 0xff00ff00ff00ff) << 8;
      uVar1 = (uVar1 & 0xffff0000ffff0000) >> 0x10 | (uVar1 & 0xffff0000ffff) << 0x10;
      FUN_00256b08(param_1 + 0x80,uVar1 >> 0x20 | uVar1 << 0x20);
      uVar1 = (param_2[2] & 0xff00ff00ff00ff00) >> 8 | (param_2[2] & 0xff00ff00ff00ff) << 8;
      uVar1 = (uVar1 & 0xffff0000ffff0000) >> 0x10 | (uVar1 & 0xffff0000ffff) << 0x10;
      FUN_00256b08(param_1 + 0x100,uVar1 >> 0x20 | uVar1 << 0x20);
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffea;
  }
  return uVar2;
}


