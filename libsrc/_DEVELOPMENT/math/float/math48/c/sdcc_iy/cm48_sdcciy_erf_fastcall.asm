
; float erf(float x) __z88dk_fastcall

SECTION code_fp_math48

PUBLIC cm48_sdcciy_erf_fastcall

EXTERN cm48_sdcciyp_dx2m48, am48_erf, cm48_sdcciyp_m482d

cm48_sdcciy_erf_fastcall:

   call cm48_sdcciyp_dx2m48
   
   call am48_erf
   
   jp cm48_sdcciyp_m482d