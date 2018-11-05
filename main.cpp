#include "bdownloader.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    bDownloader w;
    w.show();

    return a.exec();
}
