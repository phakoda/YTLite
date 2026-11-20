/* Decompiled from supplied 5.2.2 arm package. VA 0x22545c. nearestIndexForRate: */

/* Function Stack Size: 0x18 bytes */

long_long YTPSpeedMaster::nearestIndexForRate_(ID param_1,SEL param_2,double param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  double dVar4;
  long lVar5;
  undefined8 uVar6;
  ulong uVar7;
  undefined **ppuVar8;
  ulong uVar9;
  ulong uVar10;
  ulong uVar11;
  float fVar12;
  double dVar13;
  
  puVar2 = PTR_s_count_0114b840;
  lVar5 = _objc_msgSend(*(undefined8 *)(param_1 + 8),PTR_s_count_0114b840);
  puVar3 = PTR_s_floatValue_0114c768;
  puVar1 = PTR_s_objectAtIndexedSubscript__0114aeb0;
  uVar10 = 2;
  if (lVar5 != 0) {
    uVar9 = 0;
    ppuVar8 = &PTR_s_setLoopMode__0114c000;
    dVar13 = 1.7976931348623157e+308;
    uVar11 = 2;
    do {
      _objc_msgSend(ppuVar8,*(undefined8 *)(param_1 + 8),puVar1,uVar9);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      fVar12 = (float)_objc_msgSend(uVar6,puVar3);
      _objc_release(uVar6);
      uVar10 = uVar9;
      dVar4 = ABS((double)fVar12 - param_3);
      if (dVar13 <= ABS((double)fVar12 - param_3)) {
        uVar10 = uVar11;
        dVar4 = dVar13;
      }
      dVar13 = dVar4;
      uVar9 = uVar9 + 1;
      uVar7 = _objc_msgSend(*(undefined8 *)(param_1 + 8),puVar2);
      ppuVar8 = (undefined **)
                ((&PTR_LAB_011cef48)[uVar9 < uVar7] + (int)-(uRam00000000011cef58 ^ 0x2a6d782b));
      uVar11 = uVar10;
    } while (uVar9 < uVar7);
  }
  return uVar10;
}


