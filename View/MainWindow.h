#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Editor.h"

class QAction;
class QLabel;
class QTextEdit;
class QMenu;
class QTabWidget;

class MainWindow : public QMainWindow{
    Q_OBJECT
public:
    MainWindow();

//protected:
  //  void closeEvent(QCloseEvent *event);
private slots:
private:
    void       createMenu();
    void       createActions();
    Editor*    createEditor();
    QTextEdit  *textEdit;
    QTabWidget *tabWidget;
    QMenu      *fileMenu;
    QMenu      *aboutMenu;
    QAction    *openAction;
    QAction    *closeAction;
    QAction    *aboutQtAction;
}; 

#endif
