#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    objectMyUrl = new MyUrl;
    base_url = objectMyUrl->getBase_url();
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
    //qDebug()<<"base_url="+base_url;
    username=ui->leUsername->text();
    password=ui->lePassword->text();


    QJsonObject jsonObj;
    jsonObj.insert("username",username);
    jsonObj.insert("password",password);


    QNetworkRequest request((base_url+"/login"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");



    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL(finished (QNetworkReply*)),
            this, SLOT(loginSlot(QNetworkReply*)));

    reply = loginManager->post(request, QJsonDocument(jsonObj).toJson());
}

void Login::loginSlot(QNetworkReply *reply)
{
    response_data = reply->readAll();
    qDebug()<<response_data;
    if(response_data != "false"){
        token = "Bearer "+response_data;
        id="1";
        objectStudentMain = new StudentMain(username, id, token);
        objectStudentMain->show();
        this->close();
    }
    else{
        ui->leUsername->setText("");
        ui->lePassword->setText("");
    }

}

