#include "qnotifierapplication.h"
#include "qnotifierlistener.h"
#include "qnotifierviewer.h"

QNotifierApplication::QNotifierApplication(int argc, char ** argv) :
    QApplication(argc, argv)
{
    this->viewer = new QNotifierViewer();
    this->listener = new QNotifierListener();

    connect(this->listener, SIGNAL(DeviceConnected(QString)),
            this->viewer, SLOT(OnDeviceConnected(QString)));
    connect(this->listener, SIGNAL(DeviceDisconnected(QString)),
            this->viewer, SLOT(OnDeviceDisconnected(QString)));

    this->viewer->Show();
    this->listener->Start();
}

QNotifierApplication::~QNotifierApplication()
{
    delete this->listener;
    delete this->viewer;
}
