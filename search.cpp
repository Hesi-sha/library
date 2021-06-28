#include "search.h"
#include "ui_search.h"
#include "signup.h"
#include <QFile>
#include <QTextStream>
#include <QString>
#include "QTableWidget"
#include "QTableWidgetItem"
#include "admin.h"
#define UserAddress "Books information.txt"
search::search(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::search)
{
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    ui->setupUi(this);
}

search::~search()
{
    delete ui;
}

void search::on_SearchLine_textChanged(const QString &arg)
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

    Book book;
    QString srch = arg;

    QFile file(UserAddress) ;
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream y(&file);
    while(!y.atEnd()){
        QList<QString> temp = y.readLine().split('-');
        book.title.append(temp[0]);
        book.author.append(temp[1]);
        book.publisher.append(temp[2]);
        book.genre.append(temp[3]);
        book.year.append(temp[4]);
    }
    file.close();

    if(ui->TitleRadio->isChecked()){
        int r = 0;
        for (int i = 0 ; i < book.title.size() ; ++i) {

            QString tmp = book.title[i];
            if(tmp.contains(srch) && !srch.isEmpty()){
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
            if(tmp.contains(srch) && !srch.isEmpty()){
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
            if(tmp.contains(srch) && !srch.isEmpty()){
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


void search::on_BackBtn_clicked()
{
    admin *ad = new admin(this);
    ad->setWindowTitle("Library");
    ad->show();
    hide();
}


