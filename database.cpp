#include "database.h"

Database::Database()
{

}

bool Database::connOpen(){

    mydb=QSqlDatabase::addDatabase("QSQLITE");
   mydb.setDatabaseName("D:/tdcthanh/C++/QLKS/hotel.db");
   if(!mydb.open()){
   qDebug()<<("Failed to open the database");
   return false;
   }else{
        qDebug()<<("Connected...");
       return true;
   }

}
void Database::connclose(){
    mydb.close();
    mydb.removeDatabase(QSqlDatabase::defaultConnection);
}
QSqlDatabase Database::getDB(){
    return mydb;
}

//bool Database::payAmount(int amount, int id){
//    QSqlQuery query;
//    int ta, pa, da;
//    query.prepare("SELECT * FROM guests WHERE id=:id");
//    query.bindValue(":id",id);
//    if(query.exec()){
//        query.next();
//        ta = query.value(10).toInt();
//        pa = query.value(11).toInt();
//        da = query.value(12).toInt();

//        int possible = pa+amount;
//        if(possible > ta){
//            return false;
//        }else{
//            int npa = pa+amount;
//            int nda = da-amount;
//            query.prepare("UPDATE guests SET paid_amount=:npa,due_amount=:nda WHERE id=:id");
//            query.bindValue(":npa",npa);
//            query.bindValue(":nda",nda);
//            query.bindValue(":id",id);
//            if(query.exec()){
//                return true;
//            }else{
//                return false;
//            }
//        }
//    }else{
//        return false;
//    }
//}
