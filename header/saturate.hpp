//
// Created by GUO on 2018-12-03.
//

#ifndef APOLLO_SATURATE_HPP
#define APOLLO_SATURATE_HPP

#include "cvdef.h"
#include "fast_math.hpp"

namespace cv {
    template<typename _Tp>
    static inline
    _Tp saturate_cast(uchar v) { return _Tp(v); }

    template<typename _Tp>
    static inline
    _Tp saturate_cast(schar v) { return _Tp(v); }
}

#endif //APOLLO_SATURATE_HPP
