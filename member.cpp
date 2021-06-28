#include "member.h"
#include "ui_member.h"
#include "signin.h"
#include "signup.h"
#include "rent.h"
#include <QFile>
#include <QTextStream>
#include <QString>
#include "QIcon"
#include "giveback.h"
#include "profile.h"
#define UserAddress "Users information.txt"


member::member(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::member)
{
    User user;
    QFile file(UserAddress) ;
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream y(&file);

    while(!y.atEnd()){
        QList<QString> temp = y.readLine().split('-');
        user.firstname.append(temp[0]);
        user.lastname.append(temp[1]);
        user.username.append(temp[2]);
        user.password.append(temp[3]);
        user.sex.append(temp[4]);
        user.index = temp[5];
    }
    file.close();

    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    ui->setupUi(this);
    ui->NameLabel->setText("Hi " + user.firstname[user.index.toInt()] + " " + user.lastname[user.index.toInt()]);
    if(user.sex[user.index.toInt()] == "Male")
        ui->ProfileBtn->setIcon(QIcon("C:/Users/DELTAcomputer/Desktop/icons/boy.PNG"));
    else
        ui->ProfileBtn->setIcon(QIcon("C:/Users/DELTAcomputer/Desktop/icons/girl.PNG"));
}

member::~member()
{
    delete ui;
}

void member::on_SignOutBtn_clicked()
{
    SignIn *in = new SignIn(this);
    in->setWindowTitle("Library");
    in->show();
    hide();
}


void member::on_RentBtn_clicked()
{
    rent *ren = new rent(this);
    ren->setWindowTitle("Library");
    ren->show();
    hide();
}


void member::on_GiveBackBtn_clicked()
{
    giveback *give = new giveback(this);
    give->setWindowTitle("Library");
    give->show();
    hide();
}


void member::on_ProfileBtn_clicked()
{
    profile *prof = new profile(this);
    prof->setWindowTitle("Library");
    prof->show();
    hide();
}

