#include "secmain.h"
#include "ui_secmain.h"
secmain::secmain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secmain)
{
    ui->setupUi(this);
    this->setWindowTitle("HOTEL MANAGEMENT SYSTEM");
    ptrcheckin=new checkin(this);
    ptrcheckout=new checkout(this);
    ptrroom=new room(this);
    ptrlist=new listguest(this);
    ptrepl=new employee(this);
    ptrht=new hotel();
    //display datetime
    QTimer *timer=new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(showtime()));
    timer->start(1000);
    QDate date=QDate::currentDate();
    QString datetext=date.toString();
    ui->date->setText(datetext);
}
secmain::~secmain()
{
    delete ui;
    delete ptrcheckin;
    delete ptrcheckout;
    delete ptrroom;
    delete ptrlist;
    delete ptrepl;
    delete ptrht;
}

void secmain::on_checkin_clicked()
{  ptrcheckin->readData();
   ptrcheckin->show();
}
void secmain::on_availableroom_clicked()
{  ptrroom->readData();
   ptrroom->show();
}


void secmain::on_checkout_clicked()
{
    ptrcheckout->readData();
   ptrcheckout->show();
}


void secmain::on_history_clicked()
{
   ptrlist->show();
}

void secmain::on_introduce_clicked()
{
  ptrepl->show();
}
void secmain::showtime(){
    QTime time=QTime::currentTime();
    QString time_text=time.toString("hh : mm : ss");
    ui->time->setText(time_text);
}


void secmain::on_viewtotalg_clicked()
{
    int count=ptrht->getTotalGuest().toInt();
    ui->total_guest->setText(QString::number(count));
}


void secmain::on_viewtotale_clicked()
{
//    int count_e=ptrht->getTotalEpl().toInt();
//    ui->total_epl->setText(QString::number(count_e));
}


void secmain::on_viewtotalr_clicked()
{
    int count_r=ptrht->getTotalRoom().toInt();
    ui->total_room->setText(QString::number(count_r));
}


void secmain::on_viewtotalg__clicked()
{
    long long count_p=ptrht->getTotalPay().toInt();
    ui->total_pay->setText(QString::number(count_p));
}

