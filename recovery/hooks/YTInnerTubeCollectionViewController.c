// Decompiled hook evidence for YTInnerTubeCollectionViewController. This is not compilable Logos source.

// -[YTInnerTubeCollectionViewController addSectionsFromArray:], original IMP slot 0x012260b8
/* Decompiled from supplied 5.2.2 arm package. VA 0x6df3c. FUN_0006df3c */

void FUN_0006df3c(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined *local_68;
  undefined8 local_60;
  code *local_58;
  undefined *puStack_50;
  undefined8 local_48;
  
  uVar2 = _objc_msgSend(param_3,@selector(mutableCopy));
  local_68 = PTR___NSConcreteGlobalBlock_01060658;
  local_60 = DAT_00c4c2a8;
  local_58 = FUN_000c375c;
  puStack_50 = &DAT_01061ed0;
  local_48 = param_1;
  _objc_msgSend(uVar2,@selector(indexesOfObjectsPassingTest:),&local_68);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(removeObjectsAtIndexes:),uVar3);
  pcVar1 = DAT_012260b8;
  uVar4 = _objc_msgSend(uVar2,@selector(copy));
  (*pcVar1)(param_1,param_2,uVar4);
  _objc_release(uVar4);
  _objc_release(uVar3);
  _objc_release(uVar2);
  return;
}


