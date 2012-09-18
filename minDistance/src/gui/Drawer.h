#ifndef DRAWER_H
#define DRAWER_H

#include <sstream>
#include <cmath>
#include <algorithm>
#include <QWidget>
#include <QPainter>
#include <QFont>
#include <QMouseEvent>
#include "src/objects/Graph.h"
#include "src/objects/Point2D.h"
//#include "src/gui/MainWidget.h"

class Drawer : public QWidget {
    Q_OBJECT

public:
    Drawer(QWidget *parent = 0);
    Drawer(QWidget *parent, const Graph <Point2D> &poly);

    double getScale() {return scale;}
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void replacePoly (const Graph <Point2D> &poly);
    void mouseMoveEvent(QMouseEvent *);

    int connect;
protected:
    int offsetx;
    int offsety;
    Graph <Point2D> poly;
    double scale;

signals:
    void pointAdded (Point2D);
    void pointRemoved (unsigned int);
    void mouseMoved(int x, int y);

};

#endif // DRAWER_H
