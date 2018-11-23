//
// Created by richard on 2018/11/23.
//


#ifndef APOLLO_MATX_HPP
#define APOLLO_MATX_HPP

#include "cvdef.h"

namespace apollo {
    template<typename _Tp, int m, int n>
    class Matx {
    public:
        enum {
            rows = m,
            cols = n,
            channels = rows * cols,
            shortdim = (m < n ? m : n)
        };
        typedef _Tp value_type;
        typedef Matx<_Tp, m, n> mat_type;
        typedef Matx<_Tp, shortdim, 1> diag_type;

        Matx();

        explicit Matx(_Tp v0); // 1x1 matrix
        Matx(_Tp v0, _Tp v1); // 1x2 matrix


        _Tp val[m * n]; // matrix elements


    };

    ////////////////////// Matx Implementation /////////////////////////
    template<typename _Tp, int m, int n>
    inline
    Matx<_Tp, m, n>::Matx() {
        for (int i = 0; i < channels; i++)
            val[i] = _Tp(0);
    }

    template<typename _Tp, int m, int n>
    inline
    Matx<_Tp, m, n>::Matx(_Tp v0) {
        val[0] = v0;
        for (int i = 1; i < channels; i++)
            val[i] = _Tp(0);

    }

    template<typename _Tp, int m, int n>
    inline
    Matx<_Tp, m, n>::Matx(_Tp v0, _Tp v1) {
        CV_StaticAssert(channels >= 2, "Matx should have at least 2 elements.");
        val[0] = v0;
        val[1] = v1;
        for (int i = 2; i < channels; i++)
            val[i] = _Tp(0);

    }


}


#endif //APOLLO_MATX_HPP
