#ifndef WELLCOME_H
#define WELLCOME_H

#include <QMainWindow>
#include "signin.h"

namespace Ui {
class wellcome;
}

class wellcome : public QMainWindow
{
    Q_OBJECT

public:
    explicit wellcome(QWidget *parent = nullptr);
    ~wellcome();

private slots:
    void on_BackBtn_clicked();

private:
    Ui::wellcome *ui;
};

#endif // WELLCOME_H
