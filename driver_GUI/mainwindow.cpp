#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <QMessageBox>
#include <QCloseEvent>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->widget_2->setShown(false);
    ui->widget_3->setShown(false);
    ui->password->setEchoMode(QLineEdit::Password);
    ui->register_pass->setEchoMode(QLineEdit::Password);
    ui->username->setPlaceholderText("Username");
    ui->password->setPlaceholderText("Password");
    ui->register_username->setPlaceholderText("Username");
    ui->register_pass->setPlaceholderText("Password");
    ui->register_model->setPlaceholderText("Spaceship Model");
    ui->register_number->setPlaceholderText("Spaceship Number");
    ui->color->setPlaceholderText("Spaceship Color");
    ui->production_year->setPlaceholderText("Production Year");
    try{
        client_driver = new driver_client("127.0.0.1",1115);
        is_connection_failed = false;
    }catch(NetworkException exception){
        statusBar()->showMessage(QString((exception.get_message()).c_str()));
        ui->widget->setShown(false);
        is_connection_failed = true;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent (QCloseEvent *event)
{
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, "Driver Window",
                                                                tr("Are you sure you want to exit?\nIf you exit, any information you have entered will be lost.\n"),
                                                                QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
                                                                QMessageBox::Yes);
    if (resBtn != QMessageBox::Yes) {
        event->ignore();
    } else {
        if(client_driver->get_find_username() && ! is_connection_failed){
            client_driver->logout();
        }
        event->accept();
    }
}

void MainWindow::on_login_button_clicked()
{
    string command=string("login ")+(ui->username->text()).toStdString()+" "+(ui->password->text()).toStdString();
    cout<<command<<endl;
    client_driver->do_UI_command(command);
    cout<<client_driver->get_result()<<endl;
    if(client_driver->get_result() == " "){
        //this->hide();
        //workspace_page->showMaximized();
       ui->widget->setShown(false);
       ui->widget_3->setShown(true);
       statusBar()->showMessage(" ");

     }else if(client_driver->get_result() == "you do not have account \"in space taxi system\"!"){
        ui->username->setFocus();
        statusBar()->showMessage(QString((client_driver->get_result()).c_str()));
     }else{
        ui->password->setFocus();
        statusBar()->showMessage(QString((client_driver->get_result()).c_str()));
     }
}

void MainWindow::on_register_button_clicked()
{
    statusBar()->showMessage(" ");
    ui->widget->setShown(false);
    ui->widget_2->setShown(true);
}

void MainWindow::on_register_button_2_clicked()
{
    string command=string("register ")+(ui->register_username->text()).toStdString()+" "+(ui->register_pass->text()).toStdString()+" "+(ui->register_number->text()).toStdString()+" "+(ui->register_model->text()).toStdString()+" "+(ui->production_year->text()).toStdString()+" "+(ui->color->text()).toStdString();
    if(ui->VIP->isChecked()){
        command=command+" VIP";
    }
    cout<<command<<endl;
    client_driver->do_UI_command(command);
    if(client_driver->get_result() == " "){
      //this->hide();
      //workspace_page->showMaximized();
      ui->widget_2->setShown(false);
      ui->widget_3->setShown(true);
      statusBar()->showMessage(" ");

    }else if(client_driver->get_result().find("is not a new username") != -1){
      ui->register_username->setFocus();
      statusBar()->showMessage(QString((client_driver->get_result()).c_str()));

    }else if(client_driver->get_result().find("is not a new spaceship number") != -1){
      ui->register_number->setFocus();
      statusBar()->showMessage(QString((client_driver->get_result()).c_str()));

    }else if(client_driver->get_result().find("is not a valid spaceship model!") != -1){
        ui->register_model->setFocus();
        statusBar()->showMessage(QString((client_driver->get_result()).c_str()));

    }
}

void MainWindow::on_back_button_clicked()
{
    statusBar()->showMessage(" ");
    ui->widget_2->setShown(false);
    ui->widget->setShown(true);
}

void MainWindow::on_logout_button_clicked()
{
    statusBar()->showMessage(" ");
    client_driver->logout();
    ui->username->clear();
    ui->password->clear();
    ui->widget_3->setShown(false);
    ui->widget->setShown(true);
}

void MainWindow::on_show_request_clicked()
{
    string command="show_trip_requests";
    client_driver->do_UI_command(command);
    string temp = client_driver->get_result();
    ui->requests->clear(); // unless you know the editor is empty
    ui->requests->appendPlainText(QString(temp.c_str()));
}

void MainWindow::on_accept_trip_clicked()
{
    string command = string("accept_trip_request ")+ui->passenger_username->text().toStdString();
    client_driver->do_UI_command(command);
    string temp=client_driver->get_result();
    if(temp != " "){
        statusBar()->showMessage(QString(temp.c_str()));
    }
}

void MainWindow::on_Arrived_clicked()
{

}

void MainWindow::on_end_trip_clicked()
{

}

void MainWindow::on_available_clicked()
{
    string command = string("set_status available ")+ui->status_galaxy->text().toStdString()+","+ui->status_planet->text().toStdString();
    client_driver->do_UI_command(command);
    string temp=client_driver->get_result();
    if(temp != " "){
        statusBar()->showMessage(QString(temp.c_str()));
    }
}

void MainWindow::on_unavailable_clicked()
{

}
