//
// Created by richard on 2018/11/23.
//


#ifndef APOLLO_MATX_HPP
#define APOLLO_MATX_HPP

#include "cvdef.h"

#include <initializer_list>

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
        Matx(_Tp v0, _Tp v1, _Tp v2); //!< 1x3 or 3x1 matrix
        Matx(_Tp v0, _Tp v1, _Tp v2, _Tp v3); //!< 1x4, 2x2 or 4x1 matrix
        Matx(_Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4); //!< 1x5 or 5x1 matrix
        Matx(_Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4, _Tp v5); //!< 1x6, 2x3, 3x2 or 6x1 matrix
        Matx(_Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4, _Tp v5, _Tp v6); //!< 1x7 or 7x1 matrix
        Matx(_Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4, _Tp v5, _Tp v6, _Tp v7); //!< 1x8, 2x4, 4x2 or 8x1 matrix
        Matx(_Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4, _Tp v5, _Tp v6, _Tp v7, _Tp v8); //!< 1x9, 3x3 or 9x1 matrix
        Matx(_Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4, _Tp v5, _Tp v6, _Tp v7, _Tp v8,
             _Tp v9); //!< 1x10, 2x5 or 5x2 or 10x1 matrix
        Matx(_Tp v0, _Tp v1, _Tp v2, _Tp v3,
             _Tp v4, _Tp v5, _Tp v6, _Tp v7,
             _Tp v8, _Tp v9, _Tp v10, _Tp v11); //!< 1x12, 2x6, 3x4, 4x3, 6x2 or 12x1 matrix
        Matx(_Tp v0, _Tp v1, _Tp v2, _Tp v3,
             _Tp v4, _Tp v5, _Tp v6, _Tp v7,
             _Tp v8, _Tp v9, _Tp v10, _Tp v11,
             _Tp v12, _Tp v13); //!< 1x14, 2x7, 7x2 or 14x1 matrix
        Matx(_Tp v0, _Tp v1, _Tp v2, _Tp v3,
             _Tp v4, _Tp v5, _Tp v6, _Tp v7,
             _Tp v8, _Tp v9, _Tp v10, _Tp v11,
             _Tp v12, _Tp v13, _Tp v14, _Tp v15); //!< 1x16, 4x4 or 16x1 matrix
        explicit Matx(const _Tp *vals); // initialize from a plain array

        Matx(std::initializer_list<_Tp>);  // initialize from an initializer list

        static Matx all(_Tp alpha);

        static Matx zeors();

        static Matx ones();

        static Matx eye();

        static Matx diag(const diag_type &d);

        static Matx randu(_Tp a, _Tp b);

        static Matx randn(_Tp a, _Tp b);


        // element access
        const _Tp &operator()(int i, int j) const;

        _Tp &operator()(int i, int j);

        // 1D element access
        const _Tp &operator()(int i) const;

        _Tp &operator()(int i);


        _Tp val[m * n]; // matrix elements


    };

    /////////////////////// Vec (used as element of multi-channel images /////////////////////

    /** @brief Template class for short numerical vectors, a partial case of Matx

    This template class represents short numerical vectors (of 1, 2, 3, 4 ... elements) on which you
    can perform basic arithmetical operations, access individual elements using [] operator etc. The
    vectors are allocated on stack, as opposite to std::valarray, std::vector, cv::Mat etc., which
    elements are dynamically allocated in the heap.

    The template takes 2 parameters:
    @tparam _Tp element type
    @tparam cn the number of elements

    In addition to the universal notation like Vec<float, 3>, you can use shorter aliases
    for the most popular specialized variants of Vec, e.g. Vec3f ~ Vec<float, 3>.

    It is possible to convert Vec\<T,2\> to/from Point_, Vec\<T,3\> to/from Point3_ , and Vec\<T,4\>
    to CvScalar or Scalar_. Use operator[] to access the elements of Vec.

    All the expected vector operations are also implemented:
    -   v1 = v2 + v3
    -   v1 = v2 - v3
    -   v1 = v2 \* scale
    -   v1 = scale \* v2
    -   v1 = -v2
    -   v1 += v2 and other augmenting operations
    -   v1 == v2, v1 != v2
    -   norm(v1) (euclidean norm)
    The Vec class is commonly used to describe pixel types of multi-channel arrays. See Mat for details.
    */
    template<typename _Tp, int cn>
    class Vec : public Matx<_Tp, cn, 1> {
    public:
//        typedef _Tp value_type;
        using value_type = _Tp;
        enum {
            channels = cn,
            dummy_enum_finalizer = 0
        };

        //! default constructor
        Vec();

        Vec(_Tp v0); //!< 1-element vector constructor
        Vec(_Tp v0, _Tp v1); //!< 2-element vector constructor
        Vec(_Tp v0, _Tp v1, _Tp v2); //!< 3-element vector constructor
        Vec(_Tp v0, _Tp v1, _Tp v2, _Tp v3); //!< 4-element vector constructor
        Vec(_Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4); //!< 5-element vector constructor
        Vec(_Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4, _Tp v5); //!< 6-element vector constructor
        Vec(_Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4, _Tp v5, _Tp v6); //!< 7-element vector constructor
        Vec(_Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4, _Tp v5, _Tp v6, _Tp v7); //!< 8-element vector constructor
        Vec(_Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4, _Tp v5, _Tp v6, _Tp v7, _Tp v8); //!< 9-element vector constructor
        Vec(_Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4, _Tp v5, _Tp v6, _Tp v7, _Tp v8,
            _Tp v9); //!< 10-element vector constructor
        Vec(_Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4, _Tp v5, _Tp v6, _Tp v7, _Tp v8, _Tp v9, _Tp v10, _Tp v11, _Tp v12,
            _Tp v13); //!< 14-element vector constructor
        explicit Vec(const _Tp *values);

        Vec(std::initializer_list<_Tp>);

        Vec(const Vec<_Tp, cn> &v);

        static Vec all(_Tp alpha);

        //! per-element multiplication
        Vec mul(const Vec<_Tp, cn> &v) const;

        //! conjugation (makes sense for complex numbers and quaternions)
        Vec conj() const;

        /*!
        cross product of the two 3D vectors.

        For other dimensionalities the exception is raised
        */
        Vec cross(const Vec &v) const;

        //! conversion to another data type
        template<typename T2>
        operator Vec<T2, cn>() const;

        /*! element access */
        const _Tp &operator[](int i) const;

        _Tp &operator[](int i);

        const _Tp &operator()(int i) const;

        _Tp &operator()(int i);



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

    template<typename _Tp, int m, int n>
    inline
    Matx<_Tp, m, n>::Matx(_Tp v0, _Tp v1, _Tp v2) {
        CV_StaticAssert(channels >= 3, "Matx should have at least 3 elements.");
        val[0] = v0;
        val[1] = v1;
        val[2] = v2;
        for (int i = 3; i < channels; i++) val[i] = _Tp(0);
    }

    template<typename _Tp, int m, int n>
    inline
    Matx<_Tp, m, n>::Matx(_Tp v0, _Tp v1, _Tp v2, _Tp v3) {
        CV_StaticAssert(channels >= 4, "Matx should have at least 4 elements.");
        val[0] = v0;
        val[1] = v1;
        val[2] = v2;
        val[3] = v3;
        for (int i = 4; i < channels; i++) val[i] = _Tp(0);
    }

    template<typename _Tp, int m, int n>
    inline
    Matx<_Tp, m, n>::Matx(_Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4) {
        CV_StaticAssert(channels >= 5, "Matx should have at least 5 elements.");
        val[0] = v0;
        val[1] = v1;
        val[2] = v2;
        val[3] = v3;
        val[4] = v4;
        for (int i = 5; i < channels; i++) val[i] = _Tp(0);
    }

    template<typename _Tp, int m, int n>
    inline
    Matx<_Tp, m, n>::Matx(_Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4, _Tp v5) {
        CV_StaticAssert(channels >= 6, "Matx should have at least 6 elements.");
        val[0] = v0;
        val[1] = v1;
        val[2] = v2;
        val[3] = v3;
        val[4] = v4;
        val[5] = v5;
        for (int i = 6; i < channels; i++) val[i] = _Tp(0);
    }

    template<typename _Tp, int m, int n>
    inline
    Matx<_Tp, m, n>::Matx(_Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4, _Tp v5, _Tp v6) {
        CV_StaticAssert(channels >= 7, "Matx should have at least 7 elements.");
        val[0] = v0;
        val[1] = v1;
        val[2] = v2;
        val[3] = v3;
        val[4] = v4;
        val[5] = v5;
        val[6] = v6;
        for (int i = 7; i < channels; i++) val[i] = _Tp(0);
    }

    template<typename _Tp, int m, int n>
    inline
    Matx<_Tp, m, n>::Matx(_Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4, _Tp v5, _Tp v6, _Tp v7) {
        CV_StaticAssert(channels >= 8, "Matx should have at least 8 elements.");
        val[0] = v0;
        val[1] = v1;
        val[2] = v2;
        val[3] = v3;
        val[4] = v4;
        val[5] = v5;
        val[6] = v6;
        val[7] = v7;
        for (int i = 8; i < channels; i++) val[i] = _Tp(0);
    }

    template<typename _Tp, int m, int n>
    inline
    Matx<_Tp, m, n>::Matx(_Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4, _Tp v5, _Tp v6, _Tp v7, _Tp v8) {
        CV_StaticAssert(channels >= 9, "Matx should have at least 9 elements.");
        val[0] = v0;
        val[1] = v1;
        val[2] = v2;
        val[3] = v3;
        val[4] = v4;
        val[5] = v5;
        val[6] = v6;
        val[7] = v7;
        val[8] = v8;
        for (int i = 9; i < channels; i++) val[i] = _Tp(0);
    }

    template<typename _Tp, int m, int n>
    inline
    Matx<_Tp, m, n>::Matx(_Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4, _Tp v5, _Tp v6, _Tp v7, _Tp v8, _Tp v9) {
        CV_StaticAssert(channels >= 10, "Matx should have at least 10 elements.");
        val[0] = v0;
        val[1] = v1;
        val[2] = v2;
        val[3] = v3;
        val[4] = v4;
        val[5] = v5;
        val[6] = v6;
        val[7] = v7;
        val[8] = v8;
        val[9] = v9;
        for (int i = 10; i < channels; i++) val[i] = _Tp(0);
    }


    template<typename _Tp, int m, int n>
    inline
    Matx<_Tp, m, n>::Matx(_Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4, _Tp v5, _Tp v6, _Tp v7, _Tp v8, _Tp v9, _Tp v10,
                          _Tp v11) {
        CV_StaticAssert(channels >= 12, "Matx should have at least 12 elements.");
        val[0] = v0;
        val[1] = v1;
        val[2] = v2;
        val[3] = v3;
        val[4] = v4;
        val[5] = v5;
        val[6] = v6;
        val[7] = v7;
        val[8] = v8;
        val[9] = v9;
        val[10] = v10;
        val[11] = v11;
        for (int i = 12; i < channels; i++) val[i] = _Tp(0);
    }

    template<typename _Tp, int m, int n>
    inline
    Matx<_Tp, m, n>::Matx(_Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4, _Tp v5, _Tp v6, _Tp v7, _Tp v8, _Tp v9, _Tp v10,
                          _Tp v11, _Tp v12, _Tp v13) {
        CV_StaticAssert(channels >= 14, "Matx should have at least 14 elements.");
        val[0] = v0;
        val[1] = v1;
        val[2] = v2;
        val[3] = v3;
        val[4] = v4;
        val[5] = v5;
        val[6] = v6;
        val[7] = v7;
        val[8] = v8;
        val[9] = v9;
        val[10] = v10;
        val[11] = v11;
        val[12] = v12;
        val[13] = v13;
        for (int i = 14; i < channels; i++) val[i] = _Tp(0);
    }


    template<typename _Tp, int m, int n>
    inline
    Matx<_Tp, m, n>::Matx(_Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4, _Tp v5, _Tp v6, _Tp v7, _Tp v8, _Tp v9, _Tp v10,
                          _Tp v11, _Tp v12, _Tp v13, _Tp v14, _Tp v15) {
        CV_StaticAssert(channels >= 16, "Matx should have at least 16 elements.");
        val[0] = v0;
        val[1] = v1;
        val[2] = v2;
        val[3] = v3;
        val[4] = v4;
        val[5] = v5;
        val[6] = v6;
        val[7] = v7;
        val[8] = v8;
        val[9] = v9;
        val[10] = v10;
        val[11] = v11;
        val[12] = v12;
        val[13] = v13;
        val[14] = v14;
        val[15] = v15;
        for (int i = 16; i < channels; i++) val[i] = _Tp(0);
    }

    template<typename _Tp, int m, int n>
    inline
    Matx<_Tp, m, n>::Matx(const _Tp *vals) {
        for (int i = 0; i < channels; i++)
            val[i] = vals[i];

    }

    template<typename _Tp, int m, int n>
    inline
    Matx<_Tp, m, n>::Matx(std::initializer_list<_Tp> list) {
        int i = 0;
        for (const auto &elem:list)
            val[i++] = elem;

    }

    template<typename _Tp, int m, int n>
    inline
    Matx<_Tp, m, n> Matx<_Tp, m, n>::all(_Tp alpha) {
        Matx<_Tp, m, n> M;
        for (int i = 0; i < m * n; i++)
            M.val[i] = alpha;
        return M;
    }

    template<typename _Tp, int m, int n>
    inline
    Matx<_Tp, m, n> Matx<_Tp, m, n>::zeors() {
        return all(0);
    }

    template<typename _Tp, int m, int n>
    inline
    Matx<_Tp, m, n> Matx<_Tp, m, n>::ones() {
        return all(1);
    }

    template<typename _Tp, int m, int n>
    inline
    Matx<_Tp, m, n> Matx<_Tp, m, n>::eye() {

        Matx<_Tp, m, n> M;
        for (int i = 0; i < shortdim; i++)
            M(i, i) = 1;
        return M;
    }

    template<typename _Tp, int m, int n>
    inline
    Matx<_Tp, m, n> Matx<_Tp, m, n>::diag(const typename Matx<_Tp, m, n>::diag_type &d) {
        Matx<_Tp, m, n> M;
        for (int i = 0; i < shortdim; i++)
            M(i, i) = d(i, 0);
        return M;
    }

    template<typename _Tp, int m, int n>
    inline
    const _Tp &Matx<_Tp, m, n>::operator()(int i, int j) const {
        return val[i * n + j];
    }

    template<typename _Tp, int m, int n>
    inline
    _Tp &Matx<_Tp, m, n>::operator()(int i, int j) {
        return val[i * n + j];
    }

    template<typename _Tp, int m, int n>
    inline
    const _Tp &Matx<_Tp, m, n>::operator()(int i) const {
        return val[i];
    }

    template<typename _Tp, int m, int n>
    inline
    _Tp &Matx<_Tp, m, n>::operator()(int i) {
        return val[i];
    }


}


#endif //APOLLO_MATX_HPP
