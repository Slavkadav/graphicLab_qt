//
// Created by dev on 28.10.17.
//

#ifndef GRAPHIC_LAB_2_AFFINTRANSLATE_H
#define GRAPHIC_LAB_2_AFFINTRANSLATE_H


#include <QtGui/QMatrix>

class AffineTranslate {
public:
    static QTransform expandMatrix(double x, double y);

    static QTransform rotateMatrix(double phi);

    static QTransform moveMatrix(double x, double y);

};


#endif //GRAPHIC_LAB_2_AFFINTRANSLATE_H
