#ifndef STATUS_H
#define STATUS_H

#include <QMainWindow>
#include "admin.h"
namespace Ui {
class status;
}

class status : public QMainWindow
{
    Q_OBJECT

public:
    explicit status(QWidget *parent = nullptr);
    ~status();

private slots:
    void on_BackBtn_clicked();

    void on_SearchLine_textChanged(const QString &arg);

private:
    Ui::status *ui;
};

#endif // STATUS_H
