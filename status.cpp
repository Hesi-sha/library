#include "status.h"
#include "ui_status.h"
#include <QFile>
#include <QTextStream>
#include <QString>
#include "QTableWidget"
#include "QTableWidgetItem"
#include "admin.h"
#define UserAddress "Books information.txt"
#define BooksCount "Number OF All Books.txt"

status::status(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::status)
{
    ui->setupUi(this);
    int count = 0;

    QFile filee(BooksCount);
    filee.open(QFile::ReadOnly | QFile::Text);
    QTextStream q(&filee);
    while(!q.atEnd()){
        QList<QString> temp = q.readLine().split(' ');
        count = temp[0].toInt();
    }
    filee.close();

    ui->RentLabel->setText(QString::number(count));
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

}

status::~status()
{
    delete ui;
}

void status::on_BackBtn_clicked()
{
    admin *ad = new admin(this);
    ad->setWindowTitle("Library");
    ad->show();
    hide();
}


void status::on_SearchLine_textChanged(const QString &arg)
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
    QTableWidgetItem *rent;

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
        book.rentedBy.append(temp[5]);
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
                rent = new QTableWidgetItem;

                title->setText(book.title[i]);
                author->setText(book.author[i]);
                publisher->setText(book.publisher[i]);
                genre->setText(book.genre[i]);
                date->setText(book.year[i]);
                rent->setText(book.rentedBy[i]);

                title->setTextAlignment( Qt::AlignCenter );
                author->setTextAlignment( Qt::AlignCenter );
                publisher->setTextAlignment( Qt::AlignCenter );
                genre->setTextAlignment( Qt::AlignCenter );
                date->setTextAlignment( Qt::AlignCenter );
                rent->setTextAlignment( Qt::AlignCenter );

                ui->BookTable->setItem(r,0,title);
                ui->BookTable->setItem(r,1,author);
                ui->BookTable->setItem(r,2,publisher);
                ui->BookTable->setItem(r,3,genre);
                ui->BookTable->setItem(r,4,date);
                ui->BookTable->setItem(r,5,rent);
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
                rent = new QTableWidgetItem;

                title->setText(book.title[i]);
                author->setText(book.author[i]);
                publisher->setText(book.publisher[i]);
                genre->setText(book.genre[i]);
                date->setText(book.year[i]);
                rent->setText(book.rentedBy[i]);

                title->setTextAlignment( Qt::AlignCenter );
                author->setTextAlignment( Qt::AlignCenter );
                publisher->setTextAlignment( Qt::AlignCenter );
                genre->setTextAlignment( Qt::AlignCenter );
                date->setTextAlignment( Qt::AlignCenter );
                rent->setTextAlignment( Qt::AlignCenter );

                ui->BookTable->setItem(r,0,title);
                ui->BookTable->setItem(r,1,author);
                ui->BookTable->setItem(r,2,publisher);
                ui->BookTable->setItem(r,3,genre);
                ui->BookTable->setItem(r,4,date);
                ui->BookTable->setItem(r,5,rent);
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
                rent = new QTableWidgetItem;

                title->setText(book.title[i]);
                author->setText(book.author[i]);
                publisher->setText(book.publisher[i]);
                genre->setText(book.genre[i]);
                date->setText(book.year[i]);
                rent->setText(book.rentedBy[i]);

                title->setTextAlignment( Qt::AlignCenter );
                author->setTextAlignment( Qt::AlignCenter );
                publisher->setTextAlignment( Qt::AlignCenter );
                genre->setTextAlignment( Qt::AlignCenter );
                date->setTextAlignment( Qt::AlignCenter );
                rent->setTextAlignment( Qt::AlignCenter );

                ui->BookTable->setItem(r,0,title);
                ui->BookTable->setItem(r,1,author);
                ui->BookTable->setItem(r,2,publisher);
                ui->BookTable->setItem(r,3,genre);
                ui->BookTable->setItem(r,4,date);
                ui->BookTable->setItem(r,5,rent);
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
                rent = new QTableWidgetItem;

                title->setText(book.title[i]);
                author->setText(book.author[i]);
                publisher->setText(book.publisher[i]);
                genre->setText(book.genre[i]);
                date->setText(book.year[i]);
                rent->setText(book.rentedBy[i]);

                title->setTextAlignment( Qt::AlignCenter );
                author->setTextAlignment( Qt::AlignCenter );
                publisher->setTextAlignment( Qt::AlignCenter );
                genre->setTextAlignment( Qt::AlignCenter );
                date->setTextAlignment( Qt::AlignCenter );
                rent->setTextAlignment( Qt::AlignCenter );

                ui->BookTable->setItem(r,0,title);
                ui->BookTable->setItem(r,1,author);
                ui->BookTable->setItem(r,2,publisher);
                ui->BookTable->setItem(r,3,genre);
                ui->BookTable->setItem(r,4,date);
                ui->BookTable->setItem(r,5,rent);
                r++;
            }
        }
    }
}
