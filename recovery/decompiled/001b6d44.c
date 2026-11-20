/* Decompiled from supplied 5.2.2 arm package. VA 0x1b6d44. FUN_001b6d44 */

undefined1  [16] FUN_001b6d44(void)

{
  long lVar1;
  undefined1 auVar2 [16];
  
  DAT_01227ab8 = 1;
  lVar1 = _NSClassFromString(&PTR____CFConstantStringClassReference_011b2030);
  if (lVar1 != 0) {
    lVar1 = _class_getInstanceMethod(lVar1,PTR_s_renderer_0114ccd0);
    if (lVar1 != 0) {
      uRam0000000001227998 =
           _method_setImplementation
                     ((&PTR_LAB_011b2f50)[lVar1 == 0] + (int)-(uRam00000000011b2f60 ^ 0xe36d87ef),
                      lVar1,FUN_001b7004);
    }
  }
  CallSupervisor(0x50e2);
  auVar2._8_8_ = 0x1f;
  auVar2._0_8_ = 0x1a;
  return auVar2;
}


