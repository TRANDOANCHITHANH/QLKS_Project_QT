#ifndef SECMAIN_H
#define SECMAIN_H

#include <QDialog>
//#include "qlistwidget.h"
#include "checkin.h"
#include "checkout.h"
#include "room.h"
#include "listguest.h"
#include "employee.h"
#include "hotel.h"
namespace Ui {
class secmain;
}

class secmain : public QDialog
{
    Q_OBJECT
    checkin *ptrcheckin;
    checkout *ptrcheckout;
    room *ptrroom;
    listguest *ptrlist;
    employee *ptrepl;
    hotel *ptrht;
public:
    explicit secmain(QWidget *parent = nullptr);
    ~secmain();

private slots:
    void showtime();
    void on_checkin_clicked();

    void on_availableroom_clicked();

    void on_checkout_clicked();

    void on_history_clicked();


    void on_introduce_clicked();

    void on_viewtotalg_clicked();

    void on_viewtotale_clicked();

    void on_viewtotalr_clicked();

    void on_viewtotalg__clicked();

private:
    Ui::secmain *ui;
};

#endif // SECMAIN_H
