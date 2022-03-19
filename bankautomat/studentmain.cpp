#include "studentmain.h"
#include "ui_studentmain.h"

StudentMain::StudentMain(QString stuUsername, QString stuId, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StudentMain)
{
    ui->setupUi(this);
    ui->labelUsername->setText(stuUsername);
    ui->labelStudentId->setText(stuId);
}

StudentMain::~StudentMain()
{
    delete ui;
}

void StudentMain::on_btnShowGrades_clicked()
{

}

