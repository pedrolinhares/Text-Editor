#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Editor.h"
#include "FileBrowserView.h"
//#include "FileTreeBrowser.h"

class QAction;
class QLabel;
class QTextEdit;
class QMenu;
class QToolBar;
class QTabWidget;

class MainWindow : public QMainWindow{
    Q_OBJECT
    public:
        MainWindow();

    //protected:
      //  void closeEvent(QCloseEvent *event);
    private slots:
        void updateTabTitle();
        bool newDocument();
        void pageChanged (int);
        void openFromFileBrowser(QString);
        void closeTab (int);
        void openFile();
        void saveFile();
        void saveAs();
        void copy();
        void cut();
        void paste();
        void undo();
        void redo();

    private:
        void       createMenu();
        void       createActions();
        void       createToolBar();
        Editor*    createEditor();
        Editor*    textEdit;
        FileBrowserView* fileBrowser;
        QTabWidget *tabWidget;
        QMenu      *fileMenu;
        QMenu      *editMenu;
        QMenu      *aboutMenu;
        QToolBar   *fileToolBar;
        QToolBar   *editToolBar;
        QToolBar   *undoRedoToolBar;
        QAction    *openAction;
        QAction    *newAction;
        QAction    *closeAction;
        QAction    *saveAction;
        QAction    *saveAsAction;
        QAction    *cutAction;
        QAction    *copyAction;
        QAction    *undoAction;
        QAction    *redoAction;
        QAction    *pasteAction;
        QAction    *aboutQtAction;
};

#endif

