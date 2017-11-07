//
// Created by dev on 07.11.17.
//

#include <QtGui/QtGui>
#include "TransformMatrix.h"


TransformMatrix *TransformMatrix::getRotateMatrix(double angle) {
    double phi = qDegreesToRadians(angle);
    auto *matrix = new TransformMatrix();
    matrix->matrix[0][0] = cos(phi);
    matrix->matrix[0][1] = sin(phi);
    matrix->matrix[1][0] = -sin(phi);
    matrix->matrix[1][1] = cos(phi);
    return matrix;
}

TransformMatrix *TransformMatrix::getTranslationMatrix(double x, double y) {
    auto *matrix = new TransformMatrix();
    matrix->matrix[2][0] = x;
    matrix->matrix[2][1] = y;
    return matrix;
}

const TransformMatrix &operator*(const TransformMatrix &left, const TransformMatrix &right) {
    TransformMatrix matr;
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            for (int inner = 0; inner < 2; inner++) {
                matr.matrix[row][col] += left.matrix[row][inner] * right.matrix[inner][col];
            }
        }
    }

    return matr;
}

TransformMatrix *TransformMatrix::getReflectionMatrix() {
    auto *matrix = new TransformMatrix();
    matrix->matrix[1][1] = -1;
    return matrix;
}

TransformMatrix *TransformMatrix::getDilatationMatrix(double x, double y) {
    auto *matrix = new TransformMatrix();
    matrix->matrix[0][0] = x;
    matrix->matrix[1][1] = y;
    return matrix;
}

