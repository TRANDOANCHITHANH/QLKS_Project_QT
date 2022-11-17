#ifndef ROOM_H
#define ROOM_H

#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <hotel.h>
#include "database.h"
#include "qsqlquerymodel.h"
namespace Ui {
class room;
}

class room : public QDialog
{
    Q_OBJECT

public:
    explicit room(QWidget *parent = nullptr);
    ~room();
    void readData();
    void setPrice(int price);
    int getPrice();
private slots:
    void on_out_clicked();

    void on_pushButton_clicked();

//    void on_pb101_clicked();

//    void on_pb102_clicked();

//    void on_pb103_clicked();

//    void on_pb104_clicked();

//    void on_pb105_clicked();

//    void on_pb201_clicked();

//    void on_pb202_clicked();

//    void on_pb203_clicked();

//    void on_pb204_clicked();

//    void on_pb205_clicked();

    void on_update_clicked();

    void on_add_clicked();

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::room *ui;
   Database db;
   int idroom;
   QString roomtype;
   QString roomsize;
   int price;
   QString available;
};

#endif // ROOM_H
