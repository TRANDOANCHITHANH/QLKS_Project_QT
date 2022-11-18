#include "hotel.h"
using namespace std;
hotel* hotel::instance = nullptr;
hotel::hotel()
{

}
int hotel::BookRoom( QString name,QString cccd,QString sdt, QString address,int room_no,int day,QString status,QString time_in){
    if(!conn.connOpen()){
        qDebug() << "Database loaded not successfull!";
    } else{
        qDebug() << "Database loaded successfull!";
}
    QSqlQuery query;
    query.prepare("update room set available='no' where idroom='"+QString::number(room_no)+"'");
    if(!query.exec())
        qDebug() << query.lastError().text() << query.lastQuery();
    else
        qDebug() << "Update was successful "<< query.lastQuery();
     query.clear();
     status="in";
     query.prepare("insert into guest (name,cccd,sdt,diachi,maphong,days,status,time_in) values ('"+name+"','"+cccd+"','"+sdt+"','"+address+"','"+QString::number(room_no)+"','"+QString::number(day)+"','"+status+"','"+time_in+"')");
     QString sta;
     if(!query.exec())
         qDebug() << query.lastError().text() << query.lastQuery();
     else
     {
         qDebug() << "Update was successful "<< query.lastQuery();
         sta = query.lastInsertId().toString();
         qDebug() <<"Last Inserted Id is  : "<< sta;
     }
     query.clear();
     query.prepare("insert into management (idroom,time_in,name,sdt,cccd,days,total_amount) values ('"+QString::number(room_no)+"','"+time_in+"','"+name+"','"+sdt+"','"+cccd+"','"+QString::number(day)+"',' ')");
     if(!query.exec())
         qDebug() << query.lastError().text() << query.lastQuery();
     else
     {
         qDebug() << "Update was successful "<< query.lastQuery();
     }
     conn.connclose();
     return 0;
}
int hotel::CheckOut(int room_no)
{
    QDateTime datetime=QDateTime::currentDateTime();
    QString datetimetext=datetime.toString();
    qDebug()<<"in CheckOut for room no : " << room_no;
    //**** update DB **********
    if(!conn.connOpen()){
        qDebug() << "Database loaded not successfull!";
    } else{
        qDebug() << "Database loaded successfull!";
}
    QSqlQuery query;
    query.prepare("update room set available ='yes' where idroom='" +QString::number(room_no)+ "'");

    if(!query.exec()){
        qDebug() << query.lastError().text() << query.lastQuery();
    }else{
        qDebug() << "Update was successful "<< query.lastQuery();
     }
        query.clear();
        query.prepare("update guest set status='out' where maphong='"+QString::number(room_no)+"'");
        if(!query.exec())
            qDebug() << query.lastError().text() << query.lastQuery();
        else
            qDebug() << "Update was successful "<< query.lastQuery();
//     query.clear();
     query.prepare("update guest set time_out='"+datetimetext+"'where maphong='"+QString::number(room_no)+"'");
     if(!query.exec())
         qDebug() << query.lastError().text() << query.lastQuery();
     else
         qDebug() << "Update was successful "<< query.lastQuery();
    conn.connclose();
      return 0;
}
//int hotel::Receive(int id,QString name,QString cccd,QString sdt,QString address,QString datetime){
//    if(!conn.connOpen()){
//        qDebug() << "Database loaded not successfull!";
//    } else{
//        qDebug() << "Database loaded successfull!";
//    }
//    QSqlQuery query;
//    query.prepare("insert into employee (id,name,cccd,phone,diachi,time_in) values('"+QString::number(id)+"','"+name+"','"+cccd+"','"+sdt+"','"+address+"','"+datetime+"')");
//    if(!query.exec())
//        qDebug() << query.lastError().text() << query.lastQuery();
//    else
//    {
//        qDebug() << "Update was successful "<< query.lastQuery();
//    }
//    conn.connclose();
//    return 0;
//}
vector<int> hotel::getRoomList(QString flag = "yes")
{
    vector<int> rooms;
    if(!conn.connOpen()){
        qDebug() << "Database loaded not successfull!";
    } else{
        qDebug() << "Database loaded successfull!";
}
    QSqlQuery query;
    query.prepare("select idroom from room where available = '" + flag + "'");
    if(!query.exec())
        qDebug() << query.lastError().text() << query.lastQuery();
    else
        qDebug() << "Fetch was successful";

    while(query.next())
    {
        QString record = query.value(0).toString();
        rooms.push_back(record.toInt());
        qDebug()<<"Line is : "<<record;
    }
   conn.connclose();
    return rooms;

}
QString hotel::getTotalGuest(){
    conn.connOpen();
       QSqlQuery query;
       query.prepare("SELECT COUNT(*) FROM guest");
       if(!query.exec())
           qDebug() << query.lastError().text() << query.lastQuery();
       else
           qDebug() << "IN SECMAIN";

       query.next();
       int lastID = query.value(0).toInt();
       return QString::number(lastID);
           conn.connclose();
}

QString hotel::getTotalRoom(){
    conn.connOpen();
       QSqlQuery query;
       query.prepare("SELECT COUNT(*) FROM room");
       if(!query.exec())
           qDebug() << query.lastError().text() << query.lastQuery();
       else
           qDebug() << "IN SECMAIN";

       query.next();
       int lastID = query.value(0).toInt();
       return QString::number(lastID);
           conn.connclose();
}
QString hotel::getTotalPay(){
    conn.connOpen();
       QSqlQuery query;
       query.prepare("SELECT SUM(total_amount) FROM management");
       if(!query.exec())
           qDebug() << query.lastError().text() << query.lastQuery();
       else
           qDebug() << "IN SECMAIN";

       query.next();
       int lastID = query.value(0).toInt();
       return QString::number(lastID);
           conn.connclose();
}
//Tra ve doi tuong
hotel *hotel::getInstance()
{
    if(instance == nullptr)
        instance = new hotel();
    return instance;
}
