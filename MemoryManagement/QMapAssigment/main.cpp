#include <QCoreApplication>
#include <QMap>
#include <QDebug>
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QMap<QString,int> map;
    QTextStream cin(stdin);
    QString value;
    int mkey;
    while(true){


        qInfo()<<"Enter a name or type quit";
        cin>>value;

        if(value == "quit"){
            foreach (QString elem, map.keys()) {
                qInfo()<<elem <<"is "<<map[elem]<<"years old";
            }
            break;

        }
        qInfo()<<"and proper age";
        std::cin>>mkey;
        map[value]=mkey;
    }

    return a.exec();
}
