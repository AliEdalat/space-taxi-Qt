#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIcon>
#include <QLabel>
#include <QGridLayout>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setWindowIcon(QIcon("index.jpeg"));
    setFixedSize(800,500);
    ui->setupUi(this);
    //ui->centralWidget->setStyleSheet("QWidget {background-image: url(./index2.jpeg) }");

    setWindowIcon(QIcon("index.jpeg"));
    ui->widget_3->setShown(false);
    ui->widget->setShown(false);
    ui->lineEdit_2->setEchoMode( QLineEdit::Password );
    ui->lineEdit_2->setPlaceholderText("Password");
    ui->lineEdit->setPlaceholderText("Username");
    ui->register_password->setEchoMode( QLineEdit::Password );
    ui->register_password->setPlaceholderText("Password");
    ui->register_username->setPlaceholderText("Username");
    ui->register_phonenumber->setPlaceholderText("Phone Number");
    ui->register_discount_code->setPlaceholderText("Discount Code");
    ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    connect(ui->source_galaxy, SIGNAL(editingFinished()), this, SLOT(handle_estimate_command()));
    connect(ui->source_planet, SIGNAL(editingFinished()), this, SLOT(handle_estimate_command()));
    connect(ui->VIP_trip, SIGNAL(clicked(bool)), this, SLOT(handle_estimate_command()));
    connect(ui->regular_trip, SIGNAL(clicked(bool)), this, SLOT(handle_estimate_command()));
    try{
        client_passenger=new passenger_client("127.0.0.1" , 1115);
        is_connection_failed = false;
    }catch(NetworkException exception){
        statusBar()->showMessage(QString((exception.get_message()).c_str()));
        ui->widget_2->setShown(false);
        is_connection_failed = true;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent (QCloseEvent *event)
{
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, "Passenger Window",
                                                                tr("Are you sure you want to exit?\nIf you exit, any information you have entered will be lost.\n"),
                                                                QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
                                                                QMessageBox::Yes);
    if (resBtn != QMessageBox::Yes) {
        event->ignore();
    } else {
        if(client_passenger->get_find_username() && ! is_connection_failed){
            client_passenger->logout();
        }
        event->accept();
    }
}


void MainWindow::on_pushButton_clicked()
{
    string command=string("login ")+(ui->lineEdit->text()).toStdString()+" "+(ui->lineEdit_2->text()).toStdString();
        cout<<command<<endl;
        client_passenger->do_UI_command(command);
        if(client_passenger->get_result() == " "){
            //this->hide();
            //workspace_page->showMaximized();
            ui->widget_2->setShown(false);
            ui->widget->setShown(true);
            statusBar()->showMessage(" ");
            ui->Username_label->setText(QString((string("Username : ")+client_passenger->get_username()).c_str()));
            ui->credit_label->setText(QString((string("Credit : ")+client_passenger->get_credit()).c_str()));
            ui->Date_Time_label->setText(QString((string("Date_Time : ")+client_passenger->get_date_time()).c_str()));

        }else if(client_passenger->get_result() == "you do not have account \"in space taxi system\"!"){
            ui->lineEdit->setFocus();
            statusBar()->showMessage(QString((client_passenger->get_result()).c_str()));
        }else{
            ui->lineEdit_2->setFocus();
            statusBar()->showMessage(QString((client_passenger->get_result()).c_str()));
        }
}

void MainWindow::on_pushButton_2_clicked()
{
	statusBar()->showMessage(" ");
    ui->widget_2->setShown(false);
    ui->widget_3->setShown(true);


}

void MainWindow::on_register_button_clicked()
{
    string command=string("register ")+(ui->register_username->text()).toStdString()+" "+(ui->register_password->text()).toStdString()+" "+(ui->register_phonenumber->text()).toStdString();
    if(! ui->register_discount_code->text().isEmpty()){
        cout<<"AA"<<endl;
        command=command+" "+(ui->register_discount_code->text()).toStdString();
    }
    cout<<command<<endl;
        client_passenger->do_UI_command(command);
        if(client_passenger->get_result() == " "){
            //this->hide();
            //workspace_page->showMaximized();
            ui->widget_3->setShown(false);
            ui->widget->setShown(true);
            statusBar()->showMessage(" ");
            ui->Username_label->setText(QString((string("Username : ")+client_passenger->get_username()).c_str()));
            ui->credit_label->setText(QString((string("Credit : ")+client_passenger->get_credit()).c_str()));
            ui->Date_Time_label->setText(QString((string("Date_Time : ")+client_passenger->get_date_time()).c_str()));

        }else if(client_passenger->get_result().find("is not a new username") != -1){
            ui->register_username->setFocus();
            statusBar()->showMessage(QString((client_passenger->get_result()).c_str()));

        }else{
            ui->register_phonenumber->setFocus();
            statusBar()->showMessage(QString((client_passenger->get_result()).c_str()));

        }
}

void MainWindow::on_Back_register_clicked()
{
	statusBar()->showMessage(" ");
    ui->widget_3->setShown(false);
    ui->widget_2->setShown(true);
}

void MainWindow::on_pushButton_6_clicked()
{
    statusBar()->showMessage(" ");
    client_passenger->logout();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->widget->setShown(false);
    ui->widget_2->setShown(true);
    ui->add_to_credit->clear();
    ui->code_text->clear();
    ui->driver_rate->clear();
    ui->d_galaxy->clear();
    ui->d_planet->clear();
    ui->register_discount_code->clear();
    ui->register_password->clear();
    ui->register_phonenumber->clear();
    ui->register_username->clear();
    ui->source_galaxy->clear();
    ui->source_planet->clear();
    ui->status_text->clear();
    ui->Text->clear();
    ui->VIP_trip->setAutoExclusive(false);
    ui->VIP_trip->setChecked(false);
    ui->regular_trip->setAutoExclusive(false);
    ui->regular_trip->setChecked(false);
    ui->trip_cost->setText("Cost : ");
    ui->trip_distance->setText("Distance : ");
}

bool is_number(string result);

void MainWindow::handle_estimate_command(){
    if(destinations.size() >= 1){
        string source_ad=(ui->source_galaxy->text()).toStdString()+","+(ui->source_planet->text()).toStdString();
        if(ui->VIP_trip->isChecked() == false){
            string temp=string("estimate_trip ")+source_ad;
            for(int i=0 ; i < destinations.size() ; i++){
                temp=temp+" "+destinations[i];
            }
            client_passenger->do_UI_command(temp);
            string result=client_passenger->get_result();
            if(!is_number(result)){
                statusBar()->showMessage(QString(result.c_str()));
                ui->trip_cost->setText("Cost : 0");
                ui->trip_distance->setText("Distance : 0");
                ui->Text->clear();
            }else{
                int find=result.find(' ');
                ui->trip_cost->setText(QString((string("Cost : ")+result.substr(0,find)).c_str()));
                ui->trip_distance->setText(QString((string("Distance : ")+result.substr(find+1)).c_str()));
                int found=temp.find(' ');
                temp=temp.substr(found+1);
                ui->Text->clear(); // unless you know the editor is empty
                ui->Text->appendPlainText(QString(temp.c_str()));
            }

        }else{
            string temp=string("estimate_trip VIP ")+source_ad;
            for(int i=0 ; i < destinations.size() ; i++){
                temp=temp+" "+destinations[i];
            }
            client_passenger->do_UI_command(temp);
            string result=client_passenger->get_result();
            if(!is_number(result)){
                statusBar()->showMessage(QString(result.c_str()));
                ui->trip_cost->setText("Cost : 0");
                ui->trip_distance->setText("Distance : 0");
                ui->Text->clear();
            }else{
                int find=result.find(' ');
                ui->trip_cost->setText(QString((string("Cost : ")+result.substr(0,find)).c_str()));
                ui->trip_distance->setText(QString((string("Distance : ")+result.substr(find+1)).c_str()));
                int found=temp.find(' ');
                temp=temp.substr(found+1);
                ui->Text->clear(); // unless you know the editor is empty
                ui->Text->appendPlainText(QString(temp.c_str()));
            }
        }
    }else{
        ui->trip_cost->setText("Cost : 0");
        ui->trip_distance->setText("Distance : 0");
        ui->Text->clear();
    }
}

void MainWindow::on_add_dest_clicked()
{
    destinations.push_back( (ui->d_galaxy->text()).toStdString()+","+(ui->d_planet->text()).toStdString());
    handle_estimate_command();
    ui->credit_label->setText(QString((string("Credit : ")+client_passenger->get_credit()).c_str()));
    ui->Date_Time_label->setText(QString((string("Date_Time : ")+client_passenger->get_date_time()).c_str()));
}

void MainWindow::on_remove_dest_clicked()
{
    if(destinations.size() >= 1){
        int index=destinations.size()-1;
        destinations.erase(destinations.begin()+index);
    }
    handle_estimate_command();
    ui->credit_label->setText(QString((string("Credit : ")+client_passenger->get_credit()).c_str()));
    ui->Date_Time_label->setText(QString((string("Date_Time : ")+client_passenger->get_date_time()).c_str()));

}

bool is_number(string result){
    for (int i = 0; i < result.size(); ++i) {
       if(result[i] != ' ' && (result[i] < 48 || result[i] > 57)){
           return false;
       }
    }
    return true;
}

void MainWindow::on_request_trip_clicked()
{
    string source_ad=(ui->source_galaxy->text()).toStdString()+","+(ui->source_planet->text()).toStdString();
    if(ui->VIP_trip->isChecked()){
        string temp=string("request_trip VIP ")+source_ad;
        for(int i=0 ; i < destinations.size() ; i++){
            temp=temp+" "+destinations[i];
        }
        client_passenger->do_UI_command(temp);
        string result=client_passenger->get_result();
        if(!is_number(result)){
            statusBar()->showMessage(QString(result.c_str()));
        }
    }else{
        string temp=string("request_trip ")+source_ad;
        for(int i=0 ; i < destinations.size() ; i++){
            temp=temp+" "+destinations[i];
        }
        client_passenger->do_UI_command(temp);
        string result=client_passenger->get_result();
        if(!is_number(result)){
            statusBar()->showMessage(QString(result.c_str()));
        }
    }
    ui->credit_label->setText(QString((string("Credit : ")+client_passenger->get_credit()).c_str()));
    ui->Date_Time_label->setText(QString((string("Date_Time : ")+client_passenger->get_date_time()).c_str()));
}

void MainWindow::on_getcode_clicked()
{
    string command="get_discount_code";
    client_passenger->do_UI_command(command);
    string temp=client_passenger->get_result();
    temp.insert(temp.find(' '), " Available Count : ");
    temp=string("Code : ")+temp;
    ui->code_text->clear();
    ui->code_text->appendPlainText(QString(temp.c_str()));
    ui->credit_label->setText(QString((string("Credit : ")+client_passenger->get_credit()).c_str()));
    ui->Date_Time_label->setText(QString((string("Date_Time : ")+client_passenger->get_date_time()).c_str()));
}

void MainWindow::on_charge_clicked()
{
    string charge_value=ui->add_to_credit->text().toStdString();
    if(ui->add_to_credit->text().isEmpty()){
       statusBar()->showMessage("Add To Credit is empty!");
       return;
    }
    string command=string("charge_account ")+charge_value;
    client_passenger->do_UI_command(command);
    string temp=client_passenger->get_result();
    if(temp != " "){
        statusBar()->showMessage(QString(temp.c_str()));
    }
    ui->credit_label->setText(QString((string("Credit : ")+client_passenger->get_credit()).c_str()));
    ui->Date_Time_label->setText(QString((string("Date_Time : ")+client_passenger->get_date_time()).c_str()));
}

void MainWindow::on_Trip_status_clicked()
{
    string command="trip_status";
    client_passenger->do_UI_command(command);
    string temp=client_passenger->get_result();
    ui->status_text->clear();
    ui->status_text->appendPlainText(QString(temp.c_str()));
    ui->credit_label->setText(QString((string("Credit : ")+client_passenger->get_credit()).c_str()));
    ui->Date_Time_label->setText(QString((string("Date_Time : ")+client_passenger->get_date_time()).c_str()));
}

void MainWindow::on_rate_driver_clicked()
{
    string command=string("rate_driver ")+ui->driver_rate->text().toStdString();
    if(ui->driver_rate->text().isEmpty()){
       statusBar()->showMessage("Driver Rate is empty!");
       return;
    }
    client_passenger->do_UI_command(command);
    string temp=client_passenger->get_result();
    if(temp != " "){
        statusBar()->showMessage(QString(temp.c_str()));
    }
    ui->credit_label->setText(QString((string("Credit : ")+client_passenger->get_credit()).c_str()));
    ui->Date_Time_label->setText(QString((string("Date_Time : ")+client_passenger->get_date_time()).c_str()));
}

void MainWindow::on_cancel_trip_clicked()
{
    string command="cancel_trip_request";
    client_passenger->do_UI_command(command);
    string temp=client_passenger->get_result();
    if(temp != " "){
        statusBar()->showMessage(QString(temp.c_str()));
    }
    ui->credit_label->setText(QString((string("Credit : ")+client_passenger->get_credit()).c_str()));
    ui->Date_Time_label->setText(QString((string("Date_Time : ")+client_passenger->get_date_time()).c_str()));
}
