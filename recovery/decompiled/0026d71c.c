/* Decompiled from supplied 5.2.2 arm package. VA 0x26d71c. FUN_0026d71c */

undefined8 FUN_0026d71c(undefined8 param_1,long param_2)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = *(int *)(param_2 + 0x10);
  if (iVar1 < 1) {
    pcVar2 = "Valid timecode frame rate must be specified. Minimum value is 1\n";
  }
  else {
    if ((((*(byte *)(param_2 + 4) & 1) == 0) || (iVar1 == 0x1e)) || (iVar1 == 0x3c)) {
      iVar1 = FUN_0026d67c(iVar1);
      if (iVar1 < 0) {
        _av_log(param_1,0x18,"Using non-standard frame rate %d/%d\n");
      }
      return 0;
    }
    pcVar2 = "Drop frame is only allowed with 30000/1001 or 60000/1001 FPS\n";
  }
  _av_log(param_1,0x10,pcVar2);
  return 0xffffffea;
}


