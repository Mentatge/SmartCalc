QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../s21_calc.c \
    ../s21_credit_calc.c \
    ../s21_stack.c \
    ../s21_validator.c \
    ../s21_vklad_calc.c \
    credit_calc.cpp \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp \
    vklad_calc.cpp

HEADERS += \
    ../s21_calc.h \
    credit_calc.h \
    mainwindow.h \
    qcustomplot.h \
    vklad_calc.h

FORMS += \
    credit_calc.ui \
    mainwindow.ui \
    vklad_calc.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../s21_calc.exe

