#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ptrsecmain =new secmain(this);
    this->setWindowTitle("HOTEL MANAGEMENT SYSTEM");
     ui->password->setEchoMode(QLineEdit::Password);
    if(!login.connOpen()){
    ui->label_5->setText("Failed to open the database");
    }else{
        ui->label_5->setText("Connectting...");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete ptrsecmain;
}


void MainWindow::on_login_clicked()
{
   QString user_name=ui->username->text();
   QString pass_word=ui->password->text();
   if(user_name.isEmpty()){
     ui->errorAcc->setText("*Không được để trống !!");
   }
   if(pass_word.isEmpty()){
    ui->label_4->setText("*Không được để trống !!");
   }
   if(!login.connOpen()){
       qDebug()<<"Failed to open the database";
       return ;
   }
   login.connOpen();
  QSqlQuery qry;
  qry.prepare("select * from login where username='"+user_name+"'and password='"+pass_word+"'");
  if(qry.exec()){
      int count = 0;
      while(qry.next()){
          count++;
      }
      if(count==1){
          ui->label_5->setText("*username and password is correct");
         login.connclose();
          this->hide();
          ptrsecmain->show();
      }
      if(count>1){
          ui->label_5->setText("*duplicate username and password");
      }
      if(count<1){
          ui->label_5->setText("*username and password is incorrect");
      }
  }

}


void MainWindow::on_exit_clicked()
{
  this->hide();
}

