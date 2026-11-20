/* Decompiled from supplied 5.2.2 arm package. VA 0x18924. FUN_00018924 */

void FUN_00018924(undefined8 param_1,undefined8 param_2,long param_3)

{
  if (DAT_01225b9c != 0) {
    DAT_01225b9c = 1;
                    /* WARNING: Could not recover jumptable at 0x000189d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)((&PTR_LAB_01155278)[param_3 == 0] + (int)-(uRam0000000001155288 ^ 0x7da69e67)))();
    return;
  }
  s_AppGroup_01154289[0] = DAT_01154280 ^ 0xd;
  s_AppGroup_01154289[1] = bRam0000000001154281 ^ 0xab;
  s_AppGroup_01154289[2] = bRam0000000001154282 ^ 0xcc;
  s_AppGroup_01154289[3] = bRam0000000001154283 ^ 0xc6;
  s_AppGroup_01154289[4] = bRam0000000001154284 ^ 0x17;
  s_AppGroup_01154289[5] = bRam0000000001154285 ^ 0x7a;
  s_AppGroup_01154289[6] = bRam0000000001154286 ^ 0x89;
  s_AppGroup_01154289[7] = bRam0000000001154287 ^ 0xa5;
  s_AppGroup_01154289[8] = bRam0000000001154288 ^ 0x1c;
  DAT_01225b9c = 1;
                    /* WARNING: Could not recover jumptable at 0x00018b40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_01155278)[param_3 == 0] + (int)-(uRam0000000001155288 ^ 0x7da69e67)))();
  return;
}


