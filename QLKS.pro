    QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
TARGET = Sqlite_DB
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    checkin.cpp \
    checkout.cpp \
    database.cpp \
    employee.cpp \
    guest.cpp \
    hotel.cpp \
    listguest.cpp \
    main.cpp \
    mainwindow.cpp \
    payamount.cpp \
    room.cpp \
    secmain.cpp

HEADERS += \
    checkin.h \
    checkout.h \
    database.h \
    employee.h \
    guest.h \
    hotel.h \
    listguest.h \
    mainwindow.h \
    payamount.h \
    room.h \
    secmain.h

FORMS += \
    checkin.ui \
    checkout.ui \
    employee.ui \
    listguest.ui \
    mainwindow.ui \
    payamount.ui \
    room.ui \
    secmain.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    background.qrc
