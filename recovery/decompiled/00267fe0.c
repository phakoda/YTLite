/* Decompiled from supplied 5.2.2 arm package. VA 0x267fe0. _av_get_pix_fmt */

void _av_get_pix_fmt(char *param_1)

{
  int iVar1;
  ulong uVar2;
  uint uVar3;
  char *pcVar4;
  long lVar5;
  undefined1 auStack_48 [32];
  long local_28;
  
  lVar5 = *(long *)PTR____stack_chk_guard_01060708;
  local_28 = lVar5;
  iVar1 = _strcmp(param_1,"rgb32");
  if (iVar1 == 0) {
    pcVar4 = "bgra";
  }
  else {
    iVar1 = _strcmp(param_1,"bgr32");
    pcVar4 = "rgba";
    if (iVar1 != 0) {
      pcVar4 = param_1;
    }
  }
  uVar2 = FUN_002680d0(pcVar4);
  if ((int)uVar2 == -1) {
    ___snprintf_chk(auStack_48,0x20,0,0x20,"%s%s");
    uVar2 = FUN_002680d0(auStack_48);
    if ((int)uVar2 == -1) {
      iVar1 = _strcmp(pcVar4,"vaapi");
      uVar3 = 0x2e;
      if (iVar1 != 0) {
        uVar3 = 0xffffffff;
      }
      uVar2 = (ulong)uVar3;
    }
  }
  if (lVar5 != local_28) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail(uVar2);
  }
  return;
}


