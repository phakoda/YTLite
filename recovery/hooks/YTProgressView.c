// Decompiled hook evidence for YTProgressView. This is not compilable Logos source.

// -[YTProgressView setProgress:], original IMP slot 0x1225c78
/* Decompiled from supplied 5.2.2 arm package. VA 0x21788. FUN_00021788 */

void FUN_00021788(undefined8 param_1)

{
  ulong uVar1;
  
  DAT_01225d00 = 1;
  (*pcRam0000000001225c78)(param_1);
  uVar1 = FUN_00023208(@"sponsorBlock");
                    /* WARNING: Could not recover jumptable at 0x000220f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_01156618)[uVar1 & 0xffffffff] + (int)-(uRam0000000001156628 ^ 0x72f3198e)))()
  ;
  return;
}



// -[YTProgressView setProgressBarColor:], original IMP slot 0x01226598
/* Decompiled from supplied 5.2.2 arm package. VA 0x967dc. FUN_000967dc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000967dc(undefined8 param_1,undefined8 param_2,long param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  long lVar7;
  long lVar8;
  
  DAT_01226dac = 1;
  _objc_retain(param_3);
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
  lVar7 = _objc_retainAutoreleasedReturnValue();
  puVar3 = PTR__OBJC_CLASS___NSKeyedUnarchiver_0114ec50;
  uVar4 = _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,puVar1);
  _objc_msgSend(puVar3,puVar2,uVar4,uVar6,0);
  _objc_retainAutoreleasedReturnValue();
  lVar8 = _ytpInt(@"progressBarIndex");
  if (lVar8 != 0 && lVar7 != 0) {
    _objc_retain((&PTR_LAB_0117edb0)[lVar8 != 0 && lVar7 != 0] +
                 (int)-(uRam000000000117edc0 ^ 0x21398f13),lVar7);
    _objc_release(param_3);
    param_3 = lVar7;
  }
  (*_DAT_01226598)(param_1,param_2,param_3);
  uVar4 = _objc_msgSend(param_1,puVar1);
  lVar7 = _class_getInstanceVariable(uVar4,s__progressBarGradient_0116a990);
                    /* WARNING: Could not recover jumptable at 0x00097070. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR__objc_msgSend_0117edd0)[lVar7 == 0] + (int)-(uRam000000000117ede0 ^ 0xe8f444cb)))
            ();
  return;
}



// -[YTProgressView setProgress:], original IMP slot 0x012265a0
/* Decompiled from supplied 5.2.2 arm package. VA 0x97274. FUN_00097274 */

void FUN_00097274(undefined8 param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  ulong uVar3;
  
  if (DAT_01226db0 == 0) {
    s_ytpGradient_0116acad[0] = DAT_0116aca1 ^ 0xcb;
    s_ytpGradient_0116acad[1] = bRam000000000116aca2 ^ 0x2e;
    s_ytpGradient_0116acad[2] = bRam000000000116aca3 ^ 0x29;
    s_ytpGradient_0116acad[3] = bRam000000000116aca4 ^ 0x9a;
    s_ytpGradient_0116acad[4] = bRam000000000116aca5 ^ 0xba;
    s_ytpGradient_0116acad[5] = bRam000000000116aca6 ^ 0x88;
    s_ytpGradient_0116acad[6] = bRam000000000116aca7 ^ 0xa0;
    s_ytpGradient_0116acad[7] = bRam000000000116aca8 ^ 0x47;
    s_ytpGradient_0116acad[8] = bRam000000000116aca9 ^ 0x73;
    s_ytpGradient_0116acad[9] = bRam000000000116acaa ^ 0xb8;
    s_ytpGradient_0116acad[10] = bRam000000000116acab ^ 0xfe;
    s_ytpGradient_0116acad[0xb] = bRam000000000116acac ^ 0xa9;
    s_YTVideoThumbnailView_0116ace0[0] = bRam000000000116acc0 ^ 5;
    s_YTVideoThumbnailView_0116ace0[1] = bRam000000000116acc1 ^ 0xaa;
    s_YTVideoThumbnailView_0116ace0[2] = bRam000000000116acc2 ^ 0x16;
    s_YTVideoThumbnailView_0116ace0[3] = bRam000000000116acc3 ^ 0xe8;
    s_YTVideoThumbnailView_0116ace0[4] = bRam000000000116acc4 ^ 0xe5;
    s_YTVideoThumbnailView_0116ace0[5] = bRam000000000116acc5 ^ 0xeb;
    s_YTVideoThumbnailView_0116ace0[6] = bRam000000000116acc6 ^ 0x5c;
    s_YTVideoThumbnailView_0116ace0[7] = bRam000000000116acc7 ^ 0x1a;
    s_YTVideoThumbnailView_0116ace0[8] = bRam000000000116acc8 ^ 0x41;
    s_YTVideoThumbnailView_0116ace0[9] = bRam000000000116acc9 ^ 0x2b;
    s_YTVideoThumbnailView_0116ace0[10] = bRam000000000116acca ^ 0x84;
    s_YTVideoThumbnailView_0116ace0[0xb] = bRam000000000116accb ^ 7;
    s_YTVideoThumbnailView_0116ace0[0xc] = bRam000000000116accc ^ 0xc6;
    s_YTVideoThumbnailView_0116ace0[0xd] = bRam000000000116accd ^ 0x33;
    s_YTVideoThumbnailView_0116ace0[0xe] = bRam000000000116acce ^ 99;
    s_YTVideoThumbnailView_0116ace0[0xf] = bRam000000000116accf ^ 0xa4;
    s_YTVideoThumbnailView_0116ace0[0x10] = bRam000000000116acd0 ^ 0x4d;
    s_YTVideoThumbnailView_0116ace0[0x11] = bRam000000000116acd1 ^ 0x11;
    s_YTVideoThumbnailView_0116ace0[0x12] = bRam000000000116acd2 ^ 0x5f;
    s_YTVideoThumbnailView_0116ace0[0x13] = bRam000000000116acd3 ^ 0x9b;
    s_YTVideoThumbnailView_0116ace0[0x14] = bRam000000000116acd4 ^ 0xf2;
    s__progressBarGradientView_0116ab90[0] = DAT_0116ab70 ^ 0xf0;
    s__progressBarGradientView_0116ab90[1] = bRam000000000116ab71 ^ 0xb2;
    s__progressBarGradientView_0116ab90[2] = bRam000000000116ab72 ^ 0x68;
    s__progressBarGradientView_0116ab90[3] = bRam000000000116ab73 ^ 99;
    s__progressBarGradientView_0116ab90[4] = bRam000000000116ab74 ^ 3;
    s__progressBarGradientView_0116ab90[5] = bRam000000000116ab75 ^ 0xab;
    s__progressBarGradientView_0116ab90[6] = bRam000000000116ab76 ^ 0xaa;
    s__progressBarGradientView_0116ab90[7] = bRam000000000116ab77 ^ 0xb0;
    s__progressBarGradientView_0116ab90[8] = bRam000000000116ab78 ^ 0x75;
    s__progressBarGradientView_0116ab90[9] = bRam000000000116ab79 ^ 0xd3;
    s__progressBarGradientView_0116ab90[10] = bRam000000000116ab7a ^ 0x17;
    s__progressBarGradientView_0116ab90[0xb] = bRam000000000116ab7b ^ 0x99;
    s__progressBarGradientView_0116ab90[0xc] = bRam000000000116ab7c ^ 0x31;
    s__progressBarGradientView_0116ab90[0xd] = bRam000000000116ab7d ^ 0x79;
    s__progressBarGradientView_0116ab90[0xe] = bRam000000000116ab7e ^ 0x26;
    s__progressBarGradientView_0116ab90[0xf] = bRam000000000116ab7f ^ 0xdd;
    s__progressBarGradientView_0116ab90[0x10] = bRam000000000116ab80 ^ 0xbb;
    s__progressBarGradientView_0116ab90[0x11] = bRam000000000116ab81 ^ 1;
    s__progressBarGradientView_0116ab90[0x12] = bRam000000000116ab82 ^ 0xea;
    s__progressBarGradientView_0116ab90[0x13] = bRam000000000116ab83 ^ 0x77;
    s__progressBarGradientView_0116ab90[0x14] = bRam000000000116ab84 ^ 0x7e;
    s__progressBarGradientView_0116ab90[0x15] = bRam000000000116ab85 ^ 0x7f;
    s__progressBarGradientView_0116ab90[0x16] = bRam000000000116ab86 ^ 0x6b;
    s__progressBarGradientView_0116ab90[0x17] = bRam000000000116ab87 ^ 0x67;
    s__progressBarGradientView_0116ab90[0x18] = bRam000000000116ab88 ^ 5;
    s_progressBarIndex_0116ac90[0] = DAT_0116ac70 ^ 0xbe;
    s_progressBarIndex_0116ac90[1] = bRam000000000116ac71 ^ 0x4d;
    s_progressBarIndex_0116ac90[2] = bRam000000000116ac72 ^ 0x7e;
    s_progressBarIndex_0116ac90[3] = bRam000000000116ac73 ^ 0x58;
    s_progressBarIndex_0116ac90[4] = bRam000000000116ac74 ^ 8;
    s_progressBarIndex_0116ac90[5] = bRam000000000116ac75 ^ 0xc1;
    s_progressBarIndex_0116ac90[6] = bRam000000000116ac76 ^ 0xaf;
    s_progressBarIndex_0116ac90[7] = bRam000000000116ac77 ^ 0x9c;
    s_progressBarIndex_0116ac90[8] = bRam000000000116ac78 ^ 0xd0;
    s_progressBarIndex_0116ac90[9] = bRam000000000116ac79 ^ 0x86;
    s_progressBarIndex_0116ac90[10] = bRam000000000116ac7a ^ 0xc1;
    s_progressBarIndex_0116ac90[0xb] = bRam000000000116ac7b ^ 0xac;
    s_progressBarIndex_0116ac90[0xc] = bRam000000000116ac7c ^ 0xdc;
    s_progressBarIndex_0116ac90[0xd] = bRam000000000116ac7d ^ 0xc4;
    s_progressBarIndex_0116ac90[0xe] = bRam000000000116ac7e ^ 0x39;
    s_progressBarIndex_0116ac90[0xf] = bRam000000000116ac7f ^ 0x6e;
    s_progressBarIndex_0116ac90[0x10] = bRam000000000116ac80 ^ 0x84;
    s_progressMainColor_0116ac50[0] = DAT_0116ac30 ^ 0x84;
    s_progressMainColor_0116ac50[1] = bRam000000000116ac31 ^ 0xbd;
    s_progressMainColor_0116ac50[2] = bRam000000000116ac32 ^ 0xbf;
    s_progressMainColor_0116ac50[3] = bRam000000000116ac33 ^ 0x82;
    s_progressMainColor_0116ac50[4] = bRam000000000116ac34 ^ 0xa2;
    s_progressMainColor_0116ac50[5] = bRam000000000116ac35 ^ 0xbe;
    s_progressMainColor_0116ac50[6] = bRam000000000116ac36 ^ 0x5e;
    s_progressMainColor_0116ac50[7] = bRam000000000116ac37 ^ 0x28;
    s_progressMainColor_0116ac50[8] = bRam000000000116ac38 ^ 0x3c;
    s_progressMainColor_0116ac50[9] = bRam000000000116ac39 ^ 6;
    s_progressMainColor_0116ac50[10] = bRam000000000116ac3a ^ 0x75;
    s_progressMainColor_0116ac50[0xb] = bRam000000000116ac3b ^ 0xfc;
    s_progressMainColor_0116ac50[0xc] = bRam000000000116ac3c ^ 0xa4;
    s_progressMainColor_0116ac50[0xd] = bRam000000000116ac3d ^ 2;
    s_progressMainColor_0116ac50[0xe] = bRam000000000116ac3e ^ 0xc9;
    s_progressMainColor_0116ac50[0xf] = bRam000000000116ac3f ^ 0x1d;
    s_progressMainColor_0116ac50[0x10] = bRam000000000116ac40 ^ 0x48;
    s_progressMainColor_0116ac50[0x11] = bRam000000000116ac41 ^ 0xdc;
    s_progressGradientColor_0116ac10[0] = DAT_0116abf0 ^ 0x22;
    s_progressGradientColor_0116ac10[1] = bRam000000000116abf1 ^ 0xf2;
    s_progressGradientColor_0116ac10[2] = bRam000000000116abf2 ^ 0x71;
    s_progressGradientColor_0116ac10[3] = bRam000000000116abf3 ^ 0xf3;
    s_progressGradientColor_0116ac10[4] = bRam000000000116abf4 ^ 0x6f;
    s_progressGradientColor_0116ac10[5] = bRam000000000116abf5 ^ 0xf9;
    s_progressGradientColor_0116ac10[6] = bRam000000000116abf6 ^ 3;
    s_progressGradientColor_0116ac10[7] = bRam000000000116abf7 ^ 6;
    s_progressGradientColor_0116ac10[8] = bRam000000000116abf8 ^ 0x7f;
    s_progressGradientColor_0116ac10[9] = bRam000000000116abf9 ^ 0x33;
    s_progressGradientColor_0116ac10[10] = bRam000000000116abfa ^ 0xf6;
    s_progressGradientColor_0116ac10[0xb] = bRam000000000116abfb ^ 0x21;
    s_progressGradientColor_0116ac10[0xc] = bRam000000000116abfc ^ 0xb9;
    s_progressGradientColor_0116ac10[0xd] = bRam000000000116abfd ^ 1;
    s_progressGradientColor_0116ac10[0xe] = bRam000000000116abfe ^ 0x85;
    s_progressGradientColor_0116ac10[0xf] = bRam000000000116abff ^ 0xe0;
    s_progressGradientColor_0116ac10[0x10] = bRam000000000116ac00 ^ 0xe3;
    s_progressGradientColor_0116ac10[0x11] = bRam000000000116ac01 ^ 99;
    s_progressGradientColor_0116ac10[0x12] = bRam000000000116ac02 ^ 0x55;
    s_progressGradientColor_0116ac10[0x13] = bRam000000000116ac03 ^ 3;
    s_progressGradientColor_0116ac10[0x14] = bRam000000000116ac04 ^ 0x14;
    s_progressGradientColor_0116ac10[0x15] = bRam000000000116ac05 ^ 1;
    s__progressBarGradientView_0116abd0[0] = bRam000000000116abb0 ^ 0xc4;
    s__progressBarGradientView_0116abd0[1] = bRam000000000116abb1 ^ 0xe7;
    s__progressBarGradientView_0116abd0[2] = bRam000000000116abb2 ^ 0x51;
    s__progressBarGradientView_0116abd0[3] = bRam000000000116abb3 ^ 0xb2;
    s__progressBarGradientView_0116abd0[4] = bRam000000000116abb4 ^ 0x97;
    s__progressBarGradientView_0116abd0[5] = bRam000000000116abb5 ^ 0x72;
    s__progressBarGradientView_0116abd0[6] = bRam000000000116abb6 ^ 0x29;
    s__progressBarGradientView_0116abd0[7] = bRam000000000116abb7 ^ 0x7e;
    s__progressBarGradientView_0116abd0[8] = bRam000000000116abb8 ^ 0xee;
    s__progressBarGradientView_0116abd0[9] = bRam000000000116abb9 ^ 0x58;
    s__progressBarGradientView_0116abd0[10] = bRam000000000116abba ^ 0x60;
    s__progressBarGradientView_0116abd0[0xb] = bRam000000000116abbb ^ 0x99;
    s__progressBarGradientView_0116abd0[0xc] = bRam000000000116abbc ^ 0x7e;
    s__progressBarGradientView_0116abd0[0xd] = bRam000000000116abbd ^ 0xca;
    s__progressBarGradientView_0116abd0[0xe] = bRam000000000116abbe ^ 0x2d;
    s__progressBarGradientView_0116abd0[0xf] = bRam000000000116abbf ^ 0x46;
    s__progressBarGradientView_0116abd0[0x10] = bRam000000000116abc0 ^ 0xe4;
    s__progressBarGradientView_0116abd0[0x11] = bRam000000000116abc1 ^ 0x4d;
    s__progressBarGradientView_0116abd0[0x12] = bRam000000000116abc2 ^ 1;
    s__progressBarGradientView_0116abd0[0x13] = bRam000000000116abc3 ^ 0x89;
    s__progressBarGradientView_0116abd0[0x14] = bRam000000000116abc4 ^ 0x40;
    s__progressBarGradientView_0116abd0[0x15] = bRam000000000116abc5 ^ 0x67;
    s__progressBarGradientView_0116abd0[0x16] = bRam000000000116abc6 ^ 0x8d;
    s__progressBarGradientView_0116abd0[0x17] = bRam000000000116abc7 ^ 0x18;
    s__progressBarGradientView_0116abd0[0x18] = bRam000000000116abc8 ^ 0xad;
  }
  DAT_01226db0 = 1;
  (*DAT_012265a0)(param_1);
  _objc_msgSend(param_1,@selector(superview));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  uVar2 = _objc_getClass(s_YTVideoThumbnailView_0116ace0);
  uVar3 = FUN_000e3100(uVar1,@selector(isKindOfClass:),uVar2);
  _objc_release(uVar1);
                    /* WARNING: Could not recover jumptable at 0x00097c7c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117ee58)[uVar3 & 0xffffffff] + (int)-(DAT_0117ee68 ^ 0x137ee3a0)))();
  return;
}


