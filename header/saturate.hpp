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

    template<>
    inline
    uchar saturate_cast<uchar>(ushort v) { return (uchar) std::min((unsigned) v, (unsigned) UCHAR_MAX); }

    template<>
    inline
    uchar saturate_cast<uchar>(int v) { return (uchar) ((unsigned) v <= UCHAR_MAX ? v : v > 0 ? UCHAR_MAX : 0); }

    template<>
    inline
    uchar saturate_cast<uchar>(short v) { return saturate_cast<uchar>((int) v); }

    template<>
    inline
    uchar saturate_cast<uchar>(unsigned v) { return (uchar) std::min(v, (unsigned) UCHAR_MAX); }

    template<>
    inline
    uchar saturate_cast<uchar>(float v) {
        int iv = cvRound(v);
        return saturate_cast<uchar>(iv);
    }

    template<>
    inline
    uchar saturate_cast<uchar>(double v) {
        int iv = cvRound(v);
        return saturate_cast<uchar>(iv);
    }

    template<>
    inline
    uchar saturate_cast<uchar>(int64 v) {
        return (uchar) ((uint64) v <= (uint64) UCHAR_MAX ? v : v > 0 ? UCHAR_MAX : 0);
    }

    template<>
    inline
    uchar saturate_cast<uchar>(uint64 v) {
        return (uchar) std::min(v, (uint64) UCHAR_MAX);
    }


}

#endif //APOLLO_SATURATE_HPP
