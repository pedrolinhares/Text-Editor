#ifndef FILE_BROWSER_VIEW
#define FILE_BROWSER_VIEW

#include <QTreeView>

class QString;
class QWidget;
class QDirModel;

class FileBrowserView : public QTreeView {
    Q_OBJECT
    public:
        FileBrowserView (const QStringList& filter, QWidget* parent = 0);

    signals:
        void picked (QString );

    private slots:
        void itemSelected (const QModelIndex&);
    private:
        QStringList nameFilter;
        QDirModel* model;
};

#endif
