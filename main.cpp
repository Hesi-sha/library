#include "signin.h"
#include "admin.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setWindowIcon(QIcon("C:/Users/DELTAcomputer/Desktop/icons/all/bookshelf.PNG"));

    SignIn w;
    w.setWindowTitle("Library");
    w.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    w.show();
    return a.exec();
}
