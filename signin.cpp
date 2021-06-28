#include "signin.h"
#include "ui_signin.h"
#include "signup.h"
#include <QFile>
#include <QTextStream>
#include <QString>
#include "member.h"
#include "admin.h"
#include "ctime"
#include <cstdlib>
#define UserAddress "Users information.txt"
QString CAPTCHA();
QString CaptchCheck;
SignIn::SignIn(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SignIn)
{
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    ui->setupUi(this);
    CaptchCheck = CAPTCHA();
    ui->CaptchaBtn->setText(CaptchCheck);
}
SignIn::~SignIn()
{
    delete ui;
}

QString CAPTCHA()
{
    int userBeg = 0;

    int userEnd = 9;

    int outPut;

    srand(time(NULL));

    QString CAPTCHA;

    outPut = rand()%((userEnd - userBeg) + 1) + userBeg;
    QString CAPTCHA1 = QString::number(outPut);

    outPut = rand()%((userEnd - userBeg) + 1) + userBeg;
    QString CAPTCHA2 = QString::number(outPut);

    outPut = rand()%((userEnd - userBeg) + 1) + userBeg;
    QString CAPTCHA3 = QString::number(outPut);

    outPut = rand()%((userEnd - userBeg) + 1) + userBeg;
    QString CAPTCHA4 = QString::number(outPut);

    outPut = rand()%((userEnd - userBeg) + 1) + userBeg;
    QString CAPTCHA5 = QString::number(outPut);

    outPut = rand()%((userEnd - userBeg) + 1) + userBeg;
    QString CAPTCHA6 = QString::number(outPut);

    CAPTCHA = CAPTCHA1 + CAPTCHA2 + CAPTCHA3 + CAPTCHA4 + CAPTCHA5 + CAPTCHA6;

    return CAPTCHA;
}

void SignIn::on_NewAccBtn_clicked()
{
    SignUp *up = new SignUp(this);
    up->setWindowTitle("Library");
    up->show();
    hide();
}


void SignIn::on_SignInBtn_clicked()
{
    User user;
    int UserInd = 0, PassInd = 0;
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
    }
    file.close();

    QString usern = this->ui->UserLine->text();
    QString passw = this->ui->PassLine->text();
    UserInd = user.username.indexOf(usern);
    PassInd = user.password.indexOf(passw);

    if(usern == "admin" && passw == "admin"){
        admin *ad = new admin(this);
        ad->setWindowTitle("Library");
        ad->show();
        hide();
    }
    else{
        if(user.username.contains(usern)){
            if(user.password.contains(passw)){
                if(UserInd == PassInd){
                    if(CaptchCheck == ui->CaptchaLine->text()){
                        QFile file(UserAddress);
                        file.open(QFile::WriteOnly | QFile :: Append);
                        QTextStream   x(&file);
                        file.resize(0);
                        QListIterator<QString> itr1(user.firstname);
                        QListIterator<QString> itr2(user.lastname);
                        QListIterator<QString> itr3(user.username);
                        QListIterator<QString> itr4(user.password);
                        QListIterator<QString> itr5(user.sex);
                        while(itr3.hasNext())
                            x << itr1.next() << "-" << itr2.next() << "-" << itr3.next() << "-" << itr4.next() << "-" << itr5.next() << "-" << UserInd << "\n";
                        file.close();

                        member *mem = new member(this);
                        mem->setWindowTitle("Library");
                        mem->show();
                        hide();
                    }
                    else{
                        CaptchCheck = CAPTCHA();
                        ui->CaptchaLine->clear();
                        ui->CaptchaBtn->setText(CaptchCheck);
                        ui->UserLine->clear();
                        ui->PassLine->clear();
                        ui->CaptchaLine->clear();
                        ui->CaptchaLine->setPlaceholderText("*");
                        ui->UserLine->setPlaceholderText("*");
                        ui->PassLine->setPlaceholderText("*");
                    }
                }
            }
            else{
                CaptchCheck = CAPTCHA();
                ui->CaptchaLine->clear();
                ui->CaptchaBtn->setText(CaptchCheck);
                ui->PassLine->clear();
                ui->PassLine->setPlaceholderText("*");
            }
        }
        else{
            CaptchCheck = CAPTCHA();
            ui->CaptchaLine->clear();
            ui->CaptchaBtn->setText(CaptchCheck);
            ui->UserLine->clear();
            ui->PassLine->clear();
            ui->UserLine->setPlaceholderText("*");
            ui->PassLine->setPlaceholderText("*");
        }
    }
}


void SignIn::on_exit_clicked()
{
    close();
}


void SignIn::on_Reload_clicked()
{
    CaptchCheck = CAPTCHA();
    ui->CaptchaBtn->setText(CaptchCheck);
}

