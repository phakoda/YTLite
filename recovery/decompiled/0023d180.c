/* Decompiled from supplied 5.2.2 arm package. VA 0x23d180. imgForVal: */

/* Function Stack Size: 0x18 bytes */

ID PlayerToast::imgForVal_(ID param_1,SEL param_2,double param_3)

{
  ID IVar1;
  
  if (DAT_0122854c != 0) {
    DAT_0122854c = 1;
                    /* WARNING: Could not recover jumptable at 0x0023d2c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    IVar1 = (*(code *)((&PTR_LAB_011d28d8)[*(long *)(param_1 + (long)_style) < 1] +
                      (int)-(uRam00000000011d28e8 ^ 0xb515959c)))();
    return IVar1;
  }
  s_vol_low_011d2352[0] = DAT_011d234a ^ 0x8e;
  s_vol_low_011d2352[1] = bRam00000000011d234b ^ 0xf9;
  s_vol_low_011d2352[2] = bRam00000000011d234c ^ 0x70;
  s_vol_low_011d2352[3] = bRam00000000011d234d ^ 0x21;
  s_vol_low_011d2352[4] = bRam00000000011d234e ^ 0x2f;
  s_vol_low_011d2352[5] = bRam00000000011d234f ^ 0x5c;
  s_vol_low_011d2352[6] = bRam00000000011d2350 ^ 200;
  s_vol_low_011d2352[7] = bRam00000000011d2351 ^ 0x9d;
  s_speed_fast_011d233f[0] = DAT_011d2334 ^ 0x76;
  s_speed_fast_011d233f[1] = DAT_011d2335 ^ 0xe1;
  s_speed_fast_011d233f[2] = DAT_011d2336 ^ 0xa2;
  s_speed_fast_011d233f[3] = DAT_011d2337 ^ 0x2a;
  s_speed_fast_011d233f[4] = DAT_011d2338 ^ 0xf5;
  s_speed_fast_011d233f[5] = DAT_011d2339 ^ 0xed;
  s_speed_fast_011d233f[6] = DAT_011d233a ^ 0xe3;
  s_speed_fast_011d233f[7] = DAT_011d233b ^ 0xe9;
  s_speed_fast_011d233f[8] = DAT_011d233c ^ 0x6e;
  s_speed_fast_011d233f[9] = DAT_011d233d ^ 0x36;
  s_speed_fast_011d233f[10] = DAT_011d233e ^ 0x30;
  s_speed_slow_011d2375[0] = DAT_011d236a ^ 0x1b;
  s_speed_slow_011d2375[1] = DAT_011d236b ^ 0x7a;
  s_speed_slow_011d2375[2] = DAT_011d236c ^ 0x48;
  s_speed_slow_011d2375[3] = DAT_011d236d ^ 0x87;
  s_speed_slow_011d2375[4] = DAT_011d236e ^ 0xf2;
  s_speed_slow_011d2375[5] = DAT_011d236f ^ 0xeb;
  s_speed_slow_011d2375[6] = DAT_011d2370 ^ 0x9b;
  s_speed_slow_011d2375[7] = DAT_011d2371 ^ 0x59;
  s_speed_slow_011d2375[8] = DAT_011d2372 ^ 0xe8;
  s_speed_slow_011d2375[9] = DAT_011d2373 ^ 0x41;
  s_speed_slow_011d2375[10] = DAT_011d2374 ^ 0x20;
  s_sun_min_011d232c[0] = DAT_011d2324 ^ 0xb;
  s_sun_min_011d232c[1] = DAT_011d2325 ^ 0xe3;
  s_sun_min_011d232c[2] = DAT_011d2326 ^ 0x27;
  s_sun_min_011d232c[3] = DAT_011d2327 ^ 0x87;
  s_sun_min_011d232c[4] = DAT_011d2328 ^ 0xa2;
  s_sun_min_011d232c[5] = DAT_011d2329 ^ 0x59;
  s_sun_min_011d232c[6] = DAT_011d232a ^ 0x45;
  s_sun_min_011d232c[7] = DAT_011d232b ^ 0xd3;
  s_speed_reg_011d230a[0] = DAT_011d2300 ^ 0x87;
  s_speed_reg_011d230a[1] = DAT_011d2301 ^ 0xc9;
  s_speed_reg_011d230a[2] = DAT_011d2302 ^ 0x90;
  s_speed_reg_011d230a[3] = DAT_011d2303 ^ 0x7e;
  s_speed_reg_011d230a[4] = DAT_011d2304 ^ 0xb7;
  s_speed_reg_011d230a[5] = DAT_011d2305 ^ 0xb5;
  s_speed_reg_011d230a[6] = DAT_011d2306 ^ 0x42;
  s_speed_reg_011d230a[7] = DAT_011d2307 ^ 0xcb;
  s_speed_reg_011d230a[8] = DAT_011d2308 ^ 0xe5;
  s_speed_reg_011d230a[9] = DAT_011d2309 ^ 0x43;
  s_vol_off_011d22f8[0] = DAT_011d22f0 ^ 0x7c;
  s_vol_off_011d22f8[1] = DAT_011d22f1 ^ 0x58;
  s_vol_off_011d22f8[2] = DAT_011d22f2 ^ 0x92;
  s_vol_off_011d22f8[3] = DAT_011d22f3 ^ 0x5a;
  s_vol_off_011d22f8[4] = DAT_011d22f4 ^ 0xfb;
  s_vol_off_011d22f8[5] = DAT_011d22f5 ^ 0xd7;
  s_vol_off_011d22f8[6] = DAT_011d22f6 ^ 0x48;
  s_vol_off_011d22f8[7] = DAT_011d22f7 ^ 0x93;
  s_sun_max_011d2388[0] = DAT_011d2380 ^ 0xc1;
  s_sun_max_011d2388[1] = DAT_011d2381 ^ 0x29;
  s_sun_max_011d2388[2] = DAT_011d2382 ^ 0xd1;
  s_sun_max_011d2388[3] = DAT_011d2383 ^ 0xbf;
  s_sun_max_011d2388[4] = DAT_011d2384 ^ 0xe8;
  s_sun_max_011d2388[5] = DAT_011d2385 ^ 0xed;
  s_sun_max_011d2388[6] = DAT_011d2386 ^ 0x61;
  s_sun_max_011d2388[7] = DAT_011d2387 ^ 0x3d;
  s_sun_mid_011d231c[0] = DAT_011d2314 ^ 0x7a;
  s_sun_mid_011d231c[1] = DAT_011d2315 ^ 0xc3;
  s_sun_mid_011d231c[2] = DAT_011d2316 ^ 0x9a;
  s_sun_mid_011d231c[3] = DAT_011d2317 ^ 0x4c;
  s_sun_mid_011d231c[4] = DAT_011d2318 ^ 0x9f;
  s_sun_mid_011d231c[5] = DAT_011d2319 ^ 0x99;
  s_sun_mid_011d231c[6] = DAT_011d231a ^ 0x4c;
  s_sun_mid_011d231c[7] = DAT_011d231b ^ 0x7d;
  s_vol_max_011d2362[0] = DAT_011d235a ^ 0x2e;
  s_vol_max_011d2362[1] = DAT_011d235b ^ 0x4b;
  s_vol_max_011d2362[2] = DAT_011d235c ^ 0x4e;
  s_vol_max_011d2362[3] = DAT_011d235d ^ 0x2b;
  s_vol_max_011d2362[4] = DAT_011d235e ^ 0x2b;
  s_vol_max_011d2362[5] = DAT_011d235f ^ 0xc2;
  s_vol_max_011d2362[6] = DAT_011d2360 ^ 0x2a;
  s_vol_max_011d2362[7] = DAT_011d2361 ^ 0x56;
  s_vol_mid_011d22e8[0] = DAT_011d22e0 ^ 0x1a;
  s_vol_mid_011d22e8[1] = DAT_011d22e1 ^ 0xc9;
  s_vol_mid_011d22e8[2] = ~DAT_011d22e2;
  s_vol_mid_011d22e8[3] = DAT_011d22e3 ^ 0xfd;
  s_vol_mid_011d22e8[4] = DAT_011d22e4 ^ 0x81;
  s_vol_mid_011d22e8[5] = DAT_011d22e5 ^ 0x1f;
  s_vol_mid_011d22e8[6] = DAT_011d22e6 ^ 0x96;
  s_vol_mid_011d22e8[7] = DAT_011d22e7 ^ 0x68;
  DAT_0122854c = 1;
                    /* WARNING: Could not recover jumptable at 0x0023da18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IVar1 = (*(code *)((&PTR_LAB_011d28d8)[*(long *)(param_1 + (long)_style) < 1] +
                    (int)-(uRam00000000011d28e8 ^ 0xb515959c)))();
  return IVar1;
}


