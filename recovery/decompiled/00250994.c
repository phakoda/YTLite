/* Decompiled from supplied 5.2.2 arm package. VA 0x250994. FUN_00250994 */

void FUN_00250994(undefined1 *param_1,int param_2,long param_3)

{
  byte bVar1;
  byte bVar2;
  
  *param_1 = *(undefined1 *)(param_3 + (*(ulong *)(param_1 + 0x10) & 0xff));
  param_1[4] = *(undefined1 *)(param_3 + (*(ulong *)(param_1 + 0x10) >> 0x20 & 0xff));
  param_1[8] = *(undefined1 *)(param_3 + (*(ulong *)(param_1 + 0x18) & 0xff));
  param_1[0xc] = *(undefined1 *)(param_3 + (*(ulong *)(param_1 + 0x18) >> 0x20 & 0xff));
  bVar1 = param_1[0x1b - (long)param_2];
  param_1[3 - (long)param_2] = *(undefined1 *)(param_3 + (ulong)(byte)param_1[0x17 - (long)param_2])
  ;
  bVar2 = param_1[0x1f - (long)param_2];
  param_1[7 - (long)param_2] = *(undefined1 *)(param_3 + (ulong)bVar1);
  bVar1 = param_1[0x13 - (long)param_2];
  param_1[0xb - (long)param_2] = *(undefined1 *)(param_3 + (ulong)bVar2);
  param_1[0xf - (long)param_2] = *(undefined1 *)(param_3 + (ulong)bVar1);
  param_1[2] = *(undefined1 *)(param_3 + (ulong)(byte)param_1[0x1a]);
  param_1[10] = *(undefined1 *)(param_3 + (ulong)(byte)param_1[0x12]);
  param_1[6] = *(undefined1 *)(param_3 + (ulong)(byte)param_1[0x1e]);
  param_1[0xe] = *(undefined1 *)(param_3 + (ulong)(byte)param_1[0x16]);
  param_1[(long)param_2 + 1] = *(undefined1 *)(param_3 + (ulong)(byte)param_1[(long)param_2 + 0x1d])
  ;
  param_1[(long)param_2 + 0xd] =
       *(undefined1 *)(param_3 + (ulong)(byte)param_1[(long)param_2 + 0x19]);
  param_1[(long)param_2 + 9] = *(undefined1 *)(param_3 + (ulong)(byte)param_1[(long)param_2 + 0x15])
  ;
  param_1[(long)param_2 + 5] = *(undefined1 *)(param_3 + (ulong)(byte)param_1[(long)param_2 + 0x11])
  ;
  return;
}


