#include "MainWindow.h"
#include <QtGui>

MainWindow::MainWindow(){
    textEdit = new QTextEdit();
    connect(textEdit, SIGNAL(textChanged()), this, SLOT(setWindowModified(true)));
    setCentralWidget(textEdit);
    
    setWindowTitle(tr("Editor Version 0.1"));
    resize(800, 600);
    createActions();
    createMenu();
}

void MainWindow::createActions(){
    /*Open document action*/
    openAction = new QAction(tr("&Open"), this);
    openAction->setIcon(QIcon("./images/open_icon.png"));
    openAction->setShortcut(tr("Ctrl+O"));
    openAction->setStatusTip(tr("Open a exiting file"));
    connect(openAction, SIGNAL(triggered()), this, SLOT(openFile()));

    /*Close Action*/
    closeAction = new QAction(tr("&Exit"), this);
    closeAction->setShortcut(tr("Ctrl+Q"));
    closeAction->setIcon(QIcon("./images/quit-icon.png"));
    closeAction->setStatusTip(tr("Exit Application"));
    connect(closeAction, SIGNAL(triggered()), qApp, SLOT(closeAllWindows()));

    /*About Qt Action*/
    aboutQtAction = new QAction(tr("About &Qt"),this);
    aboutQtAction->setStatusTip(tr("Show the Qt library's About box"));
    connect(aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

}
void MainWindow::createMenu(){
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openAction);
    fileMenu->addSeparator();
    fileMenu->addAction(closeAction);

    aboutMenu = menuBar()->addMenu(tr("&About"));
    aboutMenu->addAction(aboutQtAction);
}
bool MainWindow::openFile(){
    if(Ok_ToContinue()){
        QString fileName = QFileDialog::getOpenFileName(this, tr("Choose File to open"), ".", tr("Txt Files (*.txt)"
        "All (*.*)"));
    if(fileName.isEmpty())
        return false;
    
    loadFile(fileName);
    }
    return true;
}

bool MainWindow::Ok_ToContinue(){
    if(1/*isWindowModified()*/){
        int r = QMessageBox::warning(this, tr("TextEditor"),
                            tr("The document has been modified. \n"
                            "Do you want to save your changes?"),
                            QMessageBox::Yes | QMessageBox::Default,
                            QMessageBox::No,
                            QMessageBox::Cancel | QMessageBox::Escape);
        if(r == QMessageBox::Yes || r == QMessageBox::No)
            return true;
        else  
            return false;
    }else
        return true;
}
bool MainWindow::loadFile(QString &fileName){
    return true;   
}
