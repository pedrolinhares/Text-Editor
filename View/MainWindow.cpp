#include <QtGui>
#include "MainWindow.h"
#include <iostream>

MainWindow::MainWindow(){
    tabWidget = new QTabWidget(this);
    textEdit = createEditor();
    tabWidget->addTab(textEdit,textEdit->documentTitle());

    connect(textEdit, SIGNAL(textChanged()), this, SLOT(updateTabTitle()) );
    
    setCentralWidget(tabWidget);

    setWindowTitle(tr("Editor Version 0.1"));
    setWindowIcon(QIcon("./images/text-Doc.png"));
    resize(800, 600);
    
    showMaximized();

    createActions();
    createMenu();
}

void MainWindow::updateTabTitle(){
    int tabIndex = tabWidget->currentIndex();
    tabWidget->setTabText (tabIndex, textEdit->windowTitle() );
}

void MainWindow::createActions(){
    
    //Open document action
    openAction = new QAction(tr("&Open"), this);
    openAction->setIcon(QIcon("./images/open_icon.png"));
    openAction->setShortcut(tr("Ctrl+O"));
    openAction->setStatusTip(tr("Open a exiting file"));

    connect(openAction, SIGNAL(triggered()), textEdit, SLOT(openFile()));

    //Save document action
    saveAction = new QAction(tr("&Save"), this);
    saveAction->setIcon(QIcon("./images/save_icon.png"));
    saveAction->setShortcut(tr("Ctrl+s"));
    saveAction->setStatusTip(tr("save the current document"));

    connect(saveAction, SIGNAL(triggered()), textEdit, SLOT(saveFile()));

    //Close Action
    closeAction = new QAction(tr("&Exit"), this);
    closeAction->setShortcut(tr("Ctrl+Q"));
    closeAction->setIcon(QIcon("./images/quit-icon.png"));
    closeAction->setStatusTip(tr("Exit Application"));
    
    connect(closeAction, SIGNAL(triggered()), qApp, SLOT(closeAllWindows()));

    /*About Qt Action*/
    aboutQtAction = new QAction(tr("About &Qt"),this);
    aboutQtAction->setIcon(QIcon("./images/qt-logo.png"));
    aboutQtAction->setStatusTip(tr("Show the Qt library's About box"));
    
    connect(aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}

void MainWindow::createMenu(){
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction (openAction);
    fileMenu->addAction (saveAction);
    fileMenu->addSeparator();
    fileMenu->addAction (closeAction);

    aboutMenu = menuBar()->addMenu(tr("&About"));
    aboutMenu->addAction (aboutQtAction);
}

Editor* MainWindow::createEditor(){
    Editor *textEd = new Editor();
    /*Acrescentar coisas futuramente*/
    return textEd;
}

