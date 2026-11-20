/* Decompiled from supplied 5.2.2 arm package. VA 0x20398c. clip */

/* Function Stack Size: 0x10 bytes */

ID YTPDB::clip(ID param_1,SEL param_2)

{
  ID IVar1;
  undefined **ppuStack_1e0;
  undefined **ppuStack_1d8;
  undefined **ppuStack_1d0;
  undefined **ppuStack_1c8;
  undefined **ppuStack_1c0;
  undefined **ppuStack_1b8;
  undefined **ppuStack_1b0;
  undefined **ppuStack_1a8;
  undefined **ppuStack_1a0;
  undefined **ppuStack_198;
  undefined **ppuStack_190;
  undefined **ppuStack_188;
  undefined **ppuStack_180;
  undefined **ppuStack_178;
  undefined **ppuStack_170;
  undefined **ppuStack_168;
  undefined **ppuStack_160;
  undefined **ppuStack_158;
  undefined **ppuStack_150;
  undefined **ppuStack_148;
  undefined **ppuStack_140;
  undefined **ppuStack_138;
  undefined **ppuStack_130;
  undefined **ppuStack_128;
  undefined **ppuStack_120;
  undefined **ppuStack_118;
  undefined **ppuStack_110;
  undefined **ppuStack_108;
  undefined **ppuStack_100;
  undefined **ppuStack_f8;
  undefined **ppuStack_f0;
  undefined **ppuStack_e8;
  undefined **ppuStack_e0;
  undefined **ppuStack_d8;
  undefined **ppuStack_d0;
  undefined **ppuStack_c8;
  undefined **ppuStack_c0;
  undefined **ppuStack_b8;
  undefined **ppuStack_b0;
  undefined **ppuStack_a8;
  undefined **ppuStack_a0;
  undefined **ppuStack_98;
  undefined **ppuStack_90;
  undefined **ppuStack_88;
  undefined **ppuStack_80;
  undefined **ppuStack_78;
  undefined **ppuStack_70;
  undefined **ppuStack_68;
  undefined **ppuStack_60;
  undefined **ppuStack_58;
  undefined **ppuStack_50;
  undefined **ppuStack_48;
  undefined **ppuStack_40;
  undefined **local_30;
  uint local_24;
  undefined **local_20;
  long local_18;
  
  local_18 = *(long *)PTR____stack_chk_guard_01060708;
  local_20 = &PTR_LAB_011cb080;
  local_24 = (uint)(DAT_012280b4 == 0);
  local_30 = &PTR_LAB_011caf70;
  DAT_012280b4 = 1;
  ppuStack_1e0 = &PTR____CFConstantStringClassReference_011c5390;
  ppuStack_1d8 = &PTR____CFConstantStringClassReference_011c5290;
  ppuStack_1d0 = &PTR____CFConstantStringClassReference_011c53d0;
  ppuStack_1c8 = &PTR____CFConstantStringClassReference_011c5210;
  ppuStack_1c0 = &PTR____CFConstantStringClassReference_011c4e10;
  ppuStack_1b8 = &PTR____CFConstantStringClassReference_011c5190;
  ppuStack_1b0 = &PTR____CFConstantStringClassReference_011c4a90;
  ppuStack_1a8 = &PTR____CFConstantStringClassReference_011c5010;
  ppuStack_1a0 = &PTR____CFConstantStringClassReference_011c5150;
  ppuStack_198 = &PTR____CFConstantStringClassReference_011c4ed0;
  ppuStack_190 = &PTR____CFConstantStringClassReference_011c5310;
  ppuStack_188 = &PTR____CFConstantStringClassReference_011c52d0;
  ppuStack_180 = &PTR____CFConstantStringClassReference_011c48d0;
  ppuStack_178 = &PTR____CFConstantStringClassReference_011c4d10;
  ppuStack_170 = &PTR____CFConstantStringClassReference_011c4c90;
  ppuStack_168 = &PTR____CFConstantStringClassReference_011c5110;
  ppuStack_160 = &PTR____CFConstantStringClassReference_011c51d0;
  ppuStack_158 = &PTR____CFConstantStringClassReference_011c4f50;
  ppuStack_150 = &PTR____CFConstantStringClassReference_011c4fd0;
  ppuStack_148 = &PTR____CFConstantStringClassReference_011c4e50;
  ppuStack_140 = &PTR____CFConstantStringClassReference_011c5410;
  ppuStack_138 = &PTR____CFConstantStringClassReference_011c4d90;
  ppuStack_130 = &PTR____CFConstantStringClassReference_011c4d50;
  ppuStack_128 = &PTR____CFConstantStringClassReference_011c4c50;
  ppuStack_120 = &PTR____CFConstantStringClassReference_011c4bd0;
  ppuStack_118 = &PTR____CFConstantStringClassReference_011c4c10;
  ppuStack_110 = &PTR____CFConstantStringClassReference_011c4b90;
  ppuStack_108 = &PTR____CFConstantStringClassReference_011c4b50;
  ppuStack_100 = &PTR____CFConstantStringClassReference_011c4f10;
  ppuStack_f8 = &PTR____CFConstantStringClassReference_011c5150;
  ppuStack_f0 = &PTR____CFConstantStringClassReference_011c4dd0;
  ppuStack_e8 = &PTR____CFConstantStringClassReference_011c4cd0;
  ppuStack_e0 = &PTR____CFConstantStringClassReference_011c4b10;
  ppuStack_d8 = &PTR____CFConstantStringClassReference_011c4e90;
  ppuStack_d0 = &PTR____CFConstantStringClassReference_011c50d0;
  ppuStack_c8 = &PTR____CFConstantStringClassReference_011c4910;
  ppuStack_c0 = &PTR____CFConstantStringClassReference_011c4ad0;
  ppuStack_b8 = &PTR____CFConstantStringClassReference_011c4a50;
  ppuStack_b0 = &PTR____CFConstantStringClassReference_011c49d0;
  ppuStack_a8 = &PTR____CFConstantStringClassReference_011c4990;
  ppuStack_a0 = &PTR____CFConstantStringClassReference_011c4950;
  ppuStack_98 = &PTR____CFConstantStringClassReference_011c5350;
  ppuStack_90 = &PTR____CFConstantStringClassReference_011c5050;
  ppuStack_88 = &PTR____CFConstantStringClassReference_011c4890;
  ppuStack_80 = &PTR____CFConstantStringClassReference_011c4850;
  ppuStack_78 = &PTR____CFConstantStringClassReference_011c5250;
  ppuStack_70 = &PTR____CFConstantStringClassReference_011c4810;
  ppuStack_68 = &PTR____CFConstantStringClassReference_011c4a10;
  ppuStack_60 = &PTR____CFConstantStringClassReference_011c4f90;
  ppuStack_58 = &PTR____CFConstantStringClassReference_011c47d0;
  ppuStack_50 = &PTR____CFConstantStringClassReference_011c5090;
  ppuStack_48 = &PTR____CFConstantStringClassReference_011c4790;
  ppuStack_40 = &PTR____CFConstantStringClassReference_011c4750;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,PTR_s_arrayWithObjects_count__0114b600,
                &ppuStack_1e0,0x35);
  _objc_retainAutoreleasedReturnValue();
  if (*(long *)PTR____stack_chk_guard_01060708 == local_18) {
    IVar1 = _objc_autoreleaseReturnValue();
    return IVar1;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


