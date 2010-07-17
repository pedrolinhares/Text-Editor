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
        bool saveFile();
        bool loadFile(QString& );

    private:
        bool Ok_ToContinue();
        bool saveAs();
        bool save (const QString& );
        void setCurrentFile(const QString& );
        bool writeFile(const QString& );
        QString strippedFileName(const QString& );

        static int numDocuments;
        bool       isUntitle;
        QString    curFile;
        QAction    *action;
};

#endif
