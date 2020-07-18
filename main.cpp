#include "mainscene.h"
#include <QApplication>
#include <QtMultimedia>
#include <QResource>
#include "config.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);



    MainScene w;
    w.show();

    return a.exec();
}
