#ifndef SEARCH_H
#define SEARCH_H

#include <QMainWindow>
#include "signup.h"
#include "admin.h"

namespace Ui {
class search;
}

class search : public QMainWindow
{
    Q_OBJECT

public:
    explicit search(QWidget *parent = nullptr);
    ~search();

private slots:

    void on_BackBtn_clicked();

    void on_SearchLine_textChanged(const QString &arg);

private:
    Ui::search *ui;
};

#endif // SEARCH_H
