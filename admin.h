#ifndef ADMIN_H
#define ADMIN_H
#include <QMainWindow>
#include "mem_info.h"
#include"signin.h"
#include"add.h"
#include "del.h"
#include "search.h"
#include "edit.h"
#include "admin_profile.h"
#include "status.h"
namespace Ui {
class admin;
class Book;
}

class Book{
public:
    QList<QString> title;
    QList<QString> author;
    QList<QString> publisher;
    QList<QString> genre;
    QList<QString> year;
    QList<QString> rentedBy;
    int allRentedBooks;
    int bookInd;
};

class admin : public QMainWindow
{
    Q_OBJECT

public:
    explicit admin(QWidget *parent = nullptr);
    ~admin();

private slots:
    void on_SignOutBtn_clicked();

    void on_AddBtn_clicked();

    void on_RemoveBtn_clicked();

    void on_SearchBtn_clicked();

    void on_EditBtn_clicked();

    void on_AdminProfileBtn_clicked();

    void on_MemInfoBtn_clicked();

    void on_AllBtn_clicked();

private:
    Ui::admin *ui;
};

#endif // ADMIN_H
