#include "payamount.h"
#include "ui_payamount.h"

payamount::payamount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::payamount)
{
    ui->setupUi(this);
    this->setWindowTitle("BANK");
}

payamount::~payamount()
{
    delete ui;
}

void payamount::on_pushButton_clicked()
{
    if(ui->radioButton->isChecked()){
        QMessageBox::information(this,"Information","Thanh Toán Thành Công !!");
        this->hide();
    }
    if(ui->radioButton_2->isChecked()){
    int ok=QMessageBox::warning(this,"Xác Nhận Thông Tin","Bạn có chắc chắn thông tin nhập vào là chính xác ??",QMessageBox::Yes,QMessageBox::No);
    if(ok==QMessageBox::No){
        return ;
    }else{
    QMessageBox::information(this,"Information","THANH TOÁN THÀNH CÔNG !!");
    this->hide();
    }
}
}
