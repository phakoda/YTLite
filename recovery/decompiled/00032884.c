/* Decompiled from supplied 5.2.2 arm package. VA 0x32884. FUN_00032884 */

int FUN_00032884(CCPBKDFAlgorithm param_1,char *param_2,size_t param_3,uint8_t *param_4,
                size_t param_5,CCPseudoRandomAlgorithm param_6,uint param_7,uint8_t *param_8,
                size_t param_9)

{
  int iVar1;
  
  iVar1 = _CCKeyDerivationPBKDF
                    (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  return iVar1;
}


