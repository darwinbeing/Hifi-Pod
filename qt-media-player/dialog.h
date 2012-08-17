#pragma once
#include <QDialog>
#include <QFileSystemModel>
#include <QTreeView>

class FileDialog : public QDialog {
    Q_OBJECT
public:
    FileDialog(QWidget*,QString,QString,QString);
    QStringList selectedFiles();
private:
    QFileSystemModel fileSystem;
    QTreeView view;
};
