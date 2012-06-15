#include <QApplication>
#include <QtGui>
#include "src/gui/MainWidget.h"
#include <string>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    std::string str;
    MainWidget mainWindow;
    mainWindow.show();
    QObject::connect (&mainWindow, SIGNAL(performExitButtonAction()), &app, SLOT(quit()));
    return app.exec();

}
