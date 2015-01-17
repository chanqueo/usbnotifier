#include "qnotifierlistener.h"

#include <windows.h>
#include <dbt.h>

QNotifierListener::QNotifierListener() : QMainWindow()
{
}

bool QNotifierListener::start()
{
    GUID usbGUID = {
        0x4d36e967, 0xe325, 0x11ce,
        0xbf, 0xc1, 0x08, 0x00, 0x2b, 0xe1, 0x03, 0x18
    };

    DEV_BROADCAST_DEVICEINTERFACE notificationFilter;

    memset(&notificationFilter, 0, sizeof(DEV_BROADCAST_DEVICEINTERFACE));
    notificationFilter.dbcc_size = sizeof(DEV_BROADCAST_DEVICEINTERFACE);
    notificationFilter.dbcc_devicetype = DBT_DEVTYP_DEVICEINTERFACE;
    notificationFilter.dbcc_classguid = usbGUID;

    HDEVNOTIFY devNotify =
            RegisterDeviceNotification((HANDLE)this->winId(),
                                       &notificationFilter,
                                       DEVICE_NOTIFY_WINDOW_HANDLE);

    return devNotify != NULL;
}

bool QNotifierListener::nativeEvent(const QByteArray & eventType,
                                    void * message,
                                    long * result)
{
    Q_UNUSED(result);
    Q_UNUSED(eventType);

    MSG * msg = reinterpret_cast<MSG *>(message);

    // Does this specific message interest us?
    if(msg->message == WM_DEVICECHANGE)
    {
        switch(msg->wParam)
        {
        case DBT_DEVICEARRIVAL:
            emit this->DeviceConnected();
            break;

        case DBT_DEVICEREMOVECOMPLETE:
            emit this->DeviceDisconnected();
            break;
        }
    }

    // Qt handles the rest
    return false;
}
