#ifndef LOGIN_H
#define LOGIN_H

#include "myurl.h"
#include "studentmain.h"
#include <QDebug>

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_btnLogin_clicked();
    void loginSlot(QNetworkReply *reply);


private:
    Ui::Login *ui;
    QString username;
    QString password;
    QString id;
    StudentMain *objectStudentMain;
    MyUrl *objectMyUrl;
    QString base_url;

    QNetworkAccessManager *loginManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QByteArray token;
};

#endif // LOGIN_H
