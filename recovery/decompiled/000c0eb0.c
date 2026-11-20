/* Decompiled from supplied 5.2.2 arm package. VA 0xc0eb0. FUN_000c0eb0 */

undefined1  [16] FUN_000c0eb0(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auVar5 [16];
  
  uVar1 = _objc_alloc_init(PTR_DVNImageViewController_0114ed38);
  _objc_msgSend(uVar1,PTR_s_setFullImage__0114c5c8,*(undefined8 *)(param_1 + 0x20));
  uVar2 = _objc_alloc(PTR__OBJC_CLASS___UINavigationController_0114ece8);
  uVar2 = _objc_msgSend(uVar2,PTR_s_initWithRootViewController__0114c3a0,uVar1);
  _objc_msgSend(uVar2,PTR_s_setModalPresentationStyle__0114b958,2);
  _objc_msgSend(*(undefined8 *)(param_1 + 0x28),PTR_s_keepalive_node_0114c568);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_closestViewController_0114aec8);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,PTR_s_presentViewController_animated_c_0114b298,uVar2,1,0);
  _objc_release(uVar4);
  _objc_release(uVar3);
  _objc_release(uVar2);
  _objc_release(uVar1);
  CallSupervisor(0xf67b);
  auVar5._8_8_ = 0x1f;
  auVar5._0_8_ = 0x1a;
  return auVar5;
}


