


#ifndef _ALLOC_MALLOC_H
#define _ALLOC_MALLOC_H

#include <stddef.h>

// DATA STRUCTURES

typedef struct heap_info_s
{

   int     type;     // 0 = HEADER, 1 = ALLOCATED, 2 = FREE
   void   *address;
   size_t  size;

} heap_info_t;

extern void __LIB__ *_falloc_(void *p,size_t size);
extern void __LIB__ __CALLEE__ *_falloc__callee(void *p,size_t size);
#define _falloc_(a,b) _falloc__callee(a,b)


extern void __LIB__ *heap_alloc(void *heap,size_t size);
extern void __LIB__ __CALLEE__ *heap_alloc_callee(void *heap,size_t size);
#define heap_alloc(a,b) heap_alloc_callee(a,b)


extern void __LIB__ *heap_alloc_aligned(void *heap,size_t alignment,size_t size);
extern void __LIB__ __CALLEE__ *heap_alloc_aligned_callee(void *heap,size_t alignment,size_t size);
#define heap_alloc_aligned(a,b,c) heap_alloc_aligned_callee(a,b,c)


extern void __LIB__ *heap_alloc_fixed(void *heap,void *p,size_t size);
extern void __LIB__ __CALLEE__ *heap_alloc_fixed_callee(void *heap,void *p,size_t size);
#define heap_alloc_fixed(a,b,c) heap_alloc_fixed_callee(a,b,c)


extern void __LIB__ *heap_calloc(void *heap,size_t nmemb,size_t size);
extern void __LIB__ __CALLEE__ *heap_calloc_callee(void *heap,size_t nmemb,size_t size);
#define heap_calloc(a,b,c) heap_calloc_callee(a,b,c)


extern void __LIB__ __FASTCALL__ *heap_destroy(void *heap);


extern void __LIB__ heap_free(void *heap,void *p);
extern void __LIB__ __CALLEE__ heap_free_callee(void *heap,void *p);
#define heap_free(a,b) heap_free_callee(a,b)


extern void __LIB__ heap_info(void *heap,void *callback);
extern void __LIB__ __CALLEE__ heap_info_callee(void *heap,void *callback);
#define heap_info(a,b) heap_info_callee(a,b)


extern void __LIB__ *heap_init(void *heap,size_t size);
extern void __LIB__ __CALLEE__ *heap_init_callee(void *heap,size_t size);
#define heap_init(a,b) heap_init_callee(a,b)


extern void __LIB__ *heap_realloc(void *heap,void *p,size_t size);
extern void __LIB__ __CALLEE__ *heap_realloc_callee(void *heap,void *p,size_t size);
#define heap_realloc(a,b,c) heap_realloc_callee(a,b,c)


extern void __LIB__ *memalign(size_t alignment,size_t size);
extern void __LIB__ __CALLEE__ *memalign_callee(size_t alignment,size_t size);
#define memalign(a,b) memalign_callee(a,b)


extern int __LIB__ posix_memalign(void **memptr,size_t alignment,size_t size);
extern int __LIB__ __CALLEE__ posix_memalign_callee(void **memptr,size_t alignment,size_t size);
#define posix_memalign(a,b,c) posix_memalign_callee(a,b,c)



extern void __LIB__ *_falloc__unlocked(void *p,size_t size);
extern void __LIB__ __CALLEE__ *_falloc__unlocked_callee(void *p,size_t size);
#define _falloc__unlocked(a,b) _falloc__unlocked_callee(a,b)


extern void __LIB__ *heap_alloc_unlocked(void *heap,size_t size);
extern void __LIB__ __CALLEE__ *heap_alloc_unlocked_callee(void *heap,size_t size);
#define heap_alloc_unlocked(a,b) heap_alloc_unlocked_callee(a,b)


extern void __LIB__ *heap_alloc_aligned_unlocked(void *heap,size_t alignment,size_t size);
extern void __LIB__ __CALLEE__ *heap_alloc_aligned_unlocked_callee(void *heap,size_t alignment,size_t size);
#define heap_alloc_aligned_unlocked(a,b,c) heap_alloc_aligned_unlocked_callee(a,b,c)


extern void __LIB__ *heap_alloc_fixed_unlocked(void *heap,void *p,size_t size);
extern void __LIB__ __CALLEE__ *heap_alloc_fixed_unlocked_callee(void *heap,void *p,size_t size);
#define heap_alloc_fixed_unlocked(a,b,c) heap_alloc_fixed_unlocked_callee(a,b,c)


extern void __LIB__ *heap_calloc_unlocked(void *heap,size_t nmemb,size_t size);
extern void __LIB__ __CALLEE__ *heap_calloc_unlocked_callee(void *heap,size_t nmemb,size_t size);
#define heap_calloc_unlocked(a,b,c) heap_calloc_unlocked_callee(a,b,c)


extern void __LIB__ heap_free_unlocked(void *heap,void *p);
extern void __LIB__ __CALLEE__ heap_free_unlocked_callee(void *heap,void *p);
#define heap_free_unlocked(a,b) heap_free_unlocked_callee(a,b)


extern void __LIB__ heap_info_unlocked(void *heap,void *callback);
extern void __LIB__ __CALLEE__ heap_info_unlocked_callee(void *heap,void *callback);
#define heap_info_unlocked(a,b) heap_info_unlocked_callee(a,b)


extern void __LIB__ *heap_realloc_unlocked(void *heap,void *p,size_t size);
extern void __LIB__ __CALLEE__ *heap_realloc_unlocked_callee(void *heap,void *p,size_t size);
#define heap_realloc_unlocked(a,b,c) heap_realloc_unlocked_callee(a,b,c)


extern void __LIB__ *memalign_unlocked(size_t alignment,size_t size);
extern void __LIB__ __CALLEE__ *memalign_unlocked_callee(size_t alignment,size_t size);
#define memalign_unlocked(a,b) memalign_unlocked_callee(a,b)


extern int __LIB__ posix_memalign_unlocked(void **memptr,size_t alignment,size_t size);
extern int __LIB__ __CALLEE__ posix_memalign_unlocked_callee(void **memptr,size_t alignment,size_t size);
#define posix_memalign_unlocked(a,b,c) posix_memalign_unlocked_callee(a,b,c)



#ifndef _STDLIB_H

extern void __LIB__ *aligned_alloc(size_t alignment,size_t size);
extern void __LIB__ __CALLEE__ *aligned_alloc_callee(size_t alignment,size_t size);
#define aligned_alloc(a,b) aligned_alloc_callee(a,b)


extern void __LIB__ *calloc(size_t nmemb,size_t size);
extern void __LIB__ __CALLEE__ *calloc_callee(size_t nmemb,size_t size);
#define calloc(a,b) calloc_callee(a,b)


extern void __LIB__ __FASTCALL__ free(void *p);


extern void __LIB__ __FASTCALL__ *malloc(size_t size);


extern void __LIB__ *realloc(void *p,size_t size);
extern void __LIB__ __CALLEE__ *realloc_callee(void *p,size_t size);
#define realloc(a,b) realloc_callee(a,b)



extern void __LIB__ *aligned_alloc_unlocked(size_t alignment,size_t size);
extern void __LIB__ __CALLEE__ *aligned_alloc_unlocked_callee(size_t alignment,size_t size);
#define aligned_alloc_unlocked(a,b) aligned_alloc_unlocked_callee(a,b)


extern void __LIB__ *calloc_unlocked(size_t nmemb,size_t size);
extern void __LIB__ __CALLEE__ *calloc_unlocked_callee(size_t nmemb,size_t size);
#define calloc_unlocked(a,b) calloc_unlocked_callee(a,b)


extern void __LIB__ __FASTCALL__ free_unlocked(void *p);


extern void __LIB__ __FASTCALL__ *malloc_unlocked(size_t size);


extern void __LIB__ *realloc_unlocked(void *p,size_t size);
extern void __LIB__ __CALLEE__ *realloc_unlocked_callee(void *p,size_t size);
#define realloc_unlocked(a,b) realloc_unlocked_callee(a,b)



#endif

#endif