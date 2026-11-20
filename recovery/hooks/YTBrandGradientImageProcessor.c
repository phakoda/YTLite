// Decompiled hook evidence for YTBrandGradientImageProcessor. This is not compilable Logos source.

// -[YTBrandGradientImageProcessor willDrawInContext:drawParameters:], original IMP slot 0x01226590
/* Decompiled from supplied 5.2.2 arm package. VA 0x95f00. FUN_00095f00 */

void FUN_00095f00(undefined1 param_1 [16],undefined1 param_2 [16],double param_3,double param_4,
                 undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined1 auStack_160 [40];
  undefined1 *puStack_138;
  undefined8 local_130;
  undefined8 local_128;
  undefined8 local_120;
  undefined **local_118;
  undefined **local_110;
  undefined **local_100;
  undefined **ppuStack_f8;
  undefined **local_e8;
  undefined **ppuStack_e0;
  uint uStack_d4;
  undefined **local_d0;
  undefined **local_c8;
  uint local_bc;
  undefined **local_b8;
  undefined8 local_b0;
  
  local_b0 = *(undefined8 *)PTR____stack_chk_guard_01060708;
  local_b8 = &PTR_LAB_0117ed08;
  local_bc = (uint)(DAT_01226da8 == 0);
  local_d0 = &PTR_LAB_0117ed28;
  local_c8 = &PTR_LAB_01175340;
  local_e8 = &PTR_LAB_0117ed48;
  ppuStack_e0 = &PTR_LAB_01175340;
  local_100 = &PTR_LAB_0117ed68;
  ppuStack_f8 = &PTR_LAB_01175340;
  local_110 = &PTR_LAB_01175340;
  local_118 = &PTR_LAB_01175340;
  DAT_01226da8 = 1;
  puStack_138 = auStack_160;
  local_130 = param_5;
  local_128 = param_6;
  local_120 = param_7;
  _objc_retain(param_8);
  puVar1 = @selector(standardUserDefaults);
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,@selector(standardUserDefaults));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  puVar2 = @selector(objectForKey:);
  _objc_msgSend(uVar4,@selector(objectForKey:),@"progressMainColor");
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar4);
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,puVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,puVar2,@"progressGradientColor");
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar4);
  puVar3 = PTR__OBJC_CLASS___NSKeyedUnarchiver_0114ec50;
  puVar1 = @selector(class);
  uVar4 = _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(class));
  puVar2 = @selector(unarchivedObjectOfClass:fromData:error:);
  _objc_msgSend(puVar3,@selector(unarchivedObjectOfClass:fromData:error:),uVar4,uVar5,0);
  _objc_retainAutoreleasedReturnValue();
  puVar3 = PTR__OBJC_CLASS___NSKeyedUnarchiver_0114ec50;
  uVar4 = _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,puVar1);
  _objc_msgSend(puVar3,puVar2,uVar4,uVar6,0);
  _objc_retainAutoreleasedReturnValue();
  _objc_retain(param_8);
  _CGContextGetClipBoundingBox(local_120);
  _objc_msgSend(param_8,@selector(drawRect));
  _CGRectIntersection();
  uStack_d4 = 0;
  if (30.0 < param_4) {
    uStack_d4 = (uint)(ABS(param_3 - param_4) < 1.0);
  }
                    /* WARNING: Could not recover jumptable at 0x00096504. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(local_d0[uStack_d4] + (int)-(DAT_0117ed38 ^ 0xbed42dbe)))();
  return;
}


