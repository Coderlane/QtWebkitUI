#include "browserwindow.h"
#include "server.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Server s;
    BrowserWindow w;
    s.connect(&s, SIGNAL(Status(QString)), &w, SLOT(Status(QString)));

    w.show();
    s.Connect();

    return a.exec();
}
