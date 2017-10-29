//
// Created by dev on 28.10.17.
//

#include <QtGui/QtGui>
#include "AffineTranslate.h"

QTransform AffineTranslate::expandMatrix(double x, double y) {
    return QTransform(
            x, 0,
            0, y,
            0, 0
    );
}

QTransform AffineTranslate::rotateMatrix(double phi) {
    phi = qDegreesToRadians(phi);
    QTransform transform;

    transform.setMatrix(
            cos(phi), sin(phi), 0,
            -sin(phi), cos(phi), 0,
            0, 0, 1
    );

    return transform;
}

QTransform AffineTranslate::moveMatrix(double x, double y) {
    return QTransform(
            1, 0,
            0, 1,
            x, y
    );
}


