#include "add.h"
#include "ui_add.h"
#include "admin.h"
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QMessageBox>
#define BookAddress "Books information.txt"
add::add(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::add)
{
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    ui->setupUi(this);
}

add::~add()
{
    delete ui;
}

void add::on_Back_clicked()
{
    admin *ad = new admin(this);
    ad->setWindowTitle("Library");
    ad->show();
    hide();
}

int temp_year = 0;

void add::on_AddBookBtn_clicked()
{
    Book book;

    QString temp_title = this->ui->TitleLine->text();
    QString temp_author  = this->ui->AuthorLine->text();
    QString temp_publisher = this->ui->PublisherLine->text();
    QString temp_genre;

    if(ui->OtherCheck->isChecked())
        temp_genre = ui->OtherLine->text();
    else{
        if(ui->FantasyRadio->isChecked())
            temp_genre = "Fantasy";
        else if(ui->NovelRadio->isChecked())
            temp_genre = "Novel";
        else if(ui->MysteryRadio->isChecked())
            temp_genre = "Mystery";
        else if(ui->ScienceRadio->isChecked())
            temp_genre = "Science Fiction";
        else if(ui->HistoricalRadio->isChecked())
            temp_genre = "Historical";
        else if(ui->HorrorRadio->isChecked())
            temp_genre = "Horror";
        else if(ui->BioRadio->isChecked())
            temp_genre = "Biography";
        else if(ui->ComedyRadio->isChecked())
            temp_genre = "Comedy";
        else if(ui->RomanceRadio->isChecked())
            temp_genre = "Romance";
        else if(ui->ComicRadio->isChecked())
            temp_genre = "Comic Book";
        else if(ui->PhilsRadio->isChecked())
            temp_genre =  "Philosophy";
        else if(ui->HelpRadio->isChecked())
            temp_genre = "Self Help";
        else if(ui->ChildRadio->isChecked())
            temp_genre = "Children Story";
        else if(ui->PoetryRadio->isChecked())
            temp_genre = "Poetry";
        else if(ui->EducationRadio->isChecked())
            temp_genre = "Education";
    }

    QFile file(BookAddress);
    file.open(QFile::WriteOnly | QFile :: Append);
    QTextStream   x(&file);

    if(!temp_title.isEmpty() && !temp_publisher.isEmpty() && !temp_genre.isEmpty() && !temp_author.isEmpty() && temp_year != 0){
        x << temp_title << "-" << temp_author << "-" << temp_publisher << "-" << temp_genre << "-" << temp_year << "-" << "Available" << "\n";
        file.close();
        QMessageBox :: information(this,"Successful adding","The book is added successfully.");
        ui->TitleLine->clear();
        ui->AuthorLine->clear();
        ui->PublisherLine->clear();
        ui->YearBox->setCurrentIndex(0);
        ui->OtherLine->clear();
        ui->OtherCheck->setChecked(false);
    }
    else{
        QMessageBox msg;
        msg.warning(this,"Failed adding","Please fill all fields and try again!");

        if(temp_title.isEmpty())
            ui->TitleLine->setPlaceholderText("*");
        if(temp_author.isEmpty())
            ui->AuthorLine->setPlaceholderText("*");
        if(temp_publisher.isEmpty())
            ui->PublisherLine->setPlaceholderText("*");
    }
}

void add::on_YearBox_currentTextChanged(const QString &arg1)
{
    temp_year = arg1.toInt();
}

void add::on_OtherCheck_clicked(bool checked)
{
    if(checked == true){
        ui->OtherLine->setEnabled(true);
        ui->FantasyRadio->setEnabled(false);
        ui->NovelRadio->setEnabled(false);
        ui->MysteryRadio->setEnabled(false);
        ui->ScienceRadio->setEnabled(false);
        ui->HistoricalRadio->setEnabled(false);
        ui->HorrorRadio->setEnabled(false);
        ui->BioRadio->setEnabled(false);
        ui->ComedyRadio->setEnabled(false);
        ui->RomanceRadio->setEnabled(false);
        ui->ComicRadio->setEnabled(false);
        ui->PhilsRadio->setEnabled(false);
        ui->HelpRadio->setEnabled(false);
        ui->EducationRadio->setEnabled(false);
        ui->ChildRadio->setEnabled(false);
        ui->PoetryRadio->setEnabled(false);
    }
    else{
        ui->OtherLine->setEnabled(false);
        ui->FantasyRadio->setEnabled(true);
        ui->NovelRadio->setEnabled(true);
        ui->MysteryRadio->setEnabled(true);
        ui->ScienceRadio->setEnabled(true);
        ui->HistoricalRadio->setEnabled(true);
        ui->HorrorRadio->setEnabled(true);
        ui->BioRadio->setEnabled(true);
        ui->ComedyRadio->setEnabled(true);
        ui->RomanceRadio->setEnabled(true);
        ui->ComicRadio->setEnabled(true);
        ui->PhilsRadio->setEnabled(true);
        ui->HelpRadio->setEnabled(true);
        ui->EducationRadio->setEnabled(true);
        ui->ChildRadio->setEnabled(true);
        ui->PoetryRadio->setEnabled(true);
    }
}

void add::on_reload_clicked()
{
    add *ad = new add(this);
    ad->setWindowTitle("Library");
    ad->show();
    hide();
}
