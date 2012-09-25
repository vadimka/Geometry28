#include "MainWidget.h"



MainWidget::MainWidget()
    :   clearButton ("Clear"),
        exitButton ("Exit"),
        exportButton ("Export points to:"),
        importFromFileButton ("Import points from file:"),
        processButton ("min dist"),
        fileNameExport ("output.txt"),
        fileNameInput ("test.txt"),
    //  label("lol"),
        visualizer (this) {

    tabs.addTab(&visualizer, "Visualizer");

    mainLay.addWidget(&tabs, 0, 0);
    mainLay.addWidget(&controlWidget, 0, 1);
    this->setLayout(&mainLay);

    this->setMouseTracking(true);

    controlWidgetLay.addWidget(&importFromFileButton, 0, 0);
    controlWidgetLay.addWidget(&fileNameInput, 1, 0);
    controlWidgetLay.addWidget(&processButton, 2, 0);
    controlWidgetLay.addWidget(&clearButton, 5, 0);
    controlWidgetLay.addWidget(&exportButton, 6, 0);
    controlWidgetLay.addWidget(&fileNameExport, 7, 0);
    controlWidgetLay.addWidget(&exitButton, 8, 0);
    controlWidgetLay.addWidget(&label, 9, 0);
    controlWidget.setLayout(&controlWidgetLay);
    controlWidget.setMaximumWidth(200);

    visualizer.setMinimumSize(600, 400);

    QObject::connect(&clearButton, SIGNAL(clicked()), this, SLOT(clickedClearButton()));
    QObject::connect(&exitButton, SIGNAL(clicked()), this, SLOT(clickedExitButton()));
    QObject::connect(&exportButton, SIGNAL(clicked()), this, SLOT(clickedExportButton()));
    QObject::connect(&processButton, SIGNAL(clicked()), this, SLOT(clickedProcessButton()));
    QObject::connect(&importFromFileButton, SIGNAL(clicked()), this, SLOT(clickedImportFromFileButton()));
    QObject::connect(&visualizer, SIGNAL(mouseMoved(int,int)), this, SLOT(updateLabel(int,int)));
    QObject::connect(&visualizer, SIGNAL(pointAdded(Point2D)), this, SLOT(addPoint(Point2D)));
    QObject::connect(&visualizer, SIGNAL(pointRemoved(unsigned int)), this, SLOT(removePoint(unsigned int)));
}


void MainWidget::updateLabel(int x, int y)
{
    std::string str;
    string c;

    str += "X:  ";
    std::ostringstream oss;
    oss<<x;
    c = oss.str();
    //itoa(x, c, 10);
    str.append(c);
    str += "    Y:  ";
    std::ostringstream oss2;
    oss2<<y;
    c = oss2.str();
    //itoa(y, c, 10);
    str.append(c);
    label.setText(QString(str.c_str()));
}

void MainWidget::addPoint(Point2D arg) {
    visualizer.connect = false;
    poly.addVertex(arg);
//    poly.connectVertices();
    visualizer.replacePoly(poly);
    visualizer.update();

}


void MainWidget::clickedClearButton() {
    poly.clear();
    visualizer.replacePoly(poly);
}


void MainWidget::clickedExitButton() {
    emit performExitButtonAction();
}


void MainWidget::clickedExportButton() {
    poly.dumpVertices(fileNameExport.text().toStdString());
}


void MainWidget::clickedImportFromFileButton() {
    poly = Graph <Point2D> (PolygonInputParser::parseFile(fileNameInput.text().toStdString()));

    visualizer.replacePoly(poly);
    visualizer.update();
    //poly.connectVertices();
}


void MainWidget::clickedProcessButton() {

     std::cout << "INPUT" << std::endl;
     for (unsigned int i = 0; i < poly.vertices.size(); ++i)
     {
         std::cout << poly.vertices[i].getX()<< ' ' << poly.vertices[i].getY() << std::endl;
     }



    std::vector<Point2D> ans = mainf(poly.vertices);
 //   poly.vertices.clear();
    visualizer.connect = ans.size();
    ans.insert(ans.end(), poly.vertices.begin(), poly.vertices.end());

    visualizer.replacePoly(ans);
    visualizer.update();
    std::cout << "ANSWER" << std::endl;

    for (unsigned int i = 0; i < visualizer.connect; i++)
    {
        std::cout << ans[i].getX()<< ' ' << ans[i].getY() << '\t';
        if(i % 2 == 1 ) std::cout << std::endl;

    }
    std::cout << std::endl;


}



void MainWidget::removePoint(unsigned int index) {
    poly.removePoint(index);
    poly.edges.clear();
    visualizer.replacePoly(poly);

}
