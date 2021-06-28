#ifndef DEL_H
#define DEL_H

#include <QMainWindow>
#include "admin.h"
#include "signup.h"
namespace Ui {
class del;
}

class del : public QMainWindow
{
    Q_OBJECT

public:
    explicit del(QWidget *parent = nullptr);
    ~del();

private slots:
    void on_BackBtn_clicked();

    void on_Btn_clicked();

    void on_BookTable_cellDoubleClicked(int row, int column);

private:
    Ui::del *ui;
};

#endif // DEL_H
