#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QMessageBox>
#include <QCheckBox>
#include <QLineEdit>
#include <QTimer>
#include <QDateTime>
#include "database.h"
#include "guest.h"
#include "hotel.h"
#include "qsqlquerymodel.h"
#include "qsqlerror.h"

namespace Ui {
class employee;
}

class employee : public QDialog,public Guest
{
    Q_OBJECT

public:
    explicit employee(QWidget *parent = nullptr);
    ~employee();

private slots:
    void on_receive_clicked();

    void on_exit_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_load_clicked();

    void on_leave_clicked();

    void on_add_clicked();

//    void on_remove_clicked();

    void on_search_clicked();

private:
    Ui::employee *ui;
    employee *epl;
    Database conn;
};

#endif // EMPLOYEE_H
