#ifndef STUDENTMAIN_H
#define STUDENTMAIN_H

#include "myurl.h"

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class StudentMain;
}

class StudentMain : public QDialog
{
    Q_OBJECT

public:
    explicit StudentMain(QString stuUsername, QString stuId, QByteArray token, QWidget *parent = nullptr);
    ~StudentMain();

private slots:
    void on_btnShowGrades_clicked();
    void gradeSlot(QNetworkReply *reply);

private:
    Ui::StudentMain *ui;
    MyUrl *objectMyUrl;

    QNetworkAccessManager *gradeManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QString username;
    QByteArray webtoken;
};

#endif // STUDENTMAIN_H
