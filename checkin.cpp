#include "checkin.h"
#include "ui_checkin.h"
#include <iostream>
using namespace std;
checkin::checkin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::checkin)
{
    ui->setupUi(this);
    this->setWindowTitle("CHECKIN");
    if(!conn.connOpen()){
    ui->label_7->setText("Failed to open the database");
    }else{
        ui->label_7->setText("Connectting...");
    }
    guest=new Guest();
    QTimer *timer=new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(showtime()));
    timer->start(1000);
    QDate date=QDate::currentDate();
    QString datetext=date.toString();
    ui->date->setText(datetext);
}

checkin::~checkin()
{
    delete ui;
}
void checkin:: readData()
{
    qDebug()<<"BookRoomDialog:readData";
    vector<int>rooms = hotel::getInstance()->getRoomList("yes");//lấy id phòng trống

    for(vector<int>::iterator it = rooms.begin(); it!=rooms.end(); it++ )//vòng lặp thêm các id phòng trống vào option
    {
        this->ui->cmbRoomList->addItem(QString::number(*it));
    }
}
//bool checkin::check(){
//    conn.connOpen();
//    int c_id;
//    c_id=ui->id->text().toInt();
//    QSqlQuery qrycheck;
//    qrycheck.prepare("select *from guest where id='"+QString::number(c_id)+"'");
//    if(qrycheck.exec()){
//        while (qrycheck.next()){
//            int idDb;
//            idDb=qrycheck.value(0).toInt();
//           if(c_id==idDb){
//               return false;
//           }
//        }
//    }
//    conn.connclose();
//    return true;
//}
void checkin::on_submit_clicked()
{
        QString phone,cccd,id;
        phone=ui->phone->text();
        cccd=ui->cccd->text();
//        id=ui->id->text();

        bool cccd_check=false,phone_check=false,id_check=false;
        QRegularExpression idrx("^[0-9]{3}$",
                                      QRegularExpression::CaseInsensitiveOption);
        QRegularExpression phonerx("^[0-9]{10}$",
                                      QRegularExpression::CaseInsensitiveOption);
        QRegularExpression cccdrx("^[0-9]{12}$",
                                      QRegularExpression::CaseInsensitiveOption);

//     if(!idrx.match(id).hasMatch()){
//                 QMessageBox::warning(this,"Không Hợp Lệ","SOS ! ID Nhập Vào Gồm 3 Chữ Số!");
//                 cccd_check = true;
//                 return ;
//             }else
   if(ui->name->text()==""){
         QMessageBox::information(this,"Notification","Họ Và Tên Không Được Để Trống !");
          return;
     }else if(!cccdrx.match(cccd).hasMatch()){
         QMessageBox::warning(this,"Không Hợp Lệ","SOS ! Số CCCD Nhập Vào Gồm 12 Chữ Số!");
         cccd_check = true;
         return ;
     } else if(!phonerx.match(phone).hasMatch()){
         QMessageBox::warning(this,"Không Hợp Lệ","SOS ! Số Điện Thoại Nhập Vào Gồm 10 Chữ Số!");
         phone_check = true;
         return ;
     }else if(ui->address->text()==""){
         QMessageBox::information(this,"Notification","Địa Chỉ Không Được Để Trống !");
          return;
     }else if(ui->cmbRoomList->currentText().toInt()==NULL){
         QMessageBox::information(this,"Notification","Mã Phòng Không Được Để Trống !");
          return;
//      }else if(check()==false){
//          QMessageBox::information(this,"ERROR","ID Đã Bị Trùng !");
//           return ;
     }else{
         int ok=QMessageBox::warning(this,"Xác Nhận Thông Tin","Bạn có chắc chắn thông tin nhập vào là chính xác ??",QMessageBox::Yes,QMessageBox::No);
         if(ok==QMessageBox::No){
             return ;
         }else{
             guest->setStatus("in");
//             guest->setID(ui->id->text().toInt());
             guest->setName(ui->name->text());
             guest->setCccd(ui->cccd->text().trimmed());
             guest->setSdt(ui->phone->text().trimmed());
             guest->setAddress(ui->address->text());
             guest->setRoomNo(ui->cmbRoomList->currentText().toInt());
             guest->setDays(ui->days->text().toInt());
             QDateTime datetime=QDateTime::currentDateTime();
             QString datetimetext=datetime.toString();
             guest->setDatetime( datetimetext);
             cccd_check=false;
             phone_check=false;

         }

     int ret = hotel::getInstance()->BookRoom(guest->getName(),guest->getCccd(),guest->getSdt(),guest->getAddress(),guest->getRoomNo(),guest->getDays(),guest->getStatus(),guest->getDatetime());
     QString msg = "";
     ret==0?msg="Success!":"Failure!";

     if(ret == 0)
     {
         QMessageBox::information( this,tr("Success!"), tr("Phòng đã được đặt!") );
     }
  }
     this->hide();
}
void checkin::showtime(){
    QTime time=QTime::currentTime();
    QString time_text=time.toString("hh : mm : ss");
    ui->clock->setText(time_text);
}
void checkin::on_cancel_clicked()
{
    this->hide();

}


void checkin::on_clear_clicked()
{
    ui->name->setText(" ");
    ui->cccd->setText(" ");
    ui->phone->setText(" ");
    ui->address->setText(" ");
    ui->days->setText(" ");
}

