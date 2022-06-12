QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/Menu.cpp \
    src/OpenAccount.cpp \
    src/main.cpp \
    src/LoginWindow.cpp \
    src/Account.cpp

HEADERS += \
    include/LoginWindow.h \
    include/Menu.h \
    include/OpenAccount.h\
    include/Account.h

FORMS += \
    Ui/LoginWindow.ui \
    Ui/LoginWindow.ui \
    Ui/Menu.ui \
    Ui/OpenAccount.ui

RESOURCES += \
    Resource.qrc

DESTDIR = $$PWD
# Default rules for deployment.
qnx: target.path = /BankManagment/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
