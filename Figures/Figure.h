//
// Created by dev on 28.10.17.
//

#ifndef GRAPHIC_LAB_2_FIGURE_H
#define GRAPHIC_LAB_2_FIGURE_H


#include <QtGui/QMatrix>
#include <QtGui/QPainter>

class Figure {
    virtual void draw(QPainter *painter, QTransform position)=0;
};


#endif //GRAPHIC_LAB_2_FIGURE_H
