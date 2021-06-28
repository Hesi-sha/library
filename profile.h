#ifndef PROFILE_H
#define PROFILE_H

#include <QMainWindow>
#include "member.h"
namespace Ui {
class profile;
}

class profile : public QMainWindow
{
    Q_OBJECT

public:
    explicit profile(QWidget *parent = nullptr);
    ~profile();

private slots:
    void on_BackBtn_clicked();

    void on_ChangeInfoBtn_clicked();

    void on_ChangeAccBtn_clicked();

private:
    Ui::profile *ui;
};

#endif // PROFILE_H
