#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
    ui = nullptr;
    delete objectStudentMain;
    objectStudentMain = nullptr;
}

void Login::on_btnLogin_clicked()
{
    username=ui->leUsername->text();
    password=ui->lePassword->text();
    id="1";
    objectStudentMain = new StudentMain(username, id);
    objectStudentMain->show();
}

