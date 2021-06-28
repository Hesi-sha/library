#ifndef MEMBER_H
#define MEMBER_H

#include <QMainWindow>
#include "signin.h"
#include "signup.h"
#include "rent.h"
#include "giveback.h"
#include "profile.h"
namespace Ui {
class member;
}

class member : public QMainWindow
{
    Q_OBJECT

public:
    explicit member(QWidget *parent = nullptr);
    ~member();

private slots:
    void on_SignOutBtn_clicked();

    void on_RentBtn_clicked();

    void on_GiveBackBtn_clicked();

    void on_ProfileBtn_clicked();

private:
    Ui::member *ui;
};

#endif // MEMBER_H
