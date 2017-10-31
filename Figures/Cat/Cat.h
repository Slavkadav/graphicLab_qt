//
// Created by dev on 29.10.17.
//

#ifndef GRAPHIC_LAB_2_CAT_H
#define GRAPHIC_LAB_2_CAT_H


#include "../Figure.h"

class Cat : public Figure {
public:
    void draw(QPainter *painter, QTransform position) override;

    void drawLeftPaw(QPainter *painter, double angle);
private:

    QTransform catPosition;

    void drawBody(QPainter *painter);


    void drawEyes(QPainter *painter, const QTransform &transform);
};


#endif //GRAPHIC_LAB_2_CAT_H
