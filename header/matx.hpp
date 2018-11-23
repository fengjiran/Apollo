//
// Created by richard on 2018/11/23.
//


#ifndef APOLLO_MATX_HPP
#define APOLLO_MATX_HPP

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

        Matx(_Tp v0);

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


}


#endif //APOLLO_MATX_HPP
