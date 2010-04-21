#include "MainWindow.h"
#include <QtGui>

MainWindow::MainWindow(){
  textEdit = new QTextEdit();
  setCentralWidget(textEdit);

    setWindowTitle(tr("Editor Version 0.1"));
    resize(800, 600);
    createActions();
    createMenu();
}

void MainWindow::createActions(){
    /*Open document action*/
    openAction = new QAction(tr("&Open"), this);
    openAction->setIcon(QIcon(":/Open-icon.png"));
    openAction->setShortcut(tr("Ctrl+O"));
    openAction->setStatusTip(tr("Open a exiting file"));
    connect(openAction, SIGNAL(triggered()), this, SLOT(openFile()));

    /*About Qt Action*/
    aboutQtAction = new QAction(tr("About &Qt"),this);
    aboutQtAction->setStatusTip(tr("Show the Qt library's About box"));
    connect(aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

}
void MainWindow::createMenu(){
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openAction);

    aboutMenu = menuBar()->addMenu(tr("&About"));
    aboutMenu->addAction(aboutQtAction);
}
void MainWindow::openFile(){
    
}
