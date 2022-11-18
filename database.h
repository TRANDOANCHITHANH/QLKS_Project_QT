#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <string>
#include <QDateTime>
#include <QVariant>
class Database
{
public:
    Database();
private:
    QSqlDatabase mydb;
public:
    bool connOpen();
    void connclose();
    QSqlDatabase getDB();
    void addPackages(QString name, QString company, QString details, int price, bool available);
    bool removePackages(int id);
    void makeAvailable(int id);
    void makeUnavailable(int id);
    bool guestCheckOut(int id, int id2);
    bool payAmount(int amount, int id);
    bool isCheckOutAble(int id);
    bool loginUser(QString email,QString password);
};

#endif // DATABASE_H
