#ifndef LISTGUEST_H
#define LISTGUEST_H

#include <QDialog>
#include "database.h"
#include "qsqlquerymodel.h"
#include "qsqlerror.h"
#include "iostream"
#include "string.h"
#include <QMessageBox>
namespace Ui {
class listguest;
}

class listguest : public QDialog
{
    Q_OBJECT

public:
    explicit listguest(QWidget *parent = nullptr);
    ~listguest();

private slots:
    void on_load_clicked();

    void on_save_clicked();

    void on_exit_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_update_clicked();

    void on_remove_clicked();

private:
    Ui::listguest *ui;
    Database conn;
};

#endif // LISTGUEST_H
