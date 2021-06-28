#include "admin.h"
#include "ui_admin.h"
#include"signin.h"
#include"add.h"
#include "del.h"
#include "QString"
#include "search.h"
#include "edit.h"
#include "admin_profile.h"
#include "mem_info.h"
#include "status.h"
admin::admin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::admin)
{
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    ui->setupUi(this);
}

admin::~admin()
{
    delete ui;
}

void admin::on_SignOutBtn_clicked()
{
    SignIn *in = new SignIn(this);
    in->setWindowTitle("Library");
    in->show();
    hide();
}


void admin::on_AddBtn_clicked()
{
    add *ad = new add(this);
    ad->setWindowTitle("Library");
    ad->show();
    hide();
}


void admin::on_RemoveBtn_clicked()
{
   del *dell = new del(this);
   dell->setWindowTitle("Library");
   dell->show();
   hide();
}


void admin::on_SearchBtn_clicked()
{
    search *srch = new search(this);
    srch->setWindowTitle("Library");
    srch->show();
    hide();
}


void admin::on_EditBtn_clicked()
{
    edit *ed = new edit(this);
    ed->setWindowTitle("Library");
    ed->show();
    hide();
}


void admin::on_AdminProfileBtn_clicked()
{
    admin_profile *adp = new admin_profile(this);
    adp->setWindowTitle("Library");
    adp->show();
    hide();
}


void admin::on_MemInfoBtn_clicked()
{
    mem_info *mem = new mem_info(this);
    mem->setWindowTitle("Library");
    mem->show();
    hide();
}


void admin::on_AllBtn_clicked()
{
    status *stat = new status(this);
    stat->setWindowTitle("Library");
    stat->show();
    hide();
}

