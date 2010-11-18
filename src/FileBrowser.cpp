#include <QtGui>
#include "FileBrowser.h"

FileBrowser::FileBrowser (const QStringList& filter, QWidget* parent)
    : QListWidget (parent) {

    nameFilter = filter;
    connect(this, SIGNAL(itemActivated(QListWidgetItem*)), this, SLOT(itemSelected(QListWidgetItem*)));

    setPath(QDir::homePath());
}

void FileBrowser::setPath(const QString& path) {
    QDir dir(path);
    //dir.setMatchAllDirs(true);
    dir.setFilter(QDir::AllDirs | QDir::Files );
    dir.setNameFilters(nameFilter);
    dir.setSorting(QDir::DirsFirst | QDir::IgnoreCase);

    if (!dir.isReadable())
        return;
    clear();

    QStringList entries = dir.entryList();
    QStringList::ConstIterator it = entries.constBegin();
    while (it != entries.constEnd()) {
        if (*it != "." )
            addItem(*it);
        ++it;
    }
    basePath = dir.canonicalPath();
}

void FileBrowser::itemSelected (QListWidgetItem* item) {
    QString path = basePath + "/" + item->text();
        if (QFileInfo(path).isDir())
            setPath(path);

         if (QFileInfo(path).isFile())
            emit picked(path);

}

