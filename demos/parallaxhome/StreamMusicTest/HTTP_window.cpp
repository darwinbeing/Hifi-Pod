/*
 * MyPlayer.cpp
 *
 */
 #include <QtGui>
 #include <QtNetwork>
#include <QDomDocument>
#include <QDomElement>
#include <QDomNodeList>

 #include "HTTP_window.h"
/*
 * --------------------------------------------------------------
 * --------------------------------------------------------------
 */
 HttpWindow::HttpWindow()
 {
     listWidget = new QListWidget(this);
     
  	connect(listWidget, SIGNAL(itemActivated(QListWidgetItem*)), this, SLOT(itemSelected(QListWidgetItem*)));     
      
    pushBut = new QPushButton("Play", this);
    connect(pushBut, SIGNAL(pressed()),SLOT(PlayFile()));  
  	     
     QVBoxLayout *mainLayout = new QVBoxLayout;
     mainLayout->addWidget(listWidget);  
     mainLayout->addWidget(pushBut);       
     setLayout(mainLayout);

     addTestData();
 }
 /*
  * --------------------------------------------------------------
  * --------------------------------------------------------------
  */

   void HttpWindow::addTestData()
   {
       //Clear items
       listWidget->clear();
       items.clear();
       
       MyDataItem newIttem1;                
       newIttem1.audio = "mms://live.cri.cn/oldies";  
       newIttem1.title = "CRI oldies";
       items.append(newIttem1);

       MyDataItem newIttem5;           
       newIttem5.audio = "mms://media.crinewsradio.cn/crinewsradio";  
       newIttem5.title = "CRI News Radio";
       items.append(newIttem5);         
       
        
       MyDataItem newIttem3;              
       newIttem3.audio = "mms://bcr.media.hinet.net/RA000018";    
       newIttem3.title = "TBAY";
       items.append(newIttem3);      

       MyDataItem newIttem4;             
       newIttem4.audio = "mms://live.hitfm.cn/fm887";  
       newIttem4.title = "CRI Hit FM";
       items.append(newIttem4);      

    
       MyDataItem newIttem2;               
       newIttem2.audio = "mms://219.142.120.27/chn";  
       newIttem2.title = "CHN";
       items.append(newIttem2);    


    
       MyDataItem newItem6;               
       newItem6.audio = "mms://enmms.chinabroadcast.cn/fm91.5";  
       newItem6.title = "Easy FM";
       items.append(newItem6);  


       MyDataItem newItem7;               
       newItem7.audio = "mms://202.108.248.145/fm974";  
       newItem7.title = "FM974";
       items.append(newItem7);  


       
       for(int i=0; i< items.count(); i++){
 		  listWidget->addItem(items[i].title);
       }  
   }

/*
* --------------------------------------------------------------
* --------------------------------------------------------------
*/
void HttpWindow::PlayFile()
{
    int selIndex = listWidget->currentRow();
    
    if(selIndex >= 0 && selIndex < items.count()){
        emit streamSelected(items[selIndex].audio);
    }    
}
 /*
  * --------------------------------------------------------------
  * --------------------------------------------------------------
  */
 void HttpWindow::itemSelected(QListWidgetItem *item)
 {
     PlayFile();
 }

