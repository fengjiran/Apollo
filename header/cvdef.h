//
// Created by Richard on 2018/11/22.
//

#ifndef APOLLO_CVDEF_H
#define APOLLO_CVDEF_H

#if !defined CV_DOXYGEN && !defined CV_IGNORE_DEBUG_BUILD_GUARD
#if (defined(_MSC_VER) && (defined(DEBUG) || defined(_DEBUG))) || \
    (defined(_GLIBCXX_DEBUG) || defined(_GLIBCXX_DEBUG_PEDANTIC))
    
#define CV__DEBUG_NS_BEGIN namespace debug_build_guard {
#define CV__DEBUG_NS_END }
namespace cv {namespace debug_build_guard{} using namespace debug_build_guard;}
#endif
#endif

#ifndef CV__DEBUG_NS_BEGIN
#define CV__DEBUG_NS_BEGIN
#define CV__DEBUG_NS_END
#endif

#ifdef __OPENCV_BUILD
#include "cvconfig.h"
#endif

#ifndef __CV_EXPAND
#define __CV_EXPAND(x) x
#endif

#ifndef __CV_CAT
#define __CV_CAT__(x, y) x ## y
#define __CV_CAT_(x, y) __CV_CAT__(x, y)
#define __CV_CAT(x, y) __CV_CAT_(x, y)
#endif

#define __CV_VA_NUM_ARGS_HELPER(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, N, ...) N
#define __CV_VA_NUM_ARGS(...) __CV_EXPAND(__CV_VA_NUM_ARGS_HELPER(__VA_ARGS__, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0))


#if defined __GNUC__
#define CV_Func __func__
#elif defined _MSC_VER
#define CV_Func __FUNCTION__
#else
#define CV_Func ""
#endif

//////////////// static assert /////////////////
#define CVAUX_CONCAT_EXP(a, b) a##b
#define CVAUX_CONCAT(a, b) CVAUX_CONCAT_EXP(a,b)

#if defined(__clang__)

#  ifndef __has_extension
#    define __has_extension __has_feature /* compatibility, for older versions of clang */
#  endif

#  if __has_extension(cxx_static_assert)
#    define CV_StaticAssert(condition, reason)    static_assert((condition), reason " " #condition)
#  elif __has_extension(c_static_assert)
#    define CV_StaticAssert(condition, reason)    _Static_assert((condition), reason " " #condition)
#  endif

#elif defined(__GNUC__)
#  if (defined(__GXX_EXPERIMENTAL_CXX0X__) || __cplusplus >= 201103L)
#    define CV_StaticAssert(condition, reason)    static_assert((condition), reason " " #condition)
#  endif
#elif defined(_MSC_VER)
#  if _MSC_VER >= 1600 /* MSVC 10 */
#    define CV_StaticAssert(condition, reason)    static_assert((condition), reason " " #condition)
#  endif
#endif
#ifndef CV_StaticAssert
#  if !defined(__clang__) && defined(__GNUC__) && (__GNUC__*100 + __GNUC_MINOR__ > 302)
#    define CV_StaticAssert(condition, reason) ({ extern int __attribute__((error("CV_StaticAssert: " reason " " #condition))) CV_StaticAssert(); ((condition) ? 0 : CV_StaticAssert()); })
#  else
     template <bool x> struct CV_StaticAssert_failed;
     template <> struct CV_StaticAssert_failed<true> { enum { val = 1 }; };
     template<int x> struct CV_StaticAssert_test {};
#    define CV_StaticAssert(condition, reason)\
       typedef cv::CV_StaticAssert_test< sizeof(cv::CV_StaticAssert_failed< static_cast<bool>(condition) >) > CVAUX_CONCAT(CV_StaticAssert_failed_at_, __LINE__)
#  endif

#endif

// Suppress warning "-Wdeprecated-declarations" / C4996
#if defined(_MSC_VER)
#define CV_DO_PRAGMA(x) __pragma(x)
#elif defined(__GNUC__)
#define CV_DO_PRAGMA(x) _Pragma (#x)
#else
#define CV_DO_PRAGMA(x)
#endif

#ifdef _MSC_VER
#define CV_SUPPRESS_DEPRECATED_START \
    CV_DO_PRAGMA(warning(push)) \
    CV_DO_PRAGMA(warning(disable: 4996))
#define CV_SUPPRESS_DEPRECATED_END CV_DO_PRAGMA(warning(pop))
#elif defined (__clang__) || ((__GNUC__)  && (__GNUC__*100 + __GNUC_MINOR__ > 405))
#define CV_SUPPRESS_DEPRECATED_START \
    CV_DO_PRAGMA(GCC diagnostic push) \
    CV_DO_PRAGMA(GCC diagnostic ignored "-Wdeprecated-declarations")
#define CV_SUPPRESS_DEPRECATED_END CV_DO_PRAGMA(GCC diagnostic pop)
#else
#define CV_SUPPRESS_DEPRECATED_START
#define CV_SUPPRESS_DEPRECATED_END
#endif

#define CV_UNUSED(name) (void)name

// undef problematic defines sometimes defined by system headers (windows.h in particular)
#undef small
#undef min
#undef max
#undef abs
#undef Complex

#include <limits.h>
#include "interface.h"

#if defined __ICL
#  define CV_ICC   __ICL
#elif defined __ICC
#  define CV_ICC   __ICC
#elif defined __ECL
#  define CV_ICC   __ECL
#elif defined __ECC
#  define CV_ICC   __ECC
#elif defined __INTEL_COMPILER
#  define CV_ICC   __INTEL_COMPILER
#endif

#ifndef CV_INLINE
#  if defined __cplusplus
#    define CV_INLINE static inline
#  elif defined _MSC_VER
#    define CV_INLINE __inline
#  else
#    define CV_INLINE static
#  endif
#endif

#if defined CV_DISABLE_OPTIMIZATION || (defined CV_ICC && !defined CV_ENABLE_UNROLLED)
#  define CV_ENABLE_UNROLLED 0
#else
#  define CV_ENABLE_UNROLLED 1
#endif


#ifdef __GNUC__
#  define CV_DECL_ALIGNED(x) __attribute__ ((aligned (x)))
#elif defined _MSC_VER
#  define CV_DECL_ALIGNED(x) __declspec(align(x))
#else
#  define CV_DECL_ALIGNED(x)
#endif

/* CPU features and intrinsics support */
#define CV_CPU_NONE             0
#define CV_CPU_MMX              1
#define CV_CPU_SSE              2
#define CV_CPU_SSE2             3
#define CV_CPU_SSE3             4
#define CV_CPU_SSSE3            5
#define CV_CPU_SSE4_1           6
#define CV_CPU_SSE4_2           7
#define CV_CPU_POPCNT           8
#define CV_CPU_FP16             9
#define CV_CPU_AVX              10
#define CV_CPU_AVX2             11
#define CV_CPU_FMA3             12

#define CV_CPU_AVX_512F         13
#define CV_CPU_AVX_512BW        14
#define CV_CPU_AVX_512CD        15
#define CV_CPU_AVX_512DQ        16
#define CV_CPU_AVX_512ER        17
#define CV_CPU_AVX_512IFMA512   18 // deprecated
#define CV_CPU_AVX_512IFMA      18
#define CV_CPU_AVX_512PF        19
#define CV_CPU_AVX_512VBMI      20
#define CV_CPU_AVX_512VL        21

#define CV_CPU_NEON             100

#define CV_CPU_VSX              200
#define CV_CPU_VSX3             201


// CPU features groups
#define CV_CPU_AVX512_SKX       256

// when adding to this list remember to update the following enum
#define CV_HARDWARE_MAX_FEATURE 512

/** @brief Available CPU features.
*/

#endif //APOLLO_CVDEF_H
