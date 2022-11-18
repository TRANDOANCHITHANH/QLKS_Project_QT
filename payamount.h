#ifndef PAYAMOUNT_H
#define PAYAMOUNT_H

#include <QDialog>
#include <QMessageBox>
namespace Ui {
class payamount;
}

class payamount : public QDialog
{
    Q_OBJECT

public:
    explicit payamount(QWidget *parent = nullptr);
    ~payamount();

private slots:
    void on_pushButton_clicked();

private:
    Ui::payamount *ui;
};

#endif // PAYAMOUNT_H
