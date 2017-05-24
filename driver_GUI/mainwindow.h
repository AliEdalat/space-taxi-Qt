#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "driver_client.h"

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
    void on_login_button_clicked();

    void on_register_button_clicked();

    void on_register_button_2_clicked();

    void on_back_button_clicked();

    void on_logout_button_clicked();

    void on_show_request_clicked();

    void on_accept_trip_clicked();

    void on_Arrived_clicked();

    void on_end_trip_clicked();

    void on_available_clicked();

    void on_unavailable_clicked();

private:
    void closeEvent (QCloseEvent *event);
    bool is_connection_failed;
    Ui::MainWindow *ui;
    driver_client* client_driver;
};

#endif // MAINWINDOW_H
