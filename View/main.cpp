#include "MainWindow.h"
#include <QApplication>

int main(int argc, char** argv){
    QApplication app(argc,argv);
    MainWindow *win = new MainWindow();
    win->show();

    return app.exec();
}
