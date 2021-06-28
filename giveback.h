#ifndef GIVEBACK_H
#define GIVEBACK_H

#include <QMainWindow>
#include "member.h"
namespace Ui {
class giveback;
}

class giveback : public QMainWindow
{
    Q_OBJECT

public:
    explicit giveback(QWidget *parent = nullptr);
    ~giveback();

private slots:
    void on_BookTable_cellDoubleClicked(int row, int column);

    void on_BackBtn_clicked();

private:
    Ui::giveback *ui;
};

#endif // GIVEBACK_H
