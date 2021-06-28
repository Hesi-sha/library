#include "rent.h"
#include "ui_rent.h"
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

rent::rent(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::rent)
{
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    ui->setupUi(this);
}

rent::~rent()
{
    delete ui;
}

void rent::on_SearchBtn_clicked()
{
    for (int j = 0 ; j < 20 ; ++j )
    {
        for (int i = 0 ; i < 20 ; ++i )
            ui->Table->removeRow(i);
        for (int i = 0 ; i < 20 ; ++i )
            ui->Table->removeRow(i);
        for (int i = 0 ; i < 20 ; ++i )
            ui->Table->removeRow(i);
        for (int i = 0 ; i < 20 ; ++i )
            ui->Table->removeRow(i);
        for (int i = 0 ; i < 20 ; ++i )
            ui->Table->removeRow(i);
    }

    QTableWidgetItem *title;
    QTableWidgetItem *author;
    QTableWidgetItem *publisher;
    QTableWidgetItem *genre;
    QTableWidgetItem *date;
    QTableWidgetItem *status;

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

    QString srch_genre;

    if(ui->OtherCheck->isChecked()){
        QString srch = ui->searchLine->text();
        int r = 0;
        for (int i = 0 ; i < book.genre.size() ; ++i) {

            srch_genre = book.genre[i];
            if(srch_genre.contains(srch)){
                ui->Table->insertRow(r);
                title = new QTableWidgetItem;
                author = new QTableWidgetItem;
                publisher = new QTableWidgetItem;
                genre = new QTableWidgetItem;
                date = new QTableWidgetItem;
                status = new QTableWidgetItem;

                title->setText(book.title[i]);
                author->setText(book.author[i]);
                publisher->setText(book.publisher[i]);
                genre->setText(book.genre[i]);
                date->setText(book.year[i]);
                if(book.rentedBy[i] == "Available")
                    status->setText("Available");
                else
                    status->setText("Borrowed");

                title->setTextAlignment( Qt::AlignCenter );
                author->setTextAlignment( Qt::AlignCenter );
                publisher->setTextAlignment( Qt::AlignCenter );
                genre->setTextAlignment( Qt::AlignCenter );
                date->setTextAlignment( Qt::AlignCenter );
                status->setTextAlignment( Qt::AlignCenter );

                ui->Table->setItem(r,0,title);
                ui->Table->setItem(r,1,author);
                ui->Table->setItem(r,2,publisher);
                ui->Table->setItem(r,3,genre);
                ui->Table->setItem(r,4,date);
                ui->Table->setItem(r,5,status);
                r++;
            }
        }
    }

    else{
        if(ui->fantasyRadio->isChecked()){
            int r = 0;
            for (int i = 0 ; i < book.genre.size() ; ++i) {

                srch_genre = book.genre[i];
                if(srch_genre.contains("Fantasy")){
                    ui->Table->insertRow(r);
                    title = new QTableWidgetItem;
                    author = new QTableWidgetItem;
                    publisher = new QTableWidgetItem;
                    genre = new QTableWidgetItem;
                    date = new QTableWidgetItem;
                    status = new QTableWidgetItem;

                    title->setText(book.title[i]);
                    author->setText(book.author[i]);
                    publisher->setText(book.publisher[i]);
                    genre->setText(book.genre[i]);
                    date->setText(book.year[i]);
                    if(book.rentedBy[i] == "Available")
                        status->setText("Available");
                    else
                        status->setText("Borrowed");

                    title->setTextAlignment( Qt::AlignCenter );
                    author->setTextAlignment( Qt::AlignCenter );
                    publisher->setTextAlignment( Qt::AlignCenter );
                    genre->setTextAlignment( Qt::AlignCenter );
                    date->setTextAlignment( Qt::AlignCenter );
                    status->setTextAlignment( Qt::AlignCenter );

                    ui->Table->setItem(r,0,title);
                    ui->Table->setItem(r,1,author);
                    ui->Table->setItem(r,2,publisher);
                    ui->Table->setItem(r,3,genre);
                    ui->Table->setItem(r,4,date);
                    ui->Table->setItem(r,5,status);
                    r++;
                }
            }
        }

        else if(ui->novelRadio->isChecked()){
            int r = 0;
            for (int i = 0 ; i < book.genre.size() ; ++i) {

                srch_genre = book.genre[i];
                if(srch_genre.contains("Novel")){
                    ui->Table->insertRow(r);
                    title = new QTableWidgetItem;
                    author = new QTableWidgetItem;
                    publisher = new QTableWidgetItem;
                    genre = new QTableWidgetItem;
                    date = new QTableWidgetItem;
                    status = new QTableWidgetItem;

                    title->setText(book.title[i]);
                    author->setText(book.author[i]);
                    publisher->setText(book.publisher[i]);
                    genre->setText(book.genre[i]);
                    date->setText(book.year[i]);
                    if(book.rentedBy[i] == "Available")
                        status->setText("Available");
                    else
                        status->setText("Borrowed");

                    title->setTextAlignment( Qt::AlignCenter );
                    author->setTextAlignment( Qt::AlignCenter );
                    publisher->setTextAlignment( Qt::AlignCenter );
                    genre->setTextAlignment( Qt::AlignCenter );
                    date->setTextAlignment( Qt::AlignCenter );
                    status->setTextAlignment( Qt::AlignCenter );

                    ui->Table->setItem(r,0,title);
                    ui->Table->setItem(r,1,author);
                    ui->Table->setItem(r,2,publisher);
                    ui->Table->setItem(r,3,genre);
                    ui->Table->setItem(r,4,date);
                    ui->Table->setItem(r,5,status);
                    r++;
                }
            }
        }

        else if(ui->mysteryRadio->isChecked()){
            int r = 0;
            for (int i = 0 ; i < book.genre.size() ; ++i) {

                srch_genre = book.genre[i];
                if(srch_genre.contains("Mystery")){
                    ui->Table->insertRow(r);
                    title = new QTableWidgetItem;
                    author = new QTableWidgetItem;
                    publisher = new QTableWidgetItem;
                    genre = new QTableWidgetItem;
                    date = new QTableWidgetItem;
                    status = new QTableWidgetItem;

                    title->setText(book.title[i]);
                    author->setText(book.author[i]);
                    publisher->setText(book.publisher[i]);
                    genre->setText(book.genre[i]);
                    date->setText(book.year[i]);
                    if(book.rentedBy[i] == "Available")
                        status->setText("Available");
                    else
                        status->setText("Borrowed");

                    title->setTextAlignment( Qt::AlignCenter );
                    author->setTextAlignment( Qt::AlignCenter );
                    publisher->setTextAlignment( Qt::AlignCenter );
                    genre->setTextAlignment( Qt::AlignCenter );
                    date->setTextAlignment( Qt::AlignCenter );
                    status->setTextAlignment( Qt::AlignCenter );

                    ui->Table->setItem(r,0,title);
                    ui->Table->setItem(r,1,author);
                    ui->Table->setItem(r,2,publisher);
                    ui->Table->setItem(r,3,genre);
                    ui->Table->setItem(r,4,date);
                    ui->Table->setItem(r,5,status);
                    r++;
                }
            }
        }

        else if(ui->scienceRadio->isChecked()){
            int r = 0;
            for (int i = 0 ; i < book.genre.size() ; ++i) {

                srch_genre = book.genre[i];
                if(srch_genre.contains("Science Fiction")){
                    ui->Table->insertRow(r);
                    title = new QTableWidgetItem;
                    author = new QTableWidgetItem;
                    publisher = new QTableWidgetItem;
                    genre = new QTableWidgetItem;
                    date = new QTableWidgetItem;
                    status = new QTableWidgetItem;

                    title->setText(book.title[i]);
                    author->setText(book.author[i]);
                    publisher->setText(book.publisher[i]);
                    genre->setText(book.genre[i]);
                    date->setText(book.year[i]);
                    if(book.rentedBy[i] == "Available")
                        status->setText("Available");
                    else
                        status->setText("Borrowed");

                    title->setTextAlignment( Qt::AlignCenter );
                    author->setTextAlignment( Qt::AlignCenter );
                    publisher->setTextAlignment( Qt::AlignCenter );
                    genre->setTextAlignment( Qt::AlignCenter );
                    date->setTextAlignment( Qt::AlignCenter );
                    status->setTextAlignment( Qt::AlignCenter );

                    ui->Table->setItem(r,0,title);
                    ui->Table->setItem(r,1,author);
                    ui->Table->setItem(r,2,publisher);
                    ui->Table->setItem(r,3,genre);
                    ui->Table->setItem(r,4,date);
                    ui->Table->setItem(r,5,status);
                    r++;
                }
            }
        }

        else if(ui->historicalRadio->isChecked()){
            int r = 0;
            for (int i = 0 ; i < book.genre.size() ; ++i) {

                srch_genre = book.genre[i];
                if(srch_genre.contains("Historical")){
                    ui->Table->insertRow(r);
                    title = new QTableWidgetItem;
                    author = new QTableWidgetItem;
                    publisher = new QTableWidgetItem;
                    genre = new QTableWidgetItem;
                    date = new QTableWidgetItem;
                    status = new QTableWidgetItem;

                    title->setText(book.title[i]);
                    author->setText(book.author[i]);
                    publisher->setText(book.publisher[i]);
                    genre->setText(book.genre[i]);
                    date->setText(book.year[i]);
                    if(book.rentedBy[i] == "Available")
                        status->setText("Available");
                    else
                        status->setText("Borrowed");

                    title->setTextAlignment( Qt::AlignCenter );
                    author->setTextAlignment( Qt::AlignCenter );
                    publisher->setTextAlignment( Qt::AlignCenter );
                    genre->setTextAlignment( Qt::AlignCenter );
                    date->setTextAlignment( Qt::AlignCenter );
                    status->setTextAlignment( Qt::AlignCenter );

                    ui->Table->setItem(r,0,title);
                    ui->Table->setItem(r,1,author);
                    ui->Table->setItem(r,2,publisher);
                    ui->Table->setItem(r,3,genre);
                    ui->Table->setItem(r,4,date);
                    ui->Table->setItem(r,5,status);
                    r++;
                }
            }
        }

        else if(ui->horrorRadio->isChecked()){
            int r = 0;
            for (int i = 0 ; i < book.genre.size() ; ++i) {

                srch_genre = book.genre[i];
                if(srch_genre.contains("Horror")){
                    ui->Table->insertRow(r);
                    title = new QTableWidgetItem;
                    author = new QTableWidgetItem;
                    publisher = new QTableWidgetItem;
                    genre = new QTableWidgetItem;
                    date = new QTableWidgetItem;
                    status = new QTableWidgetItem;

                    title->setText(book.title[i]);
                    author->setText(book.author[i]);
                    publisher->setText(book.publisher[i]);
                    genre->setText(book.genre[i]);
                    date->setText(book.year[i]);
                    if(book.rentedBy[i] == "Available")
                        status->setText("Available");
                    else
                        status->setText("Borrowed");

                    title->setTextAlignment( Qt::AlignCenter );
                    author->setTextAlignment( Qt::AlignCenter );
                    publisher->setTextAlignment( Qt::AlignCenter );
                    genre->setTextAlignment( Qt::AlignCenter );
                    date->setTextAlignment( Qt::AlignCenter );
                    status->setTextAlignment( Qt::AlignCenter );

                    ui->Table->setItem(r,0,title);
                    ui->Table->setItem(r,1,author);
                    ui->Table->setItem(r,2,publisher);
                    ui->Table->setItem(r,3,genre);
                    ui->Table->setItem(r,4,date);
                    ui->Table->setItem(r,5,status);
                    r++;
                }
            }
        }

        else if(ui->bioRadio->isChecked()){
            int r = 0;
            for (int i = 0 ; i < book.genre.size() ; ++i) {

                srch_genre = book.genre[i];
                if(srch_genre.contains("Biography")){
                    ui->Table->insertRow(r);
                    title = new QTableWidgetItem;
                    author = new QTableWidgetItem;
                    publisher = new QTableWidgetItem;
                    genre = new QTableWidgetItem;
                    date = new QTableWidgetItem;
                    status = new QTableWidgetItem;

                    title->setText(book.title[i]);
                    author->setText(book.author[i]);
                    publisher->setText(book.publisher[i]);
                    genre->setText(book.genre[i]);
                    date->setText(book.year[i]);
                    if(book.rentedBy[i] == "Available")
                        status->setText("Available");
                    else
                        status->setText("Borrowed");

                    title->setTextAlignment( Qt::AlignCenter );
                    author->setTextAlignment( Qt::AlignCenter );
                    publisher->setTextAlignment( Qt::AlignCenter );
                    genre->setTextAlignment( Qt::AlignCenter );
                    date->setTextAlignment( Qt::AlignCenter );
                    status->setTextAlignment( Qt::AlignCenter );

                    ui->Table->setItem(r,0,title);
                    ui->Table->setItem(r,1,author);
                    ui->Table->setItem(r,2,publisher);
                    ui->Table->setItem(r,3,genre);
                    ui->Table->setItem(r,4,date);
                    ui->Table->setItem(r,5,status);
                    r++;
                }
            }
        }

        else if(ui->comedyRadio->isChecked()){
            int r = 0;
            for (int i = 0 ; i < book.genre.size() ; ++i) {

                srch_genre = book.genre[i];
                if(srch_genre.contains("Comedy")){
                    ui->Table->insertRow(r);
                    title = new QTableWidgetItem;
                    author = new QTableWidgetItem;
                    publisher = new QTableWidgetItem;
                    genre = new QTableWidgetItem;
                    date = new QTableWidgetItem;
                    status = new QTableWidgetItem;

                    title->setText(book.title[i]);
                    author->setText(book.author[i]);
                    publisher->setText(book.publisher[i]);
                    genre->setText(book.genre[i]);
                    date->setText(book.year[i]);
                    if(book.rentedBy[i] == "Available")
                        status->setText("Available");
                    else
                        status->setText("Borrowed");

                    title->setTextAlignment( Qt::AlignCenter );
                    author->setTextAlignment( Qt::AlignCenter );
                    publisher->setTextAlignment( Qt::AlignCenter );
                    genre->setTextAlignment( Qt::AlignCenter );
                    date->setTextAlignment( Qt::AlignCenter );
                    status->setTextAlignment( Qt::AlignCenter );

                    ui->Table->setItem(r,0,title);
                    ui->Table->setItem(r,1,author);
                    ui->Table->setItem(r,2,publisher);
                    ui->Table->setItem(r,3,genre);
                    ui->Table->setItem(r,4,date);
                    ui->Table->setItem(r,5,status);
                    r++;
                }
            }
        }

        else if(ui->romanceRadio->isChecked()){
            int r = 0;
            for (int i = 0 ; i < book.genre.size() ; ++i) {

                srch_genre = book.genre[i];
                if(srch_genre.contains("Romance")){
                    ui->Table->insertRow(r);
                    title = new QTableWidgetItem;
                    author = new QTableWidgetItem;
                    publisher = new QTableWidgetItem;
                    genre = new QTableWidgetItem;
                    date = new QTableWidgetItem;
                    status = new QTableWidgetItem;

                    title->setText(book.title[i]);
                    author->setText(book.author[i]);
                    publisher->setText(book.publisher[i]);
                    genre->setText(book.genre[i]);
                    date->setText(book.year[i]);
                    if(book.rentedBy[i] == "Available")
                        status->setText("Available");
                    else
                        status->setText("Borrowed");

                    title->setTextAlignment( Qt::AlignCenter );
                    author->setTextAlignment( Qt::AlignCenter );
                    publisher->setTextAlignment( Qt::AlignCenter );
                    genre->setTextAlignment( Qt::AlignCenter );
                    date->setTextAlignment( Qt::AlignCenter );
                    status->setTextAlignment( Qt::AlignCenter );

                    ui->Table->setItem(r,0,title);
                    ui->Table->setItem(r,1,author);
                    ui->Table->setItem(r,2,publisher);
                    ui->Table->setItem(r,3,genre);
                    ui->Table->setItem(r,4,date);
                    ui->Table->setItem(r,5,status);
                    r++;
                }
            }
        }

        else if(ui->comicRadio->isChecked()){
            int r = 0;
            for (int i = 0 ; i < book.genre.size() ; ++i) {

                srch_genre = book.genre[i];
                if(srch_genre.contains("Comic Book")){
                    ui->Table->insertRow(r);
                    title = new QTableWidgetItem;
                    author = new QTableWidgetItem;
                    publisher = new QTableWidgetItem;
                    genre = new QTableWidgetItem;
                    date = new QTableWidgetItem;
                    status = new QTableWidgetItem;

                    title->setText(book.title[i]);
                    author->setText(book.author[i]);
                    publisher->setText(book.publisher[i]);
                    genre->setText(book.genre[i]);
                    date->setText(book.year[i]);
                    if(book.rentedBy[i] == "Available")
                        status->setText("Available");
                    else
                        status->setText("Borrowed");

                    title->setTextAlignment( Qt::AlignCenter );
                    author->setTextAlignment( Qt::AlignCenter );
                    publisher->setTextAlignment( Qt::AlignCenter );
                    genre->setTextAlignment( Qt::AlignCenter );
                    date->setTextAlignment( Qt::AlignCenter );
                    status->setTextAlignment( Qt::AlignCenter );

                    ui->Table->setItem(r,0,title);
                    ui->Table->setItem(r,1,author);
                    ui->Table->setItem(r,2,publisher);
                    ui->Table->setItem(r,3,genre);
                    ui->Table->setItem(r,4,date);
                    ui->Table->setItem(r,5,status);
                    r++;
                }
            }
        }

        else if(ui->philsRadio->isChecked()){
            int r = 0;
            for (int i = 0 ; i < book.genre.size() ; ++i) {

                srch_genre = book.genre[i];
                if(srch_genre.contains("Philosophy")){
                    ui->Table->insertRow(r);
                    title = new QTableWidgetItem;
                    author = new QTableWidgetItem;
                    publisher = new QTableWidgetItem;
                    genre = new QTableWidgetItem;
                    date = new QTableWidgetItem;
                    status = new QTableWidgetItem;

                    title->setText(book.title[i]);
                    author->setText(book.author[i]);
                    publisher->setText(book.publisher[i]);
                    genre->setText(book.genre[i]);
                    date->setText(book.year[i]);
                    if(book.rentedBy[i] == "Available")
                        status->setText("Available");
                    else
                        status->setText("Borrowed");

                    title->setTextAlignment( Qt::AlignCenter );
                    author->setTextAlignment( Qt::AlignCenter );
                    publisher->setTextAlignment( Qt::AlignCenter );
                    genre->setTextAlignment( Qt::AlignCenter );
                    date->setTextAlignment( Qt::AlignCenter );
                    status->setTextAlignment( Qt::AlignCenter );

                    ui->Table->setItem(r,0,title);
                    ui->Table->setItem(r,1,author);
                    ui->Table->setItem(r,2,publisher);
                    ui->Table->setItem(r,3,genre);
                    ui->Table->setItem(r,4,date);
                    ui->Table->setItem(r,5,status);
                    r++;
                }
            }
        }

        else if(ui->helpRadio->isChecked()){
            int r = 0;
            for (int i = 0 ; i < book.genre.size() ; ++i) {

                srch_genre = book.genre[i];
                if(srch_genre.contains("Self Help")){
                    ui->Table->insertRow(r);
                    title = new QTableWidgetItem;
                    author = new QTableWidgetItem;
                    publisher = new QTableWidgetItem;
                    genre = new QTableWidgetItem;
                    date = new QTableWidgetItem;
                    status = new QTableWidgetItem;

                    title->setText(book.title[i]);
                    author->setText(book.author[i]);
                    publisher->setText(book.publisher[i]);
                    genre->setText(book.genre[i]);
                    date->setText(book.year[i]);
                    if(book.rentedBy[i] == "Available")
                        status->setText("Available");
                    else
                        status->setText("Borrowed");

                    title->setTextAlignment( Qt::AlignCenter );
                    author->setTextAlignment( Qt::AlignCenter );
                    publisher->setTextAlignment( Qt::AlignCenter );
                    genre->setTextAlignment( Qt::AlignCenter );
                    date->setTextAlignment( Qt::AlignCenter );
                    status->setTextAlignment( Qt::AlignCenter );

                    ui->Table->setItem(r,0,title);
                    ui->Table->setItem(r,1,author);
                    ui->Table->setItem(r,2,publisher);
                    ui->Table->setItem(r,3,genre);
                    ui->Table->setItem(r,4,date);
                    ui->Table->setItem(r,5,status);
                    r++;
                }
            }
        }
        else if(ui->educationRadio->isChecked()){
            int r = 0;
            for (int i = 0 ; i < book.genre.size() ; ++i) {

                srch_genre = book.genre[i];
                if(srch_genre.contains("Education")){
                    ui->Table->insertRow(r);
                    title = new QTableWidgetItem;
                    author = new QTableWidgetItem;
                    publisher = new QTableWidgetItem;
                    genre = new QTableWidgetItem;
                    date = new QTableWidgetItem;
                    status = new QTableWidgetItem;

                    title->setText(book.title[i]);
                    author->setText(book.author[i]);
                    publisher->setText(book.publisher[i]);
                    genre->setText(book.genre[i]);
                    date->setText(book.year[i]);
                    if(book.rentedBy[i] == "Available")
                        status->setText("Available");
                    else
                        status->setText("Borrowed");

                    title->setTextAlignment( Qt::AlignCenter );
                    author->setTextAlignment( Qt::AlignCenter );
                    publisher->setTextAlignment( Qt::AlignCenter );
                    genre->setTextAlignment( Qt::AlignCenter );
                    date->setTextAlignment( Qt::AlignCenter );
                    status->setTextAlignment( Qt::AlignCenter );

                    ui->Table->setItem(r,0,title);
                    ui->Table->setItem(r,1,author);
                    ui->Table->setItem(r,2,publisher);
                    ui->Table->setItem(r,3,genre);
                    ui->Table->setItem(r,4,date);
                    ui->Table->setItem(r,5,status);
                    r++;
                }
            }
        }

        else if(ui->childRadio->isChecked()){
            int r = 0;
            for (int i = 0 ; i < book.genre.size() ; ++i) {

                srch_genre = book.genre[i];
                if(srch_genre.contains("Children Story")){
                    ui->Table->insertRow(r);
                    title = new QTableWidgetItem;
                    author = new QTableWidgetItem;
                    publisher = new QTableWidgetItem;
                    genre = new QTableWidgetItem;
                    date = new QTableWidgetItem;
                    status = new QTableWidgetItem;

                    title->setText(book.title[i]);
                    author->setText(book.author[i]);
                    publisher->setText(book.publisher[i]);
                    genre->setText(book.genre[i]);
                    date->setText(book.year[i]);
                    if(book.rentedBy[i] == "Available")
                        status->setText("Available");
                    else
                        status->setText("Borrowed");

                    title->setTextAlignment( Qt::AlignCenter );
                    author->setTextAlignment( Qt::AlignCenter );
                    publisher->setTextAlignment( Qt::AlignCenter );
                    genre->setTextAlignment( Qt::AlignCenter );
                    date->setTextAlignment( Qt::AlignCenter );
                    status->setTextAlignment( Qt::AlignCenter );

                    ui->Table->setItem(r,0,title);
                    ui->Table->setItem(r,1,author);
                    ui->Table->setItem(r,2,publisher);
                    ui->Table->setItem(r,3,genre);
                    ui->Table->setItem(r,4,date);
                    ui->Table->setItem(r,5,status);
                    r++;
                }
            }
        }

        else if(ui->poetryRadio->isChecked()){
            int r = 0;
            for (int i = 0 ; i < book.genre.size() ; ++i) {

                srch_genre = book.genre[i];
                if(srch_genre.contains("Poetry")){
                    ui->Table->insertRow(r);
                    title = new QTableWidgetItem;
                    author = new QTableWidgetItem;
                    publisher = new QTableWidgetItem;
                    genre = new QTableWidgetItem;
                    date = new QTableWidgetItem;
                    status = new QTableWidgetItem;

                    title->setText(book.title[i]);
                    author->setText(book.author[i]);
                    publisher->setText(book.publisher[i]);
                    genre->setText(book.genre[i]);
                    date->setText(book.year[i]);
                    if(book.rentedBy[i] == "Available")
                        status->setText("Available");
                    else
                        status->setText("Borrowed");

                    title->setTextAlignment( Qt::AlignCenter );
                    author->setTextAlignment( Qt::AlignCenter );
                    publisher->setTextAlignment( Qt::AlignCenter );
                    genre->setTextAlignment( Qt::AlignCenter );
                    date->setTextAlignment( Qt::AlignCenter );
                    status->setTextAlignment( Qt::AlignCenter );

                    ui->Table->setItem(r,0,title);
                    ui->Table->setItem(r,1,author);
                    ui->Table->setItem(r,2,publisher);
                    ui->Table->setItem(r,3,genre);
                    ui->Table->setItem(r,4,date);
                    ui->Table->setItem(r,5,status);
                    r++;
                }
            }
        }
    }

}


void rent::on_OtherCheck_clicked(bool checked)
{
    if(checked == true){
        ui->searchLine->setEnabled(true);
        ui->fantasyRadio->setEnabled(false);
        ui->novelRadio->setEnabled(false);
        ui->mysteryRadio->setEnabled(false);
        ui->scienceRadio->setEnabled(false);
        ui->historicalRadio->setEnabled(false);
        ui->horrorRadio->setEnabled(false);
        ui->bioRadio->setEnabled(false);
        ui->comedyRadio->setEnabled(false);
        ui->romanceRadio->setEnabled(false);
        ui->comicRadio->setEnabled(false);
        ui->philsRadio->setEnabled(false);
        ui->helpRadio->setEnabled(false);
        ui->educationRadio->setEnabled(false);
        ui->childRadio->setEnabled(false);
        ui->poetryRadio->setEnabled(false);
    }
    else{
        ui->searchLine->setEnabled(false);
        ui->fantasyRadio->setEnabled(true);
        ui->novelRadio->setEnabled(true);
        ui->mysteryRadio->setEnabled(true);
        ui->scienceRadio->setEnabled(true);
        ui->historicalRadio->setEnabled(true);
        ui->horrorRadio->setEnabled(true);
        ui->bioRadio->setEnabled(true);
        ui->comedyRadio->setEnabled(true);
        ui->romanceRadio->setEnabled(true);
        ui->comicRadio->setEnabled(true);
        ui->philsRadio->setEnabled(true);
        ui->helpRadio->setEnabled(true);
        ui->educationRadio->setEnabled(true);
        ui->childRadio->setEnabled(true);
        ui->poetryRadio->setEnabled(true);
    }
}


void rent::on_backBtn_clicked()
{
    member *mem = new member(this);
    mem->setWindowTitle("Library");
    mem->show();
    hide();
}


void rent::on_Table_cellDoubleClicked(int row, int column)
{
    Book book;
    User user;

    QFile filex(BookAddress);
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

    QFile filey(UserAddress) ;
    filey.open(QFile::ReadOnly | QFile::Text);
    QTextStream z(&filey);

    while(!z.atEnd()){
        QList<QString> temp = z.readLine().split('-');
        user.firstname.append(temp[0]);
        user.lastname.append(temp[1]);
        user.username.append(temp[2]);
        user.password.append(temp[3]);
        user.sex.append(temp[4]);
        user.index = temp[5];
    }
    filey.close();

    QString FindBook = ui->Table->item(row,0)->text();
    int index = book.title.indexOf(FindBook);

    if(book.rentedBy[index] == "Available"){
        book.rentedBy.replace(index, user.firstname[user.index.toInt()] + " " + user.lastname[user.index.toInt()]);
        QMessageBox qmb;
        qmb.information(this,"Successful renting","The book has been borrowed successfully.");
        ui->Table->item(row,5)->setText("Borrowed");

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
        p << ++book.allRentedBooks << " ";
        fileex.close();

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

        while(itr3.hasNext()){
            x << itr1.next() << "-" << itr2.next() << "-" << itr3.next() << "-" << itr4.next() << "-" << itr5.next() << "-" << itr6.next() << "\n";
        }
        file.close();
    }
    else{
        QMessageBox qmb;
        qmb.warning(this,"Failed renting","The book is not available for borrowing!");
    }

}
