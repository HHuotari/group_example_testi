#ifndef STUDENTMAIN_H
#define STUDENTMAIN_H

#include <QDialog>

namespace Ui {
class StudentMain;
}

class StudentMain : public QDialog
{
    Q_OBJECT

public:
    explicit StudentMain(QString stuUsername, QString stuId, QWidget *parent = nullptr);
    ~StudentMain();

private slots:
    void on_btnShowGrades_clicked();

private:
    Ui::StudentMain *ui;
};

#endif // STUDENTMAIN_H
