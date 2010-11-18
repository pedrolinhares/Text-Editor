#ifndef FILE_TREE_BROWSER_H
#define FILE_TREE_BROWSER_H

#include <QTreeWidget>

class QListBox;
class QString;
class QWidget;

class FileTreeBrowser : public QTreeWidget {
    Q_OBJECT
    public:
        FileTreeBrowser (const QStringList& filter, QWidget* parent = 0);
        void setPath (const QString& path);

    signals:
        void picked (QString& );

    private slots:
        void itemSelected (QTreeWidgetItem* );

    private:
        QStringList nameFilter;
        QString basePath;
};

#endif

