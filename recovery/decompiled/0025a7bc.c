/* Decompiled from supplied 5.2.2 arm package. VA 0x25a7bc. _av_file_map */

int _av_file_map(undefined8 param_1,long *param_2,long *param_3,undefined4 param_4,
                undefined8 param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  ulong uVar5;
  int *piVar6;
  long lVar7;
  stat sStack_170;
  undefined **local_e0;
  undefined4 local_d8;
  undefined8 local_d0;
  undefined1 auStack_c8 [128];
  long local_48;
  
  lVar7 = *(long *)PTR____stack_chk_guard_01060708;
  local_e0 = &PTR_s_FILE_01064338;
  local_d8 = param_4;
  local_d0 = param_5;
  local_48 = lVar7;
  iVar1 = _avpriv_open(param_1,0);
  *param_2 = 0;
  *param_3 = 0;
  if (iVar1 < 0) {
    piVar6 = ___error();
    iVar2 = -*piVar6;
    _av_strerror(iVar2,auStack_c8,0x80);
    uVar5 = _av_log(&local_e0,0x10,"Cannot read file \'%s\': %s\n");
  }
  else {
    iVar2 = _fstat(iVar1,&sStack_170);
    if (iVar2 < 0) {
      piVar6 = ___error();
      iVar2 = -*piVar6;
      _av_strerror(iVar2,auStack_c8,0x80);
      _av_log(&local_e0,0x10,"Error occurred in fstat(): %s\n");
      uVar3 = _close(iVar1);
      uVar5 = (ulong)uVar3;
    }
    else {
      *param_3 = sStack_170.st_size;
      lVar4 = 0;
      if ((sStack_170.st_size == 0) ||
         (lVar4 = _mmap(0,sStack_170.st_size,3,2,iVar1,0), lVar4 != -1)) {
        *param_2 = lVar4;
        uVar3 = _close(iVar1);
        uVar5 = (ulong)uVar3;
        iVar2 = 0;
      }
      else {
        piVar6 = ___error();
        iVar2 = -*piVar6;
        _av_strerror(iVar2,auStack_c8,0x80);
        _av_log(&local_e0,0x10,"Error occurred in mmap(): %s\n");
        uVar3 = _close(iVar1);
        uVar5 = (ulong)uVar3;
        *param_3 = 0;
      }
    }
  }
  if (lVar7 == local_48) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(uVar5);
}


