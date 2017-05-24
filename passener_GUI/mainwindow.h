#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QLineEdit>
#include <QComboBox>
#include <QGridLayout>
#include <string>
#include "passenger_client.h"
#include <QString>
#include <cstdlib>
#include <QCloseEvent>
#include <QMessageBox>
#include <vector>
#include <QLineEdit>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QPlainTextEdit>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QRadioButton>
//#include "passenger_workspace.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_register_button_clicked();

    void on_Back_register_clicked();

    void on_pushButton_6_clicked();

    void on_add_dest_clicked();

    void on_remove_dest_clicked();

    void on_request_trip_clicked();

    void on_getcode_clicked();

    void on_charge_clicked();

    void on_Trip_status_clicked();

    void on_rate_driver_clicked();

    void on_cancel_trip_clicked();
    void handle_estimate_command();

private:
    //void handle_estimate_command(bool is_vip);
    void closeEvent (QCloseEvent *event);
    bool is_connection_failed;
    Ui::MainWindow *ui;
    passenger_client *client_passenger;
    std::vector<std::string> destinations;
};

#endif // MAINWINDOW_H
