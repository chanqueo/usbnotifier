#include "qnotifierapplication.h"
#include "qnotifierlistener.h"
#include "qnotifiersettings.h"
#include "qnotifierviewer.h"

QNotifierApplication::QNotifierApplication(int argc, char ** argv) : QApplication(argc, argv)
{
    this->settings = new QNotifierSettings();
    this->settings->Load();
    this->viewer = new QNotifierViewer(this->settings);
    this->listener = new QNotifierListener();

    connect(this->listener, SIGNAL(DeviceConnected(QString)),
            this->viewer, SLOT(OnDeviceConnected(QString)));
    connect(this->listener, SIGNAL(DeviceDisconnected(QString)),
            this->viewer, SLOT(OnDeviceDisconnected(QString)));

    this->viewer->Show();
    this->listener->Start(this->settings->GetGUID());
}

QNotifierApplication::~QNotifierApplication()
{
    delete this->settings;
    delete this->listener;
    delete this->viewer;
}
