/* Decompiled from supplied 5.2.2 arm package. VA 0x268388. _av_pix_fmt_get_chroma_sub_sample */

undefined8 _av_pix_fmt_get_chroma_sub_sample(uint param_1,uint *param_2,uint *param_3)

{
  byte bVar1;
  long lVar2;
  undefined8 uVar3;
  
  uVar3 = 0xffffffb2;
  if ((param_1 < 0xc6) && ((long)(int)param_1 * 0xa0 != -0x1065540)) {
    lVar2 = (long)(int)param_1 * 0xa0;
    bVar1 = (&DAT_0106554a)[lVar2];
    uVar3 = 0;
    *param_2 = (uint)(byte)(&DAT_01065549)[lVar2];
    *param_3 = (uint)bVar1;
  }
  return uVar3;
}


