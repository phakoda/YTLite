/* Decompiled from supplied 5.2.2 arm package. VA 0x260a70. FUN_00260a70 */

void FUN_00260a70(int param_1,undefined8 param_2)

{
  _av_vlog(param_2,0x18);
  _av_log(param_2,0x18,
          " is not implemented. Update your FFmpeg version to the newest one from Git. If the problem still occurs, it means that your file has a feature which has not been implemented.\n"
         );
  if (param_1 != 0) {
    _av_log(param_2,0x18,
            "If you want to help, upload a sample of this file to https://streams.videolan.org/upload/ and contact the ffmpeg-devel mailing list. (ffmpeg-devel@ffmpeg.org)\n"
           );
  }
  return;
}


