//
// Created by dev on 28.10.17.
//
#include <QtGui/QPainter>
#include "CatAndMouse.h"
#include "AffinTranslate/AffineTranslate.h"
#include <QtGui/QtGui>

void CatAndMouse::paintEvent(QPaintEvent *qEvent) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(Qt::transparent);
//    painter.setPen(Qt::DashLine);
    int radius = 300;

    painter.drawEllipse(
            QPointF(width() / 2, height() / 2),
            radius,
            radius

    );


    iteration = (iteration + 1) % 360;

    painter.setBackground(QBrush(Qt::white));

    QTransform matrix = AffineTranslate::rotateMatrix(-iteration);
    matrix *= AffineTranslate::moveMatrix(width() / 2, height() / 2);
    matrix *= AffineTranslate::moveMatrix(
            radius * cos(qDegreesToRadians(-(double) iteration)),
            radius * sin(qDegreesToRadians(-(double) iteration))
    );

    cat->draw(&painter, AffineTranslate::moveMatrix(50, height() / 2));
    QTransform transform;
    transform.rotate(iteration);

    static int j = 50;
    if (iteration > 175 && iteration < 185) j -= 10;
    else if (j < 60) j++;

    cat->drawLeftPaw(&painter, j);
    mouse->draw(&painter, matrix);

}

CatAndMouse::CatAndMouse() : QWidget() {

    this->mouse = new Mouse();
    this->cat = new Cat();
    this->timer = new QTimer(this);
    timer->setInterval(20);
    timer->start();
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
}
