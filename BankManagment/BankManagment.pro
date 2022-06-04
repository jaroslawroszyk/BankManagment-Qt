QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    LoginWindow.cpp \
    menu.cpp

HEADERS += \
    LoginWindow.h \
    menu.h

FORMS += \
    LoginWindow.ui \
    Menu.ui

RESOURCES += \
    Resource.qrc
# Default rules for deployment.
qnx: target.path = /BankManagment/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
