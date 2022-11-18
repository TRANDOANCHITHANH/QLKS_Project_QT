#include "checkout.h"
#include "ui_checkout.h"
using namespace std;
checkout::checkout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::checkout)
{
    ui->setupUi(this);
    this->setWindowTitle("CHECK OUT");
    pay=new payamount(this);
}

checkout::~checkout()
{
    delete ui;

}
void checkout::readData()
{
    vector<int>rooms = hotel::getInstance()->getRoomList("no");
    this->ui->cmbRoomList->clear();
    char flag = 0;
    for(vector<int>::iterator it = rooms.begin(); it!=rooms.end(); it++ )
    {
        this->ui->cmbRoomList->addItem(QString::number(*it));
        flag = 1;
    }

    if(flag==1) this->ui->checkout_2->setEnabled(true);
}
void checkout::on_pushButton_2_clicked()
{
    this->hide();
}


void checkout::on_checkout_2_clicked()
{   int  roomno = ui->cmbRoomList->currentText().toInt();
    conn.connOpen();
    QSqlQuery query;
    query.prepare("select * from management where idroom='"+QString::number(roomno)+"'");
    query.exec();
     while( query.next()){
     if(query.value(8).toString()=="Đã thanh toán"){
         int ret = hotel::getInstance()->CheckOut(roomno);

         QString msg = "";
         ret==0?msg="Success!":"Failure!";

          if(ret == 0)
         {
             QMessageBox::information(
             this,
             tr("Success!"),
             tr("TRẢ PHÒNG THÀNH CÔNG !!") );
         }
          conn.connclose();
          this->hide();
         }else if(query.value(8).toString().isEmpty()){
         QMessageBox::critical(this,"Error","Chưa Thanh Toán!!");
         return ;
         }
     }
}



void checkout::on_cmbRoomList_currentIndexChanged(int index)
{
    index=ui->cmbRoomList->currentText().toInt();
    if(!conn.connOpen()){
        qDebug() << "Database loaded not successfull!";
    } else{
        qDebug() << "Database loaded successfull!";
      }
    QSqlQuery query;
    query.prepare("select * from guest where maphong='"+QString::number(index)+"'");
    if(!query.exec()){
        qDebug() << query.lastError().text() << query.lastQuery();
    }else{
        qDebug() << "Fetch was successful";
}

    while(query.next()){
          ui->cid->setText(query.value(0).toString());
          ui->cname->setText(query.value(1).toString());
          ui->cccd->setText(query.value(2).toString());
          ui->cphone->setText(query.value(3).toString());
          ui->caddress->setText(query.value(4).toString());
          ui->ctime_in->setText(query.value(8).toString());
    }
    conn.connclose();

}

void checkout::on_pushButton_clicked()//tính tiền phòng
{    int index=ui->cmbRoomList->currentText().toInt();
    conn.connOpen();
    QSqlQuery query;
  query.prepare("select * from room where idroom='"+QString::number(index)+"'");
   if(!query.exec()){
          qDebug() << query.lastError().text() << query.lastQuery();
      }else{
          qDebug() << "Fetch was successful";}
          query.next();
         int price=query.value(3).toInt();
       query.clear();
       query.prepare("update management set price='"+QString::number(price)+"' where idroom='"+QString::number(index)+"'");
       if(!query.exec()){
              qDebug() << query.lastError().text() << query.lastQuery();
          }else{
              qDebug() << "Fetch was successful";}
        query.clear();
        query.prepare("select * from management where idroom='"+QString::number(index)+"'");
         if(!query.exec()){
                qDebug() << query.lastError().text() << query.lastQuery();
            }else{
                qDebug() << "Fetch was successful";}
                query.next();
                 int day=query.value(5).toInt();
                  int total=day*price;
                   ui->money->setText(QString::number(total));
       query.clear();
         query.prepare("update management set total_amount='"+QString::number(total)+"' where idroom='"+QString::number(index)+"'");
          if(!query.exec()){
                 qDebug() << query.lastError().text() << query.lastQuery();
             }else{
                 qDebug() << "Fetch was successful";}
       conn.connclose();
}


void checkout::on_pay_clicked()
{   pay->show();
    int index=ui->cmbRoomList->currentText().toInt();
       conn.connOpen();
       QSqlQuery query;
         query.prepare("update management set note='Đã thanh toán' where idroom='"+QString::number(index)+"'");
         if(!query.exec()){
                qDebug() << query.lastError().text() << query.lastQuery();
            }else{
                qDebug() << "Fetch was successful";
                conn.connclose();
         }

}

