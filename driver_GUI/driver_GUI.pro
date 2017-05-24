#-------------------------------------------------
#
# Project created by QtCreator 2017-05-22T19:47:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = driver_GUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    client_socket.cpp \
    command.cpp \
    driver_client.cpp \
    invalid_command.cpp \
    tools.cpp

HEADERS  += mainwindow.h \
    client_socket.h \
    command.h \
    driver_client.h \
    invalid_command.h \
    network_exception.h \
    tools.h

FORMS    += mainwindow.ui
