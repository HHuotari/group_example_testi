#ifndef LOGIN_H
#define LOGIN_H

#include "studentmain.h"

#include <QDialog>

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

private:
    Ui::Login *ui;
    QString username;
    QString password;
    QString id;
    StudentMain *objectStudentMain;
};

#endif // LOGIN_H
