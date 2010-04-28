#ifndef EDITOR_H
#define EDITOR_H

#include <QTextEdit>

class QString;
class QAction;

class Editor : public QTextEdit{
    Q_OBJECT
public:
    Editor(QWidget *parent = 0);
private slots:
    void documentWasModified();
    bool openFile();
    bool loadFile(QString& );
private:
    bool       Ok_ToContinue();
    static int numDocuments;
    bool       isUntitle;
    QString    CurFile;
    QAction    *action;
};

#endif
