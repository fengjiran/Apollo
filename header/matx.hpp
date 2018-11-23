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

    };
}


#endif //APOLLO_MATX_HPP
