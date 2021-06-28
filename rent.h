#ifndef RENT_H
#define RENT_H

#include <QMainWindow>

namespace Ui {
class rent;
}

class rent : public QMainWindow
{
    Q_OBJECT

public:
    explicit rent(QWidget *parent = nullptr);
    ~rent();

private slots:
    void on_SearchBtn_clicked();

    void on_OtherCheck_clicked(bool checked);

    void on_backBtn_clicked();

    void on_Table_cellDoubleClicked(int row, int column);

private:
    Ui::rent *ui;
};

#endif // RENT_H
