#ifndef SIGNIN_H
#define SIGNIN_H

#include <QMainWindow>
#include "signup.h"
#include "member.h"
#include "admin.h"

QT_BEGIN_NAMESPACE
namespace Ui { class SignIn; }
QT_END_NAMESPACE

class SignIn : public QMainWindow
{
    Q_OBJECT

public:
    SignIn(QWidget *parent = nullptr);
    ~SignIn();

private slots:
    void on_NewAccBtn_clicked();

    void on_SignInBtn_clicked();

    void on_exit_clicked();

    void on_Reload_clicked();

private:
    Ui::SignIn *ui;
};
#endif // SIGNIN_H
