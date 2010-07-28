#include <QtGui>
#include "MainWindow.h"
#include <iostream>

MainWindow::MainWindow(){
    tabWidget = new QTabWidget(this);
    tabWidget->setMovable (true);
    tabWidget->setTabsClosable (true);
    tabWidget->setDocumentMode (true);


    connect (tabWidget, SIGNAL(tabCloseRequested(int)), this, SLOT(closeTab(int)));
    connect (tabWidget, SIGNAL(currentChanged(int)), this, SLOT(pageChanged(int)));

    //Defines wich files will be visible in the file browser
    QStringList filters;
    filters << "*.txt" <<"*.cpp" <<"*.h";
    fileBrowser = new FileBrowser (filters, this);
    fileBrowser->setFixedWidth(200);

    connect (fileBrowser, SIGNAL(picked(QString&)), this, 
            SLOT(openFromFileBrowser(QString&)));

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget (fileBrowser);
    layout->addWidget (tabWidget);

    QWidget* centralWidget = new QWidget;
    centralWidget->setLayout(layout);

    setCentralWidget (centralWidget);

    setWindowTitle (tr("Editor Version 0.1"));
    setWindowIcon (QPixmap(":/images/text_doc.png"));
    
    createActions();
    createMenu();
    createToolBar();

    newDocument();

    resize (800, 600);
    showMaximized();

}

void MainWindow::updateTabTitle(){
    int tabIndex = tabWidget->currentIndex();
    tabWidget->setTabText (tabIndex, textEdit->windowTitle() );
}

void MainWindow::createActions(){
   
    //New file Action

    newAction = new QAction (tr("New document"), this);
    newAction->setIcon(QIcon(":/images/new_icon.png"));
    newAction->setShortcut (tr("Ctrl+N"));
    newAction->setStatusTip (tr("Open new file"));

    connect (newAction, SIGNAL(triggered()), this, SLOT(newDocument()));

    //Open document action
    openAction = new QAction(tr("&Open"), this);
    openAction->setIcon(QIcon(":/images/open_icon.png"));
    openAction->setShortcut(tr("Ctrl+O"));
    openAction->setStatusTip(tr("Open a exiting file"));

    connect(openAction, SIGNAL(triggered()), this, SLOT(openFile()));

    //Save document action
    saveAction = new QAction(tr("&Save"), this);
    saveAction->setIcon(QIcon(":/images/save_icon.png"));
    saveAction->setShortcut(tr("Ctrl+s"));
    saveAction->setStatusTip(tr("save the current document"));

    connect(saveAction, SIGNAL(triggered()), this, SLOT(saveFile()));

    //Save As Action

    saveAsAction = new QAction(tr("&Save As.."), this);
    saveAsAction->setShortcut(Qt::SHIFT | Qt::CTRL | Qt::Key_S);
    saveAsAction->setStatusTip(tr("save the current document with a different name"));

    connect(saveAsAction, SIGNAL(triggered()),this, SLOT(saveAs()));

    //Copy Action

    copyAction = new QAction (tr("Copy"), this);
    copyAction->setShortcut (tr("Ctrl+c"));
    copyAction->setIcon(QIcon(":/images/copy_icon.png"));
    copyAction->setStatusTip (tr("Copy selected text to clipboard"));
    copyAction->setEnabled(false);

    connect (copyAction, SIGNAL(triggered()), this, SLOT(copy()));

    //Cut Action
    cutAction = new QAction (tr("Cut"), this);
    cutAction->setShortcut (tr("Ctrl+x"));
    cutAction->setIcon(QIcon(":/images/cut_icon.png"));
    cutAction->setStatusTip (tr("Cut selected text to clipboard"));
    cutAction->setEnabled(false);

    connect (cutAction, SIGNAL(triggered()), this, SLOT(cut()));

    //Paste Action
    pasteAction = new QAction (tr("Paste"), this);
    pasteAction->setShortcut (tr("Ctrl+v"));
    pasteAction->setIcon(QIcon(":/images/paste_icon.png"));
    pasteAction->setStatusTip (tr("paste text in clipboard"));

    connect (pasteAction, SIGNAL(triggered()), this, SLOT(paste()));

    //Undo Action
    undoAction = new QAction (tr("Undo"), this);
    undoAction->setShortcut (tr("Ctrl+z"));
    undoAction->setIcon(QIcon(":/images/undo_icon.png"));
    undoAction->setStatusTip (tr("Undo the last action"));
    undoAction->setEnabled(false);

    connect (undoAction, SIGNAL(triggered()), this, SLOT(undo()));

    //Redo Action
    redoAction = new QAction (tr("Redo"), this);
    redoAction->setShortcut (Qt::SHIFT | Qt::CTRL | Qt::Key_Z);
    redoAction->setIcon(QIcon(":/images/redo_icon.png"));
    redoAction->setStatusTip (tr("Redo the last action"));
    redoAction->setEnabled(false);

    connect (redoAction, SIGNAL(triggered()), this, SLOT(redo()));

    //Close Action
    closeAction = new QAction(tr("&Exit"), this);
    closeAction->setShortcut(tr("Ctrl+Q"));
    closeAction->setIcon(QIcon(":/images/quit_icon.png"));
    closeAction->setStatusTip(tr("Exit Application"));
    
    connect(closeAction, SIGNAL(triggered()), qApp, SLOT(closeAllWindows()));

    /*About Qt Action*/
    aboutQtAction = new QAction(tr("About &Qt"),this);
    aboutQtAction->setIcon(QIcon(":/images/qt_logo.png"));
    aboutQtAction->setStatusTip(tr("Show the Qt library's About box"));
    
    connect(aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}

void MainWindow::createMenu(){
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction (newAction);
    fileMenu->addSeparator();
    fileMenu->addAction (openAction);
    fileMenu->addAction (saveAction);
    fileMenu->addAction (saveAsAction);
    fileMenu->addSeparator();
    fileMenu->addAction (closeAction);

    editMenu = menuBar()->addMenu (tr("&Edit"));
    editMenu->addAction(undoAction);
    editMenu->addAction(redoAction);
    editMenu->addSeparator();
    editMenu->addAction(cutAction);
    editMenu->addAction(copyAction);
    editMenu->addAction(pasteAction);

    aboutMenu = menuBar()->addMenu(tr("&About"));
    aboutMenu->addAction (aboutQtAction);
}

Editor* MainWindow::createEditor(){
    Editor* textEd = 0;
    textEd = new Editor();
    
    return textEd;
}

bool MainWindow::newDocument() {
    textEdit = createEditor();
    
    if (!textEdit)
        return false;

    if (tabWidget->count() == 0) {
        saveAction->setEnabled (true);
        saveAsAction->setEnabled (true);
        pasteAction->setEnabled (true); 
    }

    connect (textEdit, SIGNAL(textChanged()), this, SLOT(updateTabTitle()) );
    connect (textEdit, SIGNAL(copyAvailable(bool)), cutAction, SLOT(setEnabled(bool)));
    connect (textEdit, SIGNAL(copyAvailable(bool)), copyAction, SLOT(setEnabled(bool)));
    connect (textEdit, SIGNAL(undoAvailable(bool)), undoAction, SLOT(setEnabled(bool)));
    connect (textEdit, SIGNAL(redoAvailable(bool)), redoAction, SLOT(setEnabled(bool)));

    int tabIndex = tabWidget->addTab(textEdit, textEdit->documentTitle());
    tabWidget->setCurrentIndex(tabIndex);
    return true;
}

void MainWindow::createToolBar () {
    fileToolBar = addToolBar (tr("&File"));
    fileToolBar->addAction (newAction);
    fileToolBar->addAction (openAction);
    fileToolBar->addAction (saveAction);

    editToolBar = addToolBar (tr("Edit"));
    editToolBar->addAction (copyAction);
    editToolBar->addAction (cutAction);
    editToolBar->addAction (pasteAction);

    undoRedoToolBar = addToolBar (tr("Undo & Redo actions"));
    undoRedoToolBar->addAction (undoAction);
    undoRedoToolBar->addAction (redoAction);
}

void MainWindow::pageChanged(int tabIndex) {
    textEdit = dynamic_cast<Editor*> (tabWidget->widget(tabIndex));
}

void MainWindow::closeTab (int tabIndex) {
    textEdit = dynamic_cast<Editor*> (tabWidget->widget(tabIndex));
     
    if(textEdit->Ok_ToContinue())
        delete tabWidget->widget(tabIndex);

    //Deactivate actions because there is no tab 
     if (tabWidget->count() == 0) {
         saveAction->setEnabled (false);
         saveAsAction->setEnabled (false);
         pasteAction->setEnabled (false);
     }
}

void MainWindow::openFile () {
    int numberOfTabs = tabWidget->count();
    if (numberOfTabs == 0) {
        QString fileName = QFileDialog::getOpenFileName(this, tr("Choose File to open"), ".",
                                                       tr("Txt Files (*.txt)\n"
                                                            "All (*)"));
        if (!fileName.isEmpty())
            openFromFileBrowser (fileName);
    } else
        textEdit->openFile();
}

void MainWindow::saveFile () {
    textEdit->saveFile();
}

void MainWindow::saveAs () {
    textEdit->saveAs();
}

void MainWindow::copy () {
    textEdit->copy();
}

void MainWindow::cut () {
    textEdit->cut();
}

void MainWindow::paste () {
    textEdit->paste();
}

void MainWindow::undo () {
    textEdit->undo();
}

void MainWindow::redo () {
    textEdit->redo();
}

void MainWindow::openFromFileBrowser (QString& filePath) {
    newDocument();
    textEdit->loadFile(filePath);
}
