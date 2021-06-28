#include "giveback.h"
#include "ui_giveback.h"
#include <QFile>
#include <QTextStream>
#include <QString>
#include "QTableWidget"
#include "QTableWidgetItem"
#include "QMessageBox"
#include "admin.h"
#include "signup.h"
#include "member.h"
#define BookAddress "Books information.txt"
#define UserAddress "Users information.txt"
#define BooksCount "Number OF All Books.txt"

giveback::giveback(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::giveback)
{
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    ui->setupUi(this);

    User user;
    QFile file(UserAddress) ;
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream y(&file);

    while(!y.atEnd()){
        QList<QString> temp = y.readLine().split('-');
        user.firstname.append(temp[0]);
        user.lastname.append(temp[1]);
        user.username.append(temp[2]);
        user.password.append(temp[3]);
        user.sex.append(temp[4]);
        user.index = temp[5];
    }
    file.close();

    Book book;
    QFile filex(BookAddress) ;
    filex.open(QFile::ReadOnly | QFile::Text);
    QTextStream x(&filex);
    while(!x.atEnd()){
        QList<QString> temp = x.readLine().split('-');
        book.title.append(temp[0]);
        book.author.append(temp[1]);
        book.publisher.append(temp[2]);
        book.genre.append(temp[3]);
        book.year.append(temp[4]);
        book.rentedBy.append(temp[5]);
    }
    filex.close();
    QString Name = user.firstname[user.index.toInt()] + " " + user.lastname[user.index.toInt()];

    QTableWidgetItem *title;
    QTableWidgetItem *author;
    QTableWidgetItem *publisher;
    QTableWidgetItem *genre;
    QTableWidgetItem *date;

    int r = 0;
    for (int i = 0 ; i < book.title.size() ; ++i) {
        if(book.rentedBy[i] == Name){
            ui->BookTable->insertRow(r);
            title = new QTableWidgetItem;
            author = new QTableWidgetItem;
            publisher = new QTableWidgetItem;
            genre = new QTableWidgetItem;
            date = new QTableWidgetItem;

            title->setText(book.title[i]);
            author->setText(book.author[i]);
            publisher->setText(book.publisher[i]);
            genre->setText(book.genre[i]);
            date->setText(book.year[i]);

            title->setTextAlignment( Qt::AlignCenter );
            author->setTextAlignment( Qt::AlignCenter );
            publisher->setTextAlignment( Qt::AlignCenter );
            genre->setTextAlignment( Qt::AlignCenter );
            date->setTextAlignment( Qt::AlignCenter );

            ui->BookTable->setItem(r,0,title);
            ui->BookTable->setItem(r,1,author);
            ui->BookTable->setItem(r,2,publisher);
            ui->BookTable->setItem(r,3,genre);
            ui->BookTable->setItem(r,4,date);
            r++;
        }
    }
}

giveback::~giveback()
{
    delete ui;
}

void giveback::on_BookTable_cellDoubleClicked(int row, int column)
{

    Book book;

    QFile filex(BookAddress) ;
    filex.open(QFile::ReadOnly | QFile::Text);
    QTextStream y(&filex);
    while(!y.atEnd()){
        QList<QString> temp = y.readLine().split('-');
        book.title.append(temp[0]);
        book.author.append(temp[1]);
        book.publisher.append(temp[2]);
        book.genre.append(temp[3]);
        book.year.append(temp[4]);
        book.rentedBy.append(temp[5]);
    }
    filex.close();

    QString DelStr = ui->BookTable->item(row,0)->text();
    int index = book.title.indexOf(DelStr);

    book.rentedBy.replace(index,"Available");

    ui->BookTable->removeRow(row);

    QMessageBox qmb;
    qmb.information(this,"Successful returning","The book is gave back successfully.");

    QFile file(BookAddress);
    file.open(QFile::WriteOnly | QFile :: Append);
    QTextStream   x(&file);
    file.resize(0);
    QListIterator<QString> itr1(book.title);
    QListIterator<QString> itr2(book.author);
    QListIterator<QString> itr3(book.publisher);
    QListIterator<QString> itr4(book.genre);
    QListIterator<QString> itr5(book.year);
    QListIterator<QString> itr6(book.rentedBy);
    while(itr3.hasNext())
        x << itr1.next() << "-" << itr2.next() << "-" << itr3.next() << "-" << itr4.next() << "-" << itr5.next() << "-" << itr6.next() << "\n";
    file.close();

    QFile filee(BooksCount);
    filee.open(QFile::ReadOnly | QFile::Text);
    QTextStream q(&filee);
    while(!q.atEnd()){
        QList<QString> temp = q.readLine().split(' ');
        book.allRentedBooks = temp[0].toInt();
    }
    filee.close();

    QFile fileex(BooksCount);
    fileex.open(QFile::WriteOnly | QFile :: Append);
    QTextStream   p(&fileex);
    fileex.resize(0);
    p << --book.allRentedBooks << " ";
    fileex.close();
}


void giveback::on_BackBtn_clicked()
{
    member *mem = new member(this);
    mem->setWindowTitle("Library");
    mem->show();
    hide();
}

