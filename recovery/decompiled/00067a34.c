/* Decompiled from supplied 5.2.2 arm package. VA 0x67a34. FUN_00067a34 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_00067a34(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined1 auVar8 [16];
  
  _objc_retain(param_3);
  _objc_msgSend(param_3,PTR_s_onUiReady_0114c4d0);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_yt_commandExecutorCommand_0114c4d8;
  uVar2 = FUN_000d7040(uVar4,PTR_s_respondsToSelector__0114af58,
                       PTR_s_yt_commandExecutorCommand_0114c4d8);
  if (uVar2 != 0) {
    _objc_msgSend((&PTR_LAB_0117ae10)[uVar2] + (int)-(DAT_0117ae20 ^ 0x64daae42),uVar4,puVar1);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,PTR_s_commandsArray_0114c4e0);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,PTR_s_indexesOfObjectsPassingTest__0114c4e8,
                  &PTR___NSConcreteGlobalBlock_01061be0);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,PTR_s_removeObjectsAtIndexes__0114c4f0,uVar7);
    _objc_release(uVar7);
    _objc_release(uVar6);
    _objc_release(uVar5);
  }
  iVar3 = FUN_000d7104(uVar4);
  if (iVar3 != 0) {
    _objc_msgSend(param_3,PTR_s_setOnUiReady__0114c4f8,0);
  }
  (*_DAT_01226098)(param_1,param_2,param_3);
  _objc_release(uVar4);
  _objc_release(param_3);
  CallSupervisor(0x1b98);
  auVar8._8_8_ = 0x1f;
  auVar8._0_8_ = 0x1a;
  return auVar8;
}


