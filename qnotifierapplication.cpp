#include "qnotifierapplication.h"
#include "qnotifiericon.h"
#include "qnotifierlistener.h"

QNotifierApplication::QNotifierApplication(int argc, char ** argv) :
    QApplication(argc, argv)
{
    this->icon = new QNotifierIcon();
    this->icon->show();

    this->listener = new QNotifierListener();

    connect(this->listener, SIGNAL(DeviceConnected()),
            this->icon, SLOT(OnDeviceConnected()));
    connect(this->listener, SIGNAL(DeviceDisconnected()),
            this->icon, SLOT(OnDeviceDisconnected()));

    this->listener->start();
}

QNotifierApplication::~QNotifierApplication()
{
    delete this->icon;
}
