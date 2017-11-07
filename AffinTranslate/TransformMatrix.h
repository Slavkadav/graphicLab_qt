//
// Created by dev on 07.11.17.
//

#ifndef GRAPHIC_LAB_2_TRANSFORMMATRIX_H
#define GRAPHIC_LAB_2_TRANSFORMMATRIX_H


class TransformMatrix {
    double matrix[3][3] = {{1, 0, 0},
                           {0, 1, 0},
                           {0, 0, 1}};


public:
    static TransformMatrix *getRotateMatrix(double phi);

    static TransformMatrix *getTranslationMatrix(double x, double y);

    static TransformMatrix *getReflectionMatrix();

    static TransformMatrix *getDilatationMatrix(double x, double y);


    friend const TransformMatrix &operator*(const TransformMatrix &left, const TransformMatrix &right);
};


#endif //GRAPHIC_LAB_2_TRANSFORMMATRIX_H
