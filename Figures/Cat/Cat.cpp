//
// Created by dev on 29.10.17.
//

#include <QtGui/QtGui>
#include "Cat.h"

void Cat::draw(QPainter *painter, QTransform position) {
    this->catPosition = position;
    painter->setTransform(position);
    drawBody(painter);
    painter->setTransform(position);
    painter->resetTransform();
}

void Cat::drawBody(QPainter *painter) {


    painter->setBrush(Qt::gray);

    //тело
    QPolygonF body;
    body
            << QPoint(10, 0)
            << QPoint(60, 0)
            << QPoint(70, 50)
            << QPoint(0, 50);
    painter->drawPolygon(body);

    //лапа справа
    painter->setBrush(Qt::black);
    QRect rect(35, 45, 15, 20);
    painter->drawChord(rect, 30 * 16, 120 * 16);

    //уши
    painter->setBrush(Qt::gray);
    QPolygon ear;
    ear << QPoint(15, 0)
        << QPoint(20, -15)
        << QPoint(25, 0);
    QPolygon innerEar;
    innerEar << QPoint(17, 0)
             << QPoint(20, -10)
             << QPoint(23, 0);
    painter->drawPolygon(ear);
    painter->drawPolygon(innerEar);
    painter->translate(25, 0);
    painter->drawPolygon(ear);
    painter->drawPolygon(innerEar);

    //глазницы
    painter->translate(-10, 15);
    painter->drawEllipse(0, 0, 10, 10);
    painter->translate(25, 0);
    painter->drawEllipse(0, 0, 10, 10);


    //нос
    painter->setBrush(Qt::black);
    painter->translate(-5, 15);
    QPolygon nose;
    nose
            << QPoint(0, 0)
            << QPoint(-2, 5)
            << QPoint(2, 5);
    painter->drawPolygon(nose);

    //рот
    painter->translate(0, 10);
    painter->drawRect(-5, 0, 10, 5);

}

void Cat::drawLeftPaw(QPainter *painter, double angle) {
    painter->setTransform(catPosition);
    painter->translate(-10, 55);

    painter->translate(
            30 * cos(qDegreesToRadians(180 + angle)),
            30 * sin(qDegreesToRadians(180 + angle))
    );
    painter->drawChord(0, 0, 20, 30, 30 * 16, 120 * 16);

    painter->setTransform(catPosition);
    painter->translate(0, 50);
    painter->rotate(angle + 20);

    QPolygon polygon;
    polygon << QPoint(0, 0)
            << QPoint(-30, 0)
            << QPoint(-30, 16);

    painter->drawPolygon(polygon);


    painter->resetTransform();
}

void Cat::drawEyes(QPainter *painter, const QTransform &transform) {

}
