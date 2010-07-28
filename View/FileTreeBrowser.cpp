#include <QtGui>
#include "FileTreeBrowser.h"

FileTreeBrowser::FileTreeBrowser (const QStringList& filter, QWidget* parent)
    : QTreeWidget (parent) {

    nameFilter = filter;
    connect(this, SIGNAL(itemActivated(QTreeWidgetItem*, int)), this, SLOT(itemSelected(QTreeWidgetItem*)));

    setColumnCount(1);
    setRootIsDecorated (true);
    setPath(QDir::homePath());
}

void FileTreeBrowser::setPath(const QString& path) {
    QDir dir(path);
    //dir.setMatchAllDirs(true);
    dir.setFilter(QDir::AllDirs | QDir::Files );
    dir.setNameFilters(nameFilter);
    dir.setSorting(QDir::DirsFirst | QDir::IgnoreCase);

    if (!dir.isReadable())
        return;
    clear();

    basePath = dir.canonicalPath();

    QList<QTreeWidgetItem*> items;
    QTreeWidgetItem* item;
    QStringList entries = dir.entryList();
    QStringList::ConstIterator it = entries.constBegin();
    while (it != entries.constEnd()) {
        if (*it != "." ) {
            try {
                item = new QTreeWidgetItem( this, QStringList(*it));

                QString path = basePath + "/" + item->text(0);
                if (QFileInfo(path).isDir())
                    item->setIcon(0, QIcon(":/images/dir_icon.png"));

                 if (QFileInfo(path).isFile())
                    item->setIcon(0, QIcon(":/images/file_icon.png"));
                
                 item->setFlags (Qt::ItemIsEnabled | Qt::ItemIsSelectable | 
                                    Qt::ItemIsEditable | Qt::ItemIsUserCheckable);
                
                 items.append (item);
                 item->setExpanded (true);
                 item->setChildIndicatorPolicy (QTreeWidgetItem::ShowIndicator);
            
            } catch (std::bad_alloc ){}
        }
        ++it;
    }

    insertTopLevelItems(0, items);
    setHeaderLabel (QString("File Browser"));
}

void FileTreeBrowser::itemSelected (QTreeWidgetItem* item) {
    QString path = basePath + "/" + item->text(0);
        if (QFileInfo(path).isDir())
            setPath(path);

         if (QFileInfo(path).isFile())
            emit picked(path);

}
