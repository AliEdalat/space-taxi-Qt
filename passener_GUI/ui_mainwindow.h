/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QScrollArea>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *gridLayoutWidget_5;
    QGridLayout *gridLayout_5;
    QLabel *label_7;
    QLabel *label_10;
    QLineEdit *source_planet;
    QLineEdit *source_galaxy;
    QLabel *label_11;
    QWidget *gridLayoutWidget_6;
    QGridLayout *gridLayout_6;
    QVBoxLayout *verticalLayout_2;
    QPushButton *add_dest;
    QPushButton *remove_dest;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_9;
    QLabel *label_13;
    QLineEdit *d_galaxy;
    QLabel *label_12;
    QLineEdit *d_planet;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_8;
    QRadioButton *VIP_trip;
    QRadioButton *regular_trip;
    QPushButton *request_trip;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPlainTextEdit *Text;
    QWidget *gridLayoutWidget_9;
    QGridLayout *gridLayout_9;
    QLabel *trip_distance;
    QLabel *trip_cost;
    QWidget *tab_3;
    QWidget *gridLayoutWidget_7;
    QGridLayout *gridLayout_7;
    QVBoxLayout *verticalLayout_3;
    QPushButton *Trip_status;
    QPushButton *cancel_trip;
    QLineEdit *driver_rate;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QPlainTextEdit *status_text;
    QPushButton *rate_driver;
    QLabel *label_14;
    QWidget *tab_2;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QLineEdit *add_to_credit;
    QLabel *label_6;
    QPushButton *charge;
    QWidget *tab_4;
    QWidget *gridLayoutWidget_8;
    QGridLayout *gridLayout_8;
    QPushButton *getcode;
    QScrollArea *scrollArea_3;
    QWidget *scrollAreaWidgetContents_3;
    QPlainTextEdit *code_text;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridLayout_4;
    QLabel *Username_label;
    QLabel *credit_label;
    QLabel *Date_Time_label;
    QPushButton *pushButton_6;
    QWidget *widget_3;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *register_username;
    QLabel *label_4;
    QLabel *label_3;
    QLineEdit *register_phonenumber;
    QLabel *label_5;
    QLineEdit *register_password;
    QPushButton *register_button;
    QPushButton *Back_register;
    QLabel *label_15;
    QLineEdit *register_discount_code;
    QWidget *widget_2;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton;
    QLabel *label_2;
    QLabel *label;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(749, 448);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/newPrefix/index.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(40, 0, 691, 411));
        tabWidget = new QTabWidget(widget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 30, 571, 341));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayoutWidget_5 = new QWidget(tab);
        gridLayoutWidget_5->setObjectName(QString::fromUtf8("gridLayoutWidget_5"));
        gridLayoutWidget_5->setGeometry(QRect(10, 40, 551, 31));
        gridLayout_5 = new QGridLayout(gridLayoutWidget_5);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(gridLayoutWidget_5);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_5->addWidget(label_7, 0, 0, 1, 1);

        label_10 = new QLabel(gridLayoutWidget_5);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_5->addWidget(label_10, 0, 1, 1, 1);

        source_planet = new QLineEdit(gridLayoutWidget_5);
        source_planet->setObjectName(QString::fromUtf8("source_planet"));

        gridLayout_5->addWidget(source_planet, 0, 4, 1, 1);

        source_galaxy = new QLineEdit(gridLayoutWidget_5);
        source_galaxy->setObjectName(QString::fromUtf8("source_galaxy"));

        gridLayout_5->addWidget(source_galaxy, 0, 2, 1, 1);

        label_11 = new QLabel(gridLayoutWidget_5);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_5->addWidget(label_11, 0, 3, 1, 1);

        gridLayoutWidget_6 = new QWidget(tab);
        gridLayoutWidget_6->setObjectName(QString::fromUtf8("gridLayoutWidget_6"));
        gridLayoutWidget_6->setGeometry(QRect(10, 80, 551, 231));
        gridLayout_6 = new QGridLayout(gridLayoutWidget_6);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        add_dest = new QPushButton(gridLayoutWidget_6);
        add_dest->setObjectName(QString::fromUtf8("add_dest"));

        verticalLayout_2->addWidget(add_dest);

        remove_dest = new QPushButton(gridLayoutWidget_6);
        remove_dest->setObjectName(QString::fromUtf8("remove_dest"));

        verticalLayout_2->addWidget(remove_dest);


        gridLayout_6->addLayout(verticalLayout_2, 1, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_9 = new QLabel(gridLayoutWidget_6);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_3->addWidget(label_9);

        label_13 = new QLabel(gridLayoutWidget_6);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_3->addWidget(label_13);

        d_galaxy = new QLineEdit(gridLayoutWidget_6);
        d_galaxy->setObjectName(QString::fromUtf8("d_galaxy"));

        horizontalLayout_3->addWidget(d_galaxy);

        label_12 = new QLabel(gridLayoutWidget_6);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_3->addWidget(label_12);

        d_planet = new QLineEdit(gridLayoutWidget_6);
        d_planet->setObjectName(QString::fromUtf8("d_planet"));

        horizontalLayout_3->addWidget(d_planet);


        gridLayout_6->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_8 = new QLabel(gridLayoutWidget_6);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_2->addWidget(label_8);

        VIP_trip = new QRadioButton(gridLayoutWidget_6);
        VIP_trip->setObjectName(QString::fromUtf8("VIP_trip"));

        horizontalLayout_2->addWidget(VIP_trip);

        regular_trip = new QRadioButton(gridLayoutWidget_6);
        regular_trip->setObjectName(QString::fromUtf8("regular_trip"));

        horizontalLayout_2->addWidget(regular_trip);


        gridLayout_6->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        request_trip = new QPushButton(gridLayoutWidget_6);
        request_trip->setObjectName(QString::fromUtf8("request_trip"));

        gridLayout_6->addWidget(request_trip, 3, 0, 1, 1);

        scrollArea = new QScrollArea(gridLayoutWidget_6);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 426, 136));
        Text = new QPlainTextEdit(scrollAreaWidgetContents);
        Text->setObjectName(QString::fromUtf8("Text"));
        Text->setGeometry(QRect(0, 0, 431, 141));
        Text->setReadOnly(true);
        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_6->addWidget(scrollArea, 1, 0, 1, 1);

        gridLayoutWidget_9 = new QWidget(tab);
        gridLayoutWidget_9->setObjectName(QString::fromUtf8("gridLayoutWidget_9"));
        gridLayoutWidget_9->setGeometry(QRect(60, 10, 391, 21));
        gridLayout_9 = new QGridLayout(gridLayoutWidget_9);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_9->setContentsMargins(0, 0, 0, 0);
        trip_distance = new QLabel(gridLayoutWidget_9);
        trip_distance->setObjectName(QString::fromUtf8("trip_distance"));

        gridLayout_9->addWidget(trip_distance, 0, 0, 1, 1);

        trip_cost = new QLabel(gridLayoutWidget_9);
        trip_cost->setObjectName(QString::fromUtf8("trip_cost"));

        gridLayout_9->addWidget(trip_cost, 0, 1, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayoutWidget_7 = new QWidget(tab_3);
        gridLayoutWidget_7->setObjectName(QString::fromUtf8("gridLayoutWidget_7"));
        gridLayoutWidget_7->setGeometry(QRect(70, 40, 391, 161));
        gridLayout_7 = new QGridLayout(gridLayoutWidget_7);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        Trip_status = new QPushButton(gridLayoutWidget_7);
        Trip_status->setObjectName(QString::fromUtf8("Trip_status"));

        verticalLayout_3->addWidget(Trip_status);

        cancel_trip = new QPushButton(gridLayoutWidget_7);
        cancel_trip->setObjectName(QString::fromUtf8("cancel_trip"));

        verticalLayout_3->addWidget(cancel_trip);


        gridLayout_7->addLayout(verticalLayout_3, 1, 2, 1, 1);

        driver_rate = new QLineEdit(gridLayoutWidget_7);
        driver_rate->setObjectName(QString::fromUtf8("driver_rate"));

        gridLayout_7->addWidget(driver_rate, 2, 1, 1, 1);

        scrollArea_2 = new QScrollArea(gridLayoutWidget_7);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 214, 125));
        status_text = new QPlainTextEdit(scrollAreaWidgetContents_2);
        status_text->setObjectName(QString::fromUtf8("status_text"));
        status_text->setGeometry(QRect(0, 0, 241, 161));
        status_text->setReadOnly(true);
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        gridLayout_7->addWidget(scrollArea_2, 1, 1, 1, 1);

        rate_driver = new QPushButton(gridLayoutWidget_7);
        rate_driver->setObjectName(QString::fromUtf8("rate_driver"));

        gridLayout_7->addWidget(rate_driver, 2, 2, 1, 1);

        label_14 = new QLabel(gridLayoutWidget_7);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_7->addWidget(label_14, 2, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayoutWidget_3 = new QWidget(tab_2);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(160, 80, 241, 91));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        add_to_credit = new QLineEdit(gridLayoutWidget_3);
        add_to_credit->setObjectName(QString::fromUtf8("add_to_credit"));

        gridLayout_3->addWidget(add_to_credit, 0, 1, 1, 1);

        label_6 = new QLabel(gridLayoutWidget_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_3->addWidget(label_6, 0, 0, 1, 1);

        charge = new QPushButton(gridLayoutWidget_3);
        charge->setObjectName(QString::fromUtf8("charge"));

        gridLayout_3->addWidget(charge, 1, 1, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        gridLayoutWidget_8 = new QWidget(tab_4);
        gridLayoutWidget_8->setObjectName(QString::fromUtf8("gridLayoutWidget_8"));
        gridLayoutWidget_8->setGeometry(QRect(130, 70, 381, 112));
        gridLayout_8 = new QGridLayout(gridLayoutWidget_8);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        getcode = new QPushButton(gridLayoutWidget_8);
        getcode->setObjectName(QString::fromUtf8("getcode"));

        gridLayout_8->addWidget(getcode, 1, 0, 1, 1);

        scrollArea_3 = new QScrollArea(gridLayoutWidget_8);
        scrollArea_3->setObjectName(QString::fromUtf8("scrollArea_3"));
        scrollArea_3->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 377, 76));
        code_text = new QPlainTextEdit(scrollAreaWidgetContents_3);
        code_text->setObjectName(QString::fromUtf8("code_text"));
        code_text->setGeometry(QRect(3, 0, 371, 78));
        code_text->setReadOnly(true);
        scrollArea_3->setWidget(scrollAreaWidgetContents_3);

        gridLayout_8->addWidget(scrollArea_3, 0, 0, 1, 1);

        tabWidget->addTab(tab_4, QString());
        gridLayoutWidget_4 = new QWidget(widget);
        gridLayoutWidget_4->setObjectName(QString::fromUtf8("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(10, 0, 571, 31));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_4);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        Username_label = new QLabel(gridLayoutWidget_4);
        Username_label->setObjectName(QString::fromUtf8("Username_label"));

        gridLayout_4->addWidget(Username_label, 0, 0, 1, 1);

        credit_label = new QLabel(gridLayoutWidget_4);
        credit_label->setObjectName(QString::fromUtf8("credit_label"));

        gridLayout_4->addWidget(credit_label, 0, 1, 1, 1);

        Date_Time_label = new QLabel(gridLayoutWidget_4);
        Date_Time_label->setObjectName(QString::fromUtf8("Date_Time_label"));

        gridLayout_4->addWidget(Date_Time_label, 0, 2, 1, 1);

        pushButton_6 = new QPushButton(widget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(500, 370, 88, 27));
        widget_3 = new QWidget(centralWidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(140, 20, 451, 271));
        gridLayoutWidget = new QWidget(widget_3);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(40, 70, 381, 177));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        register_username = new QLineEdit(gridLayoutWidget);
        register_username->setObjectName(QString::fromUtf8("register_username"));

        gridLayout->addWidget(register_username, 0, 1, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        register_phonenumber = new QLineEdit(gridLayoutWidget);
        register_phonenumber->setObjectName(QString::fromUtf8("register_phonenumber"));

        gridLayout->addWidget(register_phonenumber, 1, 1, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        register_password = new QLineEdit(gridLayoutWidget);
        register_password->setObjectName(QString::fromUtf8("register_password"));

        gridLayout->addWidget(register_password, 2, 1, 1, 1);

        register_button = new QPushButton(gridLayoutWidget);
        register_button->setObjectName(QString::fromUtf8("register_button"));

        gridLayout->addWidget(register_button, 4, 1, 1, 1);

        Back_register = new QPushButton(gridLayoutWidget);
        Back_register->setObjectName(QString::fromUtf8("Back_register"));

        gridLayout->addWidget(Back_register, 5, 1, 1, 1);

        label_15 = new QLabel(gridLayoutWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout->addWidget(label_15, 3, 0, 1, 1);

        register_discount_code = new QLineEdit(gridLayoutWidget);
        register_discount_code->setObjectName(QString::fromUtf8("register_discount_code"));

        gridLayout->addWidget(register_discount_code, 3, 1, 1, 1);

        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(20, 80, 731, 301));
        gridLayoutWidget_2 = new QWidget(widget_2);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(80, 50, 331, 191));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(gridLayoutWidget_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_2->addWidget(pushButton, 2, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        label = new QLabel(gridLayoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 1, 0, 1, 1);

        pushButton_2 = new QPushButton(gridLayoutWidget_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout_2->addWidget(pushButton_2, 3, 1, 1, 1);

        lineEdit = new QLineEdit(gridLayoutWidget_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout_2->addWidget(lineEdit, 0, 1, 1, 1);

        lineEdit_2 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout_2->addWidget(lineEdit_2, 1, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 749, 22));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "passenger", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Source : ", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "Galaxy : ", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "Planet : ", 0, QApplication::UnicodeUTF8));
        add_dest->setText(QApplication::translate("MainWindow", "Add Destination", 0, QApplication::UnicodeUTF8));
        remove_dest->setText(QApplication::translate("MainWindow", "Remove ", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "Destination : ", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "Galaxy : ", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "Planet : ", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "Trip Type : ", 0, QApplication::UnicodeUTF8));
        VIP_trip->setText(QApplication::translate("MainWindow", "VIP", 0, QApplication::UnicodeUTF8));
        regular_trip->setText(QApplication::translate("MainWindow", "Regular", 0, QApplication::UnicodeUTF8));
        request_trip->setText(QApplication::translate("MainWindow", "Request Trip", 0, QApplication::UnicodeUTF8));
        trip_distance->setText(QApplication::translate("MainWindow", "Distance : ", 0, QApplication::UnicodeUTF8));
        trip_cost->setText(QApplication::translate("MainWindow", "Cost : ", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Request Trip", 0, QApplication::UnicodeUTF8));
        Trip_status->setText(QApplication::translate("MainWindow", "Trip Status", 0, QApplication::UnicodeUTF8));
        cancel_trip->setText(QApplication::translate("MainWindow", "Cancel Trip", 0, QApplication::UnicodeUTF8));
        rate_driver->setText(QApplication::translate("MainWindow", "Rate Driver", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindow", "Driver Rate : ", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Manage Trip", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Add to credit :", 0, QApplication::UnicodeUTF8));
        charge->setText(QApplication::translate("MainWindow", "charge", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Charge Account", 0, QApplication::UnicodeUTF8));
        getcode->setText(QApplication::translate("MainWindow", "Get Discount Code", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Discount Code", 0, QApplication::UnicodeUTF8));
        Username_label->setText(QApplication::translate("MainWindow", "User : ", 0, QApplication::UnicodeUTF8));
        credit_label->setText(QApplication::translate("MainWindow", "Credit : ", 0, QApplication::UnicodeUTF8));
        Date_Time_label->setText(QApplication::translate("MainWindow", "Date_Time : ", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("MainWindow", "Logout", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Phone Number :", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Username :", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Password :", 0, QApplication::UnicodeUTF8));
        register_button->setText(QApplication::translate("MainWindow", "Register", 0, QApplication::UnicodeUTF8));
        Back_register->setText(QApplication::translate("MainWindow", "Back", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MainWindow", "Discount Code : ", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "login", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Username :", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Password :", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", "register", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
