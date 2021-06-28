#include "mem_info.h"
#include "ui_mem_info.h"
#include "admin.h"
#include <QFile>
#include <QTextStream>
#include <QString>
#include "QTableWidget"
#include "QTableWidgetItem"
#include "signup.h"
#define BookAddress "Users information.txt"

mem_info::mem_info(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mem_info)
{
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    ui->setupUi(this);
}

mem_info::~mem_info()
{
    delete ui;
}

void mem_info::on_BackBtn_clicked()
{
    admin *ad = new admin(this);
    ad->setWindowTitle("Library");
    ad->show();
    hide();
}


void mem_info::on_SearchLine_textChanged(const QString &arg)
{
    for (int j = 0 ; j < 20 ; ++j )
    {
        for (int i = 0 ; i < 20 ; ++i )
            ui->UserTable->removeRow(i);
        for (int i = 0 ; i < 20 ; ++i )
            ui->UserTable->removeRow(i);
        for (int i = 0 ; i < 20 ; ++i )
            ui->UserTable->removeRow(i);
        for (int i = 0 ; i < 20 ; ++i )
            ui->UserTable->removeRow(i);
        for (int i = 0 ; i < 20 ; ++i )
            ui->UserTable->removeRow(i);
    }

    QTableWidgetItem *first;
    QTableWidgetItem *last;
    QTableWidgetItem *usern;
    QTableWidgetItem *passw;

    QString srch = arg;
    User user;

    QFile file(BookAddress) ;
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream y(&file);
    while(!y.atEnd()){
        QList<QString> temp = y.readLine().split('-');
        user.firstname.append(temp[0]);
        user.lastname.append(temp[1]);
        user.username.append(temp[2]);
        user.password.append(temp[3]);
    }
    file.close();

    if(ui->FirstRadio->isChecked()){
        int r = 0;
        for (int i = 0 ; i < user.firstname.size() ; ++i) {

            QString tmp = user.firstname[i];
            if(tmp.contains(srch) && !srch.isEmpty()){
                ui->UserTable->insertRow(r);
                first = new QTableWidgetItem;
                last = new QTableWidgetItem;
                usern = new QTableWidgetItem;
                passw = new QTableWidgetItem;

                first->setText(user.firstname[i]);
                last->setText(user.lastname[i]);
                usern->setText(user.username[i]);
                passw->setText(user.password[i]);

                first->setTextAlignment( Qt::AlignCenter );
                last->setTextAlignment( Qt::AlignCenter );
                usern->setTextAlignment( Qt::AlignCenter );
                passw->setTextAlignment( Qt::AlignCenter );

                ui->UserTable->setItem(r,0,first);
                ui->UserTable->setItem(r,1,last);
                ui->UserTable->setItem(r,2,usern);
                ui->UserTable->setItem(r,3,passw);
                r++;
            }
        }
    }

    else if(ui->LastRadio->isChecked()){
        int r = 0;
        for (int i = 0 ; i < user.lastname.size() ; ++i) {

            QString tmp = user.lastname[i];
            if(tmp.contains(srch) && !srch.isEmpty()){
                ui->UserTable->insertRow(r);
                first = new QTableWidgetItem;
                last = new QTableWidgetItem;
                usern = new QTableWidgetItem;
                passw = new QTableWidgetItem;

                first->setText(user.firstname[i]);
                last->setText(user.lastname[i]);
                usern->setText(user.username[i]);
                passw->setText(user.password[i]);

                first->setTextAlignment( Qt::AlignCenter );
                last->setTextAlignment( Qt::AlignCenter );
                usern->setTextAlignment( Qt::AlignCenter );
                passw->setTextAlignment( Qt::AlignCenter );

                ui->UserTable->setItem(r,0,first);
                ui->UserTable->setItem(r,1,last);
                ui->UserTable->setItem(r,2,usern);
                ui->UserTable->setItem(r,3,passw);
                r++;
            }
        }
    }

    else if(ui->UserRadio->isChecked()){
        int r = 0;
        for (int i = 0 ; i < user.username.size() ; ++i) {

            QString tmp = user.username[i];
            if(tmp.contains(srch) && !srch.isEmpty()){
                ui->UserTable->insertRow(r);
                first = new QTableWidgetItem;
                last = new QTableWidgetItem;
                usern = new QTableWidgetItem;
                passw = new QTableWidgetItem;

                first->setText(user.firstname[i]);
                last->setText(user.lastname[i]);
                usern->setText(user.username[i]);
                passw->setText(user.password[i]);

                first->setTextAlignment( Qt::AlignCenter );
                last->setTextAlignment( Qt::AlignCenter );
                usern->setTextAlignment( Qt::AlignCenter );
                passw->setTextAlignment( Qt::AlignCenter );

                ui->UserTable->setItem(r,0,first);
                ui->UserTable->setItem(r,1,last);
                ui->UserTable->setItem(r,2,usern);
                ui->UserTable->setItem(r,3,passw);
                r++;
            }
        }
    }

    else if(ui->PasswordRadio->isChecked()){
        int r = 0;
        for (int i = 0 ; i < user.password.size() ; ++i) {

            QString tmp = user.password[i];
            if(tmp.contains(srch)){
                ui->UserTable->insertRow(r);
                first = new QTableWidgetItem;
                last = new QTableWidgetItem;
                usern = new QTableWidgetItem;
                passw = new QTableWidgetItem;

                first->setText(user.firstname[i]);
                last->setText(user.lastname[i]);
                usern->setText(user.username[i]);
                passw->setText(user.password[i]);

                first->setTextAlignment( Qt::AlignCenter );
                last->setTextAlignment( Qt::AlignCenter );
                usern->setTextAlignment( Qt::AlignCenter );
                passw->setTextAlignment( Qt::AlignCenter );

                ui->UserTable->setItem(r,0,first);
                ui->UserTable->setItem(r,1,last);
                ui->UserTable->setItem(r,2,usern);
                ui->UserTable->setItem(r,3,passw);
                r++;
            }
        }
    }
}
