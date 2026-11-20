/* Decompiled from supplied 5.2.2 arm package. VA 0x25e5ac. FUN_0025e5ac */

int FUN_0025e5ac(long param_1,undefined8 *param_2,long param_3,int param_4)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  undefined8 uVar6;
  char *pcVar7;
  undefined8 uVar8;
  long lVar9;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar9 = *(long *)PTR____stack_chk_guard_01060708;
  uVar8 = *(undefined8 *)(param_3 + 0x18);
  iVar4 = -0x4e4b4e55;
  local_58 = lVar9;
  uVar2 = _CVPixelBufferGetPixelFormatType(uVar8);
  iVar3 = _av_map_videotoolbox_format_to_pixfmt();
  if (*(int *)((long)param_2 + 0x74) == iVar3) {
    lVar5 = _CVPixelBufferGetWidth(uVar8);
    if ((lVar5 == *(int *)(param_1 + 0x4c)) &&
       (lVar5 = _CVPixelBufferGetHeight(uVar8), lVar5 == *(int *)(param_1 + 0x50))) {
      bVar1 = param_4 == 1;
      iVar3 = _CVPixelBufferLockBaseAddress(uVar8,bVar1);
      if (iVar3 == 0) {
        iVar4 = _CVPixelBufferIsPlanar(uVar8);
        if (iVar4 == 0) {
          uVar6 = _CVPixelBufferGetBaseAddress(uVar8);
          *param_2 = uVar6;
          uVar2 = _CVPixelBufferGetBytesPerRow(uVar8);
          *(undefined4 *)(param_2 + 8) = uVar2;
        }
        else {
          iVar4 = _CVPixelBufferGetPlaneCount(uVar8);
          for (lVar5 = 0; lVar5 < iVar4; lVar5 = lVar5 + 1) {
            uVar6 = _CVPixelBufferGetBaseAddressOfPlane(uVar8,lVar5);
            param_2[lVar5] = uVar6;
            uVar2 = _CVPixelBufferGetBytesPerRowOfPlane(uVar8,lVar5);
            *(undefined4 *)((long)param_2 + lVar5 * 4 + 0x40) = uVar2;
          }
        }
        iVar4 = _ff_hwframe_map_create
                          (*(undefined8 *)(param_3 + 0x1e0),param_2,param_3,FUN_0025e770,bVar1);
        if (iVar4 < 0) {
          _CVPixelBufferUnlockBaseAddress(uVar8,bVar1);
        }
        else {
          iVar4 = 0;
        }
        goto LAB_0025e698;
      }
      pcVar7 = "Error locking the pixel buffer.\n";
    }
    else {
      pcVar7 = "Inconsistent frame dimensions.\n";
    }
  }
  else {
    local_68 = 0;
    uStack_60 = 0;
    local_78 = 0;
    uStack_70 = 0;
    _av_fourcc_make_string(&local_78,uVar2);
    pcVar7 = "Unsupported or mismatching pixel format: %s\n";
  }
  _av_log(param_1,0x10,pcVar7);
LAB_0025e698:
  if (lVar9 != local_58) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  return iVar4;
}


