#ifndef FILE_BROWSER_H
#define FILE_BROWSER_H

#include <QListWidget>

class QListBox;
class QString;
class QWidget;

class FileBrowser : public QListWidget {
    Q_OBJECT
    public:
        FileBrowser (const QStringList& filter, QWidget* parent = 0);
        void setPath (const QString& path);

    signals:
        void picked (QString& );

    private slots:
        void itemSelected (QListWidgetItem* );

    private:
        QStringList nameFilter;
        QString basePath;
};

#endif
