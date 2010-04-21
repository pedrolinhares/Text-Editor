#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QAction;
class QLabel;
class QTextEdit;
class QMenu;

class MainWindow : public QMainWindow{
    Q_OBJECT
public:
    MainWindow();

//protected:
  //  void closeEvent(QCloseEvent *event);
private slots:
    void openFile();
private:
    void createMenu();
    void createActions();
    QTextEdit *textEdit;
    QMenu *fileMenu;
    QMenu *aboutMenu;
    QAction *openAction;
    QAction *aboutQtAction;
}; 

#endif
