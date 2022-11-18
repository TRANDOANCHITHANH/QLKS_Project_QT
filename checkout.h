#ifndef CHECKOUT_H
#define CHECKOUT_H

#include <QDialog>
#include <QMessageBox>
#include "hotel.h"
#include "database.h"
#include "guest.h"
#include "payamount.h"
namespace Ui {
class checkout;
}

class checkout : public QDialog
{
    Q_OBJECT

public:
    explicit checkout(QWidget *parent = nullptr);
    ~checkout();
         void readData();
private slots:
    void on_checkout_2_clicked();

    void on_pushButton_2_clicked();

    void on_cmbRoomList_currentIndexChanged(int index);

    void on_pushButton_clicked();

    void on_pay_clicked();

private:
    Ui::checkout *ui;
    Database conn;
    Guest *guest;
    payamount *pay;
};

#endif // CHECKOUT_H
