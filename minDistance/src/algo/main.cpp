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
    std::string str2;

    if (argc > 2 && std::string(argv[1]) == "--test") {
        if (argc == 4) {
            cout << "testing..." << endl;
            str  = argv[2];
            str2 = argv[3];
        } else if (argc == 5 && std::string(argv[2]) == "--check") {
            cout << "testing and checking..." << endl;
            cout << "O(n*logn) ";
            str = argv[3];
            str2 = argv[4];
        } else {
            cout << "Usage:" << endl;
            cout << "[--test] [--check] [numberOfPoints] [srandNumber]" << endl;
            cout << "[--test] [numberOfPoints] [srandNumber]" << endl;
            return 0;
        }
        int n, n2;
        std::istringstream ist(str);
        ist>>n;
        std::istringstream ist2(str2);
        ist2>>n2;
        Validator::test_size = n;
        Validator::srand_nmbr = n2;
        Validator val;
        val.generate();
        val.min_dist();
        if (argc == 5 && std::string(argv[2]) == "--check") {
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
