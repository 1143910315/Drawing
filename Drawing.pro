#-------------------------------------------------
#
# Project created by QtCreator 2018-04-02T16:04:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Drawing
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    customView/graphicsview.cpp \
    customView/selectablelistview.cpp \
    listModel/paintinglistmodel.cpp \
    model/globalmodel.cpp \
    model/rectmodel.cpp \
    model/voidmodel.cpp \
    main.cpp \
    mainwindow.cpp \
    listModel/datalistmodel.cpp \
    model/linemodel.cpp \
    model/circlemodel.cpp


HEADERS += \
    customView/graphicsview.h \
    customView/selectablelistview.h \
    listModel/paintinglistmodel.h \
    model/globalmodel.h \
    model/paintingmodel.h \
    model/rectmodel.h \
    model/voidmodel.h \
    mainwindow.h \
    listModel/datalistmodel.h \
    model/linemodel.h \
    model/circlemodel.h


FORMS += \
        mainwindow.ui
