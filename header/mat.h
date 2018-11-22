//
// Created by richard on 2018/11/22.
//

#ifndef APOLLO_MAT_H
#define APOLLO_MAT_H

namespace cv {
    class Mat {
    public:
        Mat();  // default constructor

        // rows: number of rows in a 2D array
        // cols: number of columns in a 2D array
        // type: array type
        Mat(int rows, int cols, int type);
    };
}

#endif //APOLLO_MAT_H
