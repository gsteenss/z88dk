
; float sinh(float x) __z88dk_fastcall

SECTION code_fp_math48

PUBLIC cm48_sdcciy_sinh

EXTERN cm48_sdcciyp_dx2m48, am48_sinh, cm48_sdcciyp_m482d

cm48_sdcciy_sinh:

   call cm48_sdcciyp_dx2m48
   
   call am48_sinh
   
   jp cm48_sdcciyp_m482d