#include "signup.h"
#include "ui_signup.h"
#include "signin.h"
#include "wellcome.h"
#include <QFile>
#include <QTextStream>
#include <QString>
#define UserAddress "Users information.txt"

SignUp::SignUp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SignUp)
{
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    ui->setupUi(this);
}

SignUp::~SignUp()
{
    delete ui;
}

void SignUp::on_SignBtn_clicked()
{
    SignIn *in = new SignIn(this);
    in->setWindowTitle("Library");
    in->show();
    hide();
}

void SignUp::on_CreateBtn_clicked()
{
    User user;
    QFile file(UserAddress) ;
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream y(&file);

    while(!y.atEnd()){
        QList<QString> temp = y.readLine().split('-');
        user.username.append(temp[2]);
        user.password.append(temp[3]);
    }
    file.close();

    QString first = ui->FirstLine->text();
    QString last  = ui->LastLine->text();
    QString usern = ui->UserLine->text();
    QString pass  = ui->PassLine->text();
    QString confpass  = ui->ConfirmPassLine->text();
    QString sex;

    if(first.isEmpty()){
        ui->FirstLine->setPlaceholderText("*");
        ui->LastLine->setPlaceholderText("*");
        ui->UserLine->setPlaceholderText("*");
        ui->PassLine->setPlaceholderText("*");
        ui->ConfirmPassLine->setPlaceholderText("*");
    }
    else{
        if(last.isEmpty()){
            ui->LastLine->setPlaceholderText("*");
            ui->UserLine->setPlaceholderText("*");
            ui->PassLine->setPlaceholderText("*");
            ui->ConfirmPassLine->setPlaceholderText("*");
        }
        else{
            if(usern.isEmpty() || user.username.contains(usern)){
                ui->UserLine->setPlaceholderText("*");
                ui->PassLine->setPlaceholderText("*");
                ui->ConfirmPassLine->setPlaceholderText("*");
            }
            else{
                if(pass.isEmpty() || user.password.contains(pass)){
                    ui->PassLine->setPlaceholderText("*");
                    ui->ConfirmPassLine->setPlaceholderText("*");
                }
                else{
                    if(confpass.isEmpty()){
                        ui->ConfirmPassLine->setPlaceholderText("*");
                    }
                    else{
                        if(!ui->MaleRadio->isChecked() && !ui->FemaleRadio->isChecked()){

                        }
                        else{
                            if(pass != confpass){
                                ui->PassLine->clear();
                                ui->ConfirmPassLine->clear();
                                ui->PassLine->setPlaceholderText("*");
                                ui->ConfirmPassLine->setPlaceholderText("*");
                            }
                            else{
                                QFile file(UserAddress);
                                file.open(QFile::WriteOnly | QFile :: Append);
                                QTextStream   x(&file);

                                if(ui->MaleRadio->isChecked())
                                    sex = "Male";
                                if(ui->FemaleRadio->isChecked())
                                    sex = "Female";

                                x << first << "-" << last << "-" << usern << "-" << pass << "-" << sex << "\n";
                                file.close();

                                wellcome *well = new wellcome(this);
                                well->setWindowTitle("Library");
                                well->show();
                                hide();
                            }
                        }
                    }
                }
            }
        }
    }



}
