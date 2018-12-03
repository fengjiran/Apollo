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

    template<typename _Tp>
    static inline
    _Tp saturate_cast(ushort v) { return _Tp(v); }

    template<typename _Tp>
    static inline
    _Tp saturate_cast(short v) { return _Tp(v); }

    template<typename _Tp>
    static inline
    _Tp saturate_cast(unsigned v) { return _Tp(v); }

    template<typename _Tp>
    static inline
    _Tp saturate_cast(int v) { return _Tp(v); }

    template<typename _Tp>
    static inline
    _Tp saturate_cast(float v) { return _Tp(v); }

    template<typename _Tp>
    static inline
    _Tp saturate_cast(double v) { return _Tp(v); }

    template<typename _Tp>
    static inline
    _Tp saturate_cast(int64 v) { return _Tp(v); }

    template<typename _Tp>
    static inline
    _Tp saturate_cast(uint64 v) { return _Tp(v); }

    template<>
    inline
    uchar saturate_cast<uchar>(schar v) { return (uchar) std::max((int) v, 0); }
}

#endif //APOLLO_SATURATE_HPP
