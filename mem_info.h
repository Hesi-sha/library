#ifndef MEM_INFO_H
#define MEM_INFO_H

#include <QMainWindow>
#include "admin.h"
namespace Ui {
class mem_info;
}

class mem_info : public QMainWindow
{
    Q_OBJECT

public:
    explicit mem_info(QWidget *parent = nullptr);
    ~mem_info();

private slots:
    void on_BackBtn_clicked();

    void on_SearchLine_textChanged(const QString &arg);

private:
    Ui::mem_info *ui;
};

#endif // MEM_INFO_H
