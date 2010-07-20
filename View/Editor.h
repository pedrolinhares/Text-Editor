#ifndef EDITOR_H
#define EDITOR_H

#include <QTextEdit>

class QString;
class QAction;

class Editor : public QTextEdit{
    Q_OBJECT

    public:
        Editor(QWidget *parent = 0);
        
        //public slots
        bool openFile();
        bool saveFile();
        bool saveAs();
        bool Ok_ToContinue();
        bool loadFile(QString& );

    private slots:
        void documentWasModified();

    private:
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
