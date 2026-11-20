/* Decompiled from supplied 5.2.2 arm package. VA 0x1fff08. formatTime: */

/* Function Stack Size: 0x18 bytes */

ID SRTParser::formatTime_(ID param_1,SEL param_2,double param_3)

{
  ID IVar1;
  long lVar2;
  double dVar3;
  
  DAT_012280a4 = 1;
  dVar3 = param_3 - (double)((long)(param_3 / DAT_00c4c380) * 0xe10);
  lVar2 = (long)(dVar3 / 60.0);
  IVar1 = FUN_002012e0(PTR__OBJC_CLASS___NSString_0114eb38,PTR_s_stringWithFormat__0114b378,
                       &PTR____CFConstantStringClassReference_011c2250,
                       (long)(param_3 / DAT_00c4c380),lVar2,(long)(dVar3 - (double)(lVar2 * 0x3c)),
                       (long)((param_3 - (double)(long)param_3) * DAT_00c4c4a0));
  return IVar1;
}


