#ifndef ADD_H
#define ADD_H

#include <QMainWindow>
#include "admin.h"

namespace Ui {
class add;
}

class add : public QMainWindow
{
    Q_OBJECT

public:
    explicit add(QWidget *parent = nullptr);
    ~add();

private slots:
    void on_Back_clicked();

    void on_AddBookBtn_clicked();

    void on_YearBox_currentTextChanged(const QString &arg1);

    void on_OtherCheck_clicked(bool checked);

    void on_reload_clicked();

private:
    Ui::add *ui;
};

#endif // ADD_H
