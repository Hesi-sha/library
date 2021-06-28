#include "edit.h"
#include "ui_edit.h"
#include <QFile>
#include <QTextStream>
#include <QString>
#include "QTableWidget"
#include "QTableWidgetItem"
#include "QMessageBox"
#include "admin.h"
#include "signup.h"
#define BookAddress "Books information.txt"
edit::edit(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::edit)
{
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    ui->setupUi(this);
}

edit::~edit()
{
    delete ui;
}

void edit::on_BackBtn_clicked()
{
    admin *ad = new admin(this);
    ad->setWindowTitle("Library");
    ad->show();
    hide();
}


void edit::on_Btn_clicked()
{
    for (int j = 0 ; j < 20 ; ++j )
    {
        for (int i = 0 ; i < 20 ; ++i )
            ui->BookTable->removeRow(i);
        for (int i = 0 ; i < 20 ; ++i )
            ui->BookTable->removeRow(i);
        for (int i = 0 ; i < 20 ; ++i )
            ui->BookTable->removeRow(i);
        for (int i = 0 ; i < 20 ; ++i )
            ui->BookTable->removeRow(i);
        for (int i = 0 ; i < 20 ; ++i )
            ui->BookTable->removeRow(i);
    }

    QTableWidgetItem *title;
    QTableWidgetItem *author;
    QTableWidgetItem *publisher;
    QTableWidgetItem *genre;
    QTableWidgetItem *date;

    QString srch = ui->SearchLine->text();
    Book book;

    QFile file(BookAddress) ;
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream y(&file);
    while(!y.atEnd()){
        QList<QString> temp = y.readLine().split('-');
        book.title.append(temp[0]);
        book.author.append(temp[1]);
        book.publisher.append(temp[2]);
        book.genre.append(temp[3]);
        book.year.append(temp[4]);
        book.rentedBy.append(temp[5]);
    }
    file.close();

    if(ui->TitleRadio->isChecked()){
        int r = 0;
        for (int i = 0 ; i < book.title.size() ; ++i) {

            QString tmp = book.title[i];
            if(tmp.contains(srch)){
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

    else if(ui->AuthorRadio->isChecked()){
        int r = 0;
        for (int i = 0 ; i < book.author.size() ; ++i) {

            QString tmp = book.author[i];
            if(tmp.contains(srch)){
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

    else if(ui->GenreRadio->isChecked()){
        int r = 0;
        for (int i = 0 ; i < book.genre.size() ; ++i) {

            QString tmp = book.genre[i];
            if(tmp.contains(srch)){
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

    else if(ui->PublisherRadio->isChecked()){
        int r = 0;
        for (int i = 0 ; i < book.publisher.size() ; ++i) {

            QString tmp = book.publisher[i];
            if(tmp.contains(srch)){
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
}

int index;
bool once = false;
void edit::on_BookTable_itemClicked(QTableWidgetItem *item)
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

    int x = item->row();
    QString FindIt = ui->BookTable->item(x,0)->text();
    if(once == false){
        once = true;
        index = book.title.indexOf(FindIt);
    }
}

void edit::on_BookTable_itemDoubleClicked(QTableWidgetItem *item)
{
    once = false;
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

    QString AfterEdit = item->text();

    if(item->column() == 0){
        book.title.replace(index,AfterEdit);
    }
    else if(item->column() == 1){
        book.author.replace(index,AfterEdit);
    }
    else if(item->column() == 2){
        book.publisher.replace(index,AfterEdit);
    }
    else if(item->column() == 3){
        book.genre.replace(index,AfterEdit);
    }
    else if(item->column() == 4){
        book.year.replace(index,AfterEdit);
    }

    QMessageBox qmb;
    qmb.information(this,"Successful editing","The book is edited successfully.");

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
}

