#include "guest.h"

Guest::Guest()
{

}
QString Guest::getName(){
    return this->name;
}
QString Guest::getAddress(){
    return this->address;
}
QString Guest::getCheckin(){
    return this->checkin;
}
QString Guest::getCheckout(){
    return this->checkout;
}
QString Guest::getDatetime(){
    return this->datetime;
}
QString Guest::getRoomType(){
    return this->room_type;
}
QString Guest::getStatus(){
    return this->status;
}
int Guest::getTotalAmount(){
    return this->total_amount;
}
int Guest::getPaidAmount(){
    return this->paid_amount;
}

int Guest::getID(){
    return this->id;
}

int Guest::getRoomNo(){
    return this->room_no;
}
QString Guest::getCccd(){
    return this->cccd;
}

QString Guest::getSdt(){
    return this->sdt;

}
int Guest::getDays(){
    return this->day;

}
///////////////////////////////////////////////////
/// SETTERS
////////////////////////////////////////////////////
/// /////////////////////////////////////////////////.


void Guest::setName(QString name){
    this->name = name;
}

void Guest::setAddress(QString address){
    this->address = address;
}

void Guest::setCheckin(QString checkin){
    this->checkin = checkin;
}

void Guest::setCheckout(QString checkout){
    this->checkout = checkout;
}

void Guest::setDatetime(QString datetime){
    this->datetime = datetime;
}
void Guest::setRoomType(QString room_type){
    this->room_type = room_type;
}

void Guest::setStatus(QString status){
    this->status = status;
}

void Guest::setTotalAmount(int total_amount){
    this->total_amount = total_amount;
}

void Guest::setPaidAmount(int amt){
    this->paid_amount = amt;
}


void Guest::setID(int id){
    this->id = id;
}

void Guest::setRoomNo(int room_no){
    this->room_no = room_no;
}
void Guest::setCccd(QString cccd){
    this->cccd=cccd;
}
void Guest::setSdt(QString sdt){
    this->sdt=sdt;
}
void Guest::setDays(int day){
    this->day=day;
}
