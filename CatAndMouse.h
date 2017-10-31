//
// Created by dev on 28.10.17.
//

#ifndef GRAPHIC_LAB_2_CATANDMOUSE_H
#define GRAPHIC_LAB_2_CATANDMOUSE_H


#include <QtWidgets/QWidget>
#include <QtCore/QTimer>
#include "Figures/Mouse/Mouse.h"
#include "Figures/Cat/Cat.h"

class CatAndMouse : public QWidget {
public:
    CatAndMouse();

private:
    void paintEvent(QPaintEvent *qEvent) override;

    Mouse *mouse;
    QTimer *timer;
    int iteration = 0;
    Cat *cat;

};


#endif //GRAPHIC_LAB_2_CATANDMOUSE_H
