#include "smartdevicemanager.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SmartDeviceManager w;
    w.show();
    return a.exec();
}
