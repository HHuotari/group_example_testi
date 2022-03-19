#include "studentmain.h"
#include "ui_studentmain.h"

StudentMain::StudentMain(QString stuUsername, QString stuId, QByteArray token, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StudentMain)
{
    ui->setupUi(this);
    ui->labelUsername->setText("username = " +stuUsername);
    username = stuUsername;
    webtoken = token;

    //ui->labelStudentId->setText(stuId);
    ui->labelStudentId->setText(token);
    objectMyUrl = new MyUrl;
}

StudentMain::~StudentMain()
{
    delete ui;
}

void StudentMain::on_btnShowGrades_clicked()
{
    QString site_url = objectMyUrl->getBase_url()+"/student/grades/"+username;
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(webtoken));
    //WEBTOKEN LOPPU

    gradeManager = new QNetworkAccessManager(this);
    connect(gradeManager, SIGNAL(finished (QNetworkReply*)),this, SLOT(gradeSlot(QNetworkReply*)));
    reply = gradeManager->get(request);
}

void StudentMain::gradeSlot(QNetworkReply *reply)
{
    response_data = reply->readAll();
    qDebug()<<response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
        QJsonArray json_array = json_doc.array();
        QString grades;
        foreach (const QJsonValue &value, json_array) {
            QJsonObject json_obj = value.toObject();
            grades+=json_obj["fname"].toString()+"|"+json_obj["lname"].toString()+"|"+json_obj["name"].toString()+"|"+QString::number(json_obj["grade"].toInt())+"\r";
        }

        qDebug()<<grades;

        ui->textGrades->setText(grades);
}

