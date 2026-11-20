/* Decompiled from supplied 5.2.2 arm package. VA 0x25c73c. _av_hash_names */

undefined8 _av_hash_names(ulong param_1)

{
  if (0xe < (uint)param_1) {
    return 0;
  }
  return *(undefined8 *)
          ((long)&PTR_s_MD5_010644f8 +
          (-(param_1 >> 0x1f & 1) & 0xfffffff000000000 | (param_1 & 0xffffffff) << 4));
}


