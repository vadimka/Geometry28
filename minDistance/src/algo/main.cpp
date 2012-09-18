#include <QApplication>
#include <QtGui>
#include "src/gui/MainWidget.h"
#include <string>
#include <iostream>
using std::cout;

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    std::string str;

    if (argc > 2 && std::string(argv[1]) == "--test") {
        if (argc == 3) {
            cout << "testing..." << endl;
            str  = argv[2];
        } else if (argc == 4 && std::string(argv[2]) == "--check") {
            cout << "testing and checking..." << endl;
            cout << "O(n*logn) ";
            str = argv[3];
        } else {
            cout << "Usage:" << endl;
            cout << "[--test] [--check] [numberOfPoints]" << endl;
            cout << "[--test] [numberOfPoints]" << endl;
            return 0;
        }

        int n = atoi(str.c_str());
        Validator::test_size = n;
        Validator val;
        val.generate();
        val.min_dist();

        if (argc == 4 && std::string(argv[2]) == "--check") {
            val.test();
        }
        return 0;
    } else {

        MainWidget mainWindow;
        mainWindow.show();
        QObject::connect (&mainWindow, SIGNAL(performExitButtonAction()), &app, SLOT(quit()));
        return app.exec();

    }

    //return app.exec();
}
