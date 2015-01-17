#include "qnotifierapplication.h"

QNotifierApplication::QNotifierApplication(int argc, char ** argv) :
    QApplication(argc, argv)
{
    this->icon = new QNotifierIcon();
    this->icon->show();

    this->listener = new QNotifierListener();

    connect(this->listener, &QNotifierListener::DeviceConnected,
            this->icon, &QNotifierIcon::OnDeviceConnected );
    connect(this->listener, &QNotifierListener::DeviceDisconnected,
            this->icon,  &QNotifierIcon::OnDeviceDisconnected );

    this->listener->start();
}

QNotifierApplication::~QNotifierApplication()
{
    delete this->icon;
}
