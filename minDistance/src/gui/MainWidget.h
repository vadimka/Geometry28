#ifndef MAINWIDGET_H
#define	MAINWIDGET_H

#include <string>
#include <iostream>
#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QTabWidget>
#include "src/algo/PolygonInputParser.h"
#include "src/gui/Drawer.h"
#include "src/objects/Graph.h"
#include "src/algo/minDist.h"
#include "src/algo/validator.h"

class MainWidget : public QWidget {
    Q_OBJECT

protected:
    QTabWidget tabs;
    QWidget controlWidget;

    QGridLayout mainLay;
    QGridLayout controlWidgetLay;

    QPushButton clearButton;
    QPushButton exitButton;
    QPushButton exportButton;
    QPushButton importFromFileButton;
    QPushButton processButton;



    QLineEdit fileNameExport;
    QLineEdit fileNameInput;

    Drawer visualizer;

    Graph<Point2D> poly;

public:
    MainWidget();
        QLabel label;
    
public slots:
    void addPoint (Point2D);
    void clickedClearButton();
    void clickedExitButton();
    void clickedExportButton();
    void clickedImportFromFileButton();
    void clickedProcessButton();
    void removePoint (unsigned int);
    void updateLabel(int x, int y);

signals:
    void performExitButtonAction();
};

#endif	/* MAINWIDGET_H */
