#include <QtGui>
#include <iostream>
#include "FileBrowserView.h"

FileBrowserView::FileBrowserView (const QStringList& filter, QWidget* parent)
                    : QTreeView (parent) {
    nameFilter = filter;

    model = new QDirModel;
    model->setReadOnly (true);
    model->setFilter(QDir::AllDirs | QDir::NoDotAndDotDot | QDir::Files );
    model->setNameFilters (nameFilter);
    model->setSorting (QDir::DirsFirst | QDir::IgnoreCase | QDir::Name);

    setModel (model);
    //header ()->setStretchLastSection (false);
    header ()->setSortIndicator (0, Qt::AscendingOrder);
    header ()->setSortIndicatorShown (true);
    header ()->setClickable (true);


    QModelIndex index = model->index (QDir::homePath());
    //setRootIndex (index);
    expand (index);
    scrollTo (index);
    resizeColumnToContents (0);

    int numColumn = model->columnCount(index);
    for (int i = 1; i != numColumn; i++)
        hideColumn (i);

    connect (this, SIGNAL(activated (const QModelIndex&)), this,
            SLOT(itemSelected(const QModelIndex&)));
}

void FileBrowserView::itemSelected (const QModelIndex& index) {
    if(!model->isDir(index))
        emit picked (model->filePath(index));
} 
