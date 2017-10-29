//
// Created by dev on 29.10.17.
//

#ifndef GRAPHIC_LAB_2_CAT_H
#define GRAPHIC_LAB_2_CAT_H


#include "../Figure.h"

class Cat : public Figure {
public:
    void draw(QPainter *painter, QTransform position) override;

private:
    void drawBody(QPainter *painter);

    void drawLeftPaw(QPainter *painter, const QTransform &transform);

    void drawEyes(QPainter *painter, const QTransform &transform);
};


#endif //GRAPHIC_LAB_2_CAT_H
