
#include <QtWidgets/QApplication>
#include "CatAndMouse.h"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    CatAndMouse el;

    el.resize(640, 640);
    el.setFixedSize(640, 640);
    el.show();

    return app.exec();
}