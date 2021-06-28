#include "admin_profile.h"
#include "ui_admin_profile.h"
#include "admin.h"
admin_profile::admin_profile(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::admin_profile)
{
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    ui->setupUi(this);
}

admin_profile::~admin_profile()
{
    delete ui;
}

void admin_profile::on_pushButton_clicked()
{
    admin *ad = new admin(this);
    ad->setWindowTitle("Library");
    ad->show();
    hide();
}

