#ifndef GUEST_H
#define GUEST_H
#include <QString>

class Guest
{
public:
    Guest();
        QString getName();
        QString getAddress();
        QString getCheckin();
        QString getCheckout();
        QString getDatetime();
        QString getRoomType();
        QString getStatus();
        int getTotalAmount();
        int getPaidAmount();
        int getRoomNo();
        int getID();
       QString getCccd();
       QString getSdt();
        int getDays();
        void setName(QString name);
        void setAddress(QString address);
        void setCheckin(QString checkin);
        void setCheckout(QString checkout);
        void setDatetime(QString datetime);
        void setRoomType(QString room_type);
        void setStatus(QString status);
        void setTotalAmount(int total_amount);
        void setPaidAmount(int paid_amount);
        void setRoomNo(int room_no);
        void setID(int id);
        void setCccd(QString cccd);
        void setSdt(QString sdt);
        void setDays(int day);
// friend class checkin;
  friend class employee;
    private:
        int id;
        int room_no;
        QString cccd;
        QString sdt;
        int day;
        QString name;
        QString address;
        QString checkin;
        QString checkout;
        QString identity;
        QString room_type;
        QString datetime;
        int total_amount;
        int paid_amount;
        int due_amount;
        QString status;
};

#endif // GUEST_H
