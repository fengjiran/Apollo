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


#endif //APOLLO_CVDEF_H
