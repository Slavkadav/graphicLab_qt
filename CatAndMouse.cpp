//
// Created by dev on 28.10.17.
//
#include <QtGui/QPainter>
#include "CatAndMouse.h"
#include "AffinTranslate/AffineTranslate.h"
#include <QDebug>
#include <QtGui/QtGui>

void CatAndMouse::paintEvent(QPaintEvent *qEvent) {
    QPainter painter(this);
    qDebug() << "paint event called";
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(Qt::transparent);
//    painter.setPen(Qt::DashLine);
    int radius = 300;

    painter.drawEllipse(
            QPointF(width() / 2, height() / 2),
            radius,
            radius

    );


    iteration += 1;

    painter.setBackground(QBrush(Qt::white));

    QTransform matrix = AffineTranslate::rotateMatrix(-iteration);
    matrix *= AffineTranslate::moveMatrix(width() / 2, height() / 2);
    matrix *= AffineTranslate::moveMatrix(
            radius * cos(qDegreesToRadians(-iteration)),
            radius * sin(qDegreesToRadians(-iteration))
    );

    cat->draw(&painter, AffineTranslate::moveMatrix(width() / 2, height() / 2));

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
