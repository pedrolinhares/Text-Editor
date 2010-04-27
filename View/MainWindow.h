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
    bool openFile();
    bool loadFile(QString& );
    bool Ok_ToContinue();
private:
    void       createMenu();
    void       createActions();
    QTextEdit  *textEdit;
    QMenu      *fileMenu;
    QMenu      *aboutMenu;
    QAction    *openAction;
    QAction    *closeAction;
    QAction    *aboutQtAction;
}; 

#endif
