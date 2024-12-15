QT       += core gui
QT       += sql
OUTPUT   += Console

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    adminwindow.cpp \
    createkormushechkaform.cpp \
    createuserform.cpp \
    kormushka.cpp \
    kormushkadb.cpp \
    main.cpp \
    mainwindow.cpp \
    user.cpp \
    userwindow.cpp

HEADERS += \
    admin.h \
    adminwindow.h \
    createkormushechkaform.h \
    createuserform.h \
    kormushka.h \
    kormushkadb.h \
    mainwindow.h \
    user.h \
    userwindow.h

FORMS += \
    adminwindow.ui \
    createkormushechkaform.ui \
    createuserform.ui \
    mainwindow.ui \
    userwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
