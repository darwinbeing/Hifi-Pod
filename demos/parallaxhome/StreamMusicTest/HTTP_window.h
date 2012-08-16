/*
 * MyPlayer.h

 */

#ifndef MYHTTPWINDOW_H_
#define MYHTTPWINDOW_H_

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QHttp>
#include <QFile>
#include <QProgressDialog>
#include <QListWidget>
#include <QPushButton>

  struct MyDataItem
    {
      QString   audio;
      QString   title;
    };  


 class HttpWindow : public QWidget
 {
     Q_OBJECT

 public:
     HttpWindow();
 public slots:
     void itemSelected(QListWidgetItem *item);
     void PlayFile();
signals:
    void streamSelected(QString);     

 private:
	 void addTestData();
 private:
     QList<MyDataItem>  items;
     QListWidget*       listWidget;
     QPushButton*       pushBut;
 };



#endif /* MYHTTPWINDOW_H_ */
