#ifndef ADMIN_PROFILE_H
#define ADMIN_PROFILE_H

#include <QMainWindow>
#include "admin.h"
namespace Ui {
class admin_profile;
}

class admin_profile : public QMainWindow
{
    Q_OBJECT

public:
    explicit admin_profile(QWidget *parent = nullptr);
    ~admin_profile();

private slots:
    void on_pushButton_clicked();

private:
    Ui::admin_profile *ui;
};

#endif // ADMIN_PROFILE_H
