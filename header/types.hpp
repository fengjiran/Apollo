//
// Created by richard on 2018/11/22.
//

#ifndef APOLLO_TYPES_H
#define APOLLO_TYPES_H

namespace apollo {

    template<typename _Tp>
    class Point_ {
    public:
        typedef _Tp value_type;

        Point_();

        Point_(_Tp _x, _Tp _y);

        Point_(const Point_ &pt);

        Point_(Point_ &&pt);
    };


    template<typename _Tp>
    class Size_ {
    public:
        typedef _Tp value_type;

        Size_();

        Size_(_Tp _width, _Tp _height);

        Size_(const Size_ &sz);

        Size_(Size_ &&sz);


    };
}

#endif //APOLLO_TYPES_H
