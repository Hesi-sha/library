#include "profile.h"
#include "ui_profile.h"
#include "member.h"
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QMessageBox>
#define UserAddress "Users information.txt"

profile::profile(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::profile)
{
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    ui->setupUi(this);

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

    ui->FirstLine->setText(user.firstname[user.index.toInt()]);
    ui->LastLine->setText(user.lastname[user.index.toInt()]);
    ui->UserLine->setText(user.username[user.index.toInt()]);

}

profile::~profile()
{
    delete ui;
}

void profile::on_BackBtn_clicked()
{
    member *mem = new member(this);
    mem->setWindowTitle("Library");
    mem->show();
    hide();
}


void profile::on_ChangeInfoBtn_clicked()
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

    QString ChngFirst = ui->FirstLine->text();
    QString ChngLast  = ui->LastLine->text();
    user.firstname.replace(user.index.toInt(),ChngFirst);
    user.lastname.replace(user.index.toInt(),ChngLast);

    QMessageBox qmb;
    qmb.information(this,"Successful changing","Your name is updated.");

    QFile filex(UserAddress);
    filex.open(QFile::WriteOnly | QFile :: Append);
    QTextStream   x(&filex);
    filex.resize(0);
    QListIterator<QString> itr1(user.firstname);
    QListIterator<QString> itr2(user.lastname);
    QListIterator<QString> itr3(user.username);
    QListIterator<QString> itr4(user.password);
    QListIterator<QString> itr5(user.sex);
    QString itr6(user.index);
    while(itr3.hasNext())
        x << itr1.next() << "-" << itr2.next() << "-" << itr3.next() << "-" << itr4.next() << "-" << itr5.next() << "-" << itr6 << "\n";
    filex.close();
}


void profile::on_ChangeAccBtn_clicked()
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

    QString ChngUser = ui->UserLine->text();
    QString Oldpass  = ui->OldLine->text();
    QString newpass  = ui->NewLine->text();
    QString confpass  = ui->ConfNewLine->text();

    if(Oldpass == user.password[user.index.toInt()] && newpass == confpass && !user.password.contains(newpass)){
        QString tmp = user.username[user.index.toInt()];
        user.username.replace(user.index.toInt(),"temp");
        if(!user.username.contains(ChngUser)){

            user.username.replace(user.index.toInt(),tmp);

            user.username.replace(user.index.toInt(),ChngUser);
            user.password.replace(user.index.toInt(),newpass);

            QMessageBox qmb;
            qmb.information(this,"Successful changing","Your account is updated.");

            QFile filex(UserAddress);
            filex.open(QFile::WriteOnly | QFile :: Append);
            QTextStream   x(&filex);
            filex.resize(0);
            QListIterator<QString> itr1(user.firstname);
            QListIterator<QString> itr2(user.lastname);
            QListIterator<QString> itr3(user.username);
            QListIterator<QString> itr4(user.password);
            QListIterator<QString> itr5(user.sex);
            QString itr6(user.index);
            while(itr3.hasNext())
                x << itr1.next() << "-" << itr2.next() << "-" << itr3.next() << "-" << itr4.next() << "-" << itr5.next() << "-" << itr6 << "\n";
            filex.close();
        }
    }
    else{
        QMessageBox qmb;
        qmb.warning(this,"Failed changing","Your account updating is failed!");
        ui->OldLine->setPlaceholderText("*");
        ui->NewLine->setPlaceholderText("*");
        ui->ConfNewLine->setPlaceholderText("*");
    }
}
