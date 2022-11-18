#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "secmain.h"
#include "ui_mainwindow.h"
#include "database.h"
#include<QMessageBox>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    secmain *ptrsecmain;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_login_clicked();

    void on_exit_clicked();

private:
    Ui::MainWindow *ui;
    Database login;
};
#endif // MAINWINDOW_H
