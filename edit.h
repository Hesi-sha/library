#ifndef EDIT_H
#define EDIT_H

#include <QMainWindow>
#include "admin.h"
#include "QTableWidget"
#include "QTableWidgetItem"

namespace Ui {
class edit;
}

class edit : public QMainWindow
{
    Q_OBJECT

public:
    explicit edit(QWidget *parent = nullptr);
    ~edit();

private slots:
    void on_BackBtn_clicked();

    void on_Btn_clicked();

    void on_BookTable_itemClicked(QTableWidgetItem *item);

    void on_BookTable_itemDoubleClicked(QTableWidgetItem *item);

private:
    Ui::edit *ui;
};

#endif // EDIT_H
