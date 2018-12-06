//
// Created by Richard on 2018/12/6.
//

#ifndef APOLLO_CVSTD_HPP
#define APOLLO_CVSTD_HPP

#include "cvdef.h"
#include <cstring>
#include <cctype>
#include <cstddef>

#include <string>

#include <algorithm>
#include <utility>
#include <cstdlib>
#include <cmath>

namespace apollo {
    static inline uchar abs(uchar a) { return a; }

    static inline ushort abs(ushort a) { return a; }

    static inline unsigned abs(unsigned a) { return a; }

    static inline uint64 abs(uint64 a) { return a; }

    using std::min;
    using std::max;
    using std::abs;
    using std::swap;
    using std::sqrt;
    using std::exp;
    using std::pow;
    using std::log;
}



#endif //APOLLO_CVSTD_HPP
