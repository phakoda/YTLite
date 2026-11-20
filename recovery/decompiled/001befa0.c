/* Decompiled from supplied 5.2.2 arm package. VA 0x1befa0. FUN_001befa0 */

undefined1  [16] FUN_001befa0(long param_1)

{
  int *piVar1;
  int *piVar2;
  undefined *puVar3;
  int iVar4;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  
  _CGAffineTransformMakeScale
            (&local_60,*(undefined8 *)(param_1 + 0x28),*(undefined8 *)(param_1 + 0x28));
  uStack_88 = uStack_58;
  local_90 = local_60;
  uStack_78 = uStack_48;
  uStack_80 = uStack_50;
  uStack_68 = uStack_38;
  local_70 = local_40;
  _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_setTransform__0114b910,&local_90);
  iVar4 = FUN_001c624c(*(undefined8 *)(param_1 + 0x20),PTR_s_isPinnedTop_0114dd48);
  puVar3 = PTR_s_setActive__0114b5a8;
  piVar1 = &ToastView::_topConstraint;
  piVar2 = &ToastView::_bottomConstraint;
  if (iVar4 == 0) {
    piVar1 = &ToastView::_bottomConstraint;
    piVar2 = &ToastView::_topConstraint;
  }
  _objc_msgSend(*(undefined8 *)(*(long *)(param_1 + 0x20) + (long)*piVar2),PTR_s_setActive__0114b5a8
                ,0);
  _objc_msgSend(*(undefined8 *)(*(long *)(param_1 + 0x20) + (long)*piVar1),puVar3,1);
  _objc_msgSend(*(undefined8 *)(*(long *)(param_1 + 0x20) + (long)ToastView::_sourceView),
                PTR_s_layoutIfNeeded_0114b928);
  CallSupervisor(0xc295);
  return ZEXT816(0x1f);
}


