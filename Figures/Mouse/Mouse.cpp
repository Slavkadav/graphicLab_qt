//
// Created by dev on 28.10.17.
//

#include "Mouse.h"

Mouse::Mouse() = default;

void Mouse::drawNose(QPainter *painter) {
    painter->setBrush(QBrush(Qt::black));

    QPolygonF nose;
    nose << QPointF(0, 0)
         << QPointF(-width / 3, 10)
         << QPointF(width / 3, 10);

    painter->drawPolygon(nose);

    QRectF rectF(-width / 3, 5, width * 2 / 3, 10);
    painter->drawChord(rectF, 0, -180 * 16);
}

void Mouse::drawBody(QPainter *painter) {
    painter->setBrush(Qt::gray);
    painter->setPen(Qt::transparent);
    QPolygonF body;
    body << QPointF(0, 0)
         << QPointF(-width, 30)
         << QPointF(width, 30);

    painter->drawPolygon(body);
    QRectF rectF(-width, 20, 2 * width, 15);
    painter->drawChord(rectF, 0, -180 * 16);

}

void Mouse::drawTail(QPainter *painter) {
    painter->setPen(Qt::black);
    painter->setBrush(Qt::black);
    painter->drawLine(
            QPointF(0, 30),
            QPointF(0, 50)
    );


}

void Mouse::draw(QPainter *painter, QTransform position) {
    painter->setTransform(position);

    drawBody(painter);
    drawNose(painter);
    drawTail(painter);

    painter->resetTransform();
}
