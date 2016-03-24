#include "qnotifierapplication.h"
#include "qnotifierlistener.h"
#include "qnotifierviewer.h"

QNotifierApplication::QNotifierApplication(int argc, char ** argv) :
    QApplication(argc, argv)
{
    this->viewer = new QNotifierViewer();
    this->listener = new QNotifierListener();

    connect(this->listener, SIGNAL(DeviceConnected()),
            this->viewer, SLOT(OnDeviceConnected()));
    connect(this->listener, SIGNAL(DeviceDisconnected()),
            this->viewer, SLOT(OnDeviceDisconnected()));

    this->viewer->Show();
    this->listener->Start();
}

QNotifierApplication::~QNotifierApplication()
{
    delete this->listener;
    delete this->viewer;
}
