#include "dialog.h"
#include <QVBoxLayout>
#include <QPushButton>

FileDialog::FileDialog(QWidget* parent,QString caption,QString path,QString) : QDialog(parent) {
    setWindowTitle(caption);
    view.setModel(&fileSystem);
    view.setHeaderHidden(true);
    view.setSelectionMode(QAbstractItemView::ExtendedSelection);
    for(int i=1;i<fileSystem.columnCount();i++) view.setColumnHidden(i,true);
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(&view);
    view.setRootIndex(fileSystem.setRootPath(path));
//    view.resizeColumnToContents(0); setMinimumHeight(600); setMinimumWidth(view.columnWidth(0));
//    view.resizeColumnToContents(0); setMinimumHeight(300); setMinimumWidth(view.columnWidth(0));

    QPushButton* openButton = new QPushButton(QIcon::fromTheme("document-open"),"Open");
    connect(openButton,SIGNAL(clicked()),this,SLOT(accept()));
    layout->addWidget(openButton);
}

QStringList FileDialog::selectedFiles() {
    QStringList files;
    foreach(QModelIndex index, view.selectionModel()->selectedRows(0) )
        files << index.data(QFileSystemModel::FilePathRole).toString();
    return files;
}
