#ifndef CHECKIN_H
#define CHECKIN_H
#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QMessageBox>
#include <QCheckBox>
#include <QLineEdit>
#include <QTimer>
#include <QDateTime>
#include "database.h"
#include "guest.h"
#include "hotel.h"
namespace Ui {
class checkin;
}

class checkin : public QDialog,public Guest
{
    Q_OBJECT
public:
    explicit checkin(QWidget *parent = nullptr);
    ~checkin();
    void readData();
    bool check();
private slots:
    void on_submit_clicked();

    void on_cancel_clicked();
    void showtime();
    void on_clear_clicked();

private:
    Ui::checkin *ui;
    Guest *guest;
//    QString name, diachi;
//    int id,cccd,sdt,maphong;
    Database conn;
};

#endif // CHECKIN_H

