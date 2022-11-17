#include "room.h"
#include "qsqlquerymodel.h"
#include "ui_room.h"
#include <QLabel>
using namespace std;
room::room(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::room)
{
    ui->setupUi(this);
    this->setWindowTitle("ROOM");
    ui->add->setToolTip("Thêm Phòng");
    ui->out->setToolTip("Thoát");
    ui->update->setToolTip("Cập Nhật");
    ui->pushButton->setToolTip("Xem Dữ Liệu");
}

room::~room()
{
    delete ui;
}
void room::setPrice(int price){
    this->price=price;
}
int room::getPrice(){
    return this->price;
}
void room::on_out_clicked()
{
    this->hide();
}
void room::readData()
{
    qDebug()<<"in readData()";

    vector<int>rooms = hotel::getInstance()->getRoomList("yes");
    ui->lblinfo->setStyleSheet("QLabel { background-color : green; color : white; }");
    ui->label->setStyleSheet("QLabel { background-color : #be1c3f; color : white;}");
    vector<int>temprooms =  {101, 102, 103, 104, 105, 201, 202, 203, 204, 205};

    //set default color to all
    for(vector<int>::iterator it = temprooms.begin(); it!=temprooms.end(); it++ )
    {
        //Put logic to change color of Labels
        QString lblname = "lbl" + QString::number(*it);
        QLabel * ptr = this->findChild<QLabel*>(lblname);

        if(ptr)
        {
            ptr->setStyleSheet("QLabel { background-color : #be1c3f; color : white;border-radius:10px; }");
        }

    }

    for(vector<int>::iterator it = rooms.begin(); it!=rooms.end(); it++ )
    {
        //thay doi background
        QString lblname = "lbl" + QString::number(*it);
        QLabel * ptr = this->findChild<QLabel*>(lblname);

        if(ptr)
        {

            ptr->setStyleSheet("QLabel { background-color : green; color : white; border-radius:10px; }");
        }

    }
}

void room::on_pushButton_clicked()
{
    room conn;
    QSqlQueryModel * modal=new QSqlQueryModel();
    db.connOpen();
    QSqlQuery* query=new QSqlQuery();
    query->prepare("select * from room");
    query->exec();
    modal->setQuery(*query);
    ui->tableView->setModel(modal);
    db.connclose();
    qDebug()<<(modal->rowCount());
}
void room::on_update_clicked()
{
   int roomn=ui->room_no->text().toInt();
   QString rtype=ui->type->text();
   QString rsize=ui->size->text();
   QString rprice=ui->price->text();
   if(!db.connOpen()){
       qDebug() << "Database loaded not successfull!";
   } else{
       qDebug() << "Database loaded successfull!";
     }
   QSqlQuery query;
   query.prepare("update room set idroom='"+QString::number(roomn)+"',roomtype='"+rtype+"',roomsize='"+rsize+"',price='"+rprice+"' where idroom='"+QString::number(roomn)+"'");
   if(query.exec()){
       QMessageBox::information(this,tr("Edit"),tr("UPDATE"));
       db.connclose();
   }else{
       QMessageBox::critical(this,tr("Error::"),query.lastError().text());
   }

}


void room::on_add_clicked()
{
    int room_n=ui->room_no->text().toInt();
    QString rtype=ui->type->text();
    QString rsize=ui->size->text();
    QString rprice=ui->price->text();
    if(!db.connOpen()){
        qDebug() << "Database loaded not successfull!";
    } else{
        qDebug() << "Database loaded successfull!";
      }
    QSqlQuery query;
    query.prepare("insert into room(idroom,roomtype,roomsize,price,available) values('"+QString::number(room_n)+"','"+rtype+"','"+rsize+"','"+rprice+"','yes')");
    if(!query.exec())
        qDebug() << query.lastError().text() << query.lastQuery();
    else
        QMessageBox::information(this,"Information","Thêm Thành Công !! ");
     db.connclose();
}


void room::on_comboBox_currentIndexChanged(int index)
{
    index=ui->comboBox->currentText().toInt();
    if(!db.connOpen()){
        qDebug() << "Database loaded not successfull!";
    } else{
        qDebug() << "Database loaded successfull!";
      }
    QSqlQuery query;
    query.prepare("select * from room where idroom='"+QString::number(index)+"'");
    if(!query.exec()){
        qDebug() << query.lastError().text() << query.lastQuery();
    }else{
        qDebug() << "Fetch was successful";
}

    while(query.next()){
        ui->room_no->setText(query.value(0).toString());
        ui->type->setText(query.value(1).toString());
        ui->size->setText(query.value(2).toString());
        ui->price->setText(query.value(3).toString());
    }
    db.connclose();
}

