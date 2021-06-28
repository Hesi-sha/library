#include "wellcome.h"
#include "ui_wellcome.h"
#include "signin.h"

wellcome::wellcome(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::wellcome)
{
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    ui->setupUi(this);
}

wellcome::~wellcome()
{
    delete ui;
}

void wellcome::on_BackBtn_clicked()
{
    SignIn *in = new SignIn(this);
    in->setWindowTitle("Library");
    in->show();
    hide();
}

