//
// Created by richard on 2018/11/22.
//

#ifndef APOLLO_TYPES_H
#define APOLLO_TYPES_H

namespace cv {
    template<typename _Tp>
    class Size_ {
        typedef _Tp value_type;

        Size_();
        Size_(_Tp _width, _Tp _height);
        Size_(const Size_& sz);

    };
}

#endif //APOLLO_TYPES_H
