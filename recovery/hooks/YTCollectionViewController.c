// Decompiled hook evidence for YTCollectionViewController. This is not compilable Logos source.

// -[YTCollectionViewController collectionView:didSelectItemAtIndexPath:], original IMP slot 0x1225948
/* Decompiled from supplied 5.2.2 arm package. VA 0x12658. FUN_00012658 */

undefined1  [16]
FUN_00012658(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  ulong uVar6;
  undefined1 auVar7 [16];
  
  DAT_01225994 = 1;
  _objc_retain(param_3);
  _objc_retain(param_4);
  puVar2 = @selector(respondsToSelector:);
  puVar1 = @selector(sectionControllers);
  uVar3 = FUN_000141c8(param_1,@selector(respondsToSelector:),@selector(sectionControllers))
  ;
  if (uVar3 == 0) {
    (*pcRam0000000001225948)(param_1,param_2,param_3,param_4);
    _objc_release(param_4);
    _objc_release(param_3);
    CallSupervisor(0x9d91);
    auVar7._8_8_ = 0x1f;
    auVar7._0_8_ = 0x1a;
    return auVar7;
  }
  _objc_msgSend((&PTR_LAB_01153300)[uVar3] + (int)-(uRam0000000001153310 ^ 0x286aa8d2),param_1,
                puVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  uVar5 = _objc_msgSend(param_4,@selector(section));
  _objc_msgSend(uVar4,@selector(objectAtIndexedSubscript:),uVar5);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar4);
  uVar6 = FUN_00014598(uVar5,puVar2,@selector(items));
                    /* WARNING: Could not recover jumptable at 0x00012c88. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  auVar7 = (*(code *)((&PTR_LAB_01153320)[uVar6 & 0xffffffff] +
                     (int)-(uRam0000000001153330 ^ 0xbb1a3eef)))();
  return auVar7;
}


