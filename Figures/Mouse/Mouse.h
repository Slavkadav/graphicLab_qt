//
// Created by dev on 28.10.17.
//

#ifndef GRAPHIC_LAB_2_CHEESE_H
#define GRAPHIC_LAB_2_CHEESE_H


#include <QtGui/QPainter>
#include "../Figure.h"

class Mouse : public Figure {
public:
    explicit Mouse();

    void draw(QPainter *painter, QTransform position) override;

private:
    int width = 10;

    void drawNose(QPainter *painter);

    void drawBody(QPainter *painter);

    void drawTail(QPainter *painter);
};


#endif //GRAPHIC_LAB_2_CHEESE_H
