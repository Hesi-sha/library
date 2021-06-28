#ifndef SIGNUP_H
#define SIGNUP_H

#include <QMainWindow>
#include "signin.h"
#include "wellcome.h"

namespace Ui {
class SignUp;
class User;
}

class User
{
public:
    QList<QString> firstname;
    QList<QString> lastname;
    QList<QString> username;
    QList<QString> password;
    QList<QString> sex;
    QString index;
};

class SignUp : public QMainWindow
{
    Q_OBJECT

public:
    explicit SignUp(QWidget *parent = nullptr);
    ~SignUp();

private slots:
    void on_SignBtn_clicked();

    void on_CreateBtn_clicked();

private:
    Ui::SignUp *ui;
};

#endif // SIGNUP_H
