#include "MainWidget.h"



MainWidget::MainWidget()
    :   clearButton ("Clear"),
        exitButton ("Exit"),
        exportButton ("Export points to:"),
        importFromFileButton ("Import points from file:"),
        processButton ("min dist"),
        fileNameExport ("output.txt"),
        fileNameInput ("test.txt"),
        visualizer (this) {

    tabs.addTab(&visualizer, "Visualizer");

    mainLay.addWidget(&tabs, 0, 0);
    mainLay.addWidget(&controlWidget, 0, 1);
    this->setLayout(&mainLay);

    controlWidgetLay.addWidget(&importFromFileButton, 0, 0);
    controlWidgetLay.addWidget(&fileNameInput, 1, 0);
    controlWidgetLay.addWidget(&processButton, 2, 0);
    controlWidgetLay.addWidget(&clearButton, 5, 0);
    controlWidgetLay.addWidget(&exportButton, 6, 0);
    controlWidgetLay.addWidget(&fileNameExport, 7, 0);
    controlWidgetLay.addWidget(&exitButton, 8, 0);
    controlWidget.setLayout(&controlWidgetLay);
    controlWidget.setMaximumWidth(200);

    visualizer.setMinimumSize(600, 400);

    QObject::connect(&clearButton, SIGNAL(clicked()), this, SLOT(clickedClearButton()));
    QObject::connect(&exitButton, SIGNAL(clicked()), this, SLOT(clickedExitButton()));
    QObject::connect(&exportButton, SIGNAL(clicked()), this, SLOT(clickedExportButton()));
    QObject::connect(&processButton, SIGNAL(clicked()), this, SLOT(clickedProcessButton()));
    QObject::connect(&importFromFileButton, SIGNAL(clicked()), this, SLOT(clickedImportFromFileButton()));
    QObject::connect(&visualizer, SIGNAL(pointAdded(Point2D)), this, SLOT(addPoint(Point2D)));
    QObject::connect(&visualizer, SIGNAL(pointRemoved(unsigned int)), this, SLOT(removePoint(unsigned int)));
}


void MainWidget::addPoint(Point2D arg) {
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
    visualizer.replacePoly(ans);
    visualizer.update();

    std::cout << "ANSWER" << std::endl;
    for (unsigned int i = 0; i < ans.size(); ++i)
    {
        std::cout << ans[i].getX()<< ' ' << ans[i].getY() << std::endl;
    }
    std::cout << std::endl;
}



void MainWidget::removePoint(unsigned int index) {
    poly.removePoint(index);
    poly.edges.clear();
    visualizer.replacePoly(poly);

}
